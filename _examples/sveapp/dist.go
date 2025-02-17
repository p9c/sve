// +build ignore

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"time"

	"github.com/p9c/sve/pkg/distutil"
)

func main() {
	clean := flag.Bool("clean", false, "Remove dist dir before starting")
	// dist := flag.String("dist", "dist", "Directory to put distribution files in")
	// for github page
	dist := flag.String("dist", "docs", "Directory to put distribution files in")

	flag.Parse()

	start := time.Now()

	if *clean {
		os.RemoveAll(*dist)
	}

	os.MkdirAll(*dist, 0755) // create dist dir if not there

	// copy static files
	distutil.MustCopyDirFiltered(".", *dist, nil)

	// find and copy wasm_exec.js
	distutil.MustCopyFile(distutil.MustWasmExecJsPath(), filepath.Join(*dist, "wasm_exec.js"))

	// check for svegen and go get if not there
	if _, err := exec.LookPath("svegen"); err != nil {
		fmt.Sprint(distutil.MustExec("go", "get", "github.com/p9c/sve"))
	}

	// run go generate
	fmt.Sprint(distutil.MustExec("go", "generate", "."))

	// run go build for wasm binary
	fmt.Sprint(distutil.MustEnvExec([]string{"GOOS=js", "GOARCH=wasm"}, "go", "build", "-o", filepath.Join(*dist, "main.wasm"), "."))
	// STATIC INDEX FILE:
	// if you are hosting with a static file server or CDN, you can write out the default index.html from simplehttp
	// req, _ := http.NewRequest("GET", "/index.html", nil)
	// outf, err := os.OpenFile(filepath.Join(*dist, "index.html"), os.O_CREATE|os.O_TRUNC|os.O_WRONLY, 0644)
	// distutil.Must(err)
	// defer outf.Close()
	// template.Must(template.New("_page_").Parse(simplehttp.DefaultPageTemplateSource)).Execute(outf, map[string]interface{}{"Request": req})

	distutil.MustCopyFile("index.html", filepath.Join(*dist, "index.html"))
	distutil.MustCopyFile("manifest.json", filepath.Join(*dist, "manifest.json"))
	distutil.MustCopyFile("sw.js", filepath.Join(*dist, "sw.js"))

	// BUILD GO SERVER:
	// or if you are deploying a Go server (yay!) you can build that binary here
	// fmt.Sprint(distutil.MustExec("go", "build", "-o", filepath.Join(*dist, "server"), "."))

	log.Printf("dist.go complete in %v", time.Since(start))
}
