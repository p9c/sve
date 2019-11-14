// +build minimal

#define protected public
#define private public

#include "webengine-minimal.h"
#include "_cgo_export.h"

#include <QAction>
#include <QActionEvent>
#include <QByteArray>
#include <QChildEvent>
#include <QCloseEvent>
#include <QColor>
#include <QContextMenuEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFocusEvent>
#include <QGraphicsObject>
#include <QGraphicsWidget>
#include <QHideEvent>
#include <QIcon>
#include <QInputMethodEvent>
#include <QKeyEvent>
#include <QLayout>
#include <QMap>
#include <QMetaMethod>
#include <QMetaObject>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QObject>
#include <QPaintDevice>
#include <QPaintEngine>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QPrinter>
#include <QResizeEvent>
#include <QShowEvent>
#include <QSize>
#include <QString>
#include <QTabletEvent>
#include <QTimerEvent>
#include <QUrl>
#include <QVariant>
#include <QVector>
#include <QWebEngineHttpRequest>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QWheelEvent>
#include <QWidget>
#include <QWindow>
#include <QtWebEngine>
#include <QStringList>

Q_DECLARE_METATYPE(QWebEngineHttpRequest*)
void* QWebEngineHttpRequest_NewQWebEngineHttpRequest(void* url, long long method)
{
	return new QWebEngineHttpRequest(*static_cast<QUrl*>(url), static_cast<QWebEngineHttpRequest::Method>(method));
}

void* QWebEngineHttpRequest_NewQWebEngineHttpRequest2(void* other)
{
	return new QWebEngineHttpRequest(*static_cast<QWebEngineHttpRequest*>(other));
}

void* QWebEngineHttpRequest_Header(void* ptr, void* headerName)
{
	return new QByteArray(static_cast<QWebEngineHttpRequest*>(ptr)->header(*static_cast<QByteArray*>(headerName)));
}

struct QtWebEngine_PackedList QWebEngineHttpRequest_Headers(void* ptr)
{
	return ({ QVector<QByteArray>* tmpValue484f93 = new QVector<QByteArray>(static_cast<QWebEngineHttpRequest*>(ptr)->headers()); QtWebEngine_PackedList { tmpValue484f93, tmpValue484f93->size() }; });
}

long long QWebEngineHttpRequest_Method(void* ptr)
{
	return static_cast<QWebEngineHttpRequest*>(ptr)->method();
}

void QWebEngineHttpRequest_SetHeader(void* ptr, void* headerName, void* headerValue)
{
	static_cast<QWebEngineHttpRequest*>(ptr)->setHeader(*static_cast<QByteArray*>(headerName), *static_cast<QByteArray*>(headerValue));
}

void QWebEngineHttpRequest_SetUrl(void* ptr, void* url)
{
	static_cast<QWebEngineHttpRequest*>(ptr)->setUrl(*static_cast<QUrl*>(url));
}

void QWebEngineHttpRequest_Swap(void* ptr, void* other)
{
	static_cast<QWebEngineHttpRequest*>(ptr)->swap(*static_cast<QWebEngineHttpRequest*>(other));
}

void* QWebEngineHttpRequest_Url(void* ptr)
{
	return new QUrl(static_cast<QWebEngineHttpRequest*>(ptr)->url());
}

void QWebEngineHttpRequest_DestroyQWebEngineHttpRequest(void* ptr)
{
	static_cast<QWebEngineHttpRequest*>(ptr)->~QWebEngineHttpRequest();
}

void* QWebEngineHttpRequest___headers_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QVector<QByteArray>*>(ptr)->at(i); if (i == static_cast<QVector<QByteArray>*>(ptr)->size()-1) { static_cast<QVector<QByteArray>*>(ptr)->~QVector(); free(ptr); }; tmp; }));
}

void QWebEngineHttpRequest___headers_setList(void* ptr, void* i)
{
	static_cast<QVector<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QWebEngineHttpRequest___headers_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<QByteArray>();
}

struct QtWebEngine_PackedString QWebEngineHttpRequest___postRequest_postData_atList(void* ptr, struct QtWebEngine_PackedString v, int i)
{
	return ({ QByteArray t1a0c54 = ({ QString tmp = static_cast<QMap<QString, QString>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QMap<QString, QString>*>(ptr)->size()-1) { static_cast<QMap<QString, QString>*>(ptr)->~QMap(); free(ptr); }; tmp; }).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t1a0c54.prepend("WHITESPACE").constData()+10), t1a0c54.size()-10 }; });
}

void QWebEngineHttpRequest___postRequest_postData_setList(void* ptr, struct QtWebEngine_PackedString key, struct QtWebEngine_PackedString i)
{
	static_cast<QMap<QString, QString>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), QString::fromUtf8(i.data, i.len));
}

void* QWebEngineHttpRequest___postRequest_postData_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<QString, QString>();
}

struct QtWebEngine_PackedList QWebEngineHttpRequest___postRequest_postData_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValuebd888a = new QList<QString>(static_cast<QMap<QString, QString>*>(ptr)->keys()); QtWebEngine_PackedList { tmpValuebd888a, tmpValuebd888a->size() }; });
}

