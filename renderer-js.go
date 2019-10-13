package sve

import (
	"bytes"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"log"
	"runtime/debug"
	"strings"
	"sync"

	js "github.com/p9c/sve/js"
)

//go:generate go run renderer-js-script-maker.go

// NewJSRenderer will create a new JSRenderer with the speicifc mount point selector.
// If an empty string is passed then the root component should include a top level <html> tag
// and the entire page will be rendered.
func NewJSRenderer(mountPointSelector string) (*JSRenderer, error) {

	ret := &JSRenderer{
		MountPointSelector: mountPointSelector,
	}

	ret.instructionBuffer = make([]byte, 16384)
	// ret.instructionTypedArray = js.TypedArrayOf(ret.instructionBuffer)

	ret.window = js.Global().Get("window")

	ret.window.Call("eval", jsHelperScript)

	ret.instructionBufferJS = ret.window.Call("sveGetRenderArray")

	ret.instructionList = newInstructionList(ret.instructionBuffer, func(il *instructionList) error {

		// call sveRender to have the instructions processed in JS
		ret.instructionBuffer[il.pos] = 0 // ensure zero terminator

		// copy the data over
		js.CopyBytesToJS(ret.instructionBufferJS, ret.instructionBuffer)

		// then call sveRender
		ret.window.Call("sveRender" /*, ret.instructionBufferJS*/)

		return nil
	})

	ret.eventHandlerBuffer = make([]byte, 16384)
	// ret.eventHandlerTypedArray = js.TypedArrayOf(ret.eventHandlerBuffer)

	ret.eventHandlerFunc = js.FuncOf(func(this js.Value, args []js.Value) interface{} {
		if len(args) != 1 {
			panic(fmt.Errorf("eventHandlerFunc got arg slice not exactly 1 element in length: %#v", args))
		}
		n := js.CopyBytesToGo(ret.eventHandlerBuffer, args[0])
		if n >= len(ret.eventHandlerBuffer) {
			panic(fmt.Errorf("event data is too large (%d bytes), cannot continue", n))
		}
		ret.handleDOMEvent() // discard this and args, all data should be in eventHandlerBuffer; avoid using js.Value
		return nil
		// return jsEnv.handleRawDOMEvent(this, args)
	})

	// wire up the event handler func and the array that we used to communicate with instead of js.Value
	// ret.window.Call("sveSetEventHandlerAndBuffer", ret.eventHandlerFunc, ret.eventHandlerTypedArray)

	// wire up the event handler func
	ret.window.Call("sveSetEventHandler", ret.eventHandlerFunc)

	// log.Printf("ret.window: %#v", ret.window)
	// log.Printf("eval: %#v", ret.window.Get("eval"))

	ret.eventWaitCh = make(chan bool, 64)

	ret.eventEnv = &eventEnv{
		rwmu:            &ret.eventRWMU,
		requestRenderCH: ret.eventWaitCh,
	}

	return ret, nil
}

type jsRenderState struct {
	// stores positionID to slice of DOMEventHandlerSpec
	domHandlerMap map[string][]DOMEventHandlerSpec
}

func newJsRenderState() *jsRenderState {
	return &jsRenderState{
		domHandlerMap: make(map[string][]DOMEventHandlerSpec, 8),
	}
}

// JSRenderer implements Renderer against the browser's DOM.
type JSRenderer struct {
	MountPointSelector string

	eventWaitCh chan bool    // events send to this and EventWait receives from it
	eventRWMU   sync.RWMutex // make sure Render and event handling are not attempted at the same time (not totally sure if this is necessary in terms of the wasm threading model but enforce it with a rwmutex all the same)
	eventEnv    *eventEnv    // our EventEnv implementation that exposes eventRWMU and eventWaitCh to events in a clean way

	eventHandlerFunc   js.Func // the callback function for DOM events
	eventHandlerBuffer []byte
	// eventHandlerTypedArray js.TypedArray

	instructionBuffer   []byte   // our local instruction buffer
	instructionBufferJS js.Value // a Uint8Array on the JS side that we copy into
	// instructionTypedArray js.TypedArray
	instructionList *instructionList

	window js.Value

	jsRenderState *jsRenderState
}

