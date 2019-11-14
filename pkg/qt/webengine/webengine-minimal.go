// +build minimal

package webengine

//#include <stdint.h>
//#include <stdlib.h>
//#include <string.h>
//#include "webengine-minimal.h"
import "C"
import (
	"github.com/p9c/sve/pkg/qt"
	"github.com/p9c/sve/pkg/qt/core"
	"github.com/p9c/sve/pkg/qt/gui"
	"github.com/p9c/sve/pkg/qt/printsupport"
	"github.com/p9c/sve/pkg/qt/widgets"
	"runtime"
	"strings"
	"unsafe"
)

func cGoUnpackString(s C.struct_QtWebEngine_PackedString) string {
	if int(s.len) == -1 {
		return C.GoString(s.data)
	}
	return C.GoStringN(s.data, C.int(s.len))
}
func cGoUnpackBytes(s C.struct_QtWebEngine_PackedString) []byte {
	if int(s.len) == -1 {
		gs := C.GoString(s.data)
		return *(*[]byte)(unsafe.Pointer(&gs))
	}
	return C.GoBytes(unsafe.Pointer(s.data), C.int(s.len))
}
func unpackStringList(s string) []string {
	if len(s) == 0 {
		return make([]string, 0)
	}
	return strings.Split(s, "¡¦!")
}

//go:generate stringer -type=QQuickWebEngineProfile__HttpCacheType
//QQuickWebEngineProfile::HttpCacheType
type QQuickWebEngineProfile__HttpCacheType int64

const (
	QQuickWebEngineProfile__MemoryHttpCache QQuickWebEngineProfile__HttpCacheType = QQuickWebEngineProfile__HttpCacheType(0)
	QQuickWebEngineProfile__DiskHttpCache   QQuickWebEngineProfile__HttpCacheType = QQuickWebEngineProfile__HttpCacheType(1)
	QQuickWebEngineProfile__NoCache         QQuickWebEngineProfile__HttpCacheType = QQuickWebEngineProfile__HttpCacheType(2)
)

//go:generate stringer -type=QQuickWebEngineProfile__PersistentCookiesPolicy
//QQuickWebEngineProfile::PersistentCookiesPolicy
type QQuickWebEngineProfile__PersistentCookiesPolicy int64

const (
	QQuickWebEngineProfile__NoPersistentCookies    QQuickWebEngineProfile__PersistentCookiesPolicy = QQuickWebEngineProfile__PersistentCookiesPolicy(0)
	QQuickWebEngineProfile__AllowPersistentCookies QQuickWebEngineProfile__PersistentCookiesPolicy = QQuickWebEngineProfile__PersistentCookiesPolicy(1)
	QQuickWebEngineProfile__ForcePersistentCookies QQuickWebEngineProfile__PersistentCookiesPolicy = QQuickWebEngineProfile__PersistentCookiesPolicy(2)
)

//go:generate stringer -type=QQuickWebEngineScript__InjectionPoint
//QQuickWebEngineScript::InjectionPoint
type QQuickWebEngineScript__InjectionPoint int64

const (
	QQuickWebEngineScript__Deferred         QQuickWebEngineScript__InjectionPoint = QQuickWebEngineScript__InjectionPoint(0)
	QQuickWebEngineScript__DocumentReady    QQuickWebEngineScript__InjectionPoint = QQuickWebEngineScript__InjectionPoint(1)
	QQuickWebEngineScript__DocumentCreation QQuickWebEngineScript__InjectionPoint = QQuickWebEngineScript__InjectionPoint(2)
)

//go:generate stringer -type=QQuickWebEngineScript__ScriptWorldId
//QQuickWebEngineScript::ScriptWorldId
type QQuickWebEngineScript__ScriptWorldId int64

const (
	QQuickWebEngineScript__MainWorld        QQuickWebEngineScript__ScriptWorldId = QQuickWebEngineScript__ScriptWorldId(0)
	QQuickWebEngineScript__ApplicationWorld QQuickWebEngineScript__ScriptWorldId = QQuickWebEngineScript__ScriptWorldId(1)
	QQuickWebEngineScript__UserWorld        QQuickWebEngineScript__ScriptWorldId = QQuickWebEngineScript__ScriptWorldId(2)
)

//go:generate stringer -type=QWebEngineCertificateError__Error
//QWebEngineCertificateError::Error
type QWebEngineCertificateError__Error int64

const (
	QWebEngineCertificateError__SslPinnedKeyNotInCertificateChain  QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-150)
	QWebEngineCertificateError__CertificateCommonNameInvalid       QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-200)
	QWebEngineCertificateError__CertificateDateInvalid             QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-201)
	QWebEngineCertificateError__CertificateAuthorityInvalid        QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-202)
	QWebEngineCertificateError__CertificateContainsErrors          QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-203)
	QWebEngineCertificateError__CertificateNoRevocationMechanism   QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-204)
	QWebEngineCertificateError__CertificateUnableToCheckRevocation QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-205)
	QWebEngineCertificateError__CertificateRevoked                 QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-206)
	QWebEngineCertificateError__CertificateInvalid                 QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-207)
	QWebEngineCertificateError__CertificateWeakSignatureAlgorithm  QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-208)
	QWebEngineCertificateError__CertificateNonUniqueName           QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-210)
	QWebEngineCertificateError__CertificateWeakKey                 QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-211)
	QWebEngineCertificateError__CertificateNameConstraintViolation QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-212)
	QWebEngineCertificateError__CertificateValidityTooLong         QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-213)
	QWebEngineCertificateError__CertificateTransparencyRequired    QWebEngineCertificateError__Error = QWebEngineCertificateError__Error(-214)
)

type QWebEngineHttpRequest struct {
	ptr unsafe.Pointer
}

type QWebEngineHttpRequest_ITF interface {
	QWebEngineHttpRequest_PTR() *QWebEngineHttpRequest
}

func (ptr *QWebEngineHttpRequest) QWebEngineHttpRequest_PTR() *QWebEngineHttpRequest {
	return ptr
}

func (ptr *QWebEngineHttpRequest) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.ptr
	}
	return nil
}

func (ptr *QWebEngineHttpRequest) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.ptr = p
	}
}

func PointerFromQWebEngineHttpRequest(ptr QWebEngineHttpRequest_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.QWebEngineHttpRequest_PTR().Pointer()
	}
	return nil
}

func NewQWebEngineHttpRequestFromPointer(ptr unsafe.Pointer) (n *QWebEngineHttpRequest) {
	n = new(QWebEngineHttpRequest)
	n.SetPointer(ptr)
	return
}

//go:generate stringer -type=QWebEngineHttpRequest__Method
//QWebEngineHttpRequest::Method
type QWebEngineHttpRequest__Method int64

const (
	QWebEngineHttpRequest__Get  QWebEngineHttpRequest__Method = QWebEngineHttpRequest__Method(0)
	QWebEngineHttpRequest__Post QWebEngineHttpRequest__Method = QWebEngineHttpRequest__Method(1)
)

func NewQWebEngineHttpRequest(url core.QUrl_ITF, method QWebEngineHttpRequest__Method) *QWebEngineHttpRequest {
	tmpValue := NewQWebEngineHttpRequestFromPointer(C.QWebEngineHttpRequest_NewQWebEngineHttpRequest(core.PointerFromQUrl(url), C.longlong(method)))
	runtime.SetFinalizer(tmpValue, (*QWebEngineHttpRequest).DestroyQWebEngineHttpRequest)
	return tmpValue
}

func NewQWebEngineHttpRequest2(other QWebEngineHttpRequest_ITF) *QWebEngineHttpRequest {
	tmpValue := NewQWebEngineHttpRequestFromPointer(C.QWebEngineHttpRequest_NewQWebEngineHttpRequest2(PointerFromQWebEngineHttpRequest(other)))
	runtime.SetFinalizer(tmpValue, (*QWebEngineHttpRequest).DestroyQWebEngineHttpRequest)
	return tmpValue
}

func (ptr *QWebEngineHttpRequest) Header(headerName core.QByteArray_ITF) *core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQByteArrayFromPointer(C.QWebEngineHttpRequest_Header(ptr.Pointer(), core.PointerFromQByteArray(headerName)))
		runtime.SetFinalizer(tmpValue, (*core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineHttpRequest) Headers() []*core.QByteArray {
	if ptr.Pointer() != nil {
		return func(l C.struct_QtWebEngine_PackedList) []*core.QByteArray {
			out := make([]*core.QByteArray, int(l.len))
			tmpList := NewQWebEngineHttpRequestFromPointer(l.data)
			for i := 0; i < len(out); i++ {
				out[i] = tmpList.__headers_atList(i)
			}
			return out
		}(C.QWebEngineHttpRequest_Headers(ptr.Pointer()))
	}
	return make([]*core.QByteArray, 0)
}

func (ptr *QWebEngineHttpRequest) Method() QWebEngineHttpRequest__Method {
	if ptr.Pointer() != nil {
		return QWebEngineHttpRequest__Method(C.QWebEngineHttpRequest_Method(ptr.Pointer()))
	}
	return 0
}

func (ptr *QWebEngineHttpRequest) SetHeader(headerName core.QByteArray_ITF, headerValue core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineHttpRequest_SetHeader(ptr.Pointer(), core.PointerFromQByteArray(headerName), core.PointerFromQByteArray(headerValue))
	}
}

func (ptr *QWebEngineHttpRequest) SetUrl(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineHttpRequest_SetUrl(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEngineHttpRequest) Swap(other QWebEngineHttpRequest_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineHttpRequest_Swap(ptr.Pointer(), PointerFromQWebEngineHttpRequest(other))
	}
}

func (ptr *QWebEngineHttpRequest) Url() *core.QUrl {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQUrlFromPointer(C.QWebEngineHttpRequest_Url(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*core.QUrl).DestroyQUrl)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineHttpRequest) DestroyQWebEngineHttpRequest() {
	if ptr.Pointer() != nil {
		C.QWebEngineHttpRequest_DestroyQWebEngineHttpRequest(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEngineHttpRequest) __headers_atList(i int) *core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQByteArrayFromPointer(C.QWebEngineHttpRequest___headers_atList(ptr.Pointer(), C.int(int32(i))))
		runtime.SetFinalizer(tmpValue, (*core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineHttpRequest) __headers_setList(i core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineHttpRequest___headers_setList(ptr.Pointer(), core.PointerFromQByteArray(i))
	}
}

func (ptr *QWebEngineHttpRequest) __headers_newList() unsafe.Pointer {
	return C.QWebEngineHttpRequest___headers_newList(ptr.Pointer())
}

func (ptr *QWebEngineHttpRequest) __postRequest_postData_atList(v string, i int) string {
	if ptr.Pointer() != nil {
		var vC *C.char
		if v != "" {
			vC = C.CString(v)
			defer C.free(unsafe.Pointer(vC))
		}
		return cGoUnpackString(C.QWebEngineHttpRequest___postRequest_postData_atList(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: vC, len: C.longlong(len(v))}, C.int(int32(i))))
	}
	return ""
}

func (ptr *QWebEngineHttpRequest) __postRequest_postData_setList(key string, i string) {
	if ptr.Pointer() != nil {
		var keyC *C.char
		if key != "" {
			keyC = C.CString(key)
			defer C.free(unsafe.Pointer(keyC))
		}
		var iC *C.char
		if i != "" {
			iC = C.CString(i)
			defer C.free(unsafe.Pointer(iC))
		}
		C.QWebEngineHttpRequest___postRequest_postData_setList(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: keyC, len: C.longlong(len(key))}, C.struct_QtWebEngine_PackedString{data: iC, len: C.longlong(len(i))})
	}
}

func (ptr *QWebEngineHttpRequest) __postRequest_postData_newList() unsafe.Pointer {
	return C.QWebEngineHttpRequest___postRequest_postData_newList(ptr.Pointer())
}

func (ptr *QWebEngineHttpRequest) __postRequest_postData_keyList() []string {
	if ptr.Pointer() != nil {
		return func(l C.struct_QtWebEngine_PackedList) []string {
			out := make([]string, int(l.len))
			tmpList := NewQWebEngineHttpRequestFromPointer(l.data)
			for i := 0; i < len(out); i++ {
				out[i] = tmpList.____postRequest_postData_keyList_atList(i)
			}
			return out
		}(C.QWebEngineHttpRequest___postRequest_postData_keyList(ptr.Pointer()))
	}
	return make([]string, 0)
}

func (ptr *QWebEngineHttpRequest) ____postRequest_postData_keyList_atList(i int) string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEngineHttpRequest_____postRequest_postData_keyList_atList(ptr.Pointer(), C.int(int32(i))))
	}
	return ""
}

func (ptr *QWebEngineHttpRequest) ____postRequest_postData_keyList_setList(i string) {
	if ptr.Pointer() != nil {
		var iC *C.char
		if i != "" {
			iC = C.CString(i)
			defer C.free(unsafe.Pointer(iC))
		}
		C.QWebEngineHttpRequest_____postRequest_postData_keyList_setList(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: iC, len: C.longlong(len(i))})
	}
}

func (ptr *QWebEngineHttpRequest) ____postRequest_postData_keyList_newList() unsafe.Pointer {
	return C.QWebEngineHttpRequest_____postRequest_postData_keyList_newList(ptr.Pointer())
}

type QWebEnginePage struct {
	core.QObject
}

type QWebEnginePage_ITF interface {
	core.QObject_ITF
	QWebEnginePage_PTR() *QWebEnginePage
}

func (ptr *QWebEnginePage) QWebEnginePage_PTR() *QWebEnginePage {
	return ptr
}

func (ptr *QWebEnginePage) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.QObject_PTR().Pointer()
	}
	return nil
}

func (ptr *QWebEnginePage) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.QObject_PTR().SetPointer(p)
	}
}

func PointerFromQWebEnginePage(ptr QWebEnginePage_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.QWebEnginePage_PTR().Pointer()
	}
	return nil
}

func NewQWebEnginePageFromPointer(ptr unsafe.Pointer) (n *QWebEnginePage) {
	n = new(QWebEnginePage)
	n.SetPointer(ptr)
	return
}

//go:generate stringer -type=QWebEnginePage__FileSelectionMode
//QWebEnginePage::FileSelectionMode
type QWebEnginePage__FileSelectionMode int64

const (
	QWebEnginePage__FileSelectOpen         QWebEnginePage__FileSelectionMode = QWebEnginePage__FileSelectionMode(0)
	QWebEnginePage__FileSelectOpenMultiple QWebEnginePage__FileSelectionMode = QWebEnginePage__FileSelectionMode(1)
)