struct QtWebEngine_PackedString QWebEngineHttpRequest_____postRequest_postData_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QWebEngineHttpRequest_____postRequest_postData_keyList_setList(void* ptr, struct QtWebEngine_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QWebEngineHttpRequest_____postRequest_postData_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

class MyQWebEnginePage: public QWebEnginePage
{
public:
	MyQWebEnginePage(QObject *parent = Q_NULLPTR) : QWebEnginePage(parent) {QWebEnginePage_QWebEnginePage_QRegisterMetaType();};
	MyQWebEnginePage(QWebEngineProfile *profile, QObject *parent = Q_NULLPTR) : QWebEnginePage(profile, parent) {QWebEnginePage_QWebEnginePage_QRegisterMetaType();};
	QWebEnginePage * createWindow(QWebEnginePage::WebWindowType ty) { return static_cast<QWebEnginePage*>(callbackQWebEnginePage_CreateWindow(this, ty)); };
	bool event(QEvent * vqe) { return callbackQWebEnginePage_Event(this, vqe) != 0; };
	void Signal_IconChanged(const QIcon & icon) { callbackQWebEnginePage_IconChanged(this, const_cast<QIcon*>(&icon)); };
	void Signal_LinkHovered(const QString & url) { QByteArray t817363 = url.toUtf8(); QtWebEngine_PackedString urlPacked = { const_cast<char*>(t817363.prepend("WHITESPACE").constData()+10), t817363.size()-10 };callbackQWebEnginePage_LinkHovered(this, urlPacked); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQWebEnginePage_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	void Signal_SelectionChanged() { callbackQWebEnginePage_SelectionChanged(this); };
	void Signal_TitleChanged(const QString & title) { QByteArray t3c6de1 = title.toUtf8(); QtWebEngine_PackedString titlePacked = { const_cast<char*>(t3c6de1.prepend("WHITESPACE").constData()+10), t3c6de1.size()-10 };callbackQWebEnginePage_TitleChanged(this, titlePacked); };
	void triggerAction(QWebEnginePage::WebAction action, bool checked) { callbackQWebEnginePage_TriggerAction(this, action, checked); };
	void Signal_UrlChanged(const QUrl & url) { callbackQWebEnginePage_UrlChanged(this, const_cast<QUrl*>(&url)); };
	 ~MyQWebEnginePage() { callbackQWebEnginePage_DestroyQWebEnginePage(this); };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQWebEnginePage_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQWebEnginePage_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQWebEnginePage_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQWebEnginePage_CustomEvent(this, event); };
	void deleteLater() { callbackQWebEnginePage_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQWebEnginePage_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQWebEnginePage_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtWebEngine_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQWebEnginePage_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQWebEnginePage_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QWebEnginePage*)
Q_DECLARE_METATYPE(MyQWebEnginePage*)

int QWebEnginePage_QWebEnginePage_QRegisterMetaType(){qRegisterMetaType<QWebEnginePage*>(); return qRegisterMetaType<MyQWebEnginePage*>();}

void* QWebEnginePage_NewQWebEnginePage(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWindow*>(parent));
	} else {
		return new MyQWebEnginePage(static_cast<QObject*>(parent));
	}
}

void* QWebEnginePage_NewQWebEnginePage2(void* profile, void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QWindow*>(parent));
	} else {
		return new MyQWebEnginePage(static_cast<QWebEngineProfile*>(profile), static_cast<QObject*>(parent));
	}
}

void* QWebEnginePage_Action(void* ptr, long long action)
{
	return static_cast<QWebEnginePage*>(ptr)->action(static_cast<QWebEnginePage::WebAction>(action));
}

void* QWebEnginePage_BackgroundColor(void* ptr)
{
	return new QColor(static_cast<QWebEnginePage*>(ptr)->backgroundColor());
}

void* QWebEnginePage_CreateStandardContextMenu(void* ptr)
{
	return static_cast<QWebEnginePage*>(ptr)->createStandardContextMenu();
}

void* QWebEnginePage_CreateWindow(void* ptr, long long ty)
{
	return static_cast<QWebEnginePage*>(ptr)->createWindow(static_cast<QWebEnginePage::WebWindowType>(ty));
}

void* QWebEnginePage_CreateWindowDefault(void* ptr, long long ty)
{
		return static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::createWindow(static_cast<QWebEnginePage::WebWindowType>(ty));
}

void QWebEnginePage_Download(void* ptr, void* url, struct QtWebEngine_PackedString filename)
{
	static_cast<QWebEnginePage*>(ptr)->download(*static_cast<QUrl*>(url), QString::fromUtf8(filename.data, filename.len));
}

char QWebEnginePage_EventDefault(void* ptr, void* vqe)
{
		return static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::event(static_cast<QEvent*>(vqe));
}

char QWebEnginePage_HasSelection(void* ptr)
{
	return static_cast<QWebEnginePage*>(ptr)->hasSelection();
}

void* QWebEnginePage_Icon(void* ptr)
{
	return new QIcon(static_cast<QWebEnginePage*>(ptr)->icon());
}

void QWebEnginePage_ConnectIconChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QIcon &)>(&QWebEnginePage::iconChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QIcon &)>(&MyQWebEnginePage::Signal_IconChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEnginePage_DisconnectIconChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QIcon &)>(&QWebEnginePage::iconChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QIcon &)>(&MyQWebEnginePage::Signal_IconChanged));
}

void QWebEnginePage_IconChanged(void* ptr, void* icon)
{
	static_cast<QWebEnginePage*>(ptr)->iconChanged(*static_cast<QIcon*>(icon));
}

void QWebEnginePage_ConnectLinkHovered(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QString &)>(&QWebEnginePage::linkHovered), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QString &)>(&MyQWebEnginePage::Signal_LinkHovered), static_cast<Qt::ConnectionType>(t));
}

void QWebEnginePage_DisconnectLinkHovered(void* ptr)
{
	QObject::disconnect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QString &)>(&QWebEnginePage::linkHovered), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QString &)>(&MyQWebEnginePage::Signal_LinkHovered));
}

void QWebEnginePage_LinkHovered(void* ptr, struct QtWebEngine_PackedString url)
{
	static_cast<QWebEnginePage*>(ptr)->linkHovered(QString::fromUtf8(url.data, url.len));
}

void QWebEnginePage_Load(void* ptr, void* url)
{
	static_cast<QWebEnginePage*>(ptr)->load(*static_cast<QUrl*>(url));
}

void QWebEnginePage_Load2(void* ptr, void* request)
{
	static_cast<QWebEnginePage*>(ptr)->load(*static_cast<QWebEngineHttpRequest*>(request));
}

void* QWebEnginePage_MetaObjectDefault(void* ptr)
{
		return const_cast<QMetaObject*>(static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::metaObject());
}

void QWebEnginePage_Print(void* ptr, void* printer)
{
	static_cast<QWebEnginePage*>(ptr)->print(static_cast<QPrinter*>(printer), [](bool){});
}

void* QWebEnginePage_Profile(void* ptr)
{
	return static_cast<QWebEnginePage*>(ptr)->profile();
}

void QWebEnginePage_RunJavaScript(void* ptr, struct QtWebEngine_PackedString scriptSource)
{
	static_cast<QWebEnginePage*>(ptr)->runJavaScript(QString::fromUtf8(scriptSource.data, scriptSource.len));
}

