// +build wasm

package main

import (
	"log"
	"os"
)

func main() {

	println("Entering main()")
	defer println("Exiting main()")

	rootInst, err := render.New(&Root{}, nil)
	if err != nil {
		log.Fatal(err)
	}

	env := NewJSEnv("#root_mount_parent", rootInst, component.RegisteredComponentTypes())
	env.DebugWriter = os.Stdout

	for ok := true; ok; ok = env.EventWait() {
		err = env.Render()
		if err != nil {
			panic(err)
		}
	}

}
