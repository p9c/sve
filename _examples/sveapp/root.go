package main

// DO NOT EDIT: This file was generated by sve. Please regenerate instead of editing or add additional code in a separate file.

import "fmt"
import "reflect"
import "encoding/json"
import "github.com/p9c/sve"
import js "github.com/p9c/sve/js"

type RootData struct {
	Url string
}

func (comp *Root) NewData(props sve.Props) (interface{}, error) {
	url := "https://random.dog/woof.json"
	return &RootData{Url: url}, nil
}
func (c *Root) Build(vgin *sve.BuildIn) (vgout *sve.BuildOut) {

	vgout = &sve.BuildOut{}

	var vgiterkey interface{}
	_ = vgiterkey
	var vgn *sve.VGNode
	vgn = &sve.VGNode{Type: sve.VGNodeType(3), Data: "div", Attr: []sve.VGAttribute{sve.VGAttribute{Namespace: "", Key: "class", Val: "root"}}}
	vgout.Out = append(vgout.Out, vgn)	// root for output
	{
		vgparent := vgn
		_ = vgparent
		vgn = &sve.VGNode{Type: sve.VGNodeType(1), Data: "\n    "}
		vgparent.AppendChild(vgn)
		vgn = &sve.VGNode{Type: sve.VGNodeType(3), Data: "random-animal", Attr: []sve.VGAttribute{sve.VGAttribute{Namespace: "", Key: "target", Val: "わんこ"}}}
		vgparent.AppendChild(vgn)
		vgn.Attr = append(vgn.Attr, sve.VGAttribute{Key: "url", Val: fmt.Sprint(data.Url)})
		{
			vgparent := vgn
			_ = vgparent
			vgn = &sve.VGNode{Type: sve.VGNodeType(1), Data: "\n"}
			vgparent.AppendChild(vgn)
		}
	}
	vgn = &sve.VGNode{Type: sve.VGNodeType(3), Data: "style", Attr: []sve.VGAttribute(nil)}
	{
		vgn.AppendChild(&sve.VGNode{Type: sve.VGNodeType(1), Data: "\n", Attr: []sve.VGAttribute(nil)})
	}
	vgout.AppendCSS(vgn)
	return vgout
}

// 'fix' unused imports
var _ fmt.Stringer
var _ reflect.Type
var _ json.RawMessage
var _ js.Value

type Root struct {}