void QWebEnginePage_RunJavaScript2(void* ptr, struct QtWebEngine_PackedString scriptSource, unsigned int worldId)
{
	static_cast<QWebEnginePage*>(ptr)->runJavaScript(QString::fromUtf8(scriptSource.data, scriptSource.len), worldId);
}

struct QtWebEngine_PackedString QWebEnginePage_SelectedText(void* ptr)
{
	return ({ QByteArray t729dfc = static_cast<QWebEnginePage*>(ptr)->selectedText().toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t729dfc.prepend("WHITESPACE").constData()+10), t729dfc.size()-10 }; });
}

void QWebEnginePage_ConnectSelectionChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)()>(&QWebEnginePage::selectionChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)()>(&MyQWebEnginePage::Signal_SelectionChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEnginePage_DisconnectSelectionChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)()>(&QWebEnginePage::selectionChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)()>(&MyQWebEnginePage::Signal_SelectionChanged));
}

void QWebEnginePage_SelectionChanged(void* ptr)
{
	static_cast<QWebEnginePage*>(ptr)->selectionChanged();
}

void QWebEnginePage_SetBackgroundColor(void* ptr, void* color)
{
	static_cast<QWebEnginePage*>(ptr)->setBackgroundColor(*static_cast<QColor*>(color));
}

void QWebEnginePage_SetContent(void* ptr, void* data, struct QtWebEngine_PackedString mimeType, void* baseUrl)
{
	static_cast<QWebEnginePage*>(ptr)->setContent(*static_cast<QByteArray*>(data), QString::fromUtf8(mimeType.data, mimeType.len), *static_cast<QUrl*>(baseUrl));
}

void QWebEnginePage_SetHtml(void* ptr, struct QtWebEngine_PackedString html, void* baseUrl)
{
	static_cast<QWebEnginePage*>(ptr)->setHtml(QString::fromUtf8(html.data, html.len), *static_cast<QUrl*>(baseUrl));
}

void QWebEnginePage_SetUrl(void* ptr, void* url)
{
	static_cast<QWebEnginePage*>(ptr)->setUrl(*static_cast<QUrl*>(url));
}

void QWebEnginePage_SetView(void* ptr, void* view)
{
	static_cast<QWebEnginePage*>(ptr)->setView(static_cast<QWidget*>(view));
}

void* QWebEnginePage_Settings(void* ptr)
{
	return static_cast<QWebEnginePage*>(ptr)->settings();
}

struct QtWebEngine_PackedString QWebEnginePage_Title(void* ptr)
{
	return ({ QByteArray t311622 = static_cast<QWebEnginePage*>(ptr)->title().toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t311622.prepend("WHITESPACE").constData()+10), t311622.size()-10 }; });
}

void QWebEnginePage_ConnectTitleChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QString &)>(&QWebEnginePage::titleChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QString &)>(&MyQWebEnginePage::Signal_TitleChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEnginePage_DisconnectTitleChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QString &)>(&QWebEnginePage::titleChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QString &)>(&MyQWebEnginePage::Signal_TitleChanged));
}

void QWebEnginePage_TitleChanged(void* ptr, struct QtWebEngine_PackedString title)
{
	static_cast<QWebEnginePage*>(ptr)->titleChanged(QString::fromUtf8(title.data, title.len));
}

struct QtWebEngine_PackedString QWebEnginePage_QWebEnginePage_Tr(char* s, char* c, int n)
{
	return ({ QByteArray t3acb8e = QWebEnginePage::tr(const_cast<const char*>(s), const_cast<const char*>(c), n).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t3acb8e.prepend("WHITESPACE").constData()+10), t3acb8e.size()-10 }; });
}

void QWebEnginePage_TriggerAction(void* ptr, long long action, char checked)
{
	static_cast<QWebEnginePage*>(ptr)->triggerAction(static_cast<QWebEnginePage::WebAction>(action), checked != 0);
}

void QWebEnginePage_TriggerActionDefault(void* ptr, long long action, char checked)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::triggerAction(static_cast<QWebEnginePage::WebAction>(action), checked != 0);
}

void* QWebEnginePage_Url(void* ptr)
{
	return new QUrl(static_cast<QWebEnginePage*>(ptr)->url());
}

void QWebEnginePage_ConnectUrlChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QUrl &)>(&QWebEnginePage::urlChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QUrl &)>(&MyQWebEnginePage::Signal_UrlChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEnginePage_DisconnectUrlChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEnginePage*>(ptr), static_cast<void (QWebEnginePage::*)(const QUrl &)>(&QWebEnginePage::urlChanged), static_cast<MyQWebEnginePage*>(ptr), static_cast<void (MyQWebEnginePage::*)(const QUrl &)>(&MyQWebEnginePage::Signal_UrlChanged));
}

void QWebEnginePage_UrlChanged(void* ptr, void* url)
{
	static_cast<QWebEnginePage*>(ptr)->urlChanged(*static_cast<QUrl*>(url));
}

void* QWebEnginePage_View(void* ptr)
{
	return static_cast<QWebEnginePage*>(ptr)->view();
}

void QWebEnginePage_DestroyQWebEnginePage(void* ptr)
{
	static_cast<QWebEnginePage*>(ptr)->~QWebEnginePage();
}

void QWebEnginePage_DestroyQWebEnginePageDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void* QWebEnginePage___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QWebEnginePage___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QWebEnginePage___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QWebEnginePage___findChildren_atList2(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEnginePage___findChildren_setList2(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEnginePage___findChildren_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEnginePage___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEnginePage___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEnginePage___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEnginePage___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEnginePage___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEnginePage___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEnginePage___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEnginePage___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEnginePage___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

char QWebEnginePage_EventFilterDefault(void* ptr, void* watched, void* event)
{
		return static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void QWebEnginePage_ChildEventDefault(void* ptr, void* event)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::childEvent(static_cast<QChildEvent*>(event));
}

void QWebEnginePage_ConnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEnginePage_CustomEventDefault(void* ptr, void* event)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::customEvent(static_cast<QEvent*>(event));
}

void QWebEnginePage_DeleteLaterDefault(void* ptr)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::deleteLater();
}