//go:generate stringer -type=QWebEnginePage__JavaScriptConsoleMessageLevel
//QWebEnginePage::JavaScriptConsoleMessageLevel
type QWebEnginePage__JavaScriptConsoleMessageLevel int64

const (
	QWebEnginePage__InfoMessageLevel    QWebEnginePage__JavaScriptConsoleMessageLevel = QWebEnginePage__JavaScriptConsoleMessageLevel(0)
	QWebEnginePage__WarningMessageLevel QWebEnginePage__JavaScriptConsoleMessageLevel = QWebEnginePage__JavaScriptConsoleMessageLevel(1)
	QWebEnginePage__ErrorMessageLevel   QWebEnginePage__JavaScriptConsoleMessageLevel = QWebEnginePage__JavaScriptConsoleMessageLevel(2)
)

//go:generate stringer -type=QWebEnginePage__WebAction
//QWebEnginePage::WebAction
type QWebEnginePage__WebAction int64

const (
	QWebEnginePage__Back                       QWebEnginePage__WebAction = QWebEnginePage__WebAction(0)
	QWebEnginePage__Forward                    QWebEnginePage__WebAction = QWebEnginePage__WebAction(1)
	QWebEnginePage__Stop                       QWebEnginePage__WebAction = QWebEnginePage__WebAction(2)
	QWebEnginePage__Reload                     QWebEnginePage__WebAction = QWebEnginePage__WebAction(3)
	QWebEnginePage__Cut                        QWebEnginePage__WebAction = QWebEnginePage__WebAction(4)
	QWebEnginePage__Copy                       QWebEnginePage__WebAction = QWebEnginePage__WebAction(5)
	QWebEnginePage__Paste                      QWebEnginePage__WebAction = QWebEnginePage__WebAction(6)
	QWebEnginePage__Undo                       QWebEnginePage__WebAction = QWebEnginePage__WebAction(7)
	QWebEnginePage__Redo                       QWebEnginePage__WebAction = QWebEnginePage__WebAction(8)
	QWebEnginePage__SelectAll                  QWebEnginePage__WebAction = QWebEnginePage__WebAction(9)
	QWebEnginePage__ReloadAndBypassCache       QWebEnginePage__WebAction = QWebEnginePage__WebAction(10)
	QWebEnginePage__PasteAndMatchStyle         QWebEnginePage__WebAction = QWebEnginePage__WebAction(11)
	QWebEnginePage__OpenLinkInThisWindow       QWebEnginePage__WebAction = QWebEnginePage__WebAction(12)
	QWebEnginePage__OpenLinkInNewWindow        QWebEnginePage__WebAction = QWebEnginePage__WebAction(13)
	QWebEnginePage__OpenLinkInNewTab           QWebEnginePage__WebAction = QWebEnginePage__WebAction(14)
	QWebEnginePage__CopyLinkToClipboard        QWebEnginePage__WebAction = QWebEnginePage__WebAction(15)
	QWebEnginePage__DownloadLinkToDisk         QWebEnginePage__WebAction = QWebEnginePage__WebAction(16)
	QWebEnginePage__CopyImageToClipboard       QWebEnginePage__WebAction = QWebEnginePage__WebAction(17)
	QWebEnginePage__CopyImageUrlToClipboard    QWebEnginePage__WebAction = QWebEnginePage__WebAction(18)
	QWebEnginePage__DownloadImageToDisk        QWebEnginePage__WebAction = QWebEnginePage__WebAction(19)
	QWebEnginePage__CopyMediaUrlToClipboard    QWebEnginePage__WebAction = QWebEnginePage__WebAction(20)
	QWebEnginePage__ToggleMediaControls        QWebEnginePage__WebAction = QWebEnginePage__WebAction(21)
	QWebEnginePage__ToggleMediaLoop            QWebEnginePage__WebAction = QWebEnginePage__WebAction(22)
	QWebEnginePage__ToggleMediaPlayPause       QWebEnginePage__WebAction = QWebEnginePage__WebAction(23)
	QWebEnginePage__ToggleMediaMute            QWebEnginePage__WebAction = QWebEnginePage__WebAction(24)
	QWebEnginePage__DownloadMediaToDisk        QWebEnginePage__WebAction = QWebEnginePage__WebAction(25)
	QWebEnginePage__InspectElement             QWebEnginePage__WebAction = QWebEnginePage__WebAction(26)
	QWebEnginePage__ExitFullScreen             QWebEnginePage__WebAction = QWebEnginePage__WebAction(27)
	QWebEnginePage__RequestClose               QWebEnginePage__WebAction = QWebEnginePage__WebAction(28)
	QWebEnginePage__Unselect                   QWebEnginePage__WebAction = QWebEnginePage__WebAction(29)
	QWebEnginePage__SavePage                   QWebEnginePage__WebAction = QWebEnginePage__WebAction(30)
	QWebEnginePage__OpenLinkInNewBackgroundTab QWebEnginePage__WebAction = QWebEnginePage__WebAction(31)
	QWebEnginePage__ViewSource                 QWebEnginePage__WebAction = QWebEnginePage__WebAction(32)
	QWebEnginePage__ToggleBold                 QWebEnginePage__WebAction = QWebEnginePage__WebAction(33)
	QWebEnginePage__ToggleItalic               QWebEnginePage__WebAction = QWebEnginePage__WebAction(34)
	QWebEnginePage__ToggleUnderline            QWebEnginePage__WebAction = QWebEnginePage__WebAction(35)
	QWebEnginePage__ToggleStrikethrough        QWebEnginePage__WebAction = QWebEnginePage__WebAction(36)
	QWebEnginePage__AlignLeft                  QWebEnginePage__WebAction = QWebEnginePage__WebAction(37)
	QWebEnginePage__AlignCenter                QWebEnginePage__WebAction = QWebEnginePage__WebAction(38)
	QWebEnginePage__AlignRight                 QWebEnginePage__WebAction = QWebEnginePage__WebAction(39)
	QWebEnginePage__AlignJustified             QWebEnginePage__WebAction = QWebEnginePage__WebAction(40)
	QWebEnginePage__Indent                     QWebEnginePage__WebAction = QWebEnginePage__WebAction(41)
	QWebEnginePage__Outdent                    QWebEnginePage__WebAction = QWebEnginePage__WebAction(42)
	QWebEnginePage__InsertOrderedList          QWebEnginePage__WebAction = QWebEnginePage__WebAction(43)
	QWebEnginePage__InsertUnorderedList        QWebEnginePage__WebAction = QWebEnginePage__WebAction(44)
	QWebEnginePage__WebActionCount             QWebEnginePage__WebAction = QWebEnginePage__WebAction(45)
)

//go:generate stringer -type=QWebEnginePage__WebWindowType
//QWebEnginePage::WebWindowType
type QWebEnginePage__WebWindowType int64

const (
	QWebEnginePage__WebBrowserWindow        QWebEnginePage__WebWindowType = QWebEnginePage__WebWindowType(0)
	QWebEnginePage__WebBrowserTab           QWebEnginePage__WebWindowType = QWebEnginePage__WebWindowType(1)
	QWebEnginePage__WebDialog               QWebEnginePage__WebWindowType = QWebEnginePage__WebWindowType(2)
	QWebEnginePage__WebBrowserBackgroundTab QWebEnginePage__WebWindowType = QWebEnginePage__WebWindowType(3)
)

//go:generate stringer -type=QWebEnginePage__PermissionPolicy
//QWebEnginePage::PermissionPolicy
type QWebEnginePage__PermissionPolicy int64

const (
	QWebEnginePage__PermissionUnknown       QWebEnginePage__PermissionPolicy = QWebEnginePage__PermissionPolicy(0)
	QWebEnginePage__PermissionGrantedByUser QWebEnginePage__PermissionPolicy = QWebEnginePage__PermissionPolicy(1)
	QWebEnginePage__PermissionDeniedByUser  QWebEnginePage__PermissionPolicy = QWebEnginePage__PermissionPolicy(2)
)

//go:generate stringer -type=QWebEnginePage__NavigationType
//QWebEnginePage::NavigationType
type QWebEnginePage__NavigationType int64

const (
	QWebEnginePage__NavigationTypeLinkClicked   QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(0)
	QWebEnginePage__NavigationTypeTyped         QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(1)
	QWebEnginePage__NavigationTypeFormSubmitted QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(2)
	QWebEnginePage__NavigationTypeBackForward   QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(3)
	QWebEnginePage__NavigationTypeReload        QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(4)
	QWebEnginePage__NavigationTypeOther         QWebEnginePage__NavigationType = QWebEnginePage__NavigationType(5)
)

//go:generate stringer -type=QWebEnginePage__FindFlag
//QWebEnginePage::FindFlag
type QWebEnginePage__FindFlag int64

const (
	QWebEnginePage__FindBackward        QWebEnginePage__FindFlag = QWebEnginePage__FindFlag(1)
	QWebEnginePage__FindCaseSensitively QWebEnginePage__FindFlag = QWebEnginePage__FindFlag(2)
)

//go:generate stringer -type=QWebEnginePage__Feature
//QWebEnginePage::Feature
type QWebEnginePage__Feature int64

const (
	QWebEnginePage__Notifications            QWebEnginePage__Feature = QWebEnginePage__Feature(0)
	QWebEnginePage__Geolocation              QWebEnginePage__Feature = QWebEnginePage__Feature(1)
	QWebEnginePage__MediaAudioCapture        QWebEnginePage__Feature = QWebEnginePage__Feature(2)
	QWebEnginePage__MediaVideoCapture        QWebEnginePage__Feature = QWebEnginePage__Feature(3)
	QWebEnginePage__MediaAudioVideoCapture   QWebEnginePage__Feature = QWebEnginePage__Feature(4)
	QWebEnginePage__MouseLock                QWebEnginePage__Feature = QWebEnginePage__Feature(5)
	QWebEnginePage__DesktopVideoCapture      QWebEnginePage__Feature = QWebEnginePage__Feature(6)
	QWebEnginePage__DesktopAudioVideoCapture QWebEnginePage__Feature = QWebEnginePage__Feature(7)
)

func NewQWebEnginePage(parent core.QObject_ITF) *QWebEnginePage {
	tmpValue := NewQWebEnginePageFromPointer(C.QWebEnginePage_NewQWebEnginePage(core.PointerFromQObject(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

func NewQWebEnginePage2(profile QWebEngineProfile_ITF, parent core.QObject_ITF) *QWebEnginePage {
	tmpValue := NewQWebEnginePageFromPointer(C.QWebEnginePage_NewQWebEnginePage2(PointerFromQWebEngineProfile(profile), core.PointerFromQObject(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

func (ptr *QWebEnginePage) Action(action QWebEnginePage__WebAction) *widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQActionFromPointer(C.QWebEnginePage_Action(ptr.Pointer(), C.longlong(action)))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) BackgroundColor() *gui.QColor {
	if ptr.Pointer() != nil {
		tmpValue := gui.NewQColorFromPointer(C.QWebEnginePage_BackgroundColor(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*gui.QColor).DestroyQColor)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) CreateStandardContextMenu() *widgets.QMenu {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQMenuFromPointer(C.QWebEnginePage_CreateStandardContextMenu(ptr.Pointer()))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

//export callbackQWebEnginePage_CreateWindow
func callbackQWebEnginePage_CreateWindow(ptr unsafe.Pointer, ty C.longlong) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "createWindow"); signal != nil {
		return PointerFromQWebEnginePage((*(*func(QWebEnginePage__WebWindowType) *QWebEnginePage)(signal))(QWebEnginePage__WebWindowType(ty)))
	}

	return PointerFromQWebEnginePage(NewQWebEnginePageFromPointer(ptr).CreateWindowDefault(QWebEnginePage__WebWindowType(ty)))
}

func (ptr *QWebEnginePage) ConnectCreateWindow(f func(ty QWebEnginePage__WebWindowType) *QWebEnginePage) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "createWindow"); signal != nil {
			f := func(ty QWebEnginePage__WebWindowType) *QWebEnginePage {
				(*(*func(QWebEnginePage__WebWindowType) *QWebEnginePage)(signal))(ty)
				return f(ty)
			}
			qt.ConnectSignal(ptr.Pointer(), "createWindow", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "createWindow", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectCreateWindow() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "createWindow")
	}
}

func (ptr *QWebEnginePage) CreateWindow(ty QWebEnginePage__WebWindowType) *QWebEnginePage {
	if ptr.Pointer() != nil {
		tmpValue := NewQWebEnginePageFromPointer(C.QWebEnginePage_CreateWindow(ptr.Pointer(), C.longlong(ty)))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) CreateWindowDefault(ty QWebEnginePage__WebWindowType) *QWebEnginePage {
	if ptr.Pointer() != nil {
		tmpValue := NewQWebEnginePageFromPointer(C.QWebEnginePage_CreateWindowDefault(ptr.Pointer(), C.longlong(ty)))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) Download(url core.QUrl_ITF, filename string) {
	if ptr.Pointer() != nil {
		var filenameC *C.char
		if filename != "" {
			filenameC = C.CString(filename)
			defer C.free(unsafe.Pointer(filenameC))
		}
		C.QWebEnginePage_Download(ptr.Pointer(), core.PointerFromQUrl(url), C.struct_QtWebEngine_PackedString{data: filenameC, len: C.longlong(len(filename))})
	}
}

//export callbackQWebEnginePage_Event
func callbackQWebEnginePage_Event(ptr unsafe.Pointer, vqe unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "event"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QEvent) bool)(signal))(core.NewQEventFromPointer(vqe)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEnginePageFromPointer(ptr).EventDefault(core.NewQEventFromPointer(vqe)))))
}

func (ptr *QWebEnginePage) EventDefault(vqe core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEnginePage_EventDefault(ptr.Pointer(), core.PointerFromQEvent(vqe))) != 0
	}
	return false
}

func (ptr *QWebEnginePage) HasSelection() bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEnginePage_HasSelection(ptr.Pointer())) != 0
	}
	return false
}

func (ptr *QWebEnginePage) Icon() *gui.QIcon {
	if ptr.Pointer() != nil {
		tmpValue := gui.NewQIconFromPointer(C.QWebEnginePage_Icon(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*gui.QIcon).DestroyQIcon)
		return tmpValue
	}
	return nil
}

//export callbackQWebEnginePage_IconChanged
func callbackQWebEnginePage_IconChanged(ptr unsafe.Pointer, icon unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "iconChanged"); signal != nil {
		(*(*func(*gui.QIcon))(signal))(gui.NewQIconFromPointer(icon))
	}

}

