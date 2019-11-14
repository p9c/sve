package engine

import (
	"flag"
	"fmt"
	"github.com/p9c/sve/engine/component"
	"github.com/p9c/sve/engine/render"
	"github.com/p9c/sve/pkg/simplehttp"
	"github.com/p9c/sve/pkg/qt/core"
	"github.com/p9c/sve/pkg/qt/webengine"
	"github.com/p9c/sve/pkg/qt/widgets"
	"log"
	"net/http"
	"os"
)

func
Engine() {
	core.QCoreApplication_SetAttribute(core.Qt__AA_EnableHighDpiScaling, true)
	widgets.NewQApplication(len(os.Args), os.Args)
	//var qmlBridge *QmlBridge

	//wd, _ := os.Getwd()
	var view = webengine.NewQWebEngineView(nil)
	//view.SetUrl(QUrl("qrc:/index.html"))
	view.Load(core.NewQUrl3("qrc:/index.html", 0))

	mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
	flag.Parse()

	//fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
	//defer fmt.Printf("Exiting main()\n")

	rootBuilder := &Root{

	}

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

	//
	////used this because QLabel got no clicked signal
	//view.ConnectMousePressEvent(func(ev *gui.QMouseEvent) {
	//	//in main thread
	//	println(qmlBridge.SendToGo("hello from qml"))
	//})
	////create a instance of QmlBridge and connect the slot and signal
	//qmlBridge = NewQmlBridge(nil)
	//qmlBridge.ConnectSendToGo(func(data string) string {
	//	//in main thread
	//	fmt.Println("go:", data)
	//	return "hello from go"
	//})
	//qmlBridge.ConnectSendToQml(func(data string) {
	//	//view.Page().RunJavaScript(jsDataSve)
	//})
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
	//l := ":8875"
	//log.Printf("Starting HTTP Server at %q", l)
	//h := simplehttp.New(wd, true)
	//log.Fatal(http.ListenAndServe(l, h))

	widgets.QApplication_Exec()
}