void QWebEnginePage_DisconnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEnginePage_TimerEventDefault(void* ptr, void* event)
{
		static_cast<QWebEnginePage*>(ptr)->QWebEnginePage::timerEvent(static_cast<QTimerEvent*>(event));
}

class MyQWebEngineProfile: public QWebEngineProfile
{
public:
	MyQWebEngineProfile(QObject *parent = Q_NULLPTR) : QWebEngineProfile(parent) {QWebEngineProfile_QWebEngineProfile_QRegisterMetaType();};
	MyQWebEngineProfile(const QString &name, QObject *parent = Q_NULLPTR) : QWebEngineProfile(name, parent) {QWebEngineProfile_QWebEngineProfile_QRegisterMetaType();};
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQWebEngineProfile_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	 ~MyQWebEngineProfile() { callbackQWebEngineProfile_DestroyQWebEngineProfile(this); };
	bool event(QEvent * e) { return callbackQWebEngineProfile_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQWebEngineProfile_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQWebEngineProfile_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQWebEngineProfile_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQWebEngineProfile_CustomEvent(this, event); };
	void deleteLater() { callbackQWebEngineProfile_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQWebEngineProfile_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQWebEngineProfile_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtWebEngine_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQWebEngineProfile_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQWebEngineProfile_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QWebEngineProfile*)
Q_DECLARE_METATYPE(MyQWebEngineProfile*)

int QWebEngineProfile_QWebEngineProfile_QRegisterMetaType(){qRegisterMetaType<QWebEngineProfile*>(); return qRegisterMetaType<MyQWebEngineProfile*>();}

void* QWebEngineProfile_NewQWebEngineProfile(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(static_cast<QWindow*>(parent));
	} else {
		return new MyQWebEngineProfile(static_cast<QObject*>(parent));
	}
}

void* QWebEngineProfile_NewQWebEngineProfile2(struct QtWebEngine_PackedString name, void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QWindow*>(parent));
	} else {
		return new MyQWebEngineProfile(QString::fromUtf8(name.data, name.len), static_cast<QObject*>(parent));
	}
}

void* QWebEngineProfile_MetaObjectDefault(void* ptr)
{
		return const_cast<QMetaObject*>(static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::metaObject());
}

void* QWebEngineProfile_Settings(void* ptr)
{
	return static_cast<QWebEngineProfile*>(ptr)->settings();
}

struct QtWebEngine_PackedString QWebEngineProfile_QWebEngineProfile_Tr(char* s, char* c, int n)
{
	return ({ QByteArray tf8cda5 = QWebEngineProfile::tr(const_cast<const char*>(s), const_cast<const char*>(c), n).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(tf8cda5.prepend("WHITESPACE").constData()+10), tf8cda5.size()-10 }; });
}

void QWebEngineProfile_DestroyQWebEngineProfile(void* ptr)
{
	static_cast<QWebEngineProfile*>(ptr)->~QWebEngineProfile();
}