func (ptr *QWebEnginePage) ConnectIconChanged(f func(icon *gui.QIcon)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "iconChanged") {
			C.QWebEnginePage_ConnectIconChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "iconChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "iconChanged"); signal != nil {
			f := func(icon *gui.QIcon) {
				(*(*func(*gui.QIcon))(signal))(icon)
				f(icon)
			}
			qt.ConnectSignal(ptr.Pointer(), "iconChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "iconChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectIconChanged() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectIconChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "iconChanged")
	}
}

func (ptr *QWebEnginePage) IconChanged(icon gui.QIcon_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_IconChanged(ptr.Pointer(), gui.PointerFromQIcon(icon))
	}
}

//export callbackQWebEnginePage_LinkHovered
func callbackQWebEnginePage_LinkHovered(ptr unsafe.Pointer, url C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "linkHovered"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(url))
	}

}

func (ptr *QWebEnginePage) ConnectLinkHovered(f func(url string)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "linkHovered") {
			C.QWebEnginePage_ConnectLinkHovered(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "linkHovered")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "linkHovered"); signal != nil {
			f := func(url string) {
				(*(*func(string))(signal))(url)
				f(url)
			}
			qt.ConnectSignal(ptr.Pointer(), "linkHovered", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "linkHovered", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectLinkHovered() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectLinkHovered(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "linkHovered")
	}
}

func (ptr *QWebEnginePage) LinkHovered(url string) {
	if ptr.Pointer() != nil {
		var urlC *C.char
		if url != "" {
			urlC = C.CString(url)
			defer C.free(unsafe.Pointer(urlC))
		}
		C.QWebEnginePage_LinkHovered(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: urlC, len: C.longlong(len(url))})
	}
}

func (ptr *QWebEnginePage) Load(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_Load(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEnginePage) Load2(request QWebEngineHttpRequest_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_Load2(ptr.Pointer(), PointerFromQWebEngineHttpRequest(request))
	}
}

//export callbackQWebEnginePage_MetaObject
func callbackQWebEnginePage_MetaObject(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "metaObject"); signal != nil {
		return core.PointerFromQMetaObject((*(*func() *core.QMetaObject)(signal))())
	}

	return core.PointerFromQMetaObject(NewQWebEnginePageFromPointer(ptr).MetaObjectDefault())
}

func (ptr *QWebEnginePage) MetaObjectDefault() *core.QMetaObject {
	if ptr.Pointer() != nil {
		return core.NewQMetaObjectFromPointer(C.QWebEnginePage_MetaObjectDefault(ptr.Pointer()))
	}
	return nil
}

func (ptr *QWebEnginePage) Print(printer printsupport.QPrinter_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_Print(ptr.Pointer(), printsupport.PointerFromQPrinter(printer))
	}
}

func (ptr *QWebEnginePage) Profile() *QWebEngineProfile {
	if ptr.Pointer() != nil {
		tmpValue := NewQWebEngineProfileFromPointer(C.QWebEnginePage_Profile(ptr.Pointer()))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) RunJavaScript(scriptSource string) {
	if ptr.Pointer() != nil {
		var scriptSourceC *C.char
		if scriptSource != "" {
			scriptSourceC = C.CString(scriptSource)
			defer C.free(unsafe.Pointer(scriptSourceC))
		}
		C.QWebEnginePage_RunJavaScript(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: scriptSourceC, len: C.longlong(len(scriptSource))})
	}
}

func (ptr *QWebEnginePage) RunJavaScript2(scriptSource string, worldId uint) {
	if ptr.Pointer() != nil {
		var scriptSourceC *C.char
		if scriptSource != "" {
			scriptSourceC = C.CString(scriptSource)
			defer C.free(unsafe.Pointer(scriptSourceC))
		}
		C.QWebEnginePage_RunJavaScript2(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: scriptSourceC, len: C.longlong(len(scriptSource))}, C.uint(uint32(worldId)))
	}
}

func (ptr *QWebEnginePage) SelectedText() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEnginePage_SelectedText(ptr.Pointer()))
	}
	return ""
}

//export callbackQWebEnginePage_SelectionChanged
func callbackQWebEnginePage_SelectionChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "selectionChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

func (ptr *QWebEnginePage) ConnectSelectionChanged(f func()) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "selectionChanged") {
			C.QWebEnginePage_ConnectSelectionChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "selectionChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "selectionChanged"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "selectionChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "selectionChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectSelectionChanged() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectSelectionChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "selectionChanged")
	}
}

func (ptr *QWebEnginePage) SelectionChanged() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_SelectionChanged(ptr.Pointer())
	}
}

func (ptr *QWebEnginePage) SetBackgroundColor(color gui.QColor_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_SetBackgroundColor(ptr.Pointer(), gui.PointerFromQColor(color))
	}
}

func (ptr *QWebEnginePage) SetContent(data core.QByteArray_ITF, mimeType string, baseUrl core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		var mimeTypeC *C.char
		if mimeType != "" {
			mimeTypeC = C.CString(mimeType)
			defer C.free(unsafe.Pointer(mimeTypeC))
		}
		C.QWebEnginePage_SetContent(ptr.Pointer(), core.PointerFromQByteArray(data), C.struct_QtWebEngine_PackedString{data: mimeTypeC, len: C.longlong(len(mimeType))}, core.PointerFromQUrl(baseUrl))
	}
}

func (ptr *QWebEnginePage) SetHtml(html string, baseUrl core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		var htmlC *C.char
		if html != "" {
			htmlC = C.CString(html)
			defer C.free(unsafe.Pointer(htmlC))
		}
		C.QWebEnginePage_SetHtml(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: htmlC, len: C.longlong(len(html))}, core.PointerFromQUrl(baseUrl))
	}
}

func (ptr *QWebEnginePage) SetUrl(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_SetUrl(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEnginePage) SetView(view widgets.QWidget_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_SetView(ptr.Pointer(), widgets.PointerFromQWidget(view))
	}
}

func (ptr *QWebEnginePage) Settings() *QWebEngineSettings {
	if ptr.Pointer() != nil {
		return NewQWebEngineSettingsFromPointer(C.QWebEnginePage_Settings(ptr.Pointer()))
	}
	return nil
}

func (ptr *QWebEnginePage) Title() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEnginePage_Title(ptr.Pointer()))
	}
	return ""
}

//export callbackQWebEnginePage_TitleChanged
func callbackQWebEnginePage_TitleChanged(ptr unsafe.Pointer, title C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "titleChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(title))
	}

}

func (ptr *QWebEnginePage) ConnectTitleChanged(f func(title string)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "titleChanged") {
			C.QWebEnginePage_ConnectTitleChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "titleChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "titleChanged"); signal != nil {
			f := func(title string) {
				(*(*func(string))(signal))(title)
				f(title)
			}
			qt.ConnectSignal(ptr.Pointer(), "titleChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "titleChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectTitleChanged() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectTitleChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "titleChanged")
	}
}

func (ptr *QWebEnginePage) TitleChanged(title string) {
	if ptr.Pointer() != nil {
		var titleC *C.char
		if title != "" {
			titleC = C.CString(title)
			defer C.free(unsafe.Pointer(titleC))
		}
		C.QWebEnginePage_TitleChanged(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: titleC, len: C.longlong(len(title))})
	}
}

func QWebEnginePage_Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEnginePage_QWebEnginePage_Tr(sC, cC, C.int(int32(n))))
}

func (ptr *QWebEnginePage) Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEnginePage_QWebEnginePage_Tr(sC, cC, C.int(int32(n))))
}

//export callbackQWebEnginePage_TriggerAction
func callbackQWebEnginePage_TriggerAction(ptr unsafe.Pointer, action C.longlong, checked C.char) {
	if signal := qt.GetSignal(ptr, "triggerAction"); signal != nil {
		(*(*func(QWebEnginePage__WebAction, bool))(signal))(QWebEnginePage__WebAction(action), int8(checked) != 0)
	} else {
		NewQWebEnginePageFromPointer(ptr).TriggerActionDefault(QWebEnginePage__WebAction(action), int8(checked) != 0)
	}
}

func (ptr *QWebEnginePage) ConnectTriggerAction(f func(action QWebEnginePage__WebAction, checked bool)) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "triggerAction"); signal != nil {
			f := func(action QWebEnginePage__WebAction, checked bool) {
				(*(*func(QWebEnginePage__WebAction, bool))(signal))(action, checked)
				f(action, checked)
			}
			qt.ConnectSignal(ptr.Pointer(), "triggerAction", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "triggerAction", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectTriggerAction() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "triggerAction")
	}
}

func (ptr *QWebEnginePage) TriggerAction(action QWebEnginePage__WebAction, checked bool) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_TriggerAction(ptr.Pointer(), C.longlong(action), C.char(int8(qt.GoBoolToInt(checked))))
	}
}

func (ptr *QWebEnginePage) TriggerActionDefault(action QWebEnginePage__WebAction, checked bool) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_TriggerActionDefault(ptr.Pointer(), C.longlong(action), C.char(int8(qt.GoBoolToInt(checked))))
	}
}

func (ptr *QWebEnginePage) Url() *core.QUrl {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQUrlFromPointer(C.QWebEnginePage_Url(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*core.QUrl).DestroyQUrl)
		return tmpValue
	}
	return nil
}

//export callbackQWebEnginePage_UrlChanged
func callbackQWebEnginePage_UrlChanged(ptr unsafe.Pointer, url unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "urlChanged"); signal != nil {
		(*(*func(*core.QUrl))(signal))(core.NewQUrlFromPointer(url))
	}

}

func (ptr *QWebEnginePage) ConnectUrlChanged(f func(url *core.QUrl)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "urlChanged") {
			C.QWebEnginePage_ConnectUrlChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "urlChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "urlChanged"); signal != nil {
			f := func(url *core.QUrl) {
				(*(*func(*core.QUrl))(signal))(url)
				f(url)
			}
			qt.ConnectSignal(ptr.Pointer(), "urlChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "urlChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectUrlChanged() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectUrlChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "urlChanged")
	}
}

func (ptr *QWebEnginePage) UrlChanged(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_UrlChanged(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEnginePage) View() *widgets.QWidget {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQWidgetFromPointer(C.QWebEnginePage_View(ptr.Pointer()))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

//export callbackQWebEnginePage_DestroyQWebEnginePage
func callbackQWebEnginePage_DestroyQWebEnginePage(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "~QWebEnginePage"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEnginePageFromPointer(ptr).DestroyQWebEnginePageDefault()
	}
}

func (ptr *QWebEnginePage) ConnectDestroyQWebEnginePage(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "~QWebEnginePage"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "~QWebEnginePage", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "~QWebEnginePage", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEnginePage) DisconnectDestroyQWebEnginePage() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "~QWebEnginePage")
	}
}

func (ptr *QWebEnginePage) DestroyQWebEnginePage() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DestroyQWebEnginePage(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEnginePage) DestroyQWebEnginePageDefault() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DestroyQWebEnginePageDefault(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEnginePage) __dynamicPropertyNames_atList(i int) *core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQByteArrayFromPointer(C.QWebEnginePage___dynamicPropertyNames_atList(ptr.Pointer(), C.int(int32(i))))
		runtime.SetFinalizer(tmpValue, (*core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) __dynamicPropertyNames_setList(i core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage___dynamicPropertyNames_setList(ptr.Pointer(), core.PointerFromQByteArray(i))
	}
}

func (ptr *QWebEnginePage) __dynamicPropertyNames_newList() unsafe.Pointer {
	return C.QWebEnginePage___dynamicPropertyNames_newList(ptr.Pointer())
}

func (ptr *QWebEnginePage) __findChildren_atList2(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEnginePage___findChildren_atList2(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) __findChildren_setList2(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage___findChildren_setList2(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEnginePage) __findChildren_newList2() unsafe.Pointer {
	return C.QWebEnginePage___findChildren_newList2(ptr.Pointer())
}

func (ptr *QWebEnginePage) __findChildren_atList3(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEnginePage___findChildren_atList3(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) __findChildren_setList3(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage___findChildren_setList3(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEnginePage) __findChildren_newList3() unsafe.Pointer {
	return C.QWebEnginePage___findChildren_newList3(ptr.Pointer())
}

func (ptr *QWebEnginePage) __findChildren_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEnginePage___findChildren_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) __findChildren_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage___findChildren_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEnginePage) __findChildren_newList() unsafe.Pointer {
	return C.QWebEnginePage___findChildren_newList(ptr.Pointer())
}

func (ptr *QWebEnginePage) __children_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEnginePage___children_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEnginePage) __children_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage___children_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEnginePage) __children_newList() unsafe.Pointer {
	return C.QWebEnginePage___children_newList(ptr.Pointer())
}

//export callbackQWebEnginePage_EventFilter
func callbackQWebEnginePage_EventFilter(ptr unsafe.Pointer, watched unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "eventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QObject, *core.QEvent) bool)(signal))(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEnginePageFromPointer(ptr).EventFilterDefault(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
}

func (ptr *QWebEnginePage) EventFilterDefault(watched core.QObject_ITF, event core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEnginePage_EventFilterDefault(ptr.Pointer(), core.PointerFromQObject(watched), core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackQWebEnginePage_ChildEvent
func callbackQWebEnginePage_ChildEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "childEvent"); signal != nil {
		(*(*func(*core.QChildEvent))(signal))(core.NewQChildEventFromPointer(event))
	} else {
		NewQWebEnginePageFromPointer(ptr).ChildEventDefault(core.NewQChildEventFromPointer(event))
	}
}

func (ptr *QWebEnginePage) ChildEventDefault(event core.QChildEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_ChildEventDefault(ptr.Pointer(), core.PointerFromQChildEvent(event))
	}
}

//export callbackQWebEnginePage_ConnectNotify
func callbackQWebEnginePage_ConnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "connectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEnginePageFromPointer(ptr).ConnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEnginePage) ConnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_ConnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEnginePage_CustomEvent
func callbackQWebEnginePage_CustomEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEnginePageFromPointer(ptr).CustomEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEnginePage) CustomEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_CustomEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEnginePage_DeleteLater
func callbackQWebEnginePage_DeleteLater(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "deleteLater"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEnginePageFromPointer(ptr).DeleteLaterDefault()
	}
}

func (ptr *QWebEnginePage) DeleteLaterDefault() {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DeleteLaterDefault(ptr.Pointer())
		runtime.SetFinalizer(ptr, nil)
	}
}

//export callbackQWebEnginePage_Destroyed
func callbackQWebEnginePage_Destroyed(ptr unsafe.Pointer, obj unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "destroyed"); signal != nil {
		(*(*func(*core.QObject))(signal))(core.NewQObjectFromPointer(obj))
	}

}

