package main

import (
	"github.com/therecipe/qt/cmd/deploy"
	"github.com/therecipe/qt/utils"
	"os"
	"runtime"
)

func main() {
	path, err := os.Getwd()
	if err != nil {
		utils.Log.WithError(err).Debug("failed to get cwd")
	}
	deploy.Deploy("test",runtime.GOOS, path+"/app")
}

//
//type
//	QmlBridge struct {
//		core.QObject
//		_ func(data string)        `signal:sendToQml`
//		_ func(data string) string `slot:sendToGo` //only slots can return something
//	}
//
//type
//	Root struct {
//		w component.Builder
//	}
//
//func
//main() {
//	core.QCoreApplication_SetAttribute(core.Qt__AA_EnableHighDpiScaling, true)
//	widgets.NewQApplication(len(os.Args), os.Args)
//	var qmlBridge *QmlBridge
//
//	//mountPoint := flag.String("mount-point", "#sve_mount_point", "The query selector for the mount point for the root component, if it is not a full HTML component")
//	//flag.Parse()
//	//
//	//fmt.Printf("Entering main(), -mount-point=%q\n", *mountPoint)
//	//defer fmt.Printf("Exiting main()\n")
//
//	//rootBuilder := &Root{}
//
//	//buildEnv, err := component.NewBuildEnv()
//	//if err != nil {
//	//	log.Fatal(err)
//	//}
//
//	//renderer, err := render.NewJSRenderer(*mountPoint)
//	//if err != nil {
//	//	log.Fatal(err)
//	//}
//	//defer renderer.Release()
//	//
//	//for ok := true; ok; ok = renderer.EventWait() {
//
//	//buildResults := buildEnv.RunBuild(rootBuilder)
//
//	//err = renderer.Render(buildResults)
//	//if err != nil {
//	//	panic(err)
//	//}
//	//}
//	var view = webengine.NewQWebEngineView(nil)
//	//view.SetUrl(QUrl("qrc:/index.html"))
//	view.Load(core.NewQUrl3("qrc:/index.html", 0))
//
//	//used this because QLabel got no clicked signal
//	view.ConnectMousePressEvent(func(ev *gui.QMouseEvent) {
//		//in main thread
//		println(qmlBridge.SendToGo("hello from qml"))
//	})
//	//create a instance of QmlBridge and connect the slot and signal
//	qmlBridge = NewQmlBridge(nil)
//	qmlBridge.ConnectSendToGo(func(data string) string {
//		//in main thread
//		fmt.Println("go:", data)
//		return "hello from go"
//	})
//	qmlBridge.ConnectSendToQml(func(data string) {
//		//view.Page().RunJavaScript(jsDataSve)
//	})
//	//timer in another goroutine (and thread) that emits the signal to update the label
//	//you need to use slots or signals if you want to change visual Qt elements from another thread
//	go func() {
//		//some other thread
//		for t := range time.NewTicker(time.Second * 1).C {
//			qmlBridge.SendToQml(t.Format(time.ANSIC))
//		}
//	}()
//	//show label (which will act as a window)
//	view.Show()
//	//l := ":8875"
//	//log.Printf("Starting HTTP Server at %q", l)
//	//h := simplehttp.New("", true)
//	//log.Fatal(http.ListenAndServe(l, h))
//
//	widgets.QApplication_Exec()
//}
//
//
//
