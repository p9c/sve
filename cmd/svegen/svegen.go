// svegen is a command line tool to convert .sve files into Go source code.
package main

import (
	"flag"
	"fmt"
	"log"
	"path/filepath"

	"github.com/p9c/sve"
)

// we basically just wrap ParserGoPKg
func main() {

	// svegen path/to/package

	var opts sve.ParserGoPkgOpts
	flag.BoolVar(&opts.SkipRegisterComponentTypes, "skip-register", false, "Do not attempt to register component in init() method")
	flag.BoolVar(&opts.SkipGoMod, "skip-go-mod", false, "Do not try to create go.mod as needed")
	flag.BoolVar(&opts.SkipMainGo, "skip-main", false, "Do not try to create main.go as needed")
	// version := flag.Bool("version", false, "Print version and exit with code 0")
	flag.Parse()

	// if *version { // NOTE: this is really just here so you can do `svegen -version` and see if it works, makes things simple
	// 	fmt.Println("0.0.0")
	// 	os.Exit(0)
	// }

	args := flag.Args()
	if len(args) != 1 {
		fmt.Printf("expected exactly one argument of package path but got %d args instead", len(args))
	}

	pkgPath := args[0]
	var err error
	pkgPath, err = filepath.Abs(pkgPath)
	if err != nil {
		log.Fatal(err)
	}

	p := sve.NewParserGoPkg(pkgPath, &opts)

	err = p.Run()
	if err != nil {
		log.Fatal(err)
	}

}