void QWebEngineProfile_DestroyQWebEngineProfileDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void* QWebEngineProfile___clearVisitedLinks_urls_atList(void* ptr, int i)
{
	return new QUrl(({QUrl tmp = static_cast<QList<QUrl>*>(ptr)->at(i); if (i == static_cast<QList<QUrl>*>(ptr)->size()-1) { static_cast<QList<QUrl>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QWebEngineProfile___clearVisitedLinks_urls_setList(void* ptr, void* i)
{
	static_cast<QList<QUrl>*>(ptr)->append(*static_cast<QUrl*>(i));
}

void* QWebEngineProfile___clearVisitedLinks_urls_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QUrl>();
}

void* QWebEngineProfile___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QWebEngineProfile___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QWebEngineProfile___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QWebEngineProfile___findChildren_atList2(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineProfile___findChildren_setList2(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineProfile___findChildren_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineProfile___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineProfile___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineProfile___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineProfile___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineProfile___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineProfile___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineProfile___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineProfile___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineProfile___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

char QWebEngineProfile_EventDefault(void* ptr, void* e)
{
		return static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::event(static_cast<QEvent*>(e));
}

char QWebEngineProfile_EventFilterDefault(void* ptr, void* watched, void* event)
{
		return static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void QWebEngineProfile_ChildEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::childEvent(static_cast<QChildEvent*>(event));
}

void QWebEngineProfile_ConnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEngineProfile_CustomEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::customEvent(static_cast<QEvent*>(event));
}

void QWebEngineProfile_DeleteLaterDefault(void* ptr)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::deleteLater();
}

void QWebEngineProfile_DisconnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEngineProfile_TimerEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineProfile*>(ptr)->QWebEngineProfile::timerEvent(static_cast<QTimerEvent*>(event));
}

Q_DECLARE_METATYPE(QWebEngineSettings*)
void* QWebEngineSettings_NewQWebEngineSettings2(void* parentSettings)
{
	return new QWebEngineSettings(static_cast<QWebEngineSettings*>(parentSettings));
}

struct QtWebEngine_PackedString QWebEngineSettings_FontFamily(void* ptr, long long which)
{
	return ({ QByteArray t118959 = static_cast<QWebEngineSettings*>(ptr)->fontFamily(static_cast<QWebEngineSettings::FontFamily>(which)).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t118959.prepend("WHITESPACE").constData()+10), t118959.size()-10 }; });
}

int QWebEngineSettings_FontSize(void* ptr, long long ty)
{
	return static_cast<QWebEngineSettings*>(ptr)->fontSize(static_cast<QWebEngineSettings::FontSize>(ty));
}

void QWebEngineSettings_SetAttribute(void* ptr, long long attr, char on)
{
	static_cast<QWebEngineSettings*>(ptr)->setAttribute(static_cast<QWebEngineSettings::WebAttribute>(attr), on != 0);
}

void QWebEngineSettings_SetFontFamily(void* ptr, long long which, struct QtWebEngine_PackedString family)
{
	static_cast<QWebEngineSettings*>(ptr)->setFontFamily(static_cast<QWebEngineSettings::FontFamily>(which), QString::fromUtf8(family.data, family.len));
}

char QWebEngineSettings_TestAttribute(void* ptr, long long attr)
{
	return static_cast<QWebEngineSettings*>(ptr)->testAttribute(static_cast<QWebEngineSettings::WebAttribute>(attr));
}

void QWebEngineSettings_DestroyQWebEngineSettings(void* ptr)
{
	static_cast<QWebEngineSettings*>(ptr)->~QWebEngineSettings();
}

class MyQWebEngineView: public QWebEngineView
{
public:
	MyQWebEngineView(QWidget *parent = Q_NULLPTR) : QWebEngineView(parent) {QWebEngineView_QWebEngineView_QRegisterMetaType();};
	void back() { callbackQWebEngineView_Back(this); };
	void contextMenuEvent(QContextMenuEvent * vqc) { callbackQWebEngineView_ContextMenuEvent(this, vqc); };
	void dragEnterEvent(QDragEnterEvent * e) { callbackQWebEngineView_DragEnterEvent(this, e); };
	void dragLeaveEvent(QDragLeaveEvent * e) { callbackQWebEngineView_DragLeaveEvent(this, e); };
	void dragMoveEvent(QDragMoveEvent * e) { callbackQWebEngineView_DragMoveEvent(this, e); };
	void dropEvent(QDropEvent * e) { callbackQWebEngineView_DropEvent(this, e); };
	bool event(QEvent * vqe) { return callbackQWebEngineView_Event(this, vqe) != 0; };
	void forward() { callbackQWebEngineView_Forward(this); };
	void hideEvent(QHideEvent * vqh) { callbackQWebEngineView_HideEvent(this, vqh); };
	void Signal_IconChanged(const QIcon & vqi) { callbackQWebEngineView_IconChanged(this, const_cast<QIcon*>(&vqi)); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQWebEngineView_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	void reload() { callbackQWebEngineView_Reload(this); };
	void Signal_SelectionChanged() { callbackQWebEngineView_SelectionChanged(this); };
	void showEvent(QShowEvent * vqs) { callbackQWebEngineView_ShowEvent(this, vqs); };
	QSize sizeHint() const { return *static_cast<QSize*>(callbackQWebEngineView_SizeHint(const_cast<void*>(static_cast<const void*>(this)))); };
	void stop() { callbackQWebEngineView_Stop(this); };
	void Signal_TitleChanged(const QString & title) { QByteArray t3c6de1 = title.toUtf8(); QtWebEngine_PackedString titlePacked = { const_cast<char*>(t3c6de1.prepend("WHITESPACE").constData()+10), t3c6de1.size()-10 };callbackQWebEngineView_TitleChanged(this, titlePacked); };
	void Signal_UrlChanged(const QUrl & vqu) { callbackQWebEngineView_UrlChanged(this, const_cast<QUrl*>(&vqu)); };
	 ~MyQWebEngineView() { callbackQWebEngineView_DestroyQWebEngineView(this); };
	bool close() { return callbackQWebEngineView_Close(this) != 0; };
	bool focusNextPrevChild(bool next) { return callbackQWebEngineView_FocusNextPrevChild(this, next) != 0; };
	bool nativeEvent(const QByteArray & eventType, void * message, long * result) { return callbackQWebEngineView_NativeEvent(this, const_cast<QByteArray*>(&eventType), message, result) != 0; };
	void actionEvent(QActionEvent * event) { callbackQWebEngineView_ActionEvent(this, event); };
	void changeEvent(QEvent * event) { callbackQWebEngineView_ChangeEvent(this, event); };
	void closeEvent(QCloseEvent * event) { callbackQWebEngineView_CloseEvent(this, event); };
	void Signal_CustomContextMenuRequested(const QPoint & pos) { callbackQWebEngineView_CustomContextMenuRequested(this, const_cast<QPoint*>(&pos)); };
	void enterEvent(QEvent * event) { callbackQWebEngineView_EnterEvent(this, event); };
	void focusInEvent(QFocusEvent * event) { callbackQWebEngineView_FocusInEvent(this, event); };
	void focusOutEvent(QFocusEvent * event) { callbackQWebEngineView_FocusOutEvent(this, event); };
	void hide() { callbackQWebEngineView_Hide(this); };
	void inputMethodEvent(QInputMethodEvent * event) { callbackQWebEngineView_InputMethodEvent(this, event); };
	void keyPressEvent(QKeyEvent * event) { callbackQWebEngineView_KeyPressEvent(this, event); };
	void keyReleaseEvent(QKeyEvent * event) { callbackQWebEngineView_KeyReleaseEvent(this, event); };
	void leaveEvent(QEvent * event) { callbackQWebEngineView_LeaveEvent(this, event); };
	void lower() { callbackQWebEngineView_Lower(this); };
	void mouseDoubleClickEvent(QMouseEvent * event) { callbackQWebEngineView_MouseDoubleClickEvent(this, event); };
	void mouseMoveEvent(QMouseEvent * event) { callbackQWebEngineView_MouseMoveEvent(this, event); };
	void mousePressEvent(QMouseEvent * event) { callbackQWebEngineView_MousePressEvent(this, event); };
	void mouseReleaseEvent(QMouseEvent * event) { callbackQWebEngineView_MouseReleaseEvent(this, event); };
	void moveEvent(QMoveEvent * event) { callbackQWebEngineView_MoveEvent(this, event); };
	void paintEvent(QPaintEvent * event) { callbackQWebEngineView_PaintEvent(this, event); };
	void raise() { callbackQWebEngineView_Raise(this); };
	void repaint() { callbackQWebEngineView_Repaint(this); };
	void resizeEvent(QResizeEvent * event) { callbackQWebEngineView_ResizeEvent(this, event); };
	void setDisabled(bool disable) { callbackQWebEngineView_SetDisabled(this, disable); };
	void setEnabled(bool vbo) { callbackQWebEngineView_SetEnabled(this, vbo); };
	void setFocus() { callbackQWebEngineView_SetFocus2(this); };
	void setHidden(bool hidden) { callbackQWebEngineView_SetHidden(this, hidden); };
	void setStyleSheet(const QString & styleSheet) { QByteArray t728ae7 = styleSheet.toUtf8(); QtWebEngine_PackedString styleSheetPacked = { const_cast<char*>(t728ae7.prepend("WHITESPACE").constData()+10), t728ae7.size()-10 };callbackQWebEngineView_SetStyleSheet(this, styleSheetPacked); };
	void setVisible(bool visible) { callbackQWebEngineView_SetVisible(this, visible); };
	void setWindowModified(bool vbo) { callbackQWebEngineView_SetWindowModified(this, vbo); };
	void setWindowTitle(const QString & vqs) { QByteArray tda39a3 = vqs.toUtf8(); QtWebEngine_PackedString vqsPacked = { const_cast<char*>(tda39a3.prepend("WHITESPACE").constData()+10), tda39a3.size()-10 };callbackQWebEngineView_SetWindowTitle(this, vqsPacked); };
	void show() { callbackQWebEngineView_Show(this); };
	void showFullScreen() { callbackQWebEngineView_ShowFullScreen(this); };
	void showMaximized() { callbackQWebEngineView_ShowMaximized(this); };
	void showMinimized() { callbackQWebEngineView_ShowMinimized(this); };
	void showNormal() { callbackQWebEngineView_ShowNormal(this); };
	void tabletEvent(QTabletEvent * event) { callbackQWebEngineView_TabletEvent(this, event); };
	void update() { callbackQWebEngineView_Update(this); };
	void updateMicroFocus() { callbackQWebEngineView_UpdateMicroFocus(this); };
	void wheelEvent(QWheelEvent * event) { callbackQWebEngineView_WheelEvent(this, event); };
	void Signal_WindowIconChanged(const QIcon & icon) { callbackQWebEngineView_WindowIconChanged(this, const_cast<QIcon*>(&icon)); };
	void Signal_WindowTitleChanged(const QString & title) { QByteArray t3c6de1 = title.toUtf8(); QtWebEngine_PackedString titlePacked = { const_cast<char*>(t3c6de1.prepend("WHITESPACE").constData()+10), t3c6de1.size()-10 };callbackQWebEngineView_WindowTitleChanged(this, titlePacked); };
	QPaintEngine * paintEngine() const { return static_cast<QPaintEngine*>(callbackQWebEngineView_PaintEngine(const_cast<void*>(static_cast<const void*>(this)))); };
	QSize minimumSizeHint() const { return *static_cast<QSize*>(callbackQWebEngineView_MinimumSizeHint(const_cast<void*>(static_cast<const void*>(this)))); };
	QVariant inputMethodQuery(Qt::InputMethodQuery query) const { return *static_cast<QVariant*>(callbackQWebEngineView_InputMethodQuery(const_cast<void*>(static_cast<const void*>(this)), query)); };
	bool hasHeightForWidth() const { return callbackQWebEngineView_HasHeightForWidth(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	int heightForWidth(int w) const { return callbackQWebEngineView_HeightForWidth(const_cast<void*>(static_cast<const void*>(this)), w); };
	int metric(QPaintDevice::PaintDeviceMetric m) const { return callbackQWebEngineView_Metric(const_cast<void*>(static_cast<const void*>(this)), m); };
	void initPainter(QPainter * painter) const { callbackQWebEngineView_InitPainter(const_cast<void*>(static_cast<const void*>(this)), painter); };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQWebEngineView_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQWebEngineView_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQWebEngineView_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQWebEngineView_CustomEvent(this, event); };
	void deleteLater() { callbackQWebEngineView_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQWebEngineView_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQWebEngineView_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtWebEngine_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQWebEngineView_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQWebEngineView_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QWebEngineView*)
Q_DECLARE_METATYPE(MyQWebEngineView*)

int QWebEngineView_QWebEngineView_QRegisterMetaType(){qRegisterMetaType<QWebEngineView*>(); return qRegisterMetaType<MyQWebEngineView*>();}

void* QWebEngineView_NewQWebEngineView(void* parent)
{
		return new MyQWebEngineView(static_cast<QWidget*>(parent));
}

void QWebEngineView_Back(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebEngineView*>(ptr), "back");
}

void QWebEngineView_BackDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::back();
}

void QWebEngineView_ContextMenuEventDefault(void* ptr, void* vqc)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::contextMenuEvent(static_cast<QContextMenuEvent*>(vqc));
}

void QWebEngineView_DragEnterEventDefault(void* ptr, void* e)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::dragEnterEvent(static_cast<QDragEnterEvent*>(e));
}

