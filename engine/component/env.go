package component

// // Env specifies the common methods for environment implementations.
// // See JSEnv and StaticHtmlEnv for implementations.
// type Env interface {
// 	RegisterComponentType(tagName string, ct ComponentType)
// 	Render() error
// }

// func NewBuildEnv(root component.Builder) (*BuildEnv, error) {

func NewBuildEnv() (*BuildEnv, error) {
	return &BuildEnv{}, nil
}

// BuildEnv is the environment used when building virtual DOM.
type BuildEnv struct {
	// components in cache pool from prior build
	compCache map[CompKey]Builder

	// components used so far in this build
	compUsed map[CompKey]Builder

	// cache of build output by component from prior build pass
	buildCache map[interface{}]*BuildOut

	// new build output from this build pass (becomes buildCache next build pass)
	buildResults map[interface{}]*BuildOut

	// nodePositionHashMap map[*VGNode]uint64

	// root component.Builder // FIXME: does this even belong here?  BuildEnv keeps track of components created but why does it need a reference to the root component?

}

// BuildResults contains the component.BuildOut values for full tree of components built.
type BuildResults struct {
	Out    *BuildOut
	AllOut map[interface{}]*BuildOut
}

// ResultFor is alias for indexing into AllOut.
func (r *BuildResults) ResultFor(component interface{}) *BuildOut {
	return r.AllOut[component]
}

// RunBuild performs a bulid on a component, managing the lifecycles of nested components and related concerned.
// In the map that is output, m[builder] will give the component.BuildOut for the component in question.  Child components
// can likewise be indexed using the component (which should be a struct pointer) as the key.
// Callers should not modify the return value as it is reused by subsequent calls.
func (e *BuildEnv) RunBuild(builder Builder) *BuildResults {

	if e.compCache == nil {
		e.compCache = make(map[CompKey]Builder)
	}
	if e.compUsed == nil {
		e.compUsed = make(map[CompKey]Builder)
	}

	// clear old prior build pass's cache
	for k := range e.compCache {
		delete(e.compCache, k)
	}

	// swap cache and used, so the prior used is the new cache
	e.compCache, e.compUsed = e.compUsed, e.compCache

	if e.buildCache == nil {
		e.buildCache = make(map[interface{}]*BuildOut)
	}
	if e.buildResults == nil {
		e.buildResults = make(map[interface{}]*BuildOut)
	}

	// clear old prior build pass's cache
	for k := range e.buildCache {
		delete(e.buildCache, k)
	}

	// swap cache and results, so the prior results is the new cache
	e.buildCache, e.buildResults = e.buildResults, e.buildCache

	// recursively build everything
	e.buildOne(builder)

	return &BuildResults{AllOut: e.buildResults, Out: e.buildResults[builder]}
}

func (e *BuildEnv) buildOne(thisb Builder) {

	beforeBuilder, ok := thisb.(BeforeBuilder)
	if ok {
		beforeBuilder.BeforeBuild()
	}

	var buildIn BuildIn
	buildIn.BuildEnv = e

	buildOut := thisb.Build(&buildIn)

	// store in buildResults
	e.buildResults[thisb] = buildOut

	for _, c := range buildOut.Components {
		e.buildOne(c)
	}
}

// CachedComponent will return the component that corresponds to a given comp.CompKey.
// The comp.CompKey must contain a unique ID for the instance in question, and an optional
// IterKey if applicable in the caller.
// A nil value will be returned if nothing is found.  During a single build pass
// only one component will be returned for a specified key (it is removed from the pool),
// in order to protect against
// broken callers that accidentally forget to set IterKey properly and ask for the same
// component over and over, in whiich case the first call will return a value and
// subsequent calls will return nil.
func (e *BuildEnv) CachedComponent(compKey CompKey) Builder {
	ret, ok := e.compCache[compKey]
	if ok {
		delete(e.compCache, compKey)
		return ret
	}
	return nil
}

// UseComponent indicates the component which was actually used for a specified comp.CompKey
// during this build pass and stores it for later use.  In the next build pass, components
// which have be provided UseComponent() will be available via CachedComponent().
func (e *BuildEnv) UseComponent(compKey CompKey, component Builder) {
	delete(e.compCache, compKey)    // make sure it's not in the cache
	e.compUsed[compKey] = component // make sure it is in the used
}

// FIXME: IMPORTANT: If we can separate the hash computation from the equal comparision, then we can use
// the hash do map lookups but then have a stable equal comparision, this way components will never
// be incorrectly reused, but still get virtually all of the benefits of using the hash approach for
// rapid comparision (i.e. "is this probably the same"/"find me one that is probably the same" is fast
// to answer).

// NOTE: seems like we have two very distinct types of component comparisions:
// 1. Should we re-use this instance?  (Basically, is the input the same - should ignore things like computed properties and other internal state)
//    ^ This seems like a "shallow" comparision - pointer struct fields should be compared on the basis of do they point to the same thing.
// 2. Is this component changed since last render?  (This should examine whatever it needs to in order to determine if a re-render is needed)
//    ^ This seems like a "deep" comparision against a last known rendered state - you don't care about what the pointers are, you
//      follow it until you get a value, and you check if it's "changed".

// NOTE: This whole thing seems to be a question of optimization. We could just create
// a new component for each pass, but we want to reuse, so it's worth thinking the entire thought through,
// and ask what happens if we optmize each step.

//----