//export callbackQWebEnginePage_DisconnectNotify
func callbackQWebEnginePage_DisconnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "disconnectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEnginePageFromPointer(ptr).DisconnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEnginePage) DisconnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_DisconnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEnginePage_ObjectNameChanged
func callbackQWebEnginePage_ObjectNameChanged(ptr unsafe.Pointer, objectName C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "objectNameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(objectName))
	}

}

//export callbackQWebEnginePage_TimerEvent
func callbackQWebEnginePage_TimerEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "timerEvent"); signal != nil {
		(*(*func(*core.QTimerEvent))(signal))(core.NewQTimerEventFromPointer(event))
	} else {
		NewQWebEnginePageFromPointer(ptr).TimerEventDefault(core.NewQTimerEventFromPointer(event))
	}
}

func (ptr *QWebEnginePage) TimerEventDefault(event core.QTimerEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEnginePage_TimerEventDefault(ptr.Pointer(), core.PointerFromQTimerEvent(event))
	}
}

type QWebEngineProfile struct {
	core.QObject
}

type QWebEngineProfile_ITF interface {
	core.QObject_ITF
	QWebEngineProfile_PTR() *QWebEngineProfile
}

func (ptr *QWebEngineProfile) QWebEngineProfile_PTR() *QWebEngineProfile {
	return ptr
}

func (ptr *QWebEngineProfile) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.QObject_PTR().Pointer()
	}
	return nil
}

func (ptr *QWebEngineProfile) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.QObject_PTR().SetPointer(p)
	}
}

func PointerFromQWebEngineProfile(ptr QWebEngineProfile_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.QWebEngineProfile_PTR().Pointer()
	}
	return nil
}

func NewQWebEngineProfileFromPointer(ptr unsafe.Pointer) (n *QWebEngineProfile) {
	n = new(QWebEngineProfile)
	n.SetPointer(ptr)
	return
}

//go:generate stringer -type=QWebEngineProfile__HttpCacheType
//QWebEngineProfile::HttpCacheType
type QWebEngineProfile__HttpCacheType int64

const (
	QWebEngineProfile__MemoryHttpCache QWebEngineProfile__HttpCacheType = QWebEngineProfile__HttpCacheType(0)
	QWebEngineProfile__DiskHttpCache   QWebEngineProfile__HttpCacheType = QWebEngineProfile__HttpCacheType(1)
	QWebEngineProfile__NoCache         QWebEngineProfile__HttpCacheType = QWebEngineProfile__HttpCacheType(2)
)

//go:generate stringer -type=QWebEngineProfile__PersistentCookiesPolicy
//QWebEngineProfile::PersistentCookiesPolicy
type QWebEngineProfile__PersistentCookiesPolicy int64

const (
	QWebEngineProfile__NoPersistentCookies    QWebEngineProfile__PersistentCookiesPolicy = QWebEngineProfile__PersistentCookiesPolicy(0)
	QWebEngineProfile__AllowPersistentCookies QWebEngineProfile__PersistentCookiesPolicy = QWebEngineProfile__PersistentCookiesPolicy(1)
	QWebEngineProfile__ForcePersistentCookies QWebEngineProfile__PersistentCookiesPolicy = QWebEngineProfile__PersistentCookiesPolicy(2)
)

func NewQWebEngineProfile(parent core.QObject_ITF) *QWebEngineProfile {
	tmpValue := NewQWebEngineProfileFromPointer(C.QWebEngineProfile_NewQWebEngineProfile(core.PointerFromQObject(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

func NewQWebEngineProfile2(name string, parent core.QObject_ITF) *QWebEngineProfile {
	var nameC *C.char
	if name != "" {
		nameC = C.CString(name)
		defer C.free(unsafe.Pointer(nameC))
	}
	tmpValue := NewQWebEngineProfileFromPointer(C.QWebEngineProfile_NewQWebEngineProfile2(C.struct_QtWebEngine_PackedString{data: nameC, len: C.longlong(len(name))}, core.PointerFromQObject(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

//export callbackQWebEngineProfile_MetaObject
func callbackQWebEngineProfile_MetaObject(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "metaObject"); signal != nil {
		return core.PointerFromQMetaObject((*(*func() *core.QMetaObject)(signal))())
	}

	return core.PointerFromQMetaObject(NewQWebEngineProfileFromPointer(ptr).MetaObjectDefault())
}

func (ptr *QWebEngineProfile) MetaObjectDefault() *core.QMetaObject {
	if ptr.Pointer() != nil {
		return core.NewQMetaObjectFromPointer(C.QWebEngineProfile_MetaObjectDefault(ptr.Pointer()))
	}
	return nil
}

func (ptr *QWebEngineProfile) Settings() *QWebEngineSettings {
	if ptr.Pointer() != nil {
		return NewQWebEngineSettingsFromPointer(C.QWebEngineProfile_Settings(ptr.Pointer()))
	}
	return nil
}

func QWebEngineProfile_Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEngineProfile_QWebEngineProfile_Tr(sC, cC, C.int(int32(n))))
}

func (ptr *QWebEngineProfile) Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEngineProfile_QWebEngineProfile_Tr(sC, cC, C.int(int32(n))))
}

//export callbackQWebEngineProfile_DestroyQWebEngineProfile
func callbackQWebEngineProfile_DestroyQWebEngineProfile(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "~QWebEngineProfile"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineProfileFromPointer(ptr).DestroyQWebEngineProfileDefault()
	}
}

func (ptr *QWebEngineProfile) ConnectDestroyQWebEngineProfile(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "~QWebEngineProfile"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "~QWebEngineProfile", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "~QWebEngineProfile", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineProfile) DisconnectDestroyQWebEngineProfile() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "~QWebEngineProfile")
	}
}

func (ptr *QWebEngineProfile) DestroyQWebEngineProfile() {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_DestroyQWebEngineProfile(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEngineProfile) DestroyQWebEngineProfileDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_DestroyQWebEngineProfileDefault(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEngineProfile) __clearVisitedLinks_urls_atList(i int) *core.QUrl {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQUrlFromPointer(C.QWebEngineProfile___clearVisitedLinks_urls_atList(ptr.Pointer(), C.int(int32(i))))
		runtime.SetFinalizer(tmpValue, (*core.QUrl).DestroyQUrl)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __clearVisitedLinks_urls_setList(i core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___clearVisitedLinks_urls_setList(ptr.Pointer(), core.PointerFromQUrl(i))
	}
}

func (ptr *QWebEngineProfile) __clearVisitedLinks_urls_newList() unsafe.Pointer {
	return C.QWebEngineProfile___clearVisitedLinks_urls_newList(ptr.Pointer())
}

func (ptr *QWebEngineProfile) __dynamicPropertyNames_atList(i int) *core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQByteArrayFromPointer(C.QWebEngineProfile___dynamicPropertyNames_atList(ptr.Pointer(), C.int(int32(i))))
		runtime.SetFinalizer(tmpValue, (*core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __dynamicPropertyNames_setList(i core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___dynamicPropertyNames_setList(ptr.Pointer(), core.PointerFromQByteArray(i))
	}
}

func (ptr *QWebEngineProfile) __dynamicPropertyNames_newList() unsafe.Pointer {
	return C.QWebEngineProfile___dynamicPropertyNames_newList(ptr.Pointer())
}

func (ptr *QWebEngineProfile) __findChildren_atList2(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineProfile___findChildren_atList2(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __findChildren_setList2(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___findChildren_setList2(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineProfile) __findChildren_newList2() unsafe.Pointer {
	return C.QWebEngineProfile___findChildren_newList2(ptr.Pointer())
}

func (ptr *QWebEngineProfile) __findChildren_atList3(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineProfile___findChildren_atList3(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __findChildren_setList3(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___findChildren_setList3(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineProfile) __findChildren_newList3() unsafe.Pointer {
	return C.QWebEngineProfile___findChildren_newList3(ptr.Pointer())
}

func (ptr *QWebEngineProfile) __findChildren_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineProfile___findChildren_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __findChildren_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___findChildren_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineProfile) __findChildren_newList() unsafe.Pointer {
	return C.QWebEngineProfile___findChildren_newList(ptr.Pointer())
}

func (ptr *QWebEngineProfile) __children_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineProfile___children_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineProfile) __children_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile___children_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineProfile) __children_newList() unsafe.Pointer {
	return C.QWebEngineProfile___children_newList(ptr.Pointer())
}

//export callbackQWebEngineProfile_Event
func callbackQWebEngineProfile_Event(ptr unsafe.Pointer, e unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "event"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QEvent) bool)(signal))(core.NewQEventFromPointer(e)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineProfileFromPointer(ptr).EventDefault(core.NewQEventFromPointer(e)))))
}

func (ptr *QWebEngineProfile) EventDefault(e core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineProfile_EventDefault(ptr.Pointer(), core.PointerFromQEvent(e))) != 0
	}
	return false
}

//export callbackQWebEngineProfile_EventFilter
func callbackQWebEngineProfile_EventFilter(ptr unsafe.Pointer, watched unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "eventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QObject, *core.QEvent) bool)(signal))(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineProfileFromPointer(ptr).EventFilterDefault(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
}

func (ptr *QWebEngineProfile) EventFilterDefault(watched core.QObject_ITF, event core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineProfile_EventFilterDefault(ptr.Pointer(), core.PointerFromQObject(watched), core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackQWebEngineProfile_ChildEvent
func callbackQWebEngineProfile_ChildEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "childEvent"); signal != nil {
		(*(*func(*core.QChildEvent))(signal))(core.NewQChildEventFromPointer(event))
	} else {
		NewQWebEngineProfileFromPointer(ptr).ChildEventDefault(core.NewQChildEventFromPointer(event))
	}
}

func (ptr *QWebEngineProfile) ChildEventDefault(event core.QChildEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_ChildEventDefault(ptr.Pointer(), core.PointerFromQChildEvent(event))
	}
}

//export callbackQWebEngineProfile_ConnectNotify
func callbackQWebEngineProfile_ConnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "connectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEngineProfileFromPointer(ptr).ConnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEngineProfile) ConnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_ConnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEngineProfile_CustomEvent
func callbackQWebEngineProfile_CustomEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEngineProfileFromPointer(ptr).CustomEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEngineProfile) CustomEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_CustomEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEngineProfile_DeleteLater
func callbackQWebEngineProfile_DeleteLater(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "deleteLater"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineProfileFromPointer(ptr).DeleteLaterDefault()
	}
}

func (ptr *QWebEngineProfile) DeleteLaterDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_DeleteLaterDefault(ptr.Pointer())
		runtime.SetFinalizer(ptr, nil)
	}
}

//export callbackQWebEngineProfile_Destroyed
func callbackQWebEngineProfile_Destroyed(ptr unsafe.Pointer, obj unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "destroyed"); signal != nil {
		(*(*func(*core.QObject))(signal))(core.NewQObjectFromPointer(obj))
	}

}

//export callbackQWebEngineProfile_DisconnectNotify
func callbackQWebEngineProfile_DisconnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "disconnectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEngineProfileFromPointer(ptr).DisconnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEngineProfile) DisconnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_DisconnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEngineProfile_ObjectNameChanged
func callbackQWebEngineProfile_ObjectNameChanged(ptr unsafe.Pointer, objectName C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "objectNameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(objectName))
	}

}

//export callbackQWebEngineProfile_TimerEvent
func callbackQWebEngineProfile_TimerEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "timerEvent"); signal != nil {
		(*(*func(*core.QTimerEvent))(signal))(core.NewQTimerEventFromPointer(event))
	} else {
		NewQWebEngineProfileFromPointer(ptr).TimerEventDefault(core.NewQTimerEventFromPointer(event))
	}
}

func (ptr *QWebEngineProfile) TimerEventDefault(event core.QTimerEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineProfile_TimerEventDefault(ptr.Pointer(), core.PointerFromQTimerEvent(event))
	}
}

//go:generate stringer -type=QWebEngineScript__InjectionPoint
//QWebEngineScript::InjectionPoint
type QWebEngineScript__InjectionPoint int64

const (
	QWebEngineScript__Deferred         QWebEngineScript__InjectionPoint = QWebEngineScript__InjectionPoint(0)
	QWebEngineScript__DocumentReady    QWebEngineScript__InjectionPoint = QWebEngineScript__InjectionPoint(1)
	QWebEngineScript__DocumentCreation QWebEngineScript__InjectionPoint = QWebEngineScript__InjectionPoint(2)
)

//go:generate stringer -type=QWebEngineScript__ScriptWorldId
//QWebEngineScript::ScriptWorldId
type QWebEngineScript__ScriptWorldId int64

const (
	QWebEngineScript__MainWorld        QWebEngineScript__ScriptWorldId = QWebEngineScript__ScriptWorldId(0)
	QWebEngineScript__ApplicationWorld QWebEngineScript__ScriptWorldId = QWebEngineScript__ScriptWorldId(1)
	QWebEngineScript__UserWorld        QWebEngineScript__ScriptWorldId = QWebEngineScript__ScriptWorldId(2)
)

type QWebEngineSettings struct {
	ptr unsafe.Pointer
}

type QWebEngineSettings_ITF interface {
	QWebEngineSettings_PTR() *QWebEngineSettings
}

func (ptr *QWebEngineSettings) QWebEngineSettings_PTR() *QWebEngineSettings {
	return ptr
}

func (ptr *QWebEngineSettings) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.ptr
	}
	return nil
}

func (ptr *QWebEngineSettings) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.ptr = p
	}
}

func PointerFromQWebEngineSettings(ptr QWebEngineSettings_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.QWebEngineSettings_PTR().Pointer()
	}
	return nil
}

func NewQWebEngineSettingsFromPointer(ptr unsafe.Pointer) (n *QWebEngineSettings) {
	n = new(QWebEngineSettings)
	n.SetPointer(ptr)
	return
}

//go:generate stringer -type=QWebEngineSettings__FontFamily
//QWebEngineSettings::FontFamily
type QWebEngineSettings__FontFamily int64

const (
	QWebEngineSettings__StandardFont   QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(0)
	QWebEngineSettings__FixedFont      QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(1)
	QWebEngineSettings__SerifFont      QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(2)
	QWebEngineSettings__SansSerifFont  QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(3)
	QWebEngineSettings__CursiveFont    QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(4)
	QWebEngineSettings__FantasyFont    QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(5)
	QWebEngineSettings__PictographFont QWebEngineSettings__FontFamily = QWebEngineSettings__FontFamily(6)
)

//go:generate stringer -type=QWebEngineSettings__WebAttribute
//QWebEngineSettings::WebAttribute
type QWebEngineSettings__WebAttribute int64