void QWebEngineView_DragLeaveEventDefault(void* ptr, void* e)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::dragLeaveEvent(static_cast<QDragLeaveEvent*>(e));
}

void QWebEngineView_DragMoveEventDefault(void* ptr, void* e)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::dragMoveEvent(static_cast<QDragMoveEvent*>(e));
}

void QWebEngineView_DropEventDefault(void* ptr, void* e)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::dropEvent(static_cast<QDropEvent*>(e));
}

char QWebEngineView_EventDefault(void* ptr, void* vqe)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::event(static_cast<QEvent*>(vqe));
}

void QWebEngineView_Forward(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebEngineView*>(ptr), "forward");
}

void QWebEngineView_ForwardDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::forward();
}

char QWebEngineView_HasSelection(void* ptr)
{
	return static_cast<QWebEngineView*>(ptr)->hasSelection();
}

void QWebEngineView_HideEventDefault(void* ptr, void* vqh)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::hideEvent(static_cast<QHideEvent*>(vqh));
}

void* QWebEngineView_Icon(void* ptr)
{
	return new QIcon(static_cast<QWebEngineView*>(ptr)->icon());
}

void QWebEngineView_ConnectIconChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QIcon &)>(&QWebEngineView::iconChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QIcon &)>(&MyQWebEngineView::Signal_IconChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEngineView_DisconnectIconChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QIcon &)>(&QWebEngineView::iconChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QIcon &)>(&MyQWebEngineView::Signal_IconChanged));
}

void QWebEngineView_IconChanged(void* ptr, void* vqi)
{
	static_cast<QWebEngineView*>(ptr)->iconChanged(*static_cast<QIcon*>(vqi));
}

void QWebEngineView_Load(void* ptr, void* url)
{
	static_cast<QWebEngineView*>(ptr)->load(*static_cast<QUrl*>(url));
}

