package main

import (
	"flag"
	"fmt"
	"github.com/p9c/sve/engine/component"
	"github.com/p9c/sve/engine/parser"
	"github.com/p9c/sve/engine/render"
	"github.com/p9c/sve/pkg/qt/core"
	"github.com/p9c/sve/pkg/qt/webengine"
	"github.com/p9c/sve/pkg/qt/widgets"
	"log"
	"os"
	"path/filepath"
	"time"

	"github.com/p9c/sve/pkg/distutil"
)

//
//type QmlBridge struct {
//	core.QObject
//
//	_ func(data string)        `signal:sendToQml`
//	_ func(data string) string `slot:sendToGo` //only slots can return something
//}

func main() {
	start := time.Now()
	core.QCoreApplication_SetAttribute(core.Qt__AA_EnableHighDpiScaling, true)
	widgets.NewQApplication(len(os.Args), os.Args)
	//var qmlBridge *QmlBridge
	mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
	flag.Parse()
	//fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
	//defer fmt.Printf("Exiting main()\n")
	rootBuilder := &Root{}



	pkgPath, _ := os.Getwd()
	// svegen path/to/package
	var opts parser.ParserGoPkgOpts
	p := parser.NewParserGoPkg(pkgPath, &opts)
	err := p.Run()
	if err != nil {
		log.Fatal(err)
	}
	//wd, _ := os.Getwd()
	//l := "127.0.0.1:8844"
	//log.Printf("Starting HTTP Server at %q", l)
	//h := simplehttp.New(wd, true)
	// include a CSS file
	// simplehttp.DefaultStaticData["CSSFiles"] = []string{ "/my/file.css" }

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
	//println("Entering main()")
	//defer println("Exiting main()")
	//
	//rootInst, err := simplehttp.New(&Root{}, nil)
	//if err != nil {
	//	log.Fatal(err)
	//}
	//
	//env := simplehttp.NewJSEnv("#root_mount_parent", rootInst, simplehttp.RegisteredComponentTypes())
	//env.DebugWriter = os.Stdout
	//
	//for ok := true; ok; ok = env.EventWait() {
	//	err = env.Render()
	//	if err != nil {
	//		panic(err)
	//	}
	//}

	//log.Fatal(http.ListenAndServe(l, h))

	// dist := flag.String("dist", "dist", "Directory to put distribution files in")
	// for github page
	dist := flag.String("dist", "docs", "Directory to put distribution files in")

	// copy static files
	distutil.MustCopyDirFiltered(".", *dist, nil)

	// find and copy wasm_exec.js
	distutil.MustCopyFile(distutil.MustWasmExecJsPath(), filepath.Join(*dist, "wasm_exec.js"))

	// run go build for wasm binary
	fmt.Sprint(distutil.MustEnvExec([]string{"GOOS=js", "GOARCH=wasm"}, "go", "build", "-o", filepath.Join(*dist, "main.wasm"), "."))

	flag.Parse()
	// STATIC INDEX FILE:
	// if you are hosting with a static file server or CDN, you can write out the default index.html from simplehttp
	// req, _ := http.NewRequest("GET", "/index.html", nil)
	// outf, err := os.OpenFile(filepath.Join(*dist, "index.html"), os.O_CREATE|os.O_TRUNC|os.O_WRONLY, 0644)
	// distutil.Must(err)
	// defer outf.Close()
	// template.Must(template.New("_page_").Parse(simplehttp.DefaultPageTemplateSource)).Execute(outf, map[string]interface{}{"Request": req})

	//distutil.MustCopyFile("index.html", filepath.Join(*dist, "index.html"))
	//distutil.MustCopyFile("manifest.json", filepath.Join(*dist, "manifest.json"))
	//distutil.MustCopyFile("sw.js", filepath.Join(*dist, "sw.js"))
	var view = webengine.NewQWebEngineView(nil)
	//view.SetUrl(QUrl("qrc:/index.html"))
	view.Load(core.NewQUrl3("qrc:/index.html", 0))
	//
	////used this because QLabel got no clicked signal
	//view.ConnectMousePressEvent(func(ev *gui.QMouseEvent) {
	//	//in main thread
	//	println(qmlBridge.SendToGo("hello from qml"))
	//})
	////create a instance of QmlBridge and connect the slot and signal
	//

	//qmlBridge = NewQmlBridge(nil)
	//qmlBridge.ConnectSendToGo(func(data string) string {
	//	//in main thread
	//	fmt.Println("go:", data)
	//	return "hello from go"
	//})
	//qmlBridge.ConnectSendToQml(func(data string) {
	//	//view.Page().RunJavaScript(jsDataSve)
	//})
	//
	//

	//timer in another goroutine (and thread) that emits the signal to update the label
	//you need to use slots or signals if you want to change visual Qt elements from another thread
	//go func() {
	//	//some other thread
	//	for t := range time.NewTicker(time.Second * 1).C {
	//		qmlBridge.SendToQml(t.Format(time.ANSIC))
	//	}
	//}()
	//show label (which will act as a window)
	view.Show()

	// BUILD GO SERVER:
	// or if you are deploying a Go server (yay!) you can build that binary here
	// fmt.Sprint(distutil.MustExec("go", "build", "-o", filepath.Join(*dist, "server"), "."))

	log.Printf("dist.go complete in %v", time.Since(start))

	widgets.QApplication_Exec()

}