const (
	QWebEngineSettings__AutoLoadImages                      QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(0)
	QWebEngineSettings__JavascriptEnabled                   QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(1)
	QWebEngineSettings__JavascriptCanOpenWindows            QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(2)
	QWebEngineSettings__JavascriptCanAccessClipboard        QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(3)
	QWebEngineSettings__LinksIncludedInFocusChain           QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(4)
	QWebEngineSettings__LocalStorageEnabled                 QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(5)
	QWebEngineSettings__LocalContentCanAccessRemoteUrls     QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(6)
	QWebEngineSettings__XSSAuditingEnabled                  QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(7)
	QWebEngineSettings__SpatialNavigationEnabled            QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(8)
	QWebEngineSettings__LocalContentCanAccessFileUrls       QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(9)
	QWebEngineSettings__HyperlinkAuditingEnabled            QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(10)
	QWebEngineSettings__ScrollAnimatorEnabled               QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(11)
	QWebEngineSettings__ErrorPageEnabled                    QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(12)
	QWebEngineSettings__PluginsEnabled                      QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(13)
	QWebEngineSettings__FullScreenSupportEnabled            QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(14)
	QWebEngineSettings__ScreenCaptureEnabled                QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(15)
	QWebEngineSettings__WebGLEnabled                        QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(16)
	QWebEngineSettings__Accelerated2dCanvasEnabled          QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(17)
	QWebEngineSettings__AutoLoadIconsForPage                QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(18)
	QWebEngineSettings__TouchIconsEnabled                   QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(19)
	QWebEngineSettings__FocusOnNavigationEnabled            QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(20)
	QWebEngineSettings__PrintElementBackgrounds             QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(21)
	QWebEngineSettings__AllowRunningInsecureContent         QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(22)
	QWebEngineSettings__AllowGeolocationOnInsecureOrigins   QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(23)
	QWebEngineSettings__AllowWindowActivationFromJavaScript QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(24)
	QWebEngineSettings__ShowScrollBars                      QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(25)
	QWebEngineSettings__PlaybackRequiresUserGesture         QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(26)
	QWebEngineSettings__WebRTCPublicInterfacesOnly          QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(27)
	QWebEngineSettings__JavascriptCanPaste                  QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(28)
	QWebEngineSettings__DnsPrefetchEnabled                  QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(29)
	QWebEngineSettings__PdfViewerEnabled                    QWebEngineSettings__WebAttribute = QWebEngineSettings__WebAttribute(30)
)

//go:generate stringer -type=QWebEngineSettings__FontSize
//QWebEngineSettings::FontSize
type QWebEngineSettings__FontSize int64

const (
	QWebEngineSettings__MinimumFontSize        QWebEngineSettings__FontSize = QWebEngineSettings__FontSize(0)
	QWebEngineSettings__MinimumLogicalFontSize QWebEngineSettings__FontSize = QWebEngineSettings__FontSize(1)
	QWebEngineSettings__DefaultFontSize        QWebEngineSettings__FontSize = QWebEngineSettings__FontSize(2)
	QWebEngineSettings__DefaultFixedFontSize   QWebEngineSettings__FontSize = QWebEngineSettings__FontSize(3)
)

//go:generate stringer -type=QWebEngineSettings__UnknownUrlSchemePolicy
//QWebEngineSettings::UnknownUrlSchemePolicy
type QWebEngineSettings__UnknownUrlSchemePolicy int64

const (
	QWebEngineSettings__DisallowUnknownUrlSchemes                 QWebEngineSettings__UnknownUrlSchemePolicy = QWebEngineSettings__UnknownUrlSchemePolicy(1)
	QWebEngineSettings__AllowUnknownUrlSchemesFromUserInteraction QWebEngineSettings__UnknownUrlSchemePolicy = QWebEngineSettings__UnknownUrlSchemePolicy(2)
	QWebEngineSettings__AllowAllUnknownUrlSchemes                 QWebEngineSettings__UnknownUrlSchemePolicy = QWebEngineSettings__UnknownUrlSchemePolicy(3)
)

func NewQWebEngineSettings2(parentSettings QWebEngineSettings_ITF) *QWebEngineSettings {
	tmpValue := NewQWebEngineSettingsFromPointer(C.QWebEngineSettings_NewQWebEngineSettings2(PointerFromQWebEngineSettings(parentSettings)))
	runtime.SetFinalizer(tmpValue, (*QWebEngineSettings).DestroyQWebEngineSettings)
	return tmpValue
}

func (ptr *QWebEngineSettings) FontFamily(which QWebEngineSettings__FontFamily) string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEngineSettings_FontFamily(ptr.Pointer(), C.longlong(which)))
	}
	return ""
}

func (ptr *QWebEngineSettings) FontSize(ty QWebEngineSettings__FontSize) int {
	if ptr.Pointer() != nil {
		return int(int32(C.QWebEngineSettings_FontSize(ptr.Pointer(), C.longlong(ty))))
	}
	return 0
}

func (ptr *QWebEngineSettings) SetAttribute(attr QWebEngineSettings__WebAttribute, on bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineSettings_SetAttribute(ptr.Pointer(), C.longlong(attr), C.char(int8(qt.GoBoolToInt(on))))
	}
}

func (ptr *QWebEngineSettings) SetFontFamily(which QWebEngineSettings__FontFamily, family string) {
	if ptr.Pointer() != nil {
		var familyC *C.char
		if family != "" {
			familyC = C.CString(family)
			defer C.free(unsafe.Pointer(familyC))
		}
		C.QWebEngineSettings_SetFontFamily(ptr.Pointer(), C.longlong(which), C.struct_QtWebEngine_PackedString{data: familyC, len: C.longlong(len(family))})
	}
}

func (ptr *QWebEngineSettings) TestAttribute(attr QWebEngineSettings__WebAttribute) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineSettings_TestAttribute(ptr.Pointer(), C.longlong(attr))) != 0
	}
	return false
}

func (ptr *QWebEngineSettings) DestroyQWebEngineSettings() {
	if ptr.Pointer() != nil {
		C.QWebEngineSettings_DestroyQWebEngineSettings(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

//go:generate stringer -type=QWebEngineUrlRequestInfo__ResourceType
//QWebEngineUrlRequestInfo::ResourceType
type QWebEngineUrlRequestInfo__ResourceType int64

const (
	QWebEngineUrlRequestInfo__ResourceTypeMainFrame      QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(0)
	QWebEngineUrlRequestInfo__ResourceTypeSubFrame       QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(1)
	QWebEngineUrlRequestInfo__ResourceTypeStylesheet     QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(2)
	QWebEngineUrlRequestInfo__ResourceTypeScript         QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(3)
	QWebEngineUrlRequestInfo__ResourceTypeImage          QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(4)
	QWebEngineUrlRequestInfo__ResourceTypeFontResource   QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(5)
	QWebEngineUrlRequestInfo__ResourceTypeSubResource    QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(6)
	QWebEngineUrlRequestInfo__ResourceTypeObject         QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(7)
	QWebEngineUrlRequestInfo__ResourceTypeMedia          QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(8)
	QWebEngineUrlRequestInfo__ResourceTypeWorker         QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(9)
	QWebEngineUrlRequestInfo__ResourceTypeSharedWorker   QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(10)
	QWebEngineUrlRequestInfo__ResourceTypePrefetch       QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(11)
	QWebEngineUrlRequestInfo__ResourceTypeFavicon        QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(12)
	QWebEngineUrlRequestInfo__ResourceTypeXhr            QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(13)
	QWebEngineUrlRequestInfo__ResourceTypePing           QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(14)
	QWebEngineUrlRequestInfo__ResourceTypeServiceWorker  QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(15)
	QWebEngineUrlRequestInfo__ResourceTypeCspReport      QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(16)
	QWebEngineUrlRequestInfo__ResourceTypePluginResource QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(17)
	QWebEngineUrlRequestInfo__ResourceTypeUnknown        QWebEngineUrlRequestInfo__ResourceType = QWebEngineUrlRequestInfo__ResourceType(255)
)

//go:generate stringer -type=QWebEngineUrlRequestInfo__NavigationType
//QWebEngineUrlRequestInfo::NavigationType
type QWebEngineUrlRequestInfo__NavigationType int64

const (
	QWebEngineUrlRequestInfo__NavigationTypeLink          QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(0)
	QWebEngineUrlRequestInfo__NavigationTypeTyped         QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(1)
	QWebEngineUrlRequestInfo__NavigationTypeFormSubmitted QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(2)
	QWebEngineUrlRequestInfo__NavigationTypeBackForward   QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(3)
	QWebEngineUrlRequestInfo__NavigationTypeReload        QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(4)
	QWebEngineUrlRequestInfo__NavigationTypeOther         QWebEngineUrlRequestInfo__NavigationType = QWebEngineUrlRequestInfo__NavigationType(5)
)

//go:generate stringer -type=QWebEngineUrlRequestJob__Error
//QWebEngineUrlRequestJob::Error
type QWebEngineUrlRequestJob__Error int64

const (
	QWebEngineUrlRequestJob__NoError        QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(0)
	QWebEngineUrlRequestJob__UrlNotFound    QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(1)
	QWebEngineUrlRequestJob__UrlInvalid     QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(2)
	QWebEngineUrlRequestJob__RequestAborted QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(3)
	QWebEngineUrlRequestJob__RequestDenied  QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(4)
	QWebEngineUrlRequestJob__RequestFailed  QWebEngineUrlRequestJob__Error = QWebEngineUrlRequestJob__Error(5)
)

//go:generate stringer -type=QWebEngineUrlScheme__Syntax
//QWebEngineUrlScheme::Syntax
type QWebEngineUrlScheme__Syntax int64

const (
	QWebEngineUrlScheme__HostPortAndUserInformation QWebEngineUrlScheme__Syntax = QWebEngineUrlScheme__Syntax(0)
	QWebEngineUrlScheme__HostAndPort                QWebEngineUrlScheme__Syntax = QWebEngineUrlScheme__Syntax(1)
	QWebEngineUrlScheme__Host                       QWebEngineUrlScheme__Syntax = QWebEngineUrlScheme__Syntax(2)
	QWebEngineUrlScheme__Path                       QWebEngineUrlScheme__Syntax = QWebEngineUrlScheme__Syntax(3)
)

//go:generate stringer -type=QWebEngineUrlScheme__SpecialPort
//QWebEngineUrlScheme::SpecialPort
type QWebEngineUrlScheme__SpecialPort int64

const (
	QWebEngineUrlScheme__PortUnspecified QWebEngineUrlScheme__SpecialPort = QWebEngineUrlScheme__SpecialPort(-1)
)

//go:generate stringer -type=QWebEngineUrlScheme__Flag
//QWebEngineUrlScheme::Flag
type QWebEngineUrlScheme__Flag int64

const (
	QWebEngineUrlScheme__SecureScheme                 QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x1)
	QWebEngineUrlScheme__LocalScheme                  QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x2)
	QWebEngineUrlScheme__LocalAccessAllowed           QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x4)
	QWebEngineUrlScheme__NoAccessAllowed              QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x8)
	QWebEngineUrlScheme__ServiceWorkersAllowed        QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x10)
	QWebEngineUrlScheme__ViewSourceAllowed            QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x20)
	QWebEngineUrlScheme__ContentSecurityPolicyIgnored QWebEngineUrlScheme__Flag = QWebEngineUrlScheme__Flag(0x40)
)

type QWebEngineView struct {
	widgets.QWidget
}

type QWebEngineView_ITF interface {
	widgets.QWidget_ITF
	QWebEngineView_PTR() *QWebEngineView
}

func (ptr *QWebEngineView) QWebEngineView_PTR() *QWebEngineView {
	return ptr
}

func (ptr *QWebEngineView) Pointer() unsafe.Pointer {
	if ptr != nil {
		return ptr.QWidget_PTR().Pointer()
	}
	return nil
}

func (ptr *QWebEngineView) SetPointer(p unsafe.Pointer) {
	if ptr != nil {
		ptr.QWidget_PTR().SetPointer(p)
	}
}

func PointerFromQWebEngineView(ptr QWebEngineView_ITF) unsafe.Pointer {
	if ptr != nil {
		return ptr.QWebEngineView_PTR().Pointer()
	}
	return nil
}

func NewQWebEngineViewFromPointer(ptr unsafe.Pointer) (n *QWebEngineView) {
	n = new(QWebEngineView)
	n.SetPointer(ptr)
	return
}
func NewQWebEngineView(parent widgets.QWidget_ITF) *QWebEngineView {
	tmpValue := NewQWebEngineViewFromPointer(C.QWebEngineView_NewQWebEngineView(widgets.PointerFromQWidget(parent)))
	if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
		tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
	}
	return tmpValue
}

//export callbackQWebEngineView_Back
func callbackQWebEngineView_Back(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "back"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).BackDefault()
	}
}

func (ptr *QWebEngineView) ConnectBack(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "back"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "back", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "back", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectBack() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "back")
	}
}

func (ptr *QWebEngineView) Back() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Back(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) BackDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_BackDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ContextMenuEvent
func callbackQWebEngineView_ContextMenuEvent(ptr unsafe.Pointer, vqc unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "contextMenuEvent"); signal != nil {
		(*(*func(*gui.QContextMenuEvent))(signal))(gui.NewQContextMenuEventFromPointer(vqc))
	} else {
		NewQWebEngineViewFromPointer(ptr).ContextMenuEventDefault(gui.NewQContextMenuEventFromPointer(vqc))
	}
}

func (ptr *QWebEngineView) ContextMenuEventDefault(vqc gui.QContextMenuEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ContextMenuEventDefault(ptr.Pointer(), gui.PointerFromQContextMenuEvent(vqc))
	}
}

//export callbackQWebEngineView_DragEnterEvent
func callbackQWebEngineView_DragEnterEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragEnterEvent"); signal != nil {
		(*(*func(*gui.QDragEnterEvent))(signal))(gui.NewQDragEnterEventFromPointer(e))
	} else {
		NewQWebEngineViewFromPointer(ptr).DragEnterEventDefault(gui.NewQDragEnterEventFromPointer(e))
	}
}

func (ptr *QWebEngineView) DragEnterEventDefault(e gui.QDragEnterEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DragEnterEventDefault(ptr.Pointer(), gui.PointerFromQDragEnterEvent(e))
	}
}