void QWebEngineView_Load2(void* ptr, void* request)
{
	static_cast<QWebEngineView*>(ptr)->load(*static_cast<QWebEngineHttpRequest*>(request));
}

void* QWebEngineView_MetaObjectDefault(void* ptr)
{
		return const_cast<QMetaObject*>(static_cast<QWebEngineView*>(ptr)->QWebEngineView::metaObject());
}

void* QWebEngineView_Page(void* ptr)
{
	return static_cast<QWebEngineView*>(ptr)->page();
}

void QWebEngineView_Reload(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebEngineView*>(ptr), "reload");
}

void QWebEngineView_ReloadDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::reload();
}

struct QtWebEngine_PackedString QWebEngineView_SelectedText(void* ptr)
{
	return ({ QByteArray t0a8997 = static_cast<QWebEngineView*>(ptr)->selectedText().toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t0a8997.prepend("WHITESPACE").constData()+10), t0a8997.size()-10 }; });
}

void QWebEngineView_ConnectSelectionChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)()>(&QWebEngineView::selectionChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)()>(&MyQWebEngineView::Signal_SelectionChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEngineView_DisconnectSelectionChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)()>(&QWebEngineView::selectionChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)()>(&MyQWebEngineView::Signal_SelectionChanged));
}

void QWebEngineView_SelectionChanged(void* ptr)
{
	static_cast<QWebEngineView*>(ptr)->selectionChanged();
}

void QWebEngineView_SetContent(void* ptr, void* data, struct QtWebEngine_PackedString mimeType, void* baseUrl)
{
	static_cast<QWebEngineView*>(ptr)->setContent(*static_cast<QByteArray*>(data), QString::fromUtf8(mimeType.data, mimeType.len), *static_cast<QUrl*>(baseUrl));
}

void QWebEngineView_SetHtml(void* ptr, struct QtWebEngine_PackedString html, void* baseUrl)
{
	static_cast<QWebEngineView*>(ptr)->setHtml(QString::fromUtf8(html.data, html.len), *static_cast<QUrl*>(baseUrl));
}

void QWebEngineView_SetPage(void* ptr, void* page)
{
	static_cast<QWebEngineView*>(ptr)->setPage(static_cast<QWebEnginePage*>(page));
}

void QWebEngineView_SetUrl(void* ptr, void* url)
{
	static_cast<QWebEngineView*>(ptr)->setUrl(*static_cast<QUrl*>(url));
}

void* QWebEngineView_Settings(void* ptr)
{
	return static_cast<QWebEngineView*>(ptr)->settings();
}

void QWebEngineView_ShowEventDefault(void* ptr, void* vqs)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::showEvent(static_cast<QShowEvent*>(vqs));
}

void* QWebEngineView_SizeHintDefault(void* ptr)
{
		return ({ QSize tmpValue = static_cast<QWebEngineView*>(ptr)->QWebEngineView::sizeHint(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void QWebEngineView_Stop(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebEngineView*>(ptr), "stop");
}

void QWebEngineView_StopDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::stop();
}

struct QtWebEngine_PackedString QWebEngineView_Title(void* ptr)
{
	return ({ QByteArray t838611 = static_cast<QWebEngineView*>(ptr)->title().toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t838611.prepend("WHITESPACE").constData()+10), t838611.size()-10 }; });
}

void QWebEngineView_ConnectTitleChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QString &)>(&QWebEngineView::titleChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QString &)>(&MyQWebEngineView::Signal_TitleChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEngineView_DisconnectTitleChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QString &)>(&QWebEngineView::titleChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QString &)>(&MyQWebEngineView::Signal_TitleChanged));
}

void QWebEngineView_TitleChanged(void* ptr, struct QtWebEngine_PackedString title)
{
	static_cast<QWebEngineView*>(ptr)->titleChanged(QString::fromUtf8(title.data, title.len));
}

struct QtWebEngine_PackedString QWebEngineView_QWebEngineView_Tr(char* s, char* c, int n)
{
	return ({ QByteArray t7fa76b = QWebEngineView::tr(const_cast<const char*>(s), const_cast<const char*>(c), n).toUtf8(); QtWebEngine_PackedString { const_cast<char*>(t7fa76b.prepend("WHITESPACE").constData()+10), t7fa76b.size()-10 }; });
}

void* QWebEngineView_Url(void* ptr)
{
	return new QUrl(static_cast<QWebEngineView*>(ptr)->url());
}

void QWebEngineView_ConnectUrlChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QUrl &)>(&QWebEngineView::urlChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QUrl &)>(&MyQWebEngineView::Signal_UrlChanged), static_cast<Qt::ConnectionType>(t));
}

void QWebEngineView_DisconnectUrlChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebEngineView*>(ptr), static_cast<void (QWebEngineView::*)(const QUrl &)>(&QWebEngineView::urlChanged), static_cast<MyQWebEngineView*>(ptr), static_cast<void (MyQWebEngineView::*)(const QUrl &)>(&MyQWebEngineView::Signal_UrlChanged));
}

void QWebEngineView_UrlChanged(void* ptr, void* vqu)
{
	static_cast<QWebEngineView*>(ptr)->urlChanged(*static_cast<QUrl*>(vqu));
}

void QWebEngineView_DestroyQWebEngineView(void* ptr)
{
	static_cast<QWebEngineView*>(ptr)->~QWebEngineView();
}

void QWebEngineView_DestroyQWebEngineViewDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void* QWebEngineView___addActions_actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___addActions_actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* QWebEngineView___addActions_actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* QWebEngineView___insertActions_actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___insertActions_actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* QWebEngineView___insertActions_actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* QWebEngineView___actions_atList(void* ptr, int i)
{
	return ({QAction * tmp = static_cast<QList<QAction *>*>(ptr)->at(i); if (i == static_cast<QList<QAction *>*>(ptr)->size()-1) { static_cast<QList<QAction *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___actions_setList(void* ptr, void* i)
{
	static_cast<QList<QAction *>*>(ptr)->append(static_cast<QAction*>(i));
}

void* QWebEngineView___actions_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QAction *>();
}

void* QWebEngineView___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QWebEngineView___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QWebEngineView___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QWebEngineView___findChildren_atList2(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___findChildren_setList2(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineView___findChildren_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineView___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineView___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineView___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineView___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QWebEngineView___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QWebEngineView___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QWebEngineView___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

char QWebEngineView_CloseDefault(void* ptr)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::close();
}

char QWebEngineView_FocusNextPrevChildDefault(void* ptr, char next)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::focusNextPrevChild(next != 0);
}

char QWebEngineView_NativeEventDefault(void* ptr, void* eventType, void* message, long* result)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::nativeEvent(*static_cast<QByteArray*>(eventType), message, result);
}

void QWebEngineView_ActionEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::actionEvent(static_cast<QActionEvent*>(event));
}

void QWebEngineView_ChangeEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::changeEvent(static_cast<QEvent*>(event));
}

