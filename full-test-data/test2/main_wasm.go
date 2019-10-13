// +build wasm

package main

import (
	"log"
	"fmt"
	"flag"

	"github.com/p9c/sve"
)

func main() {

	mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
	flag.Parse()

	fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
	defer fmt.Printf("Exiting main()\n")

	rootBuilder := &Root{}

	buildEnv, err := sve.NewBuildEnv()
	if err != nil {
		log.Fatal(err)
	}

	renderer, err := sve.NewJSRenderer(*mountPoint)
	if err != nil {
		log.Fatal(err)
	}
	defer renderer.Release()

	for ok := true; ok; ok = renderer.EventWait() {

		buildOut, err := buildEnv.RunBuild(rootBuilder)
		if err != nil {
			panic(err)
		}

		err = renderer.Render(buildOut)
		if err != nil {
			panic(err)
		}
	}
	
}