//export callbackQWebEngineView_DragLeaveEvent
func callbackQWebEngineView_DragLeaveEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragLeaveEvent"); signal != nil {
		(*(*func(*gui.QDragLeaveEvent))(signal))(gui.NewQDragLeaveEventFromPointer(e))
	} else {
		NewQWebEngineViewFromPointer(ptr).DragLeaveEventDefault(gui.NewQDragLeaveEventFromPointer(e))
	}
}

func (ptr *QWebEngineView) DragLeaveEventDefault(e gui.QDragLeaveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DragLeaveEventDefault(ptr.Pointer(), gui.PointerFromQDragLeaveEvent(e))
	}
}

//export callbackQWebEngineView_DragMoveEvent
func callbackQWebEngineView_DragMoveEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dragMoveEvent"); signal != nil {
		(*(*func(*gui.QDragMoveEvent))(signal))(gui.NewQDragMoveEventFromPointer(e))
	} else {
		NewQWebEngineViewFromPointer(ptr).DragMoveEventDefault(gui.NewQDragMoveEventFromPointer(e))
	}
}

func (ptr *QWebEngineView) DragMoveEventDefault(e gui.QDragMoveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DragMoveEventDefault(ptr.Pointer(), gui.PointerFromQDragMoveEvent(e))
	}
}

//export callbackQWebEngineView_DropEvent
func callbackQWebEngineView_DropEvent(ptr unsafe.Pointer, e unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "dropEvent"); signal != nil {
		(*(*func(*gui.QDropEvent))(signal))(gui.NewQDropEventFromPointer(e))
	} else {
		NewQWebEngineViewFromPointer(ptr).DropEventDefault(gui.NewQDropEventFromPointer(e))
	}
}

func (ptr *QWebEngineView) DropEventDefault(e gui.QDropEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DropEventDefault(ptr.Pointer(), gui.PointerFromQDropEvent(e))
	}
}

//export callbackQWebEngineView_Event
func callbackQWebEngineView_Event(ptr unsafe.Pointer, vqe unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "event"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QEvent) bool)(signal))(core.NewQEventFromPointer(vqe)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).EventDefault(core.NewQEventFromPointer(vqe)))))
}

func (ptr *QWebEngineView) EventDefault(vqe core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_EventDefault(ptr.Pointer(), core.PointerFromQEvent(vqe))) != 0
	}
	return false
}

//export callbackQWebEngineView_Forward
func callbackQWebEngineView_Forward(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "forward"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ForwardDefault()
	}
}

func (ptr *QWebEngineView) ConnectForward(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "forward"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "forward", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "forward", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectForward() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "forward")
	}
}

func (ptr *QWebEngineView) Forward() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Forward(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) ForwardDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ForwardDefault(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) HasSelection() bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_HasSelection(ptr.Pointer())) != 0
	}
	return false
}

//export callbackQWebEngineView_HideEvent
func callbackQWebEngineView_HideEvent(ptr unsafe.Pointer, vqh unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hideEvent"); signal != nil {
		(*(*func(*gui.QHideEvent))(signal))(gui.NewQHideEventFromPointer(vqh))
	} else {
		NewQWebEngineViewFromPointer(ptr).HideEventDefault(gui.NewQHideEventFromPointer(vqh))
	}
}

func (ptr *QWebEngineView) HideEventDefault(vqh gui.QHideEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_HideEventDefault(ptr.Pointer(), gui.PointerFromQHideEvent(vqh))
	}
}

func (ptr *QWebEngineView) Icon() *gui.QIcon {
	if ptr.Pointer() != nil {
		tmpValue := gui.NewQIconFromPointer(C.QWebEngineView_Icon(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*gui.QIcon).DestroyQIcon)
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_IconChanged
func callbackQWebEngineView_IconChanged(ptr unsafe.Pointer, vqi unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "iconChanged"); signal != nil {
		(*(*func(*gui.QIcon))(signal))(gui.NewQIconFromPointer(vqi))
	}

}

func (ptr *QWebEngineView) ConnectIconChanged(f func(vqi *gui.QIcon)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "iconChanged") {
			C.QWebEngineView_ConnectIconChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "iconChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "iconChanged"); signal != nil {
			f := func(vqi *gui.QIcon) {
				(*(*func(*gui.QIcon))(signal))(vqi)
				f(vqi)
			}
			qt.ConnectSignal(ptr.Pointer(), "iconChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "iconChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectIconChanged() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DisconnectIconChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "iconChanged")
	}
}

func (ptr *QWebEngineView) IconChanged(vqi gui.QIcon_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_IconChanged(ptr.Pointer(), gui.PointerFromQIcon(vqi))
	}
}

func (ptr *QWebEngineView) Load(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Load(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEngineView) Load2(request QWebEngineHttpRequest_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Load2(ptr.Pointer(), PointerFromQWebEngineHttpRequest(request))
	}
}

//export callbackQWebEngineView_MetaObject
func callbackQWebEngineView_MetaObject(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "metaObject"); signal != nil {
		return core.PointerFromQMetaObject((*(*func() *core.QMetaObject)(signal))())
	}

	return core.PointerFromQMetaObject(NewQWebEngineViewFromPointer(ptr).MetaObjectDefault())
}

func (ptr *QWebEngineView) MetaObjectDefault() *core.QMetaObject {
	if ptr.Pointer() != nil {
		return core.NewQMetaObjectFromPointer(C.QWebEngineView_MetaObjectDefault(ptr.Pointer()))
	}
	return nil
}

func (ptr *QWebEngineView) Page() *QWebEnginePage {
	if ptr.Pointer() != nil {
		tmpValue := NewQWebEnginePageFromPointer(C.QWebEngineView_Page(ptr.Pointer()))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_Reload
func callbackQWebEngineView_Reload(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "reload"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ReloadDefault()
	}
}

func (ptr *QWebEngineView) ConnectReload(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "reload"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "reload", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "reload", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectReload() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "reload")
	}
}

func (ptr *QWebEngineView) Reload() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Reload(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) ReloadDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ReloadDefault(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) SelectedText() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEngineView_SelectedText(ptr.Pointer()))
	}
	return ""
}

//export callbackQWebEngineView_SelectionChanged
func callbackQWebEngineView_SelectionChanged(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "selectionChanged"); signal != nil {
		(*(*func())(signal))()
	}

}

func (ptr *QWebEngineView) ConnectSelectionChanged(f func()) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "selectionChanged") {
			C.QWebEngineView_ConnectSelectionChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "selectionChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "selectionChanged"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "selectionChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "selectionChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectSelectionChanged() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DisconnectSelectionChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "selectionChanged")
	}
}

func (ptr *QWebEngineView) SelectionChanged() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SelectionChanged(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) SetContent(data core.QByteArray_ITF, mimeType string, baseUrl core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		var mimeTypeC *C.char
		if mimeType != "" {
			mimeTypeC = C.CString(mimeType)
			defer C.free(unsafe.Pointer(mimeTypeC))
		}
		C.QWebEngineView_SetContent(ptr.Pointer(), core.PointerFromQByteArray(data), C.struct_QtWebEngine_PackedString{data: mimeTypeC, len: C.longlong(len(mimeType))}, core.PointerFromQUrl(baseUrl))
	}
}

func (ptr *QWebEngineView) SetHtml(html string, baseUrl core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		var htmlC *C.char
		if html != "" {
			htmlC = C.CString(html)
			defer C.free(unsafe.Pointer(htmlC))
		}
		C.QWebEngineView_SetHtml(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: htmlC, len: C.longlong(len(html))}, core.PointerFromQUrl(baseUrl))
	}
}

func (ptr *QWebEngineView) SetPage(page QWebEnginePage_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetPage(ptr.Pointer(), PointerFromQWebEnginePage(page))
	}
}

func (ptr *QWebEngineView) SetUrl(url core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetUrl(ptr.Pointer(), core.PointerFromQUrl(url))
	}
}

func (ptr *QWebEngineView) Settings() *QWebEngineSettings {
	if ptr.Pointer() != nil {
		return NewQWebEngineSettingsFromPointer(C.QWebEngineView_Settings(ptr.Pointer()))
	}
	return nil
}

//export callbackQWebEngineView_ShowEvent
func callbackQWebEngineView_ShowEvent(ptr unsafe.Pointer, vqs unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showEvent"); signal != nil {
		(*(*func(*gui.QShowEvent))(signal))(gui.NewQShowEventFromPointer(vqs))
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowEventDefault(gui.NewQShowEventFromPointer(vqs))
	}
}

func (ptr *QWebEngineView) ShowEventDefault(vqs gui.QShowEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowEventDefault(ptr.Pointer(), gui.PointerFromQShowEvent(vqs))
	}
}

//export callbackQWebEngineView_SizeHint
func callbackQWebEngineView_SizeHint(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "sizeHint"); signal != nil {
		return core.PointerFromQSize((*(*func() *core.QSize)(signal))())
	}

	return core.PointerFromQSize(NewQWebEngineViewFromPointer(ptr).SizeHintDefault())
}

func (ptr *QWebEngineView) SizeHintDefault() *core.QSize {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQSizeFromPointer(C.QWebEngineView_SizeHintDefault(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*core.QSize).DestroyQSize)
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_Stop
func callbackQWebEngineView_Stop(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "stop"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).StopDefault()
	}
}

func (ptr *QWebEngineView) ConnectStop(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "stop"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "stop", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "stop", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectStop() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "stop")
	}
}

func (ptr *QWebEngineView) Stop() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_Stop(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) StopDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_StopDefault(ptr.Pointer())
	}
}

func (ptr *QWebEngineView) Title() string {
	if ptr.Pointer() != nil {
		return cGoUnpackString(C.QWebEngineView_Title(ptr.Pointer()))
	}
	return ""
}

//export callbackQWebEngineView_TitleChanged
func callbackQWebEngineView_TitleChanged(ptr unsafe.Pointer, title C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "titleChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(title))
	}

}

func (ptr *QWebEngineView) ConnectTitleChanged(f func(title string)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "titleChanged") {
			C.QWebEngineView_ConnectTitleChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "titleChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "titleChanged"); signal != nil {
			f := func(title string) {
				(*(*func(string))(signal))(title)
				f(title)
			}
			qt.ConnectSignal(ptr.Pointer(), "titleChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "titleChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectTitleChanged() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DisconnectTitleChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "titleChanged")
	}
}

func (ptr *QWebEngineView) TitleChanged(title string) {
	if ptr.Pointer() != nil {
		var titleC *C.char
		if title != "" {
			titleC = C.CString(title)
			defer C.free(unsafe.Pointer(titleC))
		}
		C.QWebEngineView_TitleChanged(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: titleC, len: C.longlong(len(title))})
	}
}

func QWebEngineView_Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEngineView_QWebEngineView_Tr(sC, cC, C.int(int32(n))))
}

func (ptr *QWebEngineView) Tr(s string, c string, n int) string {
	var sC *C.char
	if s != "" {
		sC = C.CString(s)
		defer C.free(unsafe.Pointer(sC))
	}
	var cC *C.char
	if c != "" {
		cC = C.CString(c)
		defer C.free(unsafe.Pointer(cC))
	}
	return cGoUnpackString(C.QWebEngineView_QWebEngineView_Tr(sC, cC, C.int(int32(n))))
}

func (ptr *QWebEngineView) Url() *core.QUrl {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQUrlFromPointer(C.QWebEngineView_Url(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*core.QUrl).DestroyQUrl)
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_UrlChanged
func callbackQWebEngineView_UrlChanged(ptr unsafe.Pointer, vqu unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "urlChanged"); signal != nil {
		(*(*func(*core.QUrl))(signal))(core.NewQUrlFromPointer(vqu))
	}

}

func (ptr *QWebEngineView) ConnectUrlChanged(f func(vqu *core.QUrl)) {
	if ptr.Pointer() != nil {

		if !qt.ExistsSignal(ptr.Pointer(), "urlChanged") {
			C.QWebEngineView_ConnectUrlChanged(ptr.Pointer(), C.longlong(qt.ConnectionType(ptr.Pointer(), "urlChanged")))
		}

		if signal := qt.LendSignal(ptr.Pointer(), "urlChanged"); signal != nil {
			f := func(vqu *core.QUrl) {
				(*(*func(*core.QUrl))(signal))(vqu)
				f(vqu)
			}
			qt.ConnectSignal(ptr.Pointer(), "urlChanged", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "urlChanged", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectUrlChanged() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DisconnectUrlChanged(ptr.Pointer())
		qt.DisconnectSignal(ptr.Pointer(), "urlChanged")
	}
}

func (ptr *QWebEngineView) UrlChanged(vqu core.QUrl_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_UrlChanged(ptr.Pointer(), core.PointerFromQUrl(vqu))
	}
}

//export callbackQWebEngineView_DestroyQWebEngineView
func callbackQWebEngineView_DestroyQWebEngineView(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "~QWebEngineView"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).DestroyQWebEngineViewDefault()
	}
}

func (ptr *QWebEngineView) ConnectDestroyQWebEngineView(f func()) {
	if ptr.Pointer() != nil {

		if signal := qt.LendSignal(ptr.Pointer(), "~QWebEngineView"); signal != nil {
			f := func() {
				(*(*func())(signal))()
				f()
			}
			qt.ConnectSignal(ptr.Pointer(), "~QWebEngineView", unsafe.Pointer(&f))
		} else {
			qt.ConnectSignal(ptr.Pointer(), "~QWebEngineView", unsafe.Pointer(&f))
		}
	}
}

func (ptr *QWebEngineView) DisconnectDestroyQWebEngineView() {
	if ptr.Pointer() != nil {

		qt.DisconnectSignal(ptr.Pointer(), "~QWebEngineView")
	}
}

func (ptr *QWebEngineView) DestroyQWebEngineView() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DestroyQWebEngineView(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEngineView) DestroyQWebEngineViewDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DestroyQWebEngineViewDefault(ptr.Pointer())
		ptr.SetPointer(nil)
		runtime.SetFinalizer(ptr, nil)
	}
}

func (ptr *QWebEngineView) __addActions_actions_atList(i int) *widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQActionFromPointer(C.QWebEngineView___addActions_actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __addActions_actions_setList(i widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___addActions_actions_setList(ptr.Pointer(), widgets.PointerFromQAction(i))
	}
}

func (ptr *QWebEngineView) __addActions_actions_newList() unsafe.Pointer {
	return C.QWebEngineView___addActions_actions_newList(ptr.Pointer())
}

func (ptr *QWebEngineView) __insertActions_actions_atList(i int) *widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQActionFromPointer(C.QWebEngineView___insertActions_actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __insertActions_actions_setList(i widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___insertActions_actions_setList(ptr.Pointer(), widgets.PointerFromQAction(i))
	}
}

