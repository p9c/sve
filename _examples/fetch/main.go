package main

import (
	"flag"
	"fmt"
	"github.com/p9c/sve/engine/component"
	"github.com/p9c/sve/engine/render"
	"github.com/p9c/sve"
	"github.com/vugu/vugu/engine"
	"log"
)

func Engine() {
	mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
	flag.Parse()

	fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
	defer fmt.Printf("Exiting main()\n")

	rootBuilder := &Root{}

	buildEnv, err := component.NewBuildEnv()
	if err != nil {
		log.Fatal(err)
	}

	renderer, err := render.NewJSRenderer(*mountPoint)
	if err != nil {
		log.Fatal(err)
	}
	defer renderer.Release()

	for ok := true; ok; ok = renderer.EventWait() {

		buildResults := buildEnv.RunBuild(rootBuilder)

		err = renderer.Render(buildResults)
		if err != nil {
			panic(err)
		}
	}

}

func main() {

	mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
	flag.Parse()

	fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
	defer fmt.Printf("Exiting main()\n")

	rootBuilder := &Root{}

	buildEnv, err := engine.NewBuildEnv()
	if err != nil {
		log.Fatal(err)
	}

	renderer, err := sve.NewJSRenderer(*mountPoint)
	if err != nil {
		log.Fatal(err)
	}
	defer renderer.Release()

	for ok := true; ok; ok = renderer.EventWait() {

		buildResults := buildEnv.RunBuild(rootBuilder)

		err = renderer.Render(buildResults)
		if err != nil {
			panic(err)
		}
	}

}
