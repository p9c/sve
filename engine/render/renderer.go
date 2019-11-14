package render

import "github.com/p9c/sve/engine/component"

// Renderer takes a BuildOut ("virtual DOM") and renders it to it's final output.
type Renderer interface {
	Render(b *component.BuildOut) error
}