/*
	Points to optimize

	- Don't recreate components that have the same input, reuse them (actually, why?? - because if they
	  compute internal state we sholud preserve that where possible). If we don't do this properly, then the
	  other two optimizations likely won't work either. (THIS IS BASICALLY THE "SHALLOW COMPARE" APPAROACH - BOTH FOR HASHING
	  AND EQUAL COMPARISION - COMPARE THE POINTERS NOT FOLLOWING THEM ETC)

	- Don't re-create VGNode tree for component if output will be the same (algo for how to determine this tbd)
	  - Breaks into "our VGNode stuff is the same" and "ours plus children is the same".

	- Don't re-sync VGNodes to render pipeline if they are the same.
	  - two cases here: 1. Same exact DOM for a component returned , 2. newly generated the same DOM
*/

// NOTE: Should we be using a pool for VGNode and VGAttribute allocation?  We are going to be creating and
// destroying a whole lot of these. MAYBE, BUT BENCHMARK SHOWS ONLY ABOUT 15% IMPROVEMENT USING THE POOL, MIGHT
// BE DIFFERENT IN REAL LIFE BUT PROBABLY NOT WORTH DOING RIGHT OUT THE GATE.

/*

	Basic sequence:

	- Build is called on root component
	- Component checks self to see if DOM output will be same as last time and if we have cached component.BuildOut, return it if so.
	- No component.BuildOut cached, run through rest of Build.
	- For each component encountered, give BuildEnv the populated struct and ask it for the instance to use
	  (it will pull from cache or use the object it was sent).
	- Component is stored on VGNode.Component field.  component.BuildOut also should keep a slice of these for quick traversal.
	- component.BuildOut is returned from root component's Build.
	- The list of components in the component.BuildOut is traversed, Build called for each one,
	  and the result set on VGNode.ComponentOut.
	- This causes the above cycle to run again for each of these child components.  Runs until no more are left.
	- FIXME: need to see how we combine the CSS and JS and make this accessible to the renderer (although maybe
	  the renderer can follow the component trail in component.BuildOut, or something)

	- At this point we have a component.BuildOut with a tree of VGNodes, and each one either has content itself or
	  has another component.BuildOut in the VGNode.ComponentOut field.  Between the two caching mechanisms (component
	  checking itself to see if same output, and each component creation checked with BuildEnv for re-use),
	  the cached case for traversing even a large case should be fast.

	- During render: The component.BuildOut pointer (or maybe its Out field) is used as a cache key - same component.BuildOut ptr, we assume same
	  VGNodes, and renderer can safely skip to each child component and continue from there.
	- For each VGNode, we call String() and have a map of the prior output for this position, if it's the same,
	  we can skip all the sync stuff and just move to the next.  String() needs to be very carefully implemented
	  so it can be used for equality tests like this safely.  The idea is that if we get a different VGNode
	  but with the exact same content, we avoid the extra render instructions.

	------------------
	TODO: We need to verify that component events and slots as planned
	https://github.com/p9c/sve/wiki/Component-Related-Features-Design
	still work with this idea above.  I THINK WE CAN JUST ASSIGN THE
	SLOT AND EVENT CALLBACKS EACH TIME, THAT SHOULD WORK JUST FINE, WE
	DON'T NEED TO COMPARE AND KEEP THE OLD SLOT FUNCS ETC, JUST OVERWRITE.
*/

/*
MORE NOTES:

On 9/6/19 6:23 PM, Brad Peabody wrote:
> each unique position where a component is used could get a unique ID - generated, maybe with type name, doesn't matter really,
  but then for cases where there is no loop it's just a straight up lookup; in loop cases it's that ID plus a key of some sort
  (maybe vg-key specifies, with default of index number). could be a struct that has this ID string and key value and that's used
  to cache which component was used for this last render cycle.
>
> interesting - then if we know which exact component was in this slot last time, we can just re-assign all of the fields each pass -
  if they are the same, fine, if not, fine, either way we just assign the fields and tell the component to Build, etc.

keys can be uint64: uint32 unix timestamp (goes up to 2106-02-07 06:28:15) plus 32 bits of crytographically random data -
really should be random enough for all practical purposes (NOW IMPLEMENTED AS comp.CompKey)

*/

/*

STRUCT TAGS:

type Widget struct {

	// component param
	Size int `sve:"cparam"`
	FirstName *string `sve:"cparam"`

	// computed property, used for display, but entirely dependent upon Size
	DisplaySize string
}

*/

/*

DIRTY CHECKING:

Basic idea:

type DirtyChecker interface{
	DirtyCheck(oldData []byte) (isDirty bool, newData []byte)
	// or maybe just interface{}
	DirtyCheck(oldData interface{}) (isDirty bool, newData interface{})
}

// "mod" is good!  doesn't sound weird, "modify" is pretty clearly on point, and "mod" is short.

type ModChecker interface{
	ModCheck(oldData interface{}) (isDirty bool, newData interface{})
}

type SomeComponent struct {
	FirstName string `sve:"modcheck"`

	FirstNameFormatted string // computed field, not "modcheck"'ed
}

*/

// func (e *BuildEnv) Component(vgparent *VGNode, comp component.Builder) component.Builder {

// 	return comp
// }

// // BuildRoot creates a BuildIn struct and calls Build on the root component (component.Builder), returning it's output.
// func (e *BuildEnv) BuildRoot() (*component.BuildOut, error) {

// 	var buildIn BuildIn
// 	buildIn.BuildEnv = e

// 	// TODO: SlotMap?

// 	return e.root.Build(&buildIn)
// }

// func (e *BuildEnv) ComponentFor(n *VGNode) (component.Builder, error) {
// 	panic(fmt.Errorf("not yet implemented"))
// }

// func (e *BuildEnv) SetComponentFor(n *VGNode, c component.Builder) error {
// 	panic(fmt.Errorf("not yet implemented"))
// }