func (ptr *QWebEngineView) __insertActions_actions_newList() unsafe.Pointer {
	return C.QWebEngineView___insertActions_actions_newList(ptr.Pointer())
}

func (ptr *QWebEngineView) __actions_atList(i int) *widgets.QAction {
	if ptr.Pointer() != nil {
		tmpValue := widgets.NewQActionFromPointer(C.QWebEngineView___actions_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __actions_setList(i widgets.QAction_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___actions_setList(ptr.Pointer(), widgets.PointerFromQAction(i))
	}
}

func (ptr *QWebEngineView) __actions_newList() unsafe.Pointer {
	return C.QWebEngineView___actions_newList(ptr.Pointer())
}

func (ptr *QWebEngineView) __dynamicPropertyNames_atList(i int) *core.QByteArray {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQByteArrayFromPointer(C.QWebEngineView___dynamicPropertyNames_atList(ptr.Pointer(), C.int(int32(i))))
		runtime.SetFinalizer(tmpValue, (*core.QByteArray).DestroyQByteArray)
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __dynamicPropertyNames_setList(i core.QByteArray_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___dynamicPropertyNames_setList(ptr.Pointer(), core.PointerFromQByteArray(i))
	}
}

func (ptr *QWebEngineView) __dynamicPropertyNames_newList() unsafe.Pointer {
	return C.QWebEngineView___dynamicPropertyNames_newList(ptr.Pointer())
}

func (ptr *QWebEngineView) __findChildren_atList2(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineView___findChildren_atList2(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __findChildren_setList2(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___findChildren_setList2(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineView) __findChildren_newList2() unsafe.Pointer {
	return C.QWebEngineView___findChildren_newList2(ptr.Pointer())
}

func (ptr *QWebEngineView) __findChildren_atList3(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineView___findChildren_atList3(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __findChildren_setList3(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___findChildren_setList3(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineView) __findChildren_newList3() unsafe.Pointer {
	return C.QWebEngineView___findChildren_newList3(ptr.Pointer())
}

func (ptr *QWebEngineView) __findChildren_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineView___findChildren_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __findChildren_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___findChildren_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineView) __findChildren_newList() unsafe.Pointer {
	return C.QWebEngineView___findChildren_newList(ptr.Pointer())
}

func (ptr *QWebEngineView) __children_atList(i int) *core.QObject {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQObjectFromPointer(C.QWebEngineView___children_atList(ptr.Pointer(), C.int(int32(i))))
		if !qt.ExistsSignal(tmpValue.Pointer(), "destroyed") {
			tmpValue.ConnectDestroyed(func(*core.QObject) { tmpValue.SetPointer(nil) })
		}
		return tmpValue
	}
	return nil
}

func (ptr *QWebEngineView) __children_setList(i core.QObject_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView___children_setList(ptr.Pointer(), core.PointerFromQObject(i))
	}
}

func (ptr *QWebEngineView) __children_newList() unsafe.Pointer {
	return C.QWebEngineView___children_newList(ptr.Pointer())
}

//export callbackQWebEngineView_Close
func callbackQWebEngineView_Close(ptr unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "close"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func() bool)(signal))())))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).CloseDefault())))
}

func (ptr *QWebEngineView) CloseDefault() bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_CloseDefault(ptr.Pointer())) != 0
	}
	return false
}

//export callbackQWebEngineView_FocusNextPrevChild
func callbackQWebEngineView_FocusNextPrevChild(ptr unsafe.Pointer, next C.char) C.char {
	if signal := qt.GetSignal(ptr, "focusNextPrevChild"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(bool) bool)(signal))(int8(next) != 0))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).FocusNextPrevChildDefault(int8(next) != 0))))
}

func (ptr *QWebEngineView) FocusNextPrevChildDefault(next bool) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_FocusNextPrevChildDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(next))))) != 0
	}
	return false
}

//export callbackQWebEngineView_NativeEvent
func callbackQWebEngineView_NativeEvent(ptr unsafe.Pointer, eventType unsafe.Pointer, message unsafe.Pointer, result *C.long) C.char {
	var resultR int
	if result != nil {
		resultR = int(int32(*result))
		defer func() { *result = C.long(int32(resultR)) }()
	}
	if signal := qt.GetSignal(ptr, "nativeEvent"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QByteArray, unsafe.Pointer, *int) bool)(signal))(core.NewQByteArrayFromPointer(eventType), message, &resultR))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).NativeEventDefault(core.NewQByteArrayFromPointer(eventType), message, &resultR))))
}

func (ptr *QWebEngineView) NativeEventDefault(eventType core.QByteArray_ITF, message unsafe.Pointer, result *int) bool {
	if ptr.Pointer() != nil {
		var resultC C.long
		if result != nil {
			resultC = C.long(int32(*result))
			defer func() { *result = int(int32(resultC)) }()
		}
		return int8(C.QWebEngineView_NativeEventDefault(ptr.Pointer(), core.PointerFromQByteArray(eventType), message, &resultC)) != 0
	}
	return false
}

//export callbackQWebEngineView_ActionEvent
func callbackQWebEngineView_ActionEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "actionEvent"); signal != nil {
		(*(*func(*gui.QActionEvent))(signal))(gui.NewQActionEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).ActionEventDefault(gui.NewQActionEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) ActionEventDefault(event gui.QActionEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ActionEventDefault(ptr.Pointer(), gui.PointerFromQActionEvent(event))
	}
}

//export callbackQWebEngineView_ChangeEvent
func callbackQWebEngineView_ChangeEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "changeEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).ChangeEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) ChangeEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ChangeEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEngineView_CloseEvent
func callbackQWebEngineView_CloseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "closeEvent"); signal != nil {
		(*(*func(*gui.QCloseEvent))(signal))(gui.NewQCloseEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).CloseEventDefault(gui.NewQCloseEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) CloseEventDefault(event gui.QCloseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_CloseEventDefault(ptr.Pointer(), gui.PointerFromQCloseEvent(event))
	}
}

//export callbackQWebEngineView_CustomContextMenuRequested
func callbackQWebEngineView_CustomContextMenuRequested(ptr unsafe.Pointer, pos unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customContextMenuRequested"); signal != nil {
		(*(*func(*core.QPoint))(signal))(core.NewQPointFromPointer(pos))
	}

}

//export callbackQWebEngineView_EnterEvent
func callbackQWebEngineView_EnterEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "enterEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).EnterEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) EnterEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_EnterEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEngineView_FocusInEvent
func callbackQWebEngineView_FocusInEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusInEvent"); signal != nil {
		(*(*func(*gui.QFocusEvent))(signal))(gui.NewQFocusEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).FocusInEventDefault(gui.NewQFocusEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) FocusInEventDefault(event gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_FocusInEventDefault(ptr.Pointer(), gui.PointerFromQFocusEvent(event))
	}
}

//export callbackQWebEngineView_FocusOutEvent
func callbackQWebEngineView_FocusOutEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "focusOutEvent"); signal != nil {
		(*(*func(*gui.QFocusEvent))(signal))(gui.NewQFocusEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).FocusOutEventDefault(gui.NewQFocusEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) FocusOutEventDefault(event gui.QFocusEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_FocusOutEventDefault(ptr.Pointer(), gui.PointerFromQFocusEvent(event))
	}
}

//export callbackQWebEngineView_Hide
func callbackQWebEngineView_Hide(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "hide"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).HideDefault()
	}
}

func (ptr *QWebEngineView) HideDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_HideDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_InputMethodEvent
func callbackQWebEngineView_InputMethodEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "inputMethodEvent"); signal != nil {
		(*(*func(*gui.QInputMethodEvent))(signal))(gui.NewQInputMethodEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).InputMethodEventDefault(gui.NewQInputMethodEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) InputMethodEventDefault(event gui.QInputMethodEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_InputMethodEventDefault(ptr.Pointer(), gui.PointerFromQInputMethodEvent(event))
	}
}

//export callbackQWebEngineView_KeyPressEvent
func callbackQWebEngineView_KeyPressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyPressEvent"); signal != nil {
		(*(*func(*gui.QKeyEvent))(signal))(gui.NewQKeyEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).KeyPressEventDefault(gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) KeyPressEventDefault(event gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_KeyPressEventDefault(ptr.Pointer(), gui.PointerFromQKeyEvent(event))
	}
}

//export callbackQWebEngineView_KeyReleaseEvent
func callbackQWebEngineView_KeyReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "keyReleaseEvent"); signal != nil {
		(*(*func(*gui.QKeyEvent))(signal))(gui.NewQKeyEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).KeyReleaseEventDefault(gui.NewQKeyEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) KeyReleaseEventDefault(event gui.QKeyEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_KeyReleaseEventDefault(ptr.Pointer(), gui.PointerFromQKeyEvent(event))
	}
}

//export callbackQWebEngineView_LeaveEvent
func callbackQWebEngineView_LeaveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "leaveEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).LeaveEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) LeaveEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_LeaveEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEngineView_Lower
func callbackQWebEngineView_Lower(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "lower"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).LowerDefault()
	}
}

func (ptr *QWebEngineView) LowerDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_LowerDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_MouseDoubleClickEvent
func callbackQWebEngineView_MouseDoubleClickEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseDoubleClickEvent"); signal != nil {
		(*(*func(*gui.QMouseEvent))(signal))(gui.NewQMouseEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).MouseDoubleClickEventDefault(gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) MouseDoubleClickEventDefault(event gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_MouseDoubleClickEventDefault(ptr.Pointer(), gui.PointerFromQMouseEvent(event))
	}
}

//export callbackQWebEngineView_MouseMoveEvent
func callbackQWebEngineView_MouseMoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseMoveEvent"); signal != nil {
		(*(*func(*gui.QMouseEvent))(signal))(gui.NewQMouseEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).MouseMoveEventDefault(gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) MouseMoveEventDefault(event gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_MouseMoveEventDefault(ptr.Pointer(), gui.PointerFromQMouseEvent(event))
	}
}

//export callbackQWebEngineView_MousePressEvent
func callbackQWebEngineView_MousePressEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mousePressEvent"); signal != nil {
		(*(*func(*gui.QMouseEvent))(signal))(gui.NewQMouseEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).MousePressEventDefault(gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) MousePressEventDefault(event gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_MousePressEventDefault(ptr.Pointer(), gui.PointerFromQMouseEvent(event))
	}
}

//export callbackQWebEngineView_MouseReleaseEvent
func callbackQWebEngineView_MouseReleaseEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "mouseReleaseEvent"); signal != nil {
		(*(*func(*gui.QMouseEvent))(signal))(gui.NewQMouseEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).MouseReleaseEventDefault(gui.NewQMouseEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) MouseReleaseEventDefault(event gui.QMouseEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_MouseReleaseEventDefault(ptr.Pointer(), gui.PointerFromQMouseEvent(event))
	}
}

//export callbackQWebEngineView_MoveEvent
func callbackQWebEngineView_MoveEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "moveEvent"); signal != nil {
		(*(*func(*gui.QMoveEvent))(signal))(gui.NewQMoveEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).MoveEventDefault(gui.NewQMoveEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) MoveEventDefault(event gui.QMoveEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_MoveEventDefault(ptr.Pointer(), gui.PointerFromQMoveEvent(event))
	}
}

//export callbackQWebEngineView_PaintEvent
func callbackQWebEngineView_PaintEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "paintEvent"); signal != nil {
		(*(*func(*gui.QPaintEvent))(signal))(gui.NewQPaintEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).PaintEventDefault(gui.NewQPaintEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) PaintEventDefault(event gui.QPaintEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_PaintEventDefault(ptr.Pointer(), gui.PointerFromQPaintEvent(event))
	}
}

//export callbackQWebEngineView_Raise
func callbackQWebEngineView_Raise(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "raise"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).RaiseDefault()
	}
}

func (ptr *QWebEngineView) RaiseDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_RaiseDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_Repaint
func callbackQWebEngineView_Repaint(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "repaint"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).RepaintDefault()
	}
}

func (ptr *QWebEngineView) RepaintDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_RepaintDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ResizeEvent
func callbackQWebEngineView_ResizeEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "resizeEvent"); signal != nil {
		(*(*func(*gui.QResizeEvent))(signal))(gui.NewQResizeEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).ResizeEventDefault(gui.NewQResizeEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) ResizeEventDefault(event gui.QResizeEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ResizeEventDefault(ptr.Pointer(), gui.PointerFromQResizeEvent(event))
	}
}

//export callbackQWebEngineView_SetDisabled
func callbackQWebEngineView_SetDisabled(ptr unsafe.Pointer, disable C.char) {
	if signal := qt.GetSignal(ptr, "setDisabled"); signal != nil {
		(*(*func(bool))(signal))(int8(disable) != 0)
	} else {
		NewQWebEngineViewFromPointer(ptr).SetDisabledDefault(int8(disable) != 0)
	}
}

func (ptr *QWebEngineView) SetDisabledDefault(disable bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetDisabledDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(disable))))
	}
}

//export callbackQWebEngineView_SetEnabled
func callbackQWebEngineView_SetEnabled(ptr unsafe.Pointer, vbo C.char) {
	if signal := qt.GetSignal(ptr, "setEnabled"); signal != nil {
		(*(*func(bool))(signal))(int8(vbo) != 0)
	} else {
		NewQWebEngineViewFromPointer(ptr).SetEnabledDefault(int8(vbo) != 0)
	}
}

func (ptr *QWebEngineView) SetEnabledDefault(vbo bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetEnabledDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(vbo))))
	}
}

//export callbackQWebEngineView_SetFocus2
func callbackQWebEngineView_SetFocus2(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "setFocus2"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).SetFocus2Default()
	}
}

func (ptr *QWebEngineView) SetFocus2Default() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetFocus2Default(ptr.Pointer())
	}
}

//export callbackQWebEngineView_SetHidden
func callbackQWebEngineView_SetHidden(ptr unsafe.Pointer, hidden C.char) {
	if signal := qt.GetSignal(ptr, "setHidden"); signal != nil {
		(*(*func(bool))(signal))(int8(hidden) != 0)
	} else {
		NewQWebEngineViewFromPointer(ptr).SetHiddenDefault(int8(hidden) != 0)
	}
}

func (ptr *QWebEngineView) SetHiddenDefault(hidden bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetHiddenDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(hidden))))
	}
}

//export callbackQWebEngineView_SetStyleSheet
func callbackQWebEngineView_SetStyleSheet(ptr unsafe.Pointer, styleSheet C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "setStyleSheet"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(styleSheet))
	} else {
		NewQWebEngineViewFromPointer(ptr).SetStyleSheetDefault(cGoUnpackString(styleSheet))
	}
}

