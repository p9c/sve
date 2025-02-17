
(function() {

	if (window.sveRender) { return; } // only once

    const opcodeEnd = 0         // no more instructions in this buffer
    // const opcodeClearRefmap = 1 // clear the reference map, all following instructions must not reference prior IDs
    const opcodeClearEl = 1 // clear the currently selected element
    // const opcodeSetHTMLRef = 2  // assign ref for html tag
    // const opcodeSetHeadRef = 3  // assign ref for head tag
    // const opcodeSetBodyRef = 4  // assign ref for body tag
    // const opcodeSelectRef = 5   // select element by ref
	const opcodeRemoveOtherAttrs = 5 // remove any elements for the current element that we didn't just set
    const opcodeSetAttrStr = 6  // assign attribute string to the current selected element
    const opcodeSelectMountPoint = 7 // selects the mount point element and pushes to the stack - the first time by selector but every subsequent time it will reuse the element from before (because the selector may not match after it's been synced over, it's id etc), also make sure it's of this element name and recreate if so
	// const opcodePicardFirstChildElement = 8  // ensure an element first child and push onto element stack
	// const opcodePicardFirstChildText    = 9  // ensure a text first child and push onto element stack
	// const opcodePicardFirstChildComment = 10 // ensure a comment first child and push onto element stack
	// const opcodeSelectParent                   = 11 // pop from the element stack
	// const opcodePicardFirstChild = 12  // ensure an element first child and push onto element stack

    const opcodeMoveToFirstChild     = 20 // move node selection to first child (doesn't have to exist)
	const opcodeSetElement           = 21 // assign current selected node as an element of the specified type
	// const opcodeSetElementAttr       = 22 // set attribute on current element
	const opcodeSetText              = 23 // assign current selected node as text with specified content
	const opcodeSetComment           = 24 // assign current selected node as comment with specified content
	const opcodeMoveToParent         = 25 // move node selection to parent
	const opcodeMoveToNextSibling    = 26 // move node selection to next sibling (doesn't have to exist)
	const opcodeRemoveOtherEventListeners  = 27 // remove all event listeners from currently selected element that were not just set
	const opcodeSetEventListener     = 28 // assign event listener to currently selected element
    const opcodeSetInnerHTML         = 29 // set the innerHTML for an element

    const opcodeSetCSSTag            = 30 // write a CSS (style or link) tag
	const opcodeRemoveOtherCSSTags   = 31 // remove any CSS tags that have not been written since the last call
	const opcodeSetJSTag             = 32 // write a JS (script) tag
    const opcodeRemoveOtherJSTags    = 33 // remove any JS tags that have not been written since the last call
    
    const opcodeSetProperty          = 35 // assign a JS property to the current element


    // Decoder provides our binary decoding.
    // Using a class because that's what all the cool JS kids are doing these days.
    class Decoder {

        constructor(dataView, offset) {
            this.dataView = dataView;
            this.offset = offset || 0;
            return this;
        }

        // readUint8 reads a single byte, 0-255
        readUint8() {
            var ret = this.dataView.getUint8(this.offset);
            this.offset++;
            return ret;
        }

        // readRefToString reads a 64-bit unsigned int ref but returns it as a hex string
        readRefToString() {
            // read in two 32-bit parts, BigInt is not yet well supported
            var ret = this.dataView.getUint32(this.offset).toString(16).padStart(8, "0") +
                this.dataView.getUint32(this.offset + 4).toString(16).padStart(8, "0");
            this.offset += 8;
            return ret;
        }

        // readString is 4 bytes length followed by utf chars
        readString() {
            var len = this.dataView.getUint32(this.offset);
            var ret = utf8decoder.decode(new DataView(this.dataView.buffer, this.dataView.byteOffset + this.offset + 4, len));
            this.offset += len + 4;
            return ret;
        }

    }

    let utf8decoder = new TextDecoder();

    window.sveGetActiveEvent = function() {
        let state = window.sveState || {}; window.sveState = state;
        return state.activeEvent;
    }
    window.sveGetActiveEventTarget = function() {
        let state = window.sveState || {}; window.sveState = state;
        return state.activeEvent && state.activeEvent.target;
    }
    window.sveGetActiveEventCurrentTarget = function() {
        let state = window.sveState || {}; window.sveState = state;
        return state.activeEvent && state.activeEvent.currentTarget;
    }
    window.sveActiveEventPreventDefault = function() {
        let state = window.sveState || {}; window.sveState = state;
        if (state.activeEvent && state.activeEvent.preventDefault) {
            state.activeEvent.preventDefault();
        }
    }
    window.sveActiveEventStopPropagation = function() {
        let state = window.sveState || {}; window.sveState = state;
        if (state.activeEvent && state.activeEvent.stopPropagation) {
            state.activeEvent.stopPropagation();
        }
    }

	// window.sveSetEventHandlerAndBuffer = function(eventHandlerFunc, eventBuffer) { 
	// 	let state = window.sveState || {};
    //     window.sveState = state;
    //     state.eventBuffer = eventBuffer;
    //     state.eventBufferView = new DataView(eventBuffer.buffer, eventBuffer.byteOffset, eventBuffer.byteLength);
    //     state.eventHandlerFunc = eventHandlerFunc;
    // }

    window.sveSetEventHandler = function(eventHandlerFunc) { 
		let state = window.sveState || {};
        window.sveState = state;
        state.eventHandlerFunc = eventHandlerFunc;
    }

    window.sveGetRenderArray = function() {
        if (!window.sveRenderArray) {
            window.sveRenderArray = new Uint8Array(16384);
        }
        return window.sveRenderArray;
    }

	window.sveRender = function() { 
        
        let buffer = window.sveRenderArray;
        if (!window.sveRenderArray) {
            throw "window.sveRenderArray is not set";
        }

        // NOTE: sveRender must not automatically reset anything between calls.
        // Since a series of instructions might get cut off due to buffer end, we
        // need to be able to just pick right up with the next call where we left off.
        // The caller decides when to reset things by sending the appropriate
        // instruction(s).

		let state = window.sveState || {};
		window.sveState = state;

		console.log("sveRender called");

        let textEncoder = new TextEncoder();

		let bufferView = new DataView(buffer.buffer, buffer.byteOffset, buffer.byteLength);

        var decoder = new Decoder(bufferView, 0);
        
        // state.refMap = state.refMap || {};
        // state.curRef = state.curRef || ""; // current reference number (as a hex string)
        // state.curRefEl = state.curRefEl || null; // current reference element
        // state.elStack = state.elStack || []; // stack of elements as we traverse the DOM tree

        // mount point element
        state.mountPointEl = state.mountPointEl || null; 

        // currently selected element
        state.el = state.el || null;

        // specifies a "next" move for the current element, if used it must be followed by
        // one of opcodeSetElement, opcodeSetText, opcodeSetComment, which will create/replace/use existing
        // the element and put it in "el".  The point is this allow us to select nodes that may
        // not exist yet, knowing that the next call will specify what that node is.  It's more complex here
        // but makes it easier to generate instructions while walking a DOM tree.
        // Value is one of "first_child", "next_sibling"
        // (Parents always exist and so doesn't use this mechanism.)
        state.nextElMove = state.nextElMove || null;

        // keeps track of attributes that are being set on the current element, so we can remove any extras
        state.elAttrNames = state.elAttrNames || {};

        // map of positionID -> array of listener spec and handler function, for all elements
        state.eventHandlerMap = state.eventHandlerMap || {};
    
        // keeps track of event listeners that are being set on the current element, so we can remvoe any extras
        state.elEventKeys = state.elEventKeys || {};

        instructionLoop: while (true) {

            let opcode = decoder.readUint8();
            
            try {

                console.log("processing opcode", opcode);
                // console.log("test_span_id: ", document.querySelector("#test_span_id"));

                switch (opcode) {

                    case opcodeEnd: {
                        break instructionLoop;
                    }
        
                    case opcodeClearEl: {
                        state.el = null;
                        state.nextElMove = null;
                        break;
                    }

                    case opcodeSetProperty: {
                        let el = state.el;
                        if (!el) {
                            return "opcodeSetProperty: no current reference";
                        }
                        let propName = decoder.readString();
                        let propValueJSON = decoder.readString();
                        el[propName] = JSON.parse(propValueJSON);
                        break;
                    }                    
            
                    case opcodeSetAttrStr: {
                        let el = state.el;
                        if (!el) {
                            return "opcodeSetAttrStr: no current reference";
                        }
                        let attrName = decoder.readString();
                        let attrValue = decoder.readString();
                        el.setAttribute(attrName, attrValue);
                        state.elAttrNames[attrName] = true;
                        // console.log("setting attr", attrName, attrValue, el)
                        break;
                    }

                    case opcodeSelectMountPoint: {
                        
                        state.elAttrNames = {}; // reset attribute list
                        state.elEventKeys = {};

                        // select mount point using selector or if it was done earlier re-use the one from before
                        let selector = decoder.readString();
                        let nodeName = decoder.readString();
                        // console.log("GOT HERE selector,nodeName = ", selector, nodeName);
                        // console.log("state.mountPointEl", state.mountPointEl);
                        if (state.mountPointEl) {
                            console.log("opcodeSelectMountPoint: state.mountPointEl already exists, using it", state.mountPointEl, "parent is", state.mountPointEl.parentNode);
                            state.el = state.mountPointEl;
                            // state.elStack.push(state.mountPointEl);
                        } else {
                            console.log("opcodeSelectMountPoint: state.mountPointEl does not exist, using selector to find it", selector);
                            let el = document.querySelector(selector);
                            if (!el) {
                                throw "mount point selector not found: " + selector;
                            }
                            state.mountPointEl = el;
                            // state.elStack.push(el);
                            state.el = el;
                        }

                        let el = state.el;

                        // make sure it's the right element name and replace if not
                        if (el.nodeName.toUpperCase() != nodeName.toUpperCase()) {

                            let newEl = document.createElement(nodeName);
                            el.parentNode.replaceChild(newEl, el);

                            state.mountPointEl = newEl;
                            el = newEl;

                        }

                        state.el = el;

                        state.nextElMove = null;

                        break;
                    }

                    // remove any elements for the current element that we didn't just set
                    case opcodeRemoveOtherAttrs: {

                        if (!state.el) {
                            throw "no element selected";
                        }

                        if (state.nextElMove) {
                            throw "cannot call opcodeRemoveOtherAttrs when nextElMove is set";
                        }

                        // build a list of attribute names to remove
                        let rmAttrNames = [];
                        for (let i = 0; i < state.el.attributes.length; i++) {
                            if (!state.elAttrNames[state.el.attributes[i].name]) {
                                rmAttrNames.push(state.el.attributes[i].name);
                            }
                        }

                        // remove them
                        for (let i = 0; i < rmAttrNames.length; i++) {
                            state.el.attributes.removeNamedItem(rmAttrNames[i]);
                        }

                        break;
                    }

                    // move node selection to parent
                    case opcodeMoveToParent: {

                        // if first_child is next move then we just unset this
                        if (state.nextElMove == "first_child") {
                            state.nextElMove = null;
                        } else {
                            // otherwise we actually move and also reset nextElMove
                            state.el = state.el.parentNode;
                            state.nextElMove = null;
                        }

                        break;
                    }

                    // move node selection to first child (doesn't have to exist)
                    case opcodeMoveToFirstChild: {

                        // if a next move already set, then we need to execute it before we can do this
                        if (state.nextElMove) {
                            if (state.nextElMove == "first_child") {
                                state.el = state.el.firstChild;
                                if (!state.el) { throw "unable to find state.el.firstChild"; }
                            } else if (state.nextElMove == "next_sibling") {
                                state.el = state.el.nextSibling;
                                if (!state.el) { throw "unable to find state.el.nextSibling"; }
                            }
                            state.nextElMove = null;
                        }

                        if (!state.el) { throw "must have current selection to use opcodeMoveToFirstChild"; }
                        state.nextElMove = "first_child";

                        break;
                    }
                    
                    // move node selection to next sibling (doesn't have to exist)
                    case opcodeMoveToNextSibling: {

                        // if a next move already set, then we need to execute it before we can do this
                        if (state.nextElMove) {
                            if (state.nextElMove == "first_child") {
                                state.el = state.el.firstChild;
                                if (!state.el) { throw "unable to find state.el.firstChild"; }
                            } else if (state.nextElMove == "next_sibling") {
                                state.el = state.el.nextSibling;
                                if (!state.el) { throw "unable to find state.el.nextSibling"; }
                            }
                            state.nextElMove = null;
                        }

                        if (!state.el) { throw "must have current selection to use opcodeMoveToNextSibling"; }
                        state.nextElMove = "next_sibling";

                        break;
                    }
                    
                    // assign current selected node as an element of the specified type
                    case opcodeSetElement: {
                        
                        let nodeName = decoder.readString();

                        this.console.log("opcodeSetElement for ",
                            "nodeName=", nodeName, 
                            ", state.el=", state.el, 
                            ", state.nextElMove=", state.nextElMove);

                        state.elAttrNames = {};
                        state.elEventKeys = {};

                        // handle nextElMove cases

                        if (state.nextElMove == "first_child") {
                            state.nextElMove = null;
                            let newEl = state.el.firstChild;
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                newEl = document.createElement(nodeName);
                                state.el.appendChild(newEl);
                                state.el = newEl;
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove == "next_sibling") {
                            state.nextElMove = null;
                            let newEl = state.el.nextSibling;
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                newEl = document.createElement(nodeName);
                                // console.log("HERE1", state.el);
                                // state.el.insertAdjacentElement(newEl, 'afterend');
                                state.el.parentNode.appendChild(newEl);
                                state.el = newEl;
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove) {
                            throw "bad state.nextElMove value: " + state.nextElMove;
                        }

                        // if we get here we need to verify that state.el is in fact an element of the right type
                        // and replace if not

                        if (state.el.nodeType != 1 || state.el.nodeName.toUpperCase() != nodeName.toUpperCase()) {

                            let newEl = document.createElement(nodeName);
                            // throw "stopping here";
                            state.el.parentNode.replaceChild(newEl, state.el);
                            state.el = newEl;

                        }

                        break;
                    }

                    // assign current selected node as text with specified content
                    case opcodeSetText: {

                        let content = decoder.readString();

                        // console.log("in opcodeSetText 1");

                        // handle nextElMove cases

                        if (state.nextElMove == "first_child") {
                            state.nextElMove = null;
                            let newEl = state.el.firstChild;
                            // console.log("in opcodeSetText 2");
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                let newEl = document.createTextNode(content);
                                state.el.appendChild(newEl);
                                state.el = newEl;
                                // console.log("in opcodeSetText 3");
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove == "next_sibling") {
                            state.nextElMove = null;
                            let newEl = state.el.nextSibling;
                            // console.log("in opcodeSetText 4");
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                let newEl = document.createTextNode(content);
                                // state.el.insertAdjacentElement(newEl, 'afterend');
                                state.el.parentNode.appendChild(newEl);
                                state.el = newEl;
                                // console.log("in opcodeSetText 5");
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove) {
                            throw "bad state.nextElMove value: " + state.nextElMove;
                        }

                        // if we get here we need to verify that state.el is in fact a node of the right type
                        // and with right content and replace if not
                        // console.log("in opcodeSetText 6");

                        if (state.el.nodeType != 3) {

                            let newEl = document.createTextNode(content);
                            state.el.parentNode.replaceChild(newEl, state.el);
                            state.el = newEl;
                            // console.log("in opcodeSetText 7");

                        } else {
                            // console.log("in opcodeSetText 8");
                            state.el.textContent = content;
                        }
                        // console.log("in opcodeSetText 9");

                        break;
                    }

                    // assign current selected node as comment with specified content
                    case opcodeSetComment: {
                        
                        let content = decoder.readString();

                        // handle nextElMove cases

                        if (state.nextElMove == "first_child") {
                            state.nextElMove = null;
                            let newEl = state.el.firstChild;
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                let newEl = document.createComment(content);
                                state.el.appendChild(newEl);
                                state.el = newEl;
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove == "next_sibling") {
                            state.nextElMove = null;
                            let newEl = state.el.nextSibling;
                            if (newEl) { 
                                state.el = newEl; 
                                // fall through to verify state.el is correct below
                            } else {
                                let newEl = document.createComment(content);
                                // state.el.insertAdjacentElement(newEl, 'afterend');
                                state.el.parentNode.appendChild(newEl);
                                state.el = newEl;
                                break; // we're done here, since we just created the right element
                            }
                        } else if (state.nextElMove) {
                            throw "bad state.nextElMove value: " + state.nextElMove;
                        }

                        // if we get here we need to verify that state.el is in fact a node of the right type
                        // and with right content and replace if not

                        if (state.el.nodeType != 8) {

                            let newEl = document.createComment(content);
                            state.el.parentNode.replaceChild(newEl, state.el);
                            state.el = newEl;

                        } else {
                            state.el.textContent = content;
                        }

                        break;
                    }

                    case opcodeSetInnerHTML: {

                        let html = decoder.readString();

                        if (!state.el) { throw "opcodeSetInnerHTML must have currently selected element"; }
                        if (state.nextElMove) { throw "opcodeSetInnerHTML nextElMove must not be set"; }
                        if (state.el.nodeType != 1) { throw "opcodeSetInnerHTML currently selected element expected nodeType 1 but has: " + state.el.nodeType; }

                        state.el.innerHTML = html;

                        break;
                    }

                    // remove all event listeners from currently selected element that were not just set
                    case opcodeRemoveOtherEventListeners: {
                        this.console.log("opcodeRemoveOtherEventListeners");

                        let positionID = decoder.readString();

                        // look at all registered events for this positionID
                        let emap = state.eventHandlerMap[positionID] || {};
                        // for any that we didn't just set, remove them
                        let toBeRemoved = [];
                        for (let k in emap) {
                            if (!state.elEventKeys[k]) {
                                toBeRemoved.push(k);
                            }
                        }

                        // for each one that was missing, we remove from emap and call removeEventListener
                        for (let i = 0; i < toBeRemoved.length; i++) {
                            let f = emap[k];
                            let k = toBeRemoved[i];
                            let kparts = k.split("|");
                            state.el.removeEventListener(kparts[0], f, {capture:!!kparts[1], passive:!!kparts[2]});
                            delete emap[k];
                        }

                        // if emap is empty now, remove the entry from eventHandlerMap altogether
                        if (Object.keys(emap).length == 0) {
                            delete state.eventHandlerMap[positionID];
                        } else {
                            state.eventHandlerMap[positionID] = emap;
                        }

                        break;
                    }
                
                    // assign event listener to currently selected element
                    case opcodeSetEventListener: {
                        let positionID = decoder.readString();
                        let eventType = decoder.readString();
                        let capture = decoder.readUint8();
                        let passive = decoder.readUint8();

                        if (!state.el) {
                            throw "must have state.el set in order to call opcodeSetEventListener";
                        }

                        var eventKey = eventType + "|" + (capture?"1":"0") + "|" + (passive?"1":"0");
                        state.elEventKeys[eventKey] = true;

                        // map of positionID -> map of listener spec and handler function, for all elements
                        //state.eventHandlerMap
                        let emap = state.eventHandlerMap[positionID] || {};

                        // register function if not done already
                        let f = emap[eventKey];
                        if (!f) {
                            f = function(event) {

                                // set the active event, so the Go code and call back in and examine it if needed
                                state.activeEvent = event; 

                                let eventObj = {};
                                // console.log(event);
                                for (let i in event) {
                                    let itype = typeof(event[i]);
                                    // copy primitive values directly
                                    if ((itype == "boolean" || itype == "number" || itype == "string") && true/*event.hasOwnProperty(i)*/) {
                                        eventObj[i] = event[i];
                                    }
                                }

                                // also do the same for anything in "target"
                                if (event.target) {
                                    eventObj.target = {};
                                    let et = event.target;
                                    for (let i in et) {
                                        let itype = typeof(et[i]);
                                        if ((itype == "boolean" || itype == "number" || itype == "string") && true/*et.hasOwnProperty(i)*/) {
                                            eventObj.target[i] = et[i];
                                        }
                                    }
                                }
                                
                                // console.log(eventObj);
                                // console.log(JSON.stringify(eventObj));

                                let fullJSON = JSON.stringify({
                                    
                                    // include properties from event registration
                                    position_id: positionID,
                                    event_type: eventType,
                                    capture: !!capture,
                                    passive: !!passive,

                                    // the event object data as extracted above
                                    event_summary: eventObj,

                                });

                                // console.log(state.eventBuffer);

                                // make sure eventBuffer and eventBufferView are setup
                                let eventBuffer = state.eventBuffer;
                                if (!eventBuffer) {
                                    // FIXME: not yet sure how to handle different lengths here,
                                    // but for now this needs to be at least one byte shorter 
                                    // than Go's buffer
                                    eventBuffer = new Uint8Array(16383);
                                    state.eventBuffer = eventBuffer;
                                    state.eventBufferView = new DataView(eventBuffer.buffer, eventBuffer.byteOffset, eventBuffer.byteLength);
                                }

                                // write JSON to state.eventBuffer with uint32 length prefix
                                
                                let encodeResultBuffer = textEncoder.encode(fullJSON);
                                //console.log("encodeResult", encodeResult);
                                state.eventBuffer.set(encodeResultBuffer, 4); // copy encoded string to event buffer
                                // now write length using DataView as uint32
                                state.eventBufferView.setUint32(0, encodeResultBuffer.byteLength - encodeResultBuffer.byteOffset);

                                // let result = textEncoder.encodeInto(fullJSON, state.eventBuffer);
                                // let eventBufferDataView = new DataView(state.eventBuffer.buffer, state.eventBuffer.byteOffset, state.eventBuffer.byteLength);
                                // eventBufferDataView.setUint8(result.written, 0);

                                // write length after, since only now do we know the final length
                                // state.eventBufferView.setUint32(0, result.written);

                                // serialize event into the event buffer, somehow,
                                // and keep track of the target element, also consider grabbing
                                // the value or relevant properties as appropriate for form things
                                
                                state.eventHandlerFunc.call(null, eventBuffer); // call with null this avoid unnecessary js.Value reference

                                // unset the active event
                                state.activeEvent = null;
                            };    
                            emap[eventKey] = f;

                            // this.console.log("addEventListener", eventType);
                            state.el.addEventListener(eventType, f, {capture:capture, passive:passive});
                        }

                        state.eventHandlerMap[positionID] = emap;

                        this.console.log("opcodeSetEventListener", positionID, eventType, capture, passive);
                        break;
                    }

                    case opcodeSetCSSTag: {

                        let elementName = decoder.readString();
                        let textContent = decoder.readString();
                        let attrPairsLen = decoder.readUint8();
                        if (attrPairsLen % 2 != 0) {
                            throw "attrPairsLen is odd number: " + attrPairsLen;
                        }
                        // loop over one key/value pair at a time and put them in a map
                        var attrMap = {};
                        for (let i = 0; i < attrPairsLen; i += 2) {
                            let key = decoder.readString();
                            let val = decoder.readString();
                            attrMap[key] = val;
                        }

                        this.console.log("got opcodeSetCSSTag: elementName=", elementName, "textContent=", textContent, "attrMap=", attrMap)
                        
                        state.elCSSTagsSet = state.elCSSTagsSet || []; // ensure state.elCSSTagsSet is set to empty array if not already set

                        // let elementNameUC = elementName.toUpperCase();
                        let thisTagKey = textContent;
                        if (elementName == "link") {
                            thisTagKey = attrMap["href"];
                        }

                        if (thisTagKey == "") { // nothing to do in this case
                            this.console.log("element", elementName, "ignored due to empty key");
                            break;
                        }

                        // TODO: 
                        // * find all tags that have the same element type (link or style)
                        // * for each one for style use textContent as key, for link use url
                        // * see if matching tag already exists
                        // * if it has sveCreated==true on it, then add to map of css tags set, else ignore
                        // * if no matching tag then create and set sveCreated=true, add to map of css tags set

                        let foundTag = null;
                        this.document.querySelectorAll(elementName).forEach(cssEl => {
                            let cssElKey;
                            if (elementName == "style") {
                                cssElKey = cssEl.textContent;
                            } else /* elementName == "link" */ {
                                cssElKey = cssEl.href;
                            }
                            
                            if (thisTagKey == cssElKey) { // textContent or href as appropriate is used to determine "sameness"
                                foundTag = cssEl;
                            }
                        });

                        // could not find it, create
                        if (!foundTag) {
                            let cTag = this.document.createElement(elementName);
                            for (let k in attrMap) {
                                cTag.setAttribute(k, attrMap[k]);
                            }
                            cTag.sveCreated = true; // so we know that we created this, as opposed to it already having been on the page
                            this.console.log("GOT TEXTCONTENT: ", textContent);
                            if (textContent) {
                                cTag.appendChild(document.createTextNode(textContent)) // set textContent if provided
                                // cTag.innerText = textContent; // set textContent if provided
                            }
                            this.document.head.appendChild(cTag); // add to end of head
                            this.console.log("CREATED ctag: ", cTag);
                            state.elCSSTagsSet.push(cTag); // add to elCSSTagsSet for use in opcodeRemoveOtherCSSTags
                        } else {
                            // if we did find it, we need to push to state.elCSSTagsSet to tell opcodeRemoveOtherCSSTags not to remove it
                            state.elCSSTagsSet.push(foundTag);
                        }

                        break;
                    }
                    case opcodeRemoveOtherCSSTags: {

                        this.console.log("got opcodeRemoveOtherCSSTags");

                        // any link or style tag in doc that has sveCreated==true and is not in css tags set map gets removed

                        state.elCSSTagsSet = state.elCSSTagsSet || [];

                        this.document.querySelectorAll('style,link').forEach(cssEl => {

                            // ignore any not created by sve
                            if (!cssEl.sveCreated) { return; }

                            // ignore if in elCSSTagsSet
                            if (state.elCSSTagsSet.findIndex(el => el==cssEl) >= 0) { return; }

                            // if we got here, we remove the tag
                            cssEl.parentNode.removeChild(cssEl);
                        });

                        state.elCSSTagsSet = null; // clear this out so it gets reinitialized the next time opcodeSetCSSTag or this opcode is used

                        break;
                    }

                    default: {
                        console.error("found invalid opcode", opcode);
                        return;
                    }
                }

            } catch (e) {
                this.console.log("Error during instruction loop. Data opcode=", opcode, 
                    ", state.el=", state.el, 
                    ", state.nextElMove=", state.nextElMove, 
                    ", with error: ", e)
                throw e;
            }


		}

	}

})()