// EventEnv returns an EventEnv that can be used for synchronizing updates.
func (r *JSRenderer) EventEnv() EventEnv {
	return r.eventEnv
}

// Release calls release on any resources that this renderer allocated.
func (r *JSRenderer) Release() {
	// NOTE: seems sensible to leave this here in case we do need something to be released, better than
	// omitting it and people getting used to no release being needed and then requiring it later.
	// r.instructionTypedArray.Release()
}

// Render implements Renderer.
func (r *JSRenderer) Render(buildResults *BuildResults) error {

	bo := buildResults.Out

	// acquire read lock so events are not changing data while Render is in progress
	r.eventRWMU.RLock()
	defer r.eventRWMU.RUnlock()

	if !js.Global().Truthy() {
		return fmt.Errorf("js environment not available")
	}

	if bo == nil {
		return fmt.Errorf("BuildOut is nil")
	}

	if len(bo.Out) != 1 {
		return fmt.Errorf("BuildOut.Out has bad len %d", len(bo.Out))
	}

	if bo.Out[0].Type != ElementNode {
		return fmt.Errorf("BuildOut.Out[0].Type is (%v), not ElementNode", bo.Out[0].Type)
	}

	// log.Printf("BuildOut: %#v", b)

	// NOTE:
	// We need two different strategies for rendering elements in <html> or <head>
	// as opposed to the stuff once we're inside <body>.  If we have a specific element
	// we're rendering into we have complete control and can just replace it out entirely.
	// But for <head> we want things like existing meta tags, title tags, and script includes not be removed
	// when we sync.
	// Interestingly enough, we also want to override the title tag (not add a second one).
	// Meta tags likewise it would make the most sense to selectively replace them by their name attribute.
	// So what we're headed for is something like we record what the <head> section looked like at startup,
	// and then based on the tag type we have different handlings - like meta tags we set by name, title
	// tag we always update if present, script tags we just avoid duplication if the tag is already there
	// exactly the same or with the same src, and so on.  But then you if you just drop in some random
	// crap it will just be added.
	// This is fine for <head> - it's easy to identify. But what about script tags added toward the bottom
	// of the page just inside the body tag.  Potentially we could get away with just nuking the script tags,
	// but what if someone puts in in-line styles in a style tag - replacing it would definitely remove
	// the styling - unexpected for sure.  There needs to be some well-defined rules about this.
	// Perhaps we have separately logic for the <head>, and then otherwise we still have a designated
	// element within body which is what we target.  It should be possible to just make this the body
	// tag if nobody care, but if they need to be able to do other custom stuff outside of head, it should
	// be possible - while still controlling title and meta tags etc from the Sve app.

	// const (
	// 	modeHTML          int = iota // in html tag
	// 	modeHead                     // in head tag
	// 	modeBodyUnmounted            // in body tag but not yet mounted
	// 	modeMounted                  // in the mounted tag (could be body or something else)
	// )

	// var mode int
	// switch strings.ToLower(bo.Doc.Data) {
	// case "html":
	// 	mode = modeHTML
	// case "head":
	// 	return fmt.Errorf("BuildOut.Doc is a head element, use html instead")
	// case "body":
	// 	mode = modeBodyUnmounted
	// default:
	// 	mode = modeBodyUnmounted
	// }

	// _ = mode

	// TODO: we need to make sure this call path back and forth to the outside for DOM syncing is
	// efficient - it determines Sve's overall performance characteristics to a large degree.
	// Do some tests and see what the performance difference is if pass data directly using Call()
	// a number of times vs shipping JSON over in an ArrayBuffer and parse and process it in JS.
	// NOTE: doing Call() all over the place and getting/passing various element referances around
	// causes a memory leak, since the Go code has no way of gargage collecting the various references.
	// And while the situation should improve at some point it may be a while and it might be prudent.
	// to use a solution that does not leak (as much).  Will give a more stable feel until full DOM
	// access is figured out in WASM.

	// Test results:

	// 25us per call
	// g.Call("eval", "function testf1(a) { return a + 'f1'; }")

	// 42us per call
	// g.Call("eval", "function testf1(a) { var e = document.createElement('div'); e.innerHTML = a + 'f1'; document.body.appendChild(e); }")

	// Conclusion: it takes twice as long to call from Go into JS as it does to create and attach an HTML element.
	// Ergo, we need to minimize the number of Call()s we do.

	// Approach: used a typed array buffer to produce a sort of simple set of instructions that describe how to synchronize
	// the DOM tree.  The Go code can optimize away nodes that don't need to be changed, but if they do then it writes
	// an instruction into the queue - once this queue/buffer is filled up with an appropriate number of instructions, a
	// single call is done over to JS, which reads and executes these instructions.
	// It's a bit of work, but it will force us to break down and think through the synchronization and the result
	// should be much much faster.
	// (While we're at it, we should also see if we can optimize the callback path for events - so those use a preallocated
	// buffer as well and avoid accumulating references for each event)

	// r.instructionBuffer[0] = 7
	// r.instructionBuffer[1] = 9

	// always make sure we have at least a non-nil render state
	if r.jsRenderState == nil {
		r.jsRenderState = newJsRenderState()
	}

	log.Printf("BuildOut: %#v", bo)

	el := bo.Out[0]
	log.Printf("el: %#v", el)

	// NOTE: Mount rules:
	// <body>, <head> forbidden as top level component tag
	// * if component tag is not <html>, then whatever it is gets mounted at mount point
	// * if component tag is <html>, then html attrs are sync, head elements are synced, body attrs are synced,
	//   and first element inside <body> is mounted at mount point

	// how do we do this mountpoint thing, it's pretty important...

	// start cases:
	// * starts with html tag
	// * starts with something else
	// loop cases:
	// * in html, waiting for head or body
	// * in head, needs careful replacement
	// * in body, waiting for mount point
	// * inside mounted aread, main dom sync logic

	state := newJsRenderState()

	// TODO: move this next chunk out to it's own func at least

	visitCSSList := func(cssList []*VGNode) error {
		// CSS stuff first
		for _, cssEl := range cssList {

			// some basic sanity checking
			if cssEl.Type != ElementNode || !(cssEl.Data == "style" || cssEl.Data == "link") {
				return fmt.Errorf("CSS output must be link or style tag")
			}

			var textBuf bytes.Buffer
			for childN := cssEl.FirstChild; childN != nil; childN = childN.NextSibling {
				if childN.Type != TextNode {
					return fmt.Errorf("CSS tag must contain only text children, found %d instead: %#v", childN.Type, childN)
				}
				textBuf.WriteString(childN.Data)
			}

			var attrPairs []string
			if len(cssEl.Attr) > 0 {
				attrPairs = make([]string, 0, len(cssEl.Attr)*2)
				for _, attr := range cssEl.Attr {
					attrPairs = append(attrPairs, attr.Key, attr.Val)
				}
			}

			err := r.instructionList.writeSetCSSTag(cssEl.Data, textBuf.Bytes(), attrPairs)
			if err != nil {
				return err
			}
		}

		return nil
	}

	var walkCSSBuildOut func(buildOut *BuildOut) error
	walkCSSBuildOut = func(buildOut *BuildOut) error {
		err := visitCSSList(buildOut.CSS)
		if err != nil {
			return err
		}
		for _, c := range buildOut.Components {
			nextBuildOut := buildResults.AllOut[c]
			if nextBuildOut == nil {
				panic(fmt.Errorf("walkCSSBuildOut nextBuildOut was nil for %#v", c))
			}
			err := walkCSSBuildOut(nextBuildOut)
			if err != nil {
				return err
			}
		}
		return nil
	}
	err := walkCSSBuildOut(bo)
	if err != nil {
		return err
	}

	err = r.instructionList.writeRemoveOtherCSSTags()
	if err != nil {
		return err
	}

	// main output
	err = r.visitFirst(state, bo, buildResults, bo.Out[0], []byte("0"))
	if err != nil {
		return err
	}

	// JS stuff last
	log.Printf("TODO: handle JS")

	err = r.instructionList.flush()
	if err != nil {
		return err
	}

	r.jsRenderState = state

	return nil

}