func (ptr *QWebEngineView) SetStyleSheetDefault(styleSheet string) {
	if ptr.Pointer() != nil {
		var styleSheetC *C.char
		if styleSheet != "" {
			styleSheetC = C.CString(styleSheet)
			defer C.free(unsafe.Pointer(styleSheetC))
		}
		C.QWebEngineView_SetStyleSheetDefault(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: styleSheetC, len: C.longlong(len(styleSheet))})
	}
}

//export callbackQWebEngineView_SetVisible
func callbackQWebEngineView_SetVisible(ptr unsafe.Pointer, visible C.char) {
	if signal := qt.GetSignal(ptr, "setVisible"); signal != nil {
		(*(*func(bool))(signal))(int8(visible) != 0)
	} else {
		NewQWebEngineViewFromPointer(ptr).SetVisibleDefault(int8(visible) != 0)
	}
}

func (ptr *QWebEngineView) SetVisibleDefault(visible bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetVisibleDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(visible))))
	}
}

//export callbackQWebEngineView_SetWindowModified
func callbackQWebEngineView_SetWindowModified(ptr unsafe.Pointer, vbo C.char) {
	if signal := qt.GetSignal(ptr, "setWindowModified"); signal != nil {
		(*(*func(bool))(signal))(int8(vbo) != 0)
	} else {
		NewQWebEngineViewFromPointer(ptr).SetWindowModifiedDefault(int8(vbo) != 0)
	}
}

func (ptr *QWebEngineView) SetWindowModifiedDefault(vbo bool) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_SetWindowModifiedDefault(ptr.Pointer(), C.char(int8(qt.GoBoolToInt(vbo))))
	}
}

//export callbackQWebEngineView_SetWindowTitle
func callbackQWebEngineView_SetWindowTitle(ptr unsafe.Pointer, vqs C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "setWindowTitle"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(vqs))
	} else {
		NewQWebEngineViewFromPointer(ptr).SetWindowTitleDefault(cGoUnpackString(vqs))
	}
}

func (ptr *QWebEngineView) SetWindowTitleDefault(vqs string) {
	if ptr.Pointer() != nil {
		var vqsC *C.char
		if vqs != "" {
			vqsC = C.CString(vqs)
			defer C.free(unsafe.Pointer(vqsC))
		}
		C.QWebEngineView_SetWindowTitleDefault(ptr.Pointer(), C.struct_QtWebEngine_PackedString{data: vqsC, len: C.longlong(len(vqs))})
	}
}

//export callbackQWebEngineView_Show
func callbackQWebEngineView_Show(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "show"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowDefault()
	}
}

func (ptr *QWebEngineView) ShowDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ShowFullScreen
func callbackQWebEngineView_ShowFullScreen(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showFullScreen"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowFullScreenDefault()
	}
}

func (ptr *QWebEngineView) ShowFullScreenDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowFullScreenDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ShowMaximized
func callbackQWebEngineView_ShowMaximized(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showMaximized"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowMaximizedDefault()
	}
}

func (ptr *QWebEngineView) ShowMaximizedDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowMaximizedDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ShowMinimized
func callbackQWebEngineView_ShowMinimized(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showMinimized"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowMinimizedDefault()
	}
}

func (ptr *QWebEngineView) ShowMinimizedDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowMinimizedDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_ShowNormal
func callbackQWebEngineView_ShowNormal(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "showNormal"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).ShowNormalDefault()
	}
}

func (ptr *QWebEngineView) ShowNormalDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ShowNormalDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_TabletEvent
func callbackQWebEngineView_TabletEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "tabletEvent"); signal != nil {
		(*(*func(*gui.QTabletEvent))(signal))(gui.NewQTabletEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).TabletEventDefault(gui.NewQTabletEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) TabletEventDefault(event gui.QTabletEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_TabletEventDefault(ptr.Pointer(), gui.PointerFromQTabletEvent(event))
	}
}

//export callbackQWebEngineView_Update
func callbackQWebEngineView_Update(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "update"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).UpdateDefault()
	}
}

func (ptr *QWebEngineView) UpdateDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_UpdateDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_UpdateMicroFocus
func callbackQWebEngineView_UpdateMicroFocus(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "updateMicroFocus"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).UpdateMicroFocusDefault()
	}
}

func (ptr *QWebEngineView) UpdateMicroFocusDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_UpdateMicroFocusDefault(ptr.Pointer())
	}
}

//export callbackQWebEngineView_WheelEvent
func callbackQWebEngineView_WheelEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "wheelEvent"); signal != nil {
		(*(*func(*gui.QWheelEvent))(signal))(gui.NewQWheelEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).WheelEventDefault(gui.NewQWheelEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) WheelEventDefault(event gui.QWheelEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_WheelEventDefault(ptr.Pointer(), gui.PointerFromQWheelEvent(event))
	}
}

//export callbackQWebEngineView_WindowIconChanged
func callbackQWebEngineView_WindowIconChanged(ptr unsafe.Pointer, icon unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "windowIconChanged"); signal != nil {
		(*(*func(*gui.QIcon))(signal))(gui.NewQIconFromPointer(icon))
	}

}

//export callbackQWebEngineView_WindowTitleChanged
func callbackQWebEngineView_WindowTitleChanged(ptr unsafe.Pointer, title C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "windowTitleChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(title))
	}

}

//export callbackQWebEngineView_PaintEngine
func callbackQWebEngineView_PaintEngine(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "paintEngine"); signal != nil {
		return gui.PointerFromQPaintEngine((*(*func() *gui.QPaintEngine)(signal))())
	}

	return gui.PointerFromQPaintEngine(NewQWebEngineViewFromPointer(ptr).PaintEngineDefault())
}

func (ptr *QWebEngineView) PaintEngineDefault() *gui.QPaintEngine {
	if ptr.Pointer() != nil {
		return gui.NewQPaintEngineFromPointer(C.QWebEngineView_PaintEngineDefault(ptr.Pointer()))
	}
	return nil
}

//export callbackQWebEngineView_MinimumSizeHint
func callbackQWebEngineView_MinimumSizeHint(ptr unsafe.Pointer) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "minimumSizeHint"); signal != nil {
		return core.PointerFromQSize((*(*func() *core.QSize)(signal))())
	}

	return core.PointerFromQSize(NewQWebEngineViewFromPointer(ptr).MinimumSizeHintDefault())
}

func (ptr *QWebEngineView) MinimumSizeHintDefault() *core.QSize {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQSizeFromPointer(C.QWebEngineView_MinimumSizeHintDefault(ptr.Pointer()))
		runtime.SetFinalizer(tmpValue, (*core.QSize).DestroyQSize)
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_InputMethodQuery
func callbackQWebEngineView_InputMethodQuery(ptr unsafe.Pointer, query C.longlong) unsafe.Pointer {
	if signal := qt.GetSignal(ptr, "inputMethodQuery"); signal != nil {
		return core.PointerFromQVariant((*(*func(core.Qt__InputMethodQuery) *core.QVariant)(signal))(core.Qt__InputMethodQuery(query)))
	}

	return core.PointerFromQVariant(NewQWebEngineViewFromPointer(ptr).InputMethodQueryDefault(core.Qt__InputMethodQuery(query)))
}

func (ptr *QWebEngineView) InputMethodQueryDefault(query core.Qt__InputMethodQuery) *core.QVariant {
	if ptr.Pointer() != nil {
		tmpValue := core.NewQVariantFromPointer(C.QWebEngineView_InputMethodQueryDefault(ptr.Pointer(), C.longlong(query)))
		runtime.SetFinalizer(tmpValue, (*core.QVariant).DestroyQVariant)
		return tmpValue
	}
	return nil
}

//export callbackQWebEngineView_HasHeightForWidth
func callbackQWebEngineView_HasHeightForWidth(ptr unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "hasHeightForWidth"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func() bool)(signal))())))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).HasHeightForWidthDefault())))
}

func (ptr *QWebEngineView) HasHeightForWidthDefault() bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_HasHeightForWidthDefault(ptr.Pointer())) != 0
	}
	return false
}

//export callbackQWebEngineView_HeightForWidth
func callbackQWebEngineView_HeightForWidth(ptr unsafe.Pointer, w C.int) C.int {
	if signal := qt.GetSignal(ptr, "heightForWidth"); signal != nil {
		return C.int(int32((*(*func(int) int)(signal))(int(int32(w)))))
	}

	return C.int(int32(NewQWebEngineViewFromPointer(ptr).HeightForWidthDefault(int(int32(w)))))
}

func (ptr *QWebEngineView) HeightForWidthDefault(w int) int {
	if ptr.Pointer() != nil {
		return int(int32(C.QWebEngineView_HeightForWidthDefault(ptr.Pointer(), C.int(int32(w)))))
	}
	return 0
}

//export callbackQWebEngineView_Metric
func callbackQWebEngineView_Metric(ptr unsafe.Pointer, m C.longlong) C.int {
	if signal := qt.GetSignal(ptr, "metric"); signal != nil {
		return C.int(int32((*(*func(gui.QPaintDevice__PaintDeviceMetric) int)(signal))(gui.QPaintDevice__PaintDeviceMetric(m))))
	}

	return C.int(int32(NewQWebEngineViewFromPointer(ptr).MetricDefault(gui.QPaintDevice__PaintDeviceMetric(m))))
}

func (ptr *QWebEngineView) MetricDefault(m gui.QPaintDevice__PaintDeviceMetric) int {
	if ptr.Pointer() != nil {
		return int(int32(C.QWebEngineView_MetricDefault(ptr.Pointer(), C.longlong(m))))
	}
	return 0
}

//export callbackQWebEngineView_InitPainter
func callbackQWebEngineView_InitPainter(ptr unsafe.Pointer, painter unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "initPainter"); signal != nil {
		(*(*func(*gui.QPainter))(signal))(gui.NewQPainterFromPointer(painter))
	} else {
		NewQWebEngineViewFromPointer(ptr).InitPainterDefault(gui.NewQPainterFromPointer(painter))
	}
}

func (ptr *QWebEngineView) InitPainterDefault(painter gui.QPainter_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_InitPainterDefault(ptr.Pointer(), gui.PointerFromQPainter(painter))
	}
}

//export callbackQWebEngineView_EventFilter
func callbackQWebEngineView_EventFilter(ptr unsafe.Pointer, watched unsafe.Pointer, event unsafe.Pointer) C.char {
	if signal := qt.GetSignal(ptr, "eventFilter"); signal != nil {
		return C.char(int8(qt.GoBoolToInt((*(*func(*core.QObject, *core.QEvent) bool)(signal))(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
	}

	return C.char(int8(qt.GoBoolToInt(NewQWebEngineViewFromPointer(ptr).EventFilterDefault(core.NewQObjectFromPointer(watched), core.NewQEventFromPointer(event)))))
}

func (ptr *QWebEngineView) EventFilterDefault(watched core.QObject_ITF, event core.QEvent_ITF) bool {
	if ptr.Pointer() != nil {
		return int8(C.QWebEngineView_EventFilterDefault(ptr.Pointer(), core.PointerFromQObject(watched), core.PointerFromQEvent(event))) != 0
	}
	return false
}

//export callbackQWebEngineView_ChildEvent
func callbackQWebEngineView_ChildEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "childEvent"); signal != nil {
		(*(*func(*core.QChildEvent))(signal))(core.NewQChildEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).ChildEventDefault(core.NewQChildEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) ChildEventDefault(event core.QChildEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ChildEventDefault(ptr.Pointer(), core.PointerFromQChildEvent(event))
	}
}

//export callbackQWebEngineView_ConnectNotify
func callbackQWebEngineView_ConnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "connectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEngineViewFromPointer(ptr).ConnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEngineView) ConnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_ConnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEngineView_CustomEvent
func callbackQWebEngineView_CustomEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "customEvent"); signal != nil {
		(*(*func(*core.QEvent))(signal))(core.NewQEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).CustomEventDefault(core.NewQEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) CustomEventDefault(event core.QEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_CustomEventDefault(ptr.Pointer(), core.PointerFromQEvent(event))
	}
}

//export callbackQWebEngineView_DeleteLater
func callbackQWebEngineView_DeleteLater(ptr unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "deleteLater"); signal != nil {
		(*(*func())(signal))()
	} else {
		NewQWebEngineViewFromPointer(ptr).DeleteLaterDefault()
	}
}

func (ptr *QWebEngineView) DeleteLaterDefault() {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DeleteLaterDefault(ptr.Pointer())
		runtime.SetFinalizer(ptr, nil)
	}
}

//export callbackQWebEngineView_Destroyed
func callbackQWebEngineView_Destroyed(ptr unsafe.Pointer, obj unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "destroyed"); signal != nil {
		(*(*func(*core.QObject))(signal))(core.NewQObjectFromPointer(obj))
	}

}

//export callbackQWebEngineView_DisconnectNotify
func callbackQWebEngineView_DisconnectNotify(ptr unsafe.Pointer, sign unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "disconnectNotify"); signal != nil {
		(*(*func(*core.QMetaMethod))(signal))(core.NewQMetaMethodFromPointer(sign))
	} else {
		NewQWebEngineViewFromPointer(ptr).DisconnectNotifyDefault(core.NewQMetaMethodFromPointer(sign))
	}
}

func (ptr *QWebEngineView) DisconnectNotifyDefault(sign core.QMetaMethod_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_DisconnectNotifyDefault(ptr.Pointer(), core.PointerFromQMetaMethod(sign))
	}
}

//export callbackQWebEngineView_ObjectNameChanged
func callbackQWebEngineView_ObjectNameChanged(ptr unsafe.Pointer, objectName C.struct_QtWebEngine_PackedString) {
	if signal := qt.GetSignal(ptr, "objectNameChanged"); signal != nil {
		(*(*func(string))(signal))(cGoUnpackString(objectName))
	}

}

//export callbackQWebEngineView_TimerEvent
func callbackQWebEngineView_TimerEvent(ptr unsafe.Pointer, event unsafe.Pointer) {
	if signal := qt.GetSignal(ptr, "timerEvent"); signal != nil {
		(*(*func(*core.QTimerEvent))(signal))(core.NewQTimerEventFromPointer(event))
	} else {
		NewQWebEngineViewFromPointer(ptr).TimerEventDefault(core.NewQTimerEventFromPointer(event))
	}
}

func (ptr *QWebEngineView) TimerEventDefault(event core.QTimerEvent_ITF) {
	if ptr.Pointer() != nil {
		C.QWebEngineView_TimerEventDefault(ptr.Pointer(), core.PointerFromQTimerEvent(event))
	}
}