void QWebEngineView_CloseEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::closeEvent(static_cast<QCloseEvent*>(event));
}

void QWebEngineView_EnterEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::enterEvent(static_cast<QEvent*>(event));
}

void QWebEngineView_FocusInEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::focusInEvent(static_cast<QFocusEvent*>(event));
}

void QWebEngineView_FocusOutEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::focusOutEvent(static_cast<QFocusEvent*>(event));
}

void QWebEngineView_HideDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::hide();
}

void QWebEngineView_InputMethodEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::inputMethodEvent(static_cast<QInputMethodEvent*>(event));
}

void QWebEngineView_KeyPressEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::keyPressEvent(static_cast<QKeyEvent*>(event));
}

void QWebEngineView_KeyReleaseEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::keyReleaseEvent(static_cast<QKeyEvent*>(event));
}

void QWebEngineView_LeaveEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::leaveEvent(static_cast<QEvent*>(event));
}

void QWebEngineView_LowerDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::lower();
}

void QWebEngineView_MouseDoubleClickEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::mouseDoubleClickEvent(static_cast<QMouseEvent*>(event));
}

void QWebEngineView_MouseMoveEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::mouseMoveEvent(static_cast<QMouseEvent*>(event));
}

void QWebEngineView_MousePressEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::mousePressEvent(static_cast<QMouseEvent*>(event));
}

void QWebEngineView_MouseReleaseEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::mouseReleaseEvent(static_cast<QMouseEvent*>(event));
}

void QWebEngineView_MoveEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::moveEvent(static_cast<QMoveEvent*>(event));
}

void QWebEngineView_PaintEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::paintEvent(static_cast<QPaintEvent*>(event));
}

void QWebEngineView_RaiseDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::raise();
}

void QWebEngineView_RepaintDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::repaint();
}

void QWebEngineView_ResizeEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::resizeEvent(static_cast<QResizeEvent*>(event));
}

void QWebEngineView_SetDisabledDefault(void* ptr, char disable)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setDisabled(disable != 0);
}

void QWebEngineView_SetEnabledDefault(void* ptr, char vbo)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setEnabled(vbo != 0);
}

void QWebEngineView_SetFocus2Default(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setFocus();
}

void QWebEngineView_SetHiddenDefault(void* ptr, char hidden)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setHidden(hidden != 0);
}

void QWebEngineView_SetStyleSheetDefault(void* ptr, struct QtWebEngine_PackedString styleSheet)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setStyleSheet(QString::fromUtf8(styleSheet.data, styleSheet.len));
}

void QWebEngineView_SetVisibleDefault(void* ptr, char visible)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setVisible(visible != 0);
}

void QWebEngineView_SetWindowModifiedDefault(void* ptr, char vbo)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setWindowModified(vbo != 0);
}

void QWebEngineView_SetWindowTitleDefault(void* ptr, struct QtWebEngine_PackedString vqs)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::setWindowTitle(QString::fromUtf8(vqs.data, vqs.len));
}

void QWebEngineView_ShowDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::show();
}

void QWebEngineView_ShowFullScreenDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::showFullScreen();
}

void QWebEngineView_ShowMaximizedDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::showMaximized();
}

void QWebEngineView_ShowMinimizedDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::showMinimized();
}

void QWebEngineView_ShowNormalDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::showNormal();
}

void QWebEngineView_TabletEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::tabletEvent(static_cast<QTabletEvent*>(event));
}

void QWebEngineView_UpdateDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::update();
}

void QWebEngineView_UpdateMicroFocusDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::updateMicroFocus();
}

void QWebEngineView_WheelEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::wheelEvent(static_cast<QWheelEvent*>(event));
}

void* QWebEngineView_PaintEngineDefault(void* ptr)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::paintEngine();
}

void* QWebEngineView_MinimumSizeHintDefault(void* ptr)
{
		return ({ QSize tmpValue = static_cast<QWebEngineView*>(ptr)->QWebEngineView::minimumSizeHint(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QWebEngineView_InputMethodQueryDefault(void* ptr, long long query)
{
		return new QVariant(static_cast<QWebEngineView*>(ptr)->QWebEngineView::inputMethodQuery(static_cast<Qt::InputMethodQuery>(query)));
}

char QWebEngineView_HasHeightForWidthDefault(void* ptr)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::hasHeightForWidth();
}

int QWebEngineView_HeightForWidthDefault(void* ptr, int w)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::heightForWidth(w);
}

int QWebEngineView_MetricDefault(void* ptr, long long m)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::metric(static_cast<QPaintDevice::PaintDeviceMetric>(m));
}

void QWebEngineView_InitPainterDefault(void* ptr, void* painter)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::initPainter(static_cast<QPainter*>(painter));
}

char QWebEngineView_EventFilterDefault(void* ptr, void* watched, void* event)
{
		return static_cast<QWebEngineView*>(ptr)->QWebEngineView::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void QWebEngineView_ChildEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::childEvent(static_cast<QChildEvent*>(event));
}

void QWebEngineView_ConnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEngineView_CustomEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::customEvent(static_cast<QEvent*>(event));
}

void QWebEngineView_DeleteLaterDefault(void* ptr)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::deleteLater();
}

void QWebEngineView_DisconnectNotifyDefault(void* ptr, void* sign)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebEngineView_TimerEventDefault(void* ptr, void* event)
{
		static_cast<QWebEngineView*>(ptr)->QWebEngineView::timerEvent(static_cast<QTimerEvent*>(event));
}