// EventWait blocks until an event has occurred which causes a re-render.
// It returns true if the render loop should continue or false if it should exit.
func (r *JSRenderer) EventWait() (ok bool) {

	// make sure the JS environment is still available, returning false otherwise
	if !js.Global().Truthy() {
		return false
	}

	// FIXME: this should probably have some sort of "debouncing" on it to handle the case of
	// several events in rapid succession causing multiple renders - maybe we read from eventWaitCH
	// continuously until it's empty, with a max of like 20ms pause between each or something, and then
	// only return after we don't see anything for that time frame.

	ok = <-r.eventWaitCh
	return

}

// var window js.Value

// func init() {
// 	window = js.Global().Get("window")
// 	if window.Truthy() {
// 		js.Global().Call("eval", jsHelperScript)
// 	}
// }

func (r *JSRenderer) visitFirst(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {

	log.Printf("TODO: We need to go through and optimize away unneeded calls to create elements, set attributes, set event handlers, etc. for cases where they are the same per hash")

	log.Printf("JSRenderer.visitFirst")

	if n.Type != ElementNode {
		return fmt.Errorf("root of component must be element")
	}

	err := r.instructionList.writeClearEl()
	if err != nil {
		return err
	}

	// first tag is html
	if strings.ToLower(n.Data) == "html" {

		// TODO: sync html tag attributes

		for nchild := n.FirstChild; nchild != nil; nchild = nchild.NextSibling {

			if strings.ToLower(nchild.Data) == "head" {

				// FIXME: positionID value?
				err := r.visitHead(state, bo, br, nchild, positionID)
				if err != nil {
					return err
				}

			} else if strings.ToLower(nchild.Data) == "body" {

				// FIXME: positionID value?
				err := r.visitBody(state, bo, br, nchild, positionID)
				if err != nil {
					return err
				}

			} else {
				return fmt.Errorf("unexpected tag inside html %q (VGNode=%#v)", nchild.Data, nchild)
			}

		}

		return nil
	}

	// else, first tag is anything else - try again as the element to be mounted
	return r.visitMount(state, bo, br, n, positionID)

}

func (r *JSRenderer) visitHead(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {
	log.Printf("TODO: visitHead")
	return nil
}

func (r *JSRenderer) visitBody(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {

	if !(n.FirstChild != nil && n.FirstChild.NextSibling == nil) {
		return fmt.Errorf("body tag must contain exactly one element child")
	}

	return r.visitMount(state, bo, br, n.FirstChild, positionID)
}

func (r *JSRenderer) visitMount(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {

	// log.Printf("visitMount got here")

	err := r.instructionList.writeSelectMountPoint(r.MountPointSelector, n.Data)
	if err != nil {
		return err
	}

	return r.visitSyncElementEtc(state, bo, br, n, positionID)

}

func (r *JSRenderer) visitSyncNode(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {

	log.Printf("visitSyncNode")

	var err error

	// check for Component, in which case we descend into it instead of processing like a regular node
	if n.Component != nil {
		compBuildOut := br.ResultFor(n.Component)
		if len(compBuildOut.Out) != 1 {
			return fmt.Errorf("component %#v expected exactly one Out element but got %d instead",
				n.Component, len(compBuildOut.Out))
		}
		return r.visitSyncNode(state, compBuildOut, br, compBuildOut.Out[0], positionID)
	}

	switch n.Type {
	case ElementNode:
		err = r.instructionList.writeSetElement(n.Data)
		if err != nil {
			return err
		}
	case TextNode:
		return r.instructionList.writeSetText(n.Data) // no children possible, just return
	case CommentNode:
		return r.instructionList.writeSetComment(n.Data) // no children possible, just return
	default:
		return fmt.Errorf("unknown node type %v", n.Type)
	}

	// only elements have attributes, child or events
	return r.visitSyncElementEtc(state, bo, br, n, positionID)

}

// visitSyncElementEtc syncs the rest of the stuff that only applies to elements
func (r *JSRenderer) visitSyncElementEtc(state *jsRenderState, bo *BuildOut, br *BuildResults, n *VGNode, positionID []byte) error {

	for _, a := range n.Attr {
		err := r.instructionList.writeSetAttrStr(a.Key, a.Val)
		if err != nil {
			return err
		}
	}

	err := r.instructionList.writeRemoveOtherAttrs()
	if err != nil {
		return err
	}

	// do any JS properties
	for _, p := range n.Prop {
		err := r.instructionList.writeSetProperty(p.Key, []byte(p.Val))
		if err != nil {
			return err
		}
	}

	if len(n.DOMEventHandlerSpecList) > 0 {

		// store in domHandlerMap
		state.domHandlerMap[string(positionID)] = n.DOMEventHandlerSpecList

		for _, hs := range n.DOMEventHandlerSpecList {
			err := r.instructionList.writeSetEventListener(positionID, hs.EventType, hs.Capture, hs.Passive)
			if err != nil {
				return err
			}
		}
	}
	// always write the remove for event listeners so any previous ones are taken away
	err = r.instructionList.writeRemoveOtherEventListeners(positionID)
	if err != nil {
		return err
	}

	if n.InnerHTML != nil {
		return r.instructionList.writeSetInnerHTML(*n.InnerHTML)
	}

	if n.FirstChild != nil {

		err = r.instructionList.writeMoveToFirstChild()
		if err != nil {
			return err
		}

		childIndex := 1
		for nchild := n.FirstChild; nchild != nil; nchild = nchild.NextSibling {

			childPositionID := append(positionID, []byte(fmt.Sprintf("_%d", childIndex))...)

			err = r.visitSyncNode(state, bo, br, nchild, childPositionID)
			if err != nil {
				return err
			}
			err = r.instructionList.writeMoveToNextSibling()
			if err != nil {
				return err
			}
			childIndex++
		}

		err = r.instructionList.writeMoveToParent()
		if err != nil {
			return err
		}
	}

	return nil
}

// // writeAllStaticAttrs is a helper to write all the static attrs from a VGNode
// func (r *JSRenderer) writeAllStaticAttrs(n *VGNode) error {
// 	for _, a := range n.Attr {
// 		err := r.instructionList.writeSetAttrStr(a.Key, a.Val)
// 		if err != nil {
// 			return err
// 		}
// 	}
// 	return nil
// }

func (r *JSRenderer) handleDOMEvent() {

	strlen := binary.BigEndian.Uint32(r.eventHandlerBuffer[:4])
	b := r.eventHandlerBuffer[4 : strlen+4]
	// log.Printf("handleDOMEvent JSON from event buffer: %q", b)

	// var ee eventEnv
	// rwmu            *sync.RWMutex
	// requestRenderCH chan bool

	var domEvent DOMEvent
	domEvent.eventEnv = r.eventEnv
	domEvent.window = r.window

	var eventDetail struct {
		PositionID string `json:"position_id"`
		EventType  string `json:"event_type"`
		Capture    bool   `json:"capture"`
		Passive    bool   `json:"passive"`

		// the event object data as extracted above
		EventSummary map[string]interface{} `json:"event_summary"`
	}

	err := json.Unmarshal(b, &eventDetail)
	if err != nil {
		panic(err)
	}
	domEvent.eventSummary = eventDetail.EventSummary

	// log.Printf("eventDetail: %#v", eventDetail)

	// acquire exclusive lock before we actually process event
	r.eventRWMU.Lock()
	defer r.eventRWMU.Unlock()

	// TODO: give this more thought - but for now we just do a non-blocking push to the
	// eventWaitCh, telling the render loop that a render is required, but if a bunch
	// of them stack up we don't wait
	defer func() {

		if panicr := recover(); panicr != nil {
			fmt.Println("handleRawDOMEvent caught panic", panicr)
			debug.PrintStack()

			// in error case send false to tell event loop to exit
			select {
			case r.eventWaitCh <- false:
			default:
			}
			return

		}

		// in normal case send true to the channel to tell the event loop it should render
		select {
		case r.eventWaitCh <- true:
		default:
		}
	}()

	handlers := r.jsRenderState.domHandlerMap[eventDetail.PositionID]
	var f func(*DOMEvent)
	for _, h := range handlers {
		if h.EventType == eventDetail.EventType && h.Capture == eventDetail.Capture {
			f = h.Func
			break
		}
	}

	// make sure we found something, panic if not
	if f == nil {
		panic(fmt.Errorf("Unable to find event handler for positionID=%q, eventType=%q, capture=%v",
			eventDetail.PositionID, eventDetail.EventType, eventDetail.Capture))
	}

	// invoke handler
	f(&domEvent)

}
