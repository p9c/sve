# Vugu

<!-- [![Travis CI](https://travis-ci.org/p9c/sve.svg?branch=master)](https://travis-ci.org/p9c/sve) -->
[![Go Report Card](https://goreportcard.com/badge/github.com/p9c/sve)](https://goreportcard.com/report/github.com/p9c/sve)
[![GoDoc](https://godoc.org/github.com/p9c/sve?status.svg)](https://godoc.org/github.com/p9c/sve)
[![stability-experimental](https://img.shields.io/badge/stability-experimental-orange.svg)](https://github.com/emersion/stability-badges#experimental)

Vugu is an experimental library for web UIs written in Go and targeting webassembly.  Guide and docs at https://www.engine.org.
Godoc at https://godoc.org/github.com/p9c/sve.

If you've ever wanted to write a UI not in JS but pure Go... and run it in your browser, right now... That (experimental;) future is here!

Introducing Vugu (pronounced /ˈvuː.ɡuː/), a VueJS-inspired library in Go targeting wasm.

No node. No JS. No npm. No node_modules folder competing with your music library for disk space.

## Updates ♨

* 2019-11-10 Support for tinygo is in-progress on the tinygo branch.  No known blocking issues as yet, some minor refactor required but looks promising.
* 2019-09-29 Router is work-in-progress.  Will use radix tree to efficiently combine common prefixes.  Struct tags will usable to two-way-bind path and query params, or it can be done manually.  Some similarities to Angular and Vue routers but will be less declarative and more functional (instead of a big tree of objects with various config, you write path handler functions to set whatever properties need to be set, establish binding, etc).  Plan is to get the bulk of this coded by next week.
* 2019-09-22 Static HTML renderer (re)implemented. EventEnv bug fix and added it to to JS renderer to allow background requests at startup.  Some initial work on a router: https://github.com/sve/vgrouter
* 2019-09-15 Refactor changes merged into master. Includes: updated sample code, component resolution at code-generation time, type-safe component params, optional component param map, BeforeBuild lifecycle callback, modification tracking system, JS property assignment syntax, "full HTML" support, improved DOM event handling, Go 1.13 support, import deduplication, and a brand new rendering pipeline!  Initial documentation at https://github.com/p9c/sve/wiki/Refactor-Notes---Sep-2019
* 2019-09-08 Implemented ModTracker to keep track of changes to components and their data (this is also the beginning of Vuex-like functionality but without wrappers or events). Worked out the lifecycle of components in much more detail and work in progress on nested components implementation (component-refactor branch currently broken, but finally the core nested component functionality is going in - hopefully will finish next week).
* 2019-09-07 Updated everything for Go 1.13, including both master and component-refactor branches, Vugu's js wrapper package, site documentation.
* 2019-09-01 On component-refactor branch: Form element values and other related data now available on DOMEvent, `.prop=` syntax implemented, various cleanup, imports are deduplicated automatically now, started on nested component implementation and all of that craziness.
* 2019-08-25 CSS now supported on component-refactor branch, including in full-HTML mode, working sample that pulls in Bootstrap CSS.  Vugu's [js wrapper package](https://godoc.org/github.com/p9c/sve/pkg/js) copied to master and made available.
* 2019-08-18 Full HTML (root component can start with `<html>` tag) now supported on component-refactor branch, updated CSS and JS support figured out and implementation in-progress
* 2019-08-12 Refactored DOM event listener code in-progress, event registration/deregistration works(-ish), filling out the remaining functionality to provide event summary, calls like preventDefault(), etc.
* 2019-08-04 Some basic stuff in there on the DOM syncing rewrite and the new instruction workflow from VGNode -> binary encoded to raw bytes in Go -> read with DataView in JS -> DOM tree manipulation.  With the pattern in place the rest should get easier.
* 2019-07-28 Making some hard choices on how to do DOM syncing in a performant and reliable way.  https://github.com/p9c/sve/wiki/DOM-Syncing-Instructions
* 2019-07-20 Some design info on how "data binding" (hashing actually) will work in Vugu: https://github.com/p9c/sve/wiki/Data-Hashing-vs-Binding
* 2019-07-16 Vugu has a logo! https://www.instagram.com/p/Bz3zmtYAYcM/  Good things are in the works, the plan is to get a bunch of much-awaited updates pushed to master before the end of the month.
* 2019-05-19 Refactor still in progress - this is the cleaned-up architecture concept: https://github.com/p9c/sve/wiki/Architecture-Overview
* 2019-04-07 The Vugu Playground is up at: https://play.engine.org/
* 2019-04-05 Thanks to @erinpentecost, **svefmt is now available** and provides gofmt-like functionality on your .sve files. ("go get github.com/p9c/sve/cmd/svefmt && go install github.com/p9c/sve/cmd/svefmt")
* 2019-04-05 The component playground should be available soon; followed by some internal work to properly handle nested components in a type-safe way; then probably a router...

<img src="https://cdnjs.cloudflare.com/ajax/libs/ionicons/4.5.6/collection/build/ionicons/svg/logo-slack.svg" width="17" height="17"> Join the conversation: [Gophers on Slack](https://invite.slack.golangbridge.org/), channel #sve

## Highlights

* Runs in-browser using WebAssembly
* Single-file components
* Vue-like markup syntax
* Write idiomatic Go code
* Rapid prototyping
* ~3 minute setup
* Standard Go build tools

## Start

Get started: http://www.engine.org/doc/start

Still a work in progress, but a lot of things are already functional. Some work really well.

## Abbreviated Roadmap

- [x] Single-file components (looks similar to .vue); .sve -> .go code generation.
- [x] Includes CSS in components.
- [x] Basic flow control with vg-if, vg-for and output with vg-html.
- [x] Dynamic attributes with `<tag :prop='expr'>`.
- [x] Nested components with dynamic properties `<my-custom-component :prop='expr'>`.
- [x] Efficiently syncs to browser DOM.
- [x] Static HTML output (great for tests).
- [x] DOM Events, click, etc.
- [x] Modification tracking to avoid unnecessary computation where possible.
- [x] Basic dev and prod server tooling, easy to get started
- [x] Rewrite everything so it is not so terrible internally
- [ ] URL Router (in-progress)
- [ ] Server-side rendering (HTML generation works, needs URL Router to make it usable)
- [ ] Performance optimizations
- [ ] Go-only component events
- [ ] Slots
- [ ] Component library(s)
- And much more...

## Notes

It's built **more like a library than a framework**.  While Vugu does do code generation for your .sve component
files, (and will even output a default main_wasm.go for a new project and build your program automatically upon page refresh), 
fundamentally you are still in control.  Overall program flow, application wiring and initialization, the render loop
that keeps the page in sync with your components - you have control over all of that.
Frameworks call your code.  Vugu is a library, your code calls it (even if Vugu generates a bit of that for you in
the beginning to make things easier). One of the primary goals for Vugu, when it comes to developers first encountering it, 
was to make it very fast and easy to get started, but without imposing unnecessary limitations on how a project is structured.
Go build tooling (and now the module system) is awesome.  The idea is to leverage that to the furthest extent possible,
rather than reprogramming the wheel.

So you won't find a sve command line tool that runs a development server, instead
you'll find in the docs an appropriate snippet of code you can paste in a file and `go run` yourself.  For the code
generation while there is an http.Handler that can do this upon page refresh, you also can (and should!) run `svegen`
via `go generate`. There are many small decisions in Vugu which follow this philosophy: wherever reasonably possible,
just use the existing mechanism instead of inventing anew.  And keep doing that until there's proof that something
else is really needed.  So far it's been working well.  And it allows Vugu to focus on the specific things it 
brings to the table.
