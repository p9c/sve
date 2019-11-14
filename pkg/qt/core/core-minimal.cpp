// +build minimal

#define protected public
#define private public

#include "core-minimal.h"
#include "_cgo_export.h"

#ifndef QT_CORE_LIB
	#error ------------------------------------------------------------------
	#error please run: '$(go env GOPATH)/bin/qtsetup'
	#error more info here: https://github.com/p9c/sve/pkg/qt/wiki/Installation
	#error ------------------------------------------------------------------
#endif
#include <QAbstractEventDispatcher>
#include <QAbstractItemModel>
#include <QAbstractNativeEventFilter>
#include <QBitArray>
#include <QBrush>
#include <QByteArray>
#include <QByteArrayList>
#include <QCborValue>
#include <QChar>
#include <QChildEvent>
#include <QColor>
#include <QCoreApplication>
#include <QDataStream>
#include <QDate>
#include <QDateTime>
#include <QEasingCurve>
#include <QEvent>
#include <QEventLoop>
#include <QFont>
#include <QGenericArgument>
#include <QGenericReturnArgument>
#include <QGraphicsObject>
#include <QGraphicsWidget>
#include <QHash>
#include <QIODevice>
#include <QIcon>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QLatin1Char>
#include <QLatin1String>
#include <QLayout>
#include <QLine>
#include <QLineF>
#include <QLocale>
#include <QMap>
#include <QMargins>
#include <QMarginsF>
#include <QMetaClassInfo>
#include <QMetaEnum>
#include <QMetaMethod>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMimeData>
#include <QModelIndex>
#include <QObject>
#include <QPersistentModelIndex>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QRegExp>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QSize>
#include <QSizeF>
#include <QSocketNotifier>
#include <QString>
#include <QStringRef>
#include <QSysInfo>
#include <QThread>
#include <QTime>
#include <QTimeZone>
#include <QTimerEvent>
#include <QTranslator>
#include <QUrl>
#include <QUrlQuery>
#include <QUuid>
#include <QVariant>
#include <QVector>
#include <QWidget>
#include <QWinEventNotifier>
#include <QWindow>
#include <QTextDocument>
#include <QObject>
#include <QStringList>

class MyQAbstractEventDispatcher: public QAbstractEventDispatcher
{
public:
	bool processEvents(QEventLoop::ProcessEventsFlags flags) { return callbackQAbstractEventDispatcher_ProcessEvents(this, flags) != 0; };
	#ifdef Q_OS_WIN
		bool registerEventNotifier(QWinEventNotifier * notifier) { return callbackQAbstractEventDispatcher_RegisterEventNotifier(this, notifier) != 0; };
	#endif
	bool unregisterTimer(int timerId) { return callbackQAbstractEventDispatcher_UnregisterTimer(this, timerId) != 0; };
	bool unregisterTimers(QObject * object) { return callbackQAbstractEventDispatcher_UnregisterTimers(this, object) != 0; };
	int remainingTime(int timerId) { return callbackQAbstractEventDispatcher_RemainingTime(this, timerId); };
	void Signal_AboutToBlock() { callbackQAbstractEventDispatcher_AboutToBlock(this); };
	void Signal_Awake() { callbackQAbstractEventDispatcher_Awake(this); };
	void interrupt() { callbackQAbstractEventDispatcher_Interrupt(this); };
	void registerSocketNotifier(QSocketNotifier * notifier) { callbackQAbstractEventDispatcher_RegisterSocketNotifier(this, notifier); };
	void registerTimer(int timerId, int interval, Qt::TimerType timerType, QObject * object) { callbackQAbstractEventDispatcher_RegisterTimer4(this, timerId, interval, timerType, object); };
	#ifdef Q_OS_WIN
		void unregisterEventNotifier(QWinEventNotifier * notifier) { callbackQAbstractEventDispatcher_UnregisterEventNotifier(this, notifier); };
	#endif
	void unregisterSocketNotifier(QSocketNotifier * notifier) { callbackQAbstractEventDispatcher_UnregisterSocketNotifier(this, notifier); };
	void wakeUp() { callbackQAbstractEventDispatcher_WakeUp(this); };
	 ~MyQAbstractEventDispatcher() { callbackQAbstractEventDispatcher_DestroyQAbstractEventDispatcher(this); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QAbstractEventDispatcher*)
Q_DECLARE_METATYPE(MyQAbstractEventDispatcher*)

int QAbstractEventDispatcher_QAbstractEventDispatcher_QRegisterMetaType(){qRegisterMetaType<QAbstractEventDispatcher*>(); return qRegisterMetaType<MyQAbstractEventDispatcher*>();}

void* QAbstractEventDispatcher_QAbstractEventDispatcher_Instance(void* thread)
{
	return QAbstractEventDispatcher::instance(static_cast<QThread*>(thread));
}

char QAbstractEventDispatcher_FilterNativeEvent(void* ptr, void* eventType, void* message, long* result)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->filterNativeEvent(*static_cast<QByteArray*>(eventType), message, result);
}

char QAbstractEventDispatcher_ProcessEvents(void* ptr, long long flags)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->processEvents(static_cast<QEventLoop::ProcessEventsFlag>(flags));
}

char QAbstractEventDispatcher_RegisterEventNotifier(void* ptr, void* notifier)
{
#ifdef Q_OS_WIN
	return static_cast<QAbstractEventDispatcher*>(ptr)->registerEventNotifier(static_cast<QWinEventNotifier*>(notifier));
#else
	return false;
#endif
}

char QAbstractEventDispatcher_UnregisterTimer(void* ptr, int timerId)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->unregisterTimer(timerId);
}

char QAbstractEventDispatcher_UnregisterTimers(void* ptr, void* object)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->unregisterTimers(static_cast<QObject*>(object));
}

int QAbstractEventDispatcher_RegisterTimer(void* ptr, int interval, long long timerType, void* object)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->registerTimer(interval, static_cast<Qt::TimerType>(timerType), static_cast<QObject*>(object));
}

int QAbstractEventDispatcher_RemainingTime(void* ptr, int timerId)
{
	return static_cast<QAbstractEventDispatcher*>(ptr)->remainingTime(timerId);
}

void QAbstractEventDispatcher_ConnectAboutToBlock(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractEventDispatcher*>(ptr), static_cast<void (QAbstractEventDispatcher::*)()>(&QAbstractEventDispatcher::aboutToBlock), static_cast<MyQAbstractEventDispatcher*>(ptr), static_cast<void (MyQAbstractEventDispatcher::*)()>(&MyQAbstractEventDispatcher::Signal_AboutToBlock), static_cast<Qt::ConnectionType>(t));
}

void QAbstractEventDispatcher_DisconnectAboutToBlock(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractEventDispatcher*>(ptr), static_cast<void (QAbstractEventDispatcher::*)()>(&QAbstractEventDispatcher::aboutToBlock), static_cast<MyQAbstractEventDispatcher*>(ptr), static_cast<void (MyQAbstractEventDispatcher::*)()>(&MyQAbstractEventDispatcher::Signal_AboutToBlock));
}

void QAbstractEventDispatcher_AboutToBlock(void* ptr)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->aboutToBlock();
}

void QAbstractEventDispatcher_ConnectAwake(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractEventDispatcher*>(ptr), static_cast<void (QAbstractEventDispatcher::*)()>(&QAbstractEventDispatcher::awake), static_cast<MyQAbstractEventDispatcher*>(ptr), static_cast<void (MyQAbstractEventDispatcher::*)()>(&MyQAbstractEventDispatcher::Signal_Awake), static_cast<Qt::ConnectionType>(t));
}

void QAbstractEventDispatcher_DisconnectAwake(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractEventDispatcher*>(ptr), static_cast<void (QAbstractEventDispatcher::*)()>(&QAbstractEventDispatcher::awake), static_cast<MyQAbstractEventDispatcher*>(ptr), static_cast<void (MyQAbstractEventDispatcher::*)()>(&MyQAbstractEventDispatcher::Signal_Awake));
}

void QAbstractEventDispatcher_Awake(void* ptr)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->awake();
}

void QAbstractEventDispatcher_InstallNativeEventFilter(void* ptr, void* filterObj)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->installNativeEventFilter(static_cast<QAbstractNativeEventFilter*>(filterObj));
}

void QAbstractEventDispatcher_Interrupt(void* ptr)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->interrupt();
}

void QAbstractEventDispatcher_RegisterSocketNotifier(void* ptr, void* notifier)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->registerSocketNotifier(static_cast<QSocketNotifier*>(notifier));
}

void QAbstractEventDispatcher_RegisterTimer4(void* ptr, int timerId, int interval, long long timerType, void* object)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->registerTimer(timerId, interval, static_cast<Qt::TimerType>(timerType), static_cast<QObject*>(object));
}

void QAbstractEventDispatcher_RemoveNativeEventFilter(void* ptr, void* filter)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->removeNativeEventFilter(static_cast<QAbstractNativeEventFilter*>(filter));
}

void QAbstractEventDispatcher_UnregisterEventNotifier(void* ptr, void* notifier)
{
#ifdef Q_OS_WIN
	static_cast<QAbstractEventDispatcher*>(ptr)->unregisterEventNotifier(static_cast<QWinEventNotifier*>(notifier));
#endif
}

void QAbstractEventDispatcher_UnregisterSocketNotifier(void* ptr, void* notifier)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->unregisterSocketNotifier(static_cast<QSocketNotifier*>(notifier));
}

void QAbstractEventDispatcher_WakeUp(void* ptr)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->wakeUp();
}

void QAbstractEventDispatcher_DestroyQAbstractEventDispatcher(void* ptr)
{
	static_cast<QAbstractEventDispatcher*>(ptr)->~QAbstractEventDispatcher();
}

void QAbstractEventDispatcher_DestroyQAbstractEventDispatcherDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

class MyQAbstractItemModel: public QAbstractItemModel
{
public:
	MyQAbstractItemModel(QObject *parent = Q_NULLPTR) : QAbstractItemModel(parent) {QAbstractItemModel_QAbstractItemModel_QRegisterMetaType();};
	bool dropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent) { return callbackQAbstractItemModel_DropMimeData(this, const_cast<QMimeData*>(data), action, row, column, const_cast<QModelIndex*>(&parent)) != 0; };
	bool insertColumns(int column, int count, const QModelIndex & parent) { return callbackQAbstractItemModel_InsertColumns(this, column, count, const_cast<QModelIndex*>(&parent)) != 0; };
	bool insertRows(int row, int count, const QModelIndex & parent) { return callbackQAbstractItemModel_InsertRows(this, row, count, const_cast<QModelIndex*>(&parent)) != 0; };
	bool moveColumns(const QModelIndex & sourceParent, int sourceColumn, int count, const QModelIndex & destinationParent, int destinationChild) { return callbackQAbstractItemModel_MoveColumns(this, const_cast<QModelIndex*>(&sourceParent), sourceColumn, count, const_cast<QModelIndex*>(&destinationParent), destinationChild) != 0; };
	bool moveRows(const QModelIndex & sourceParent, int sourceRow, int count, const QModelIndex & destinationParent, int destinationChild) { return callbackQAbstractItemModel_MoveRows(this, const_cast<QModelIndex*>(&sourceParent), sourceRow, count, const_cast<QModelIndex*>(&destinationParent), destinationChild) != 0; };
	bool removeColumns(int column, int count, const QModelIndex & parent) { return callbackQAbstractItemModel_RemoveColumns(this, column, count, const_cast<QModelIndex*>(&parent)) != 0; };
	bool removeRows(int row, int count, const QModelIndex & parent) { return callbackQAbstractItemModel_RemoveRows(this, row, count, const_cast<QModelIndex*>(&parent)) != 0; };
	bool setData(const QModelIndex & index, const QVariant & value, int role) { return callbackQAbstractItemModel_SetData(this, const_cast<QModelIndex*>(&index), const_cast<QVariant*>(&value), role) != 0; };
	bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role) { return callbackQAbstractItemModel_SetHeaderData(this, section, orientation, const_cast<QVariant*>(&value), role) != 0; };
	bool setItemData(const QModelIndex & index, const QMap<int, QVariant> & roles) { return callbackQAbstractItemModel_SetItemData(this, const_cast<QModelIndex*>(&index), ({ QMap<int, QVariant>* tmpValue037c88 = new QMap<int, QVariant>(roles); QtCore_PackedList { tmpValue037c88, tmpValue037c88->size() }; })) != 0; };
	bool submit() { return callbackQAbstractItemModel_Submit(this) != 0; };
	void Signal_ColumnsAboutToBeInserted(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_ColumnsAboutToBeInserted(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_ColumnsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn) { callbackQAbstractItemModel_ColumnsAboutToBeMoved(this, const_cast<QModelIndex*>(&sourceParent), sourceStart, sourceEnd, const_cast<QModelIndex*>(&destinationParent), destinationColumn); };
	void Signal_ColumnsAboutToBeRemoved(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_ColumnsAboutToBeRemoved(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_ColumnsInserted(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_ColumnsInserted(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_ColumnsMoved(const QModelIndex & parent, int start, int end, const QModelIndex & destination, int column) { callbackQAbstractItemModel_ColumnsMoved(this, const_cast<QModelIndex*>(&parent), start, end, const_cast<QModelIndex*>(&destination), column); };
	void Signal_ColumnsRemoved(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_ColumnsRemoved(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_DataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight, const QVector<int> & roles) { callbackQAbstractItemModel_DataChanged(this, const_cast<QModelIndex*>(&topLeft), const_cast<QModelIndex*>(&bottomRight), ({ QVector<int>* tmpValue037c88 = new QVector<int>(roles); QtCore_PackedList { tmpValue037c88, tmpValue037c88->size() }; })); };
	void fetchMore(const QModelIndex & parent) { callbackQAbstractItemModel_FetchMore(this, const_cast<QModelIndex*>(&parent)); };
	void Signal_HeaderDataChanged(Qt::Orientation orientation, int first, int last) { callbackQAbstractItemModel_HeaderDataChanged(this, orientation, first, last); };
	void Signal_LayoutAboutToBeChanged(const QList<QPersistentModelIndex> & parents, QAbstractItemModel::LayoutChangeHint hint) { callbackQAbstractItemModel_LayoutAboutToBeChanged(this, ({ QList<QPersistentModelIndex>* tmpValuea664f1 = new QList<QPersistentModelIndex>(parents); QtCore_PackedList { tmpValuea664f1, tmpValuea664f1->size() }; }), hint); };
	void Signal_LayoutChanged(const QList<QPersistentModelIndex> & parents, QAbstractItemModel::LayoutChangeHint hint) { callbackQAbstractItemModel_LayoutChanged(this, ({ QList<QPersistentModelIndex>* tmpValuea664f1 = new QList<QPersistentModelIndex>(parents); QtCore_PackedList { tmpValuea664f1, tmpValuea664f1->size() }; }), hint); };
	void Signal_ModelAboutToBeReset() { callbackQAbstractItemModel_ModelAboutToBeReset(this); };
	void Signal_ModelReset() { callbackQAbstractItemModel_ModelReset(this); };
	void resetInternalData() { callbackQAbstractItemModel_ResetInternalData(this); };
	void revert() { callbackQAbstractItemModel_Revert(this); };
	void Signal_RowsAboutToBeInserted(const QModelIndex & parent, int start, int end) { callbackQAbstractItemModel_RowsAboutToBeInserted(this, const_cast<QModelIndex*>(&parent), start, end); };
	void Signal_RowsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow) { callbackQAbstractItemModel_RowsAboutToBeMoved(this, const_cast<QModelIndex*>(&sourceParent), sourceStart, sourceEnd, const_cast<QModelIndex*>(&destinationParent), destinationRow); };
	void Signal_RowsAboutToBeRemoved(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_RowsAboutToBeRemoved(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_RowsInserted(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_RowsInserted(this, const_cast<QModelIndex*>(&parent), first, last); };
	void Signal_RowsMoved(const QModelIndex & parent, int start, int end, const QModelIndex & destination, int row) { callbackQAbstractItemModel_RowsMoved(this, const_cast<QModelIndex*>(&parent), start, end, const_cast<QModelIndex*>(&destination), row); };
	void Signal_RowsRemoved(const QModelIndex & parent, int first, int last) { callbackQAbstractItemModel_RowsRemoved(this, const_cast<QModelIndex*>(&parent), first, last); };
	void sort(int column, Qt::SortOrder order) { callbackQAbstractItemModel_Sort(this, column, order); };
	 ~MyQAbstractItemModel() { callbackQAbstractItemModel_DestroyQAbstractItemModel(this); };
	QHash<int, QByteArray> roleNames() const { return ({ QHash<int, QByteArray>* tmpP = static_cast<QHash<int, QByteArray>*>(callbackQAbstractItemModel_RoleNames(const_cast<void*>(static_cast<const void*>(this)))); QHash<int, QByteArray> tmpV = *tmpP; tmpP->~QHash(); free(tmpP); tmpV; }); };
	QMap<int, QVariant> itemData(const QModelIndex & index) const { return ({ QMap<int, QVariant>* tmpP = static_cast<QMap<int, QVariant>*>(callbackQAbstractItemModel_ItemData(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); QMap<int, QVariant> tmpV = *tmpP; tmpP->~QMap(); free(tmpP); tmpV; }); };
	QMimeData * mimeData(const QModelIndexList & indexes) const { return static_cast<QMimeData*>(callbackQAbstractItemModel_MimeData(const_cast<void*>(static_cast<const void*>(this)), ({ QList<QModelIndex>* tmpValuee0adf2 = new QList<QModelIndex>(indexes); QtCore_PackedList { tmpValuee0adf2, tmpValuee0adf2->size() }; }))); };
	QModelIndex buddy(const QModelIndex & index) const { return *static_cast<QModelIndex*>(callbackQAbstractItemModel_Buddy(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); };
	QModelIndex index(int row, int column, const QModelIndex & parent) const { return *static_cast<QModelIndex*>(callbackQAbstractItemModel_Index(const_cast<void*>(static_cast<const void*>(this)), row, column, const_cast<QModelIndex*>(&parent))); };
	QModelIndex parent(const QModelIndex & index) const { return *static_cast<QModelIndex*>(callbackQAbstractItemModel_Parent(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); };
	QModelIndex sibling(int row, int column, const QModelIndex & index) const { return *static_cast<QModelIndex*>(callbackQAbstractItemModel_Sibling(const_cast<void*>(static_cast<const void*>(this)), row, column, const_cast<QModelIndex*>(&index))); };
	QList<QModelIndex> match(const QModelIndex & start, int role, const QVariant & value, int hits, Qt::MatchFlags flags) const { return ({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(callbackQAbstractItemModel_Match(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&start), role, const_cast<QVariant*>(&value), hits, flags)); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }); };
	QSize span(const QModelIndex & index) const { return *static_cast<QSize*>(callbackQAbstractItemModel_Span(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); };
	QStringList mimeTypes() const { return ({ QtCore_PackedString tempVal = callbackQAbstractItemModel_MimeTypes(const_cast<void*>(static_cast<const void*>(this))); QStringList ret = QString::fromUtf8(tempVal.data, tempVal.len).split("¡¦!", QString::SkipEmptyParts); free(tempVal.data); ret; }); };
	QVariant data(const QModelIndex & index, int role) const { return *static_cast<QVariant*>(callbackQAbstractItemModel_Data(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index), role)); };
	QVariant headerData(int section, Qt::Orientation orientation, int role) const { return *static_cast<QVariant*>(callbackQAbstractItemModel_HeaderData(const_cast<void*>(static_cast<const void*>(this)), section, orientation, role)); };
	Qt::DropActions supportedDragActions() const { return static_cast<Qt::DropAction>(callbackQAbstractItemModel_SupportedDragActions(const_cast<void*>(static_cast<const void*>(this)))); };
	Qt::DropActions supportedDropActions() const { return static_cast<Qt::DropAction>(callbackQAbstractItemModel_SupportedDropActions(const_cast<void*>(static_cast<const void*>(this)))); };
	Qt::ItemFlags flags(const QModelIndex & index) const { return static_cast<Qt::ItemFlag>(callbackQAbstractItemModel_Flags(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&index))); };
	bool canDropMimeData(const QMimeData * data, Qt::DropAction action, int row, int column, const QModelIndex & parent) const { return callbackQAbstractItemModel_CanDropMimeData(const_cast<void*>(static_cast<const void*>(this)), const_cast<QMimeData*>(data), action, row, column, const_cast<QModelIndex*>(&parent)) != 0; };
	bool canFetchMore(const QModelIndex & parent) const { return callbackQAbstractItemModel_CanFetchMore(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&parent)) != 0; };
	bool hasChildren(const QModelIndex & parent) const { return callbackQAbstractItemModel_HasChildren(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&parent)) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	int columnCount(const QModelIndex & parent) const { return callbackQAbstractItemModel_ColumnCount(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&parent)); };
	int rowCount(const QModelIndex & parent) const { return callbackQAbstractItemModel_RowCount(const_cast<void*>(static_cast<const void*>(this)), const_cast<QModelIndex*>(&parent)); };
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QAbstractItemModel*)
Q_DECLARE_METATYPE(MyQAbstractItemModel*)

int QAbstractItemModel_QAbstractItemModel_QRegisterMetaType(){qRegisterMetaType<QAbstractItemModel*>(); return qRegisterMetaType<MyQAbstractItemModel*>();}

void* QAbstractItemModel_NewQAbstractItemModel(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQAbstractItemModel(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQAbstractItemModel(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQAbstractItemModel(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQAbstractItemModel(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQAbstractItemModel(static_cast<QWindow*>(parent));
	} else {
		return new MyQAbstractItemModel(static_cast<QObject*>(parent));
	}
}

char QAbstractItemModel_BeginMoveColumns(void* ptr, void* sourceParent, int sourceFirst, int sourceLast, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->beginMoveColumns(*static_cast<QModelIndex*>(sourceParent), sourceFirst, sourceLast, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_BeginMoveRows(void* ptr, void* sourceParent, int sourceFirst, int sourceLast, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->beginMoveRows(*static_cast<QModelIndex*>(sourceParent), sourceFirst, sourceLast, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_DropMimeData(void* ptr, void* data, long long action, int row, int column, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->dropMimeData(static_cast<QMimeData*>(data), static_cast<Qt::DropAction>(action), row, column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_DropMimeDataDefault(void* ptr, void* data, long long action, int row, int column, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::dropMimeData(static_cast<QMimeData*>(data), static_cast<Qt::DropAction>(action), row, column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertColumn(void* ptr, int column, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->insertColumn(column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertColumns(void* ptr, int column, int count, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->insertColumns(column, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertColumnsDefault(void* ptr, int column, int count, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::insertColumns(column, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertRow(void* ptr, int row, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->insertRow(row, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertRows(void* ptr, int row, int count, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->insertRows(row, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_InsertRowsDefault(void* ptr, int row, int count, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::insertRows(row, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_MoveColumn(void* ptr, void* sourceParent, int sourceColumn, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->moveColumn(*static_cast<QModelIndex*>(sourceParent), sourceColumn, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_MoveColumns(void* ptr, void* sourceParent, int sourceColumn, int count, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->moveColumns(*static_cast<QModelIndex*>(sourceParent), sourceColumn, count, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_MoveColumnsDefault(void* ptr, void* sourceParent, int sourceColumn, int count, void* destinationParent, int destinationChild)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::moveColumns(*static_cast<QModelIndex*>(sourceParent), sourceColumn, count, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_MoveRow(void* ptr, void* sourceParent, int sourceRow, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->moveRow(*static_cast<QModelIndex*>(sourceParent), sourceRow, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_MoveRows(void* ptr, void* sourceParent, int sourceRow, int count, void* destinationParent, int destinationChild)
{
	return static_cast<QAbstractItemModel*>(ptr)->moveRows(*static_cast<QModelIndex*>(sourceParent), sourceRow, count, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_MoveRowsDefault(void* ptr, void* sourceParent, int sourceRow, int count, void* destinationParent, int destinationChild)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::moveRows(*static_cast<QModelIndex*>(sourceParent), sourceRow, count, *static_cast<QModelIndex*>(destinationParent), destinationChild);
}

char QAbstractItemModel_RemoveColumn(void* ptr, int column, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->removeColumn(column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_RemoveColumns(void* ptr, int column, int count, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->removeColumns(column, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_RemoveColumnsDefault(void* ptr, int column, int count, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::removeColumns(column, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_RemoveRow(void* ptr, int row, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->removeRow(row, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_RemoveRows(void* ptr, int row, int count, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->removeRows(row, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_RemoveRowsDefault(void* ptr, int row, int count, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::removeRows(row, count, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_SetData(void* ptr, void* index, void* value, int role)
{
	return static_cast<QAbstractItemModel*>(ptr)->setData(*static_cast<QModelIndex*>(index), *static_cast<QVariant*>(value), role);
}

char QAbstractItemModel_SetDataDefault(void* ptr, void* index, void* value, int role)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::setData(*static_cast<QModelIndex*>(index), *static_cast<QVariant*>(value), role);
}

char QAbstractItemModel_SetHeaderData(void* ptr, int section, long long orientation, void* value, int role)
{
	return static_cast<QAbstractItemModel*>(ptr)->setHeaderData(section, static_cast<Qt::Orientation>(orientation), *static_cast<QVariant*>(value), role);
}

char QAbstractItemModel_SetHeaderDataDefault(void* ptr, int section, long long orientation, void* value, int role)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::setHeaderData(section, static_cast<Qt::Orientation>(orientation), *static_cast<QVariant*>(value), role);
}

char QAbstractItemModel_SetItemData(void* ptr, void* index, void* roles)
{
	return static_cast<QAbstractItemModel*>(ptr)->setItemData(*static_cast<QModelIndex*>(index), *static_cast<QMap<int, QVariant>*>(roles));
}

char QAbstractItemModel_SetItemDataDefault(void* ptr, void* index, void* roles)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::setItemData(*static_cast<QModelIndex*>(index), *static_cast<QMap<int, QVariant>*>(roles));
}

char QAbstractItemModel_Submit(void* ptr)
{
	bool returnArg;
	QMetaObject::invokeMethod(static_cast<QAbstractItemModel*>(ptr), "submit", Q_RETURN_ARG(bool, returnArg));
	return returnArg;
}

char QAbstractItemModel_SubmitDefault(void* ptr)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::submit();
}

void QAbstractItemModel_BeginInsertColumns(void* ptr, void* parent, int first, int last)
{
	static_cast<QAbstractItemModel*>(ptr)->beginInsertColumns(*static_cast<QModelIndex*>(parent), first, last);
}

void QAbstractItemModel_BeginInsertRows(void* ptr, void* parent, int first, int last)
{
	static_cast<QAbstractItemModel*>(ptr)->beginInsertRows(*static_cast<QModelIndex*>(parent), first, last);
}

void QAbstractItemModel_BeginRemoveColumns(void* ptr, void* parent, int first, int last)
{
	static_cast<QAbstractItemModel*>(ptr)->beginRemoveColumns(*static_cast<QModelIndex*>(parent), first, last);
}

void QAbstractItemModel_BeginRemoveRows(void* ptr, void* parent, int first, int last)
{
	static_cast<QAbstractItemModel*>(ptr)->beginRemoveRows(*static_cast<QModelIndex*>(parent), first, last);
}

void QAbstractItemModel_BeginResetModel(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->beginResetModel();
}

void QAbstractItemModel_ChangePersistentIndex(void* ptr, void* from, void* to)
{
	static_cast<QAbstractItemModel*>(ptr)->changePersistentIndex(*static_cast<QModelIndex*>(from), *static_cast<QModelIndex*>(to));
}

void QAbstractItemModel_ChangePersistentIndexList(void* ptr, void* from, void* to)
{
	static_cast<QAbstractItemModel*>(ptr)->changePersistentIndexList(({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(from); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }), ({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(to); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }));
}

void QAbstractItemModel_ConnectColumnsAboutToBeInserted(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeInserted), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsAboutToBeInserted(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeInserted));
}

void QAbstractItemModel_ConnectColumnsAboutToBeMoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeMoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsAboutToBeMoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeMoved));
}

void QAbstractItemModel_ConnectColumnsAboutToBeRemoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeRemoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsAboutToBeRemoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsAboutToBeRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsAboutToBeRemoved));
}

void QAbstractItemModel_ConnectColumnsInserted(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsInserted), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsInserted(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsInserted));
}

void QAbstractItemModel_ConnectColumnsMoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_ColumnsMoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsMoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_ColumnsMoved));
}

void QAbstractItemModel_ConnectColumnsRemoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsRemoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectColumnsRemoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::columnsRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_ColumnsRemoved));
}

void QAbstractItemModel_ConnectDataChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QModelIndex &, const QModelIndex &, const QVector<int> &)>(&QAbstractItemModel::dataChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, const QModelIndex &, const QVector<int> &)>(&MyQAbstractItemModel::Signal_DataChanged), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectDataChanged(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QModelIndex &, const QModelIndex &, const QVector<int> &)>(&QAbstractItemModel::dataChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, const QModelIndex &, const QVector<int> &)>(&MyQAbstractItemModel::Signal_DataChanged));
}

void QAbstractItemModel_DataChanged(void* ptr, void* topLeft, void* bottomRight, void* roles)
{
	static_cast<QAbstractItemModel*>(ptr)->dataChanged(*static_cast<QModelIndex*>(topLeft), *static_cast<QModelIndex*>(bottomRight), *static_cast<QVector<int>*>(roles));
}

void QAbstractItemModel_EndInsertColumns(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endInsertColumns();
}

void QAbstractItemModel_EndInsertRows(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endInsertRows();
}

void QAbstractItemModel_EndMoveColumns(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endMoveColumns();
}

void QAbstractItemModel_EndMoveRows(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endMoveRows();
}

void QAbstractItemModel_EndRemoveColumns(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endRemoveColumns();
}

void QAbstractItemModel_EndRemoveRows(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endRemoveRows();
}

void QAbstractItemModel_EndResetModel(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->endResetModel();
}

void QAbstractItemModel_FetchMore(void* ptr, void* parent)
{
	static_cast<QAbstractItemModel*>(ptr)->fetchMore(*static_cast<QModelIndex*>(parent));
}

void QAbstractItemModel_FetchMoreDefault(void* ptr, void* parent)
{
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::fetchMore(*static_cast<QModelIndex*>(parent));
}

void QAbstractItemModel_ConnectHeaderDataChanged(void* ptr, long long t)
{
	qRegisterMetaType<Qt::Orientation>();
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(Qt::Orientation, int, int)>(&QAbstractItemModel::headerDataChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(Qt::Orientation, int, int)>(&MyQAbstractItemModel::Signal_HeaderDataChanged), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectHeaderDataChanged(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(Qt::Orientation, int, int)>(&QAbstractItemModel::headerDataChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(Qt::Orientation, int, int)>(&MyQAbstractItemModel::Signal_HeaderDataChanged));
}

void QAbstractItemModel_HeaderDataChanged(void* ptr, long long orientation, int first, int last)
{
	static_cast<QAbstractItemModel*>(ptr)->headerDataChanged(static_cast<Qt::Orientation>(orientation), first, last);
}

void QAbstractItemModel_ConnectLayoutAboutToBeChanged(void* ptr, long long t)
{
	qRegisterMetaType<QAbstractItemModel::LayoutChangeHint>();
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&QAbstractItemModel::layoutAboutToBeChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&MyQAbstractItemModel::Signal_LayoutAboutToBeChanged), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectLayoutAboutToBeChanged(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&QAbstractItemModel::layoutAboutToBeChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&MyQAbstractItemModel::Signal_LayoutAboutToBeChanged));
}

void QAbstractItemModel_LayoutAboutToBeChanged(void* ptr, void* parents, long long hint)
{
	static_cast<QAbstractItemModel*>(ptr)->layoutAboutToBeChanged(*static_cast<QList<QPersistentModelIndex>*>(parents), static_cast<QAbstractItemModel::LayoutChangeHint>(hint));
}

void QAbstractItemModel_ConnectLayoutChanged(void* ptr, long long t)
{
	qRegisterMetaType<QAbstractItemModel::LayoutChangeHint>();
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&QAbstractItemModel::layoutChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&MyQAbstractItemModel::Signal_LayoutChanged), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectLayoutChanged(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), static_cast<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&QAbstractItemModel::layoutChanged), static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(&MyQAbstractItemModel::Signal_LayoutChanged));
}

void QAbstractItemModel_LayoutChanged(void* ptr, void* parents, long long hint)
{
	static_cast<QAbstractItemModel*>(ptr)->layoutChanged(*static_cast<QList<QPersistentModelIndex>*>(parents), static_cast<QAbstractItemModel::LayoutChangeHint>(hint));
}

void QAbstractItemModel_ConnectModelAboutToBeReset(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::modelAboutToBeReset, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)()>(&MyQAbstractItemModel::Signal_ModelAboutToBeReset), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectModelAboutToBeReset(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::modelAboutToBeReset, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)()>(&MyQAbstractItemModel::Signal_ModelAboutToBeReset));
}

void QAbstractItemModel_ConnectModelReset(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::modelReset, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)()>(&MyQAbstractItemModel::Signal_ModelReset), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectModelReset(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::modelReset, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)()>(&MyQAbstractItemModel::Signal_ModelReset));
}

void QAbstractItemModel_ResetInternalData(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QAbstractItemModel*>(ptr), "resetInternalData");
}

void QAbstractItemModel_ResetInternalDataDefault(void* ptr)
{
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::resetInternalData();
}

void QAbstractItemModel_Revert(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QAbstractItemModel*>(ptr), "revert");
}

void QAbstractItemModel_RevertDefault(void* ptr)
{
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::revert();
}

void QAbstractItemModel_ConnectRowsAboutToBeInserted(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeInserted), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsAboutToBeInserted(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeInserted));
}

void QAbstractItemModel_ConnectRowsAboutToBeMoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeMoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsAboutToBeMoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeMoved));
}

void QAbstractItemModel_ConnectRowsAboutToBeRemoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeRemoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsAboutToBeRemoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsAboutToBeRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsAboutToBeRemoved));
}

void QAbstractItemModel_ConnectRowsInserted(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsInserted), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsInserted(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsInserted, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsInserted));
}

void QAbstractItemModel_ConnectRowsMoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_RowsMoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsMoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsMoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int, const QModelIndex &, int)>(&MyQAbstractItemModel::Signal_RowsMoved));
}

void QAbstractItemModel_ConnectRowsRemoved(void* ptr, long long t)
{
	QObject::connect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsRemoved), static_cast<Qt::ConnectionType>(t));
}

void QAbstractItemModel_DisconnectRowsRemoved(void* ptr)
{
	QObject::disconnect(static_cast<QAbstractItemModel*>(ptr), &QAbstractItemModel::rowsRemoved, static_cast<MyQAbstractItemModel*>(ptr), static_cast<void (MyQAbstractItemModel::*)(const QModelIndex &, int, int)>(&MyQAbstractItemModel::Signal_RowsRemoved));
}

void QAbstractItemModel_Sort(void* ptr, int column, long long order)
{
	static_cast<QAbstractItemModel*>(ptr)->sort(column, static_cast<Qt::SortOrder>(order));
}

void QAbstractItemModel_SortDefault(void* ptr, int column, long long order)
{
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::sort(column, static_cast<Qt::SortOrder>(order));
}

void QAbstractItemModel_DestroyQAbstractItemModel(void* ptr)
{
	static_cast<QAbstractItemModel*>(ptr)->~QAbstractItemModel();
}

void QAbstractItemModel_DestroyQAbstractItemModelDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

struct QtCore_PackedList QAbstractItemModel_RoleNames(void* ptr)
{
	return ({ QHash<int, QByteArray>* tmpValue40dc1d = new QHash<int, QByteArray>(static_cast<QAbstractItemModel*>(ptr)->roleNames()); QtCore_PackedList { tmpValue40dc1d, tmpValue40dc1d->size() }; });
}

struct QtCore_PackedList QAbstractItemModel_RoleNamesDefault(void* ptr)
{
		return ({ QHash<int, QByteArray>* tmpValue42442f = new QHash<int, QByteArray>(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::roleNames()); QtCore_PackedList { tmpValue42442f, tmpValue42442f->size() }; });
}

struct QtCore_PackedList QAbstractItemModel_ItemData(void* ptr, void* index)
{
	return ({ QMap<int, QVariant>* tmpValue2d9f39 = new QMap<int, QVariant>(static_cast<QAbstractItemModel*>(ptr)->itemData(*static_cast<QModelIndex*>(index))); QtCore_PackedList { tmpValue2d9f39, tmpValue2d9f39->size() }; });
}

struct QtCore_PackedList QAbstractItemModel_ItemDataDefault(void* ptr, void* index)
{
		return ({ QMap<int, QVariant>* tmpValue46a96f = new QMap<int, QVariant>(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::itemData(*static_cast<QModelIndex*>(index))); QtCore_PackedList { tmpValue46a96f, tmpValue46a96f->size() }; });
}

void* QAbstractItemModel_MimeData(void* ptr, void* indexes)
{
	return static_cast<QAbstractItemModel*>(ptr)->mimeData(({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(indexes); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }));
}

void* QAbstractItemModel_MimeDataDefault(void* ptr, void* indexes)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::mimeData(({ QList<QModelIndex>* tmpP = static_cast<QList<QModelIndex>*>(indexes); QList<QModelIndex> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; }));
}

void* QAbstractItemModel_Buddy(void* ptr, void* index)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->buddy(*static_cast<QModelIndex*>(index)));
}

void* QAbstractItemModel_BuddyDefault(void* ptr, void* index)
{
		return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::buddy(*static_cast<QModelIndex*>(index)));
}

void* QAbstractItemModel_CreateIndex2(void* ptr, int row, int column, uintptr_t id)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->createIndex(row, column, id));
}

void* QAbstractItemModel_CreateIndex(void* ptr, int row, int column, void* p)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->createIndex(row, column, p));
}

void* QAbstractItemModel_Index(void* ptr, int row, int column, void* parent)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->index(row, column, *static_cast<QModelIndex*>(parent)));
}

void* QAbstractItemModel_Parent(void* ptr, void* index)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->parent(*static_cast<QModelIndex*>(index)));
}

void* QAbstractItemModel_Sibling(void* ptr, int row, int column, void* index)
{
	return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->sibling(row, column, *static_cast<QModelIndex*>(index)));
}

void* QAbstractItemModel_SiblingDefault(void* ptr, int row, int column, void* index)
{
		return new QModelIndex(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::sibling(row, column, *static_cast<QModelIndex*>(index)));
}

struct QtCore_PackedList QAbstractItemModel_Match(void* ptr, void* start, int role, void* value, int hits, long long flags)
{
	return ({ QList<QModelIndex>* tmpValuef30906 = new QList<QModelIndex>(static_cast<QAbstractItemModel*>(ptr)->match(*static_cast<QModelIndex*>(start), role, *static_cast<QVariant*>(value), hits, static_cast<Qt::MatchFlag>(flags))); QtCore_PackedList { tmpValuef30906, tmpValuef30906->size() }; });
}

struct QtCore_PackedList QAbstractItemModel_MatchDefault(void* ptr, void* start, int role, void* value, int hits, long long flags)
{
		return ({ QList<QModelIndex>* tmpValue4d7ea4 = new QList<QModelIndex>(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::match(*static_cast<QModelIndex*>(start), role, *static_cast<QVariant*>(value), hits, static_cast<Qt::MatchFlag>(flags))); QtCore_PackedList { tmpValue4d7ea4, tmpValue4d7ea4->size() }; });
}

struct QtCore_PackedList QAbstractItemModel_PersistentIndexList(void* ptr)
{
	return ({ QList<QModelIndex>* tmpValue86ddbc = new QList<QModelIndex>(static_cast<QAbstractItemModel*>(ptr)->persistentIndexList()); QtCore_PackedList { tmpValue86ddbc, tmpValue86ddbc->size() }; });
}

void* QAbstractItemModel_Span(void* ptr, void* index)
{
	return ({ QSize tmpValue = static_cast<QAbstractItemModel*>(ptr)->span(*static_cast<QModelIndex*>(index)); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QAbstractItemModel_SpanDefault(void* ptr, void* index)
{
		return ({ QSize tmpValue = static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::span(*static_cast<QModelIndex*>(index)); new QSize(tmpValue.width(), tmpValue.height()); });
}

struct QtCore_PackedString QAbstractItemModel_MimeTypes(void* ptr)
{
	return ({ QByteArray ta50262 = static_cast<QAbstractItemModel*>(ptr)->mimeTypes().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(ta50262.prepend("WHITESPACE").constData()+10), ta50262.size()-10 }; });
}

struct QtCore_PackedString QAbstractItemModel_MimeTypesDefault(void* ptr)
{
		return ({ QByteArray tf2dad9 = static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::mimeTypes().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tf2dad9.prepend("WHITESPACE").constData()+10), tf2dad9.size()-10 }; });
}

void* QAbstractItemModel_Data(void* ptr, void* index, int role)
{
	return new QVariant(static_cast<QAbstractItemModel*>(ptr)->data(*static_cast<QModelIndex*>(index), role));
}

void* QAbstractItemModel_HeaderData(void* ptr, int section, long long orientation, int role)
{
	return new QVariant(static_cast<QAbstractItemModel*>(ptr)->headerData(section, static_cast<Qt::Orientation>(orientation), role));
}

void* QAbstractItemModel_HeaderDataDefault(void* ptr, int section, long long orientation, int role)
{
		return new QVariant(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::headerData(section, static_cast<Qt::Orientation>(orientation), role));
}

long long QAbstractItemModel_SupportedDragActions(void* ptr)
{
	return static_cast<QAbstractItemModel*>(ptr)->supportedDragActions();
}

long long QAbstractItemModel_SupportedDragActionsDefault(void* ptr)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::supportedDragActions();
}

long long QAbstractItemModel_SupportedDropActions(void* ptr)
{
	return static_cast<QAbstractItemModel*>(ptr)->supportedDropActions();
}

long long QAbstractItemModel_SupportedDropActionsDefault(void* ptr)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::supportedDropActions();
}

long long QAbstractItemModel_Flags(void* ptr, void* index)
{
	return static_cast<QAbstractItemModel*>(ptr)->flags(*static_cast<QModelIndex*>(index));
}

long long QAbstractItemModel_FlagsDefault(void* ptr, void* index)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::flags(*static_cast<QModelIndex*>(index));
}

char QAbstractItemModel_CanDropMimeData(void* ptr, void* data, long long action, int row, int column, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->canDropMimeData(static_cast<QMimeData*>(data), static_cast<Qt::DropAction>(action), row, column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_CanDropMimeDataDefault(void* ptr, void* data, long long action, int row, int column, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::canDropMimeData(static_cast<QMimeData*>(data), static_cast<Qt::DropAction>(action), row, column, *static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_CanFetchMore(void* ptr, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->canFetchMore(*static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_CanFetchMoreDefault(void* ptr, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::canFetchMore(*static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_CheckIndex(void* ptr, void* index, long long options)
{
	return static_cast<QAbstractItemModel*>(ptr)->checkIndex(*static_cast<QModelIndex*>(index), static_cast<QAbstractItemModel::CheckIndexOption>(options));
}

char QAbstractItemModel_HasChildren(void* ptr, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->hasChildren(*static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_HasChildrenDefault(void* ptr, void* parent)
{
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::hasChildren(*static_cast<QModelIndex*>(parent));
}

char QAbstractItemModel_HasIndex(void* ptr, int row, int column, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->hasIndex(row, column, *static_cast<QModelIndex*>(parent));
}

int QAbstractItemModel_ColumnCount(void* ptr, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->columnCount(*static_cast<QModelIndex*>(parent));
}

int QAbstractItemModel_RowCount(void* ptr, void* parent)
{
	return static_cast<QAbstractItemModel*>(ptr)->rowCount(*static_cast<QModelIndex*>(parent));
}

void* QAbstractItemModel___setItemData_roles_atList(void* ptr, int v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QMap<int, QVariant>*>(ptr)->value(v); if (i == static_cast<QMap<int, QVariant>*>(ptr)->size()-1) { static_cast<QMap<int, QVariant>*>(ptr)->~QMap(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___setItemData_roles_setList(void* ptr, int key, void* i)
{
	static_cast<QMap<int, QVariant>*>(ptr)->insert(key, *static_cast<QVariant*>(i));
}

void* QAbstractItemModel___setItemData_roles_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<int, QVariant>();
}

struct QtCore_PackedList QAbstractItemModel___setItemData_roles_keyList(void* ptr)
{
	return ({ QList<int>* tmpValue249128 = new QList<int>(static_cast<QMap<int, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValue249128, tmpValue249128->size() }; });
}

void* QAbstractItemModel___changePersistentIndexList_from_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___changePersistentIndexList_from_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___changePersistentIndexList_from_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

void* QAbstractItemModel___changePersistentIndexList_to_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___changePersistentIndexList_to_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___changePersistentIndexList_to_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

int QAbstractItemModel___dataChanged_roles_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QVector<int>*>(ptr)->at(i); if (i == static_cast<QVector<int>*>(ptr)->size()-1) { static_cast<QVector<int>*>(ptr)->~QVector(); free(ptr); }; tmp; });
}

void QAbstractItemModel___dataChanged_roles_setList(void* ptr, int i)
{
	static_cast<QVector<int>*>(ptr)->append(i);
}

void* QAbstractItemModel___dataChanged_roles_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<int>();
}

void* QAbstractItemModel___doSetRoleNames_roleNames_atList(void* ptr, int v, int i)
{
	return new QByteArray(({ QByteArray tmp = static_cast<QHash<int, QByteArray>*>(ptr)->value(v); if (i == static_cast<QHash<int, QByteArray>*>(ptr)->size()-1) { static_cast<QHash<int, QByteArray>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___doSetRoleNames_roleNames_setList(void* ptr, int key, void* i)
{
	static_cast<QHash<int, QByteArray>*>(ptr)->insert(key, *static_cast<QByteArray*>(i));
}

void* QAbstractItemModel___doSetRoleNames_roleNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<int, QByteArray>();
}

struct QtCore_PackedList QAbstractItemModel___doSetRoleNames_roleNames_keyList(void* ptr)
{
	return ({ QList<int>* tmpValue7fc3bb = new QList<int>(static_cast<QHash<int, QByteArray>*>(ptr)->keys()); QtCore_PackedList { tmpValue7fc3bb, tmpValue7fc3bb->size() }; });
}

void* QAbstractItemModel___layoutAboutToBeChanged_parents_atList(void* ptr, int i)
{
	return new QPersistentModelIndex(({QPersistentModelIndex tmp = static_cast<QList<QPersistentModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QPersistentModelIndex>*>(ptr)->size()-1) { static_cast<QList<QPersistentModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___layoutAboutToBeChanged_parents_setList(void* ptr, void* i)
{
	static_cast<QList<QPersistentModelIndex>*>(ptr)->append(*static_cast<QPersistentModelIndex*>(i));
}

void* QAbstractItemModel___layoutAboutToBeChanged_parents_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QPersistentModelIndex>();
}

void* QAbstractItemModel___layoutChanged_parents_atList(void* ptr, int i)
{
	return new QPersistentModelIndex(({QPersistentModelIndex tmp = static_cast<QList<QPersistentModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QPersistentModelIndex>*>(ptr)->size()-1) { static_cast<QList<QPersistentModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___layoutChanged_parents_setList(void* ptr, void* i)
{
	static_cast<QList<QPersistentModelIndex>*>(ptr)->append(*static_cast<QPersistentModelIndex*>(i));
}

void* QAbstractItemModel___layoutChanged_parents_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QPersistentModelIndex>();
}

void* QAbstractItemModel___setRoleNames_roleNames_atList(void* ptr, int v, int i)
{
	return new QByteArray(({ QByteArray tmp = static_cast<QHash<int, QByteArray>*>(ptr)->value(v); if (i == static_cast<QHash<int, QByteArray>*>(ptr)->size()-1) { static_cast<QHash<int, QByteArray>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___setRoleNames_roleNames_setList(void* ptr, int key, void* i)
{
	static_cast<QHash<int, QByteArray>*>(ptr)->insert(key, *static_cast<QByteArray*>(i));
}

void* QAbstractItemModel___setRoleNames_roleNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<int, QByteArray>();
}

struct QtCore_PackedList QAbstractItemModel___setRoleNames_roleNames_keyList(void* ptr)
{
	return ({ QList<int>* tmpValue7fc3bb = new QList<int>(static_cast<QHash<int, QByteArray>*>(ptr)->keys()); QtCore_PackedList { tmpValue7fc3bb, tmpValue7fc3bb->size() }; });
}

void* QAbstractItemModel___roleNames_atList(void* ptr, int v, int i)
{
	return new QByteArray(({ QByteArray tmp = static_cast<QHash<int, QByteArray>*>(ptr)->value(v); if (i == static_cast<QHash<int, QByteArray>*>(ptr)->size()-1) { static_cast<QHash<int, QByteArray>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___roleNames_setList(void* ptr, int key, void* i)
{
	static_cast<QHash<int, QByteArray>*>(ptr)->insert(key, *static_cast<QByteArray*>(i));
}

void* QAbstractItemModel___roleNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<int, QByteArray>();
}

struct QtCore_PackedList QAbstractItemModel___roleNames_keyList(void* ptr)
{
	return ({ QList<int>* tmpValue7fc3bb = new QList<int>(static_cast<QHash<int, QByteArray>*>(ptr)->keys()); QtCore_PackedList { tmpValue7fc3bb, tmpValue7fc3bb->size() }; });
}

void* QAbstractItemModel___itemData_atList(void* ptr, int v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QMap<int, QVariant>*>(ptr)->value(v); if (i == static_cast<QMap<int, QVariant>*>(ptr)->size()-1) { static_cast<QMap<int, QVariant>*>(ptr)->~QMap(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___itemData_setList(void* ptr, int key, void* i)
{
	static_cast<QMap<int, QVariant>*>(ptr)->insert(key, *static_cast<QVariant*>(i));
}

void* QAbstractItemModel___itemData_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<int, QVariant>();
}

struct QtCore_PackedList QAbstractItemModel___itemData_keyList(void* ptr)
{
	return ({ QList<int>* tmpValue249128 = new QList<int>(static_cast<QMap<int, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValue249128, tmpValue249128->size() }; });
}

void* QAbstractItemModel___mimeData_indexes_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___mimeData_indexes_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___mimeData_indexes_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

void* QAbstractItemModel___match_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___match_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___match_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

void* QAbstractItemModel___persistentIndexList_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___persistentIndexList_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___persistentIndexList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

void* QAbstractItemModel___encodeData_indexes_atList(void* ptr, int i)
{
	return new QModelIndex(({QModelIndex tmp = static_cast<QList<QModelIndex>*>(ptr)->at(i); if (i == static_cast<QList<QModelIndex>*>(ptr)->size()-1) { static_cast<QList<QModelIndex>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QAbstractItemModel___encodeData_indexes_setList(void* ptr, void* i)
{
	static_cast<QList<QModelIndex>*>(ptr)->append(*static_cast<QModelIndex*>(i));
}

void* QAbstractItemModel___encodeData_indexes_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QModelIndex>();
}

int QAbstractItemModel_____setItemData_roles_keyList_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QList<int>*>(ptr)->at(i); if (i == static_cast<QList<int>*>(ptr)->size()-1) { static_cast<QList<int>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QAbstractItemModel_____setItemData_roles_keyList_setList(void* ptr, int i)
{
	static_cast<QList<int>*>(ptr)->append(i);
}

void* QAbstractItemModel_____setItemData_roles_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<int>();
}

int QAbstractItemModel_____doSetRoleNames_roleNames_keyList_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QList<int>*>(ptr)->at(i); if (i == static_cast<QList<int>*>(ptr)->size()-1) { static_cast<QList<int>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QAbstractItemModel_____doSetRoleNames_roleNames_keyList_setList(void* ptr, int i)
{
	static_cast<QList<int>*>(ptr)->append(i);
}

void* QAbstractItemModel_____doSetRoleNames_roleNames_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<int>();
}

int QAbstractItemModel_____setRoleNames_roleNames_keyList_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QList<int>*>(ptr)->at(i); if (i == static_cast<QList<int>*>(ptr)->size()-1) { static_cast<QList<int>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QAbstractItemModel_____setRoleNames_roleNames_keyList_setList(void* ptr, int i)
{
	static_cast<QList<int>*>(ptr)->append(i);
}

void* QAbstractItemModel_____setRoleNames_roleNames_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<int>();
}

int QAbstractItemModel_____roleNames_keyList_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QList<int>*>(ptr)->at(i); if (i == static_cast<QList<int>*>(ptr)->size()-1) { static_cast<QList<int>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QAbstractItemModel_____roleNames_keyList_setList(void* ptr, int i)
{
	static_cast<QList<int>*>(ptr)->append(i);
}

void* QAbstractItemModel_____roleNames_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<int>();
}

int QAbstractItemModel_____itemData_keyList_atList(void* ptr, int i)
{
	return ({int tmp = static_cast<QList<int>*>(ptr)->at(i); if (i == static_cast<QList<int>*>(ptr)->size()-1) { static_cast<QList<int>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QAbstractItemModel_____itemData_keyList_setList(void* ptr, int i)
{
	static_cast<QList<int>*>(ptr)->append(i);
}

void* QAbstractItemModel_____itemData_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<int>();
}

class MyQAbstractNativeEventFilter: public QAbstractNativeEventFilter
{
public:
	MyQAbstractNativeEventFilter() : QAbstractNativeEventFilter() {QAbstractNativeEventFilter_QAbstractNativeEventFilter_QRegisterMetaType();};
	bool nativeEventFilter(const QByteArray & eventType, void * message, long * result) { return callbackQAbstractNativeEventFilter_NativeEventFilter(this, const_cast<QByteArray*>(&eventType), message, result) != 0; };
	 ~MyQAbstractNativeEventFilter() { callbackQAbstractNativeEventFilter_DestroyQAbstractNativeEventFilter(this); };
};

Q_DECLARE_METATYPE(QAbstractNativeEventFilter*)
Q_DECLARE_METATYPE(MyQAbstractNativeEventFilter*)

int QAbstractNativeEventFilter_QAbstractNativeEventFilter_QRegisterMetaType(){qRegisterMetaType<QAbstractNativeEventFilter*>(); return qRegisterMetaType<MyQAbstractNativeEventFilter*>();}

void* QAbstractNativeEventFilter_NewQAbstractNativeEventFilter()
{
	return new MyQAbstractNativeEventFilter();
}

char QAbstractNativeEventFilter_NativeEventFilter(void* ptr, void* eventType, void* message, long* result)
{
	return static_cast<QAbstractNativeEventFilter*>(ptr)->nativeEventFilter(*static_cast<QByteArray*>(eventType), message, result);
}

void QAbstractNativeEventFilter_DestroyQAbstractNativeEventFilter(void* ptr)
{
	static_cast<QAbstractNativeEventFilter*>(ptr)->~QAbstractNativeEventFilter();
}

void QAbstractNativeEventFilter_DestroyQAbstractNativeEventFilterDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

Q_DECLARE_METATYPE(QBitArray)
Q_DECLARE_METATYPE(QBitArray*)
void* QBitArray_NewQBitArray()
{
	return new QBitArray();
}

void* QBitArray_NewQBitArray4(void* other)
{
	return new QBitArray(*static_cast<QBitArray*>(other));
}

void* QBitArray_NewQBitArray3(void* other)
{
	return new QBitArray(*static_cast<QBitArray*>(other));
}

void* QBitArray_NewQBitArray2(int size, char value)
{
	return new QBitArray(size, value != 0);
}

char QBitArray_Fill(void* ptr, char value, int size)
{
	return static_cast<QBitArray*>(ptr)->fill(value != 0, size);
}

char QBitArray_ToggleBit(void* ptr, int i)
{
	return static_cast<QBitArray*>(ptr)->toggleBit(i);
}

void QBitArray_Clear(void* ptr)
{
	static_cast<QBitArray*>(ptr)->clear();
}

void QBitArray_ClearBit(void* ptr, int i)
{
	static_cast<QBitArray*>(ptr)->clearBit(i);
}

void QBitArray_Fill2(void* ptr, char value, int begin, int end)
{
	static_cast<QBitArray*>(ptr)->fill(value != 0, begin, end);
}

void QBitArray_Resize(void* ptr, int size)
{
	static_cast<QBitArray*>(ptr)->resize(size);
}

void QBitArray_SetBit(void* ptr, int i)
{
	static_cast<QBitArray*>(ptr)->setBit(i);
}

void QBitArray_SetBit2(void* ptr, int i, char value)
{
	static_cast<QBitArray*>(ptr)->setBit(i, value != 0);
}

void QBitArray_Swap(void* ptr, void* other)
{
	static_cast<QBitArray*>(ptr)->swap(*static_cast<QBitArray*>(other));
}

void QBitArray_Truncate(void* ptr, int pos)
{
	static_cast<QBitArray*>(ptr)->truncate(pos);
}

char QBitArray_At(void* ptr, int i)
{
	return static_cast<QBitArray*>(ptr)->at(i);
}

char QBitArray_IsEmpty(void* ptr)
{
	return static_cast<QBitArray*>(ptr)->isEmpty();
}

char QBitArray_IsNull(void* ptr)
{
	return static_cast<QBitArray*>(ptr)->isNull();
}

char QBitArray_TestBit(void* ptr, int i)
{
	return static_cast<QBitArray*>(ptr)->testBit(i);
}

struct QtCore_PackedString QBitArray_Bits(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QBitArray*>(ptr)->bits()), -1 };
}

int QBitArray_Count(void* ptr)
{
	return static_cast<QBitArray*>(ptr)->count();
}

int QBitArray_Count2(void* ptr, char on)
{
	return static_cast<QBitArray*>(ptr)->count(on != 0);
}

int QBitArray_Size(void* ptr)
{
	return static_cast<QBitArray*>(ptr)->size();
}

Q_DECLARE_METATYPE(QByteArray)
Q_DECLARE_METATYPE(QByteArray*)
void* QByteArray_Append5(void* ptr, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(*ch));
}

void* QByteArray_Append(void* ptr, void* ba)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(*static_cast<QByteArray*>(ba)));
}

void* QByteArray_Append6(void* ptr, struct QtCore_PackedString str)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(QString::fromUtf8(str.data, str.len)));
}

void* QByteArray_Append3(void* ptr, char* str)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(const_cast<const char*>(str)));
}

void* QByteArray_Append4(void* ptr, char* str, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(const_cast<const char*>(str), l));
}

void* QByteArray_Append2(void* ptr, int count, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->append(count, *ch));
}

void* QByteArray_Fill(void* ptr, char* ch, int size)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->fill(*ch, size));
}

void* QByteArray_Insert5(void* ptr, int i, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, *ch));
}

void* QByteArray_Insert(void* ptr, int i, void* ba)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, *static_cast<QByteArray*>(ba)));
}

void* QByteArray_Insert6(void* ptr, int i, struct QtCore_PackedString str)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, QString::fromUtf8(str.data, str.len)));
}

void* QByteArray_Insert3(void* ptr, int i, char* str)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, const_cast<const char*>(str)));
}

void* QByteArray_Insert4(void* ptr, int i, char* str, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, const_cast<const char*>(str), l));
}

void* QByteArray_Insert2(void* ptr, int i, int count, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->insert(i, count, *ch));
}

void* QByteArray_Prepend5(void* ptr, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->prepend(*ch));
}

void* QByteArray_Prepend(void* ptr, void* ba)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->prepend(*static_cast<QByteArray*>(ba)));
}

void* QByteArray_Prepend3(void* ptr, char* str)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->prepend(const_cast<const char*>(str)));
}

void* QByteArray_Prepend4(void* ptr, char* str, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->prepend(const_cast<const char*>(str), l));
}

void* QByteArray_Prepend2(void* ptr, int count, char* ch)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->prepend(count, *ch));
}

void* QByteArray_Remove(void* ptr, int pos, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->remove(pos, l));
}

void* QByteArray_Replace11(void* ptr, char* before, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*before, *after));
}

void* QByteArray_Replace5(void* ptr, char* before, void* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*before, *static_cast<QByteArray*>(after)));
}

void* QByteArray_Replace13(void* ptr, char* before, struct QtCore_PackedString after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*before, QString::fromUtf8(after.data, after.len)));
}

void* QByteArray_Replace4(void* ptr, char* before, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*before, const_cast<const char*>(after)));
}

void* QByteArray_Replace8(void* ptr, void* before, void* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*static_cast<QByteArray*>(before), *static_cast<QByteArray*>(after)));
}

void* QByteArray_Replace9(void* ptr, void* before, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(*static_cast<QByteArray*>(before), const_cast<const char*>(after)));
}

void* QByteArray_Replace14(void* ptr, struct QtCore_PackedString before, void* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(QString::fromUtf8(before.data, before.len), *static_cast<QByteArray*>(after)));
}

void* QByteArray_Replace12(void* ptr, struct QtCore_PackedString before, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(QString::fromUtf8(before.data, before.len), const_cast<const char*>(after)));
}

void* QByteArray_Replace10(void* ptr, char* before, void* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(const_cast<const char*>(before), *static_cast<QByteArray*>(after)));
}

void* QByteArray_Replace6(void* ptr, char* before, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(const_cast<const char*>(before), const_cast<const char*>(after)));
}

void* QByteArray_Replace7(void* ptr, char* before, int bsize, char* after, int asize)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(const_cast<const char*>(before), bsize, const_cast<const char*>(after), asize));
}

void* QByteArray_Replace(void* ptr, int pos, int l, void* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(pos, l, *static_cast<QByteArray*>(after)));
}

void* QByteArray_Replace3(void* ptr, int pos, int l, char* after)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(pos, l, const_cast<const char*>(after)));
}

void* QByteArray_Replace2(void* ptr, int pos, int l, char* after, int alen)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->replace(pos, l, const_cast<const char*>(after), alen));
}

void* QByteArray_SetNum8(void* ptr, double n, char* ff, int prec)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, *ff, prec));
}

void* QByteArray_SetNum7(void* ptr, float n, char* ff, int prec)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, *ff, prec));
}

void* QByteArray_SetNum(void* ptr, int n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetNum5(void* ptr, long long n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetNum6(void* ptr, unsigned long long n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetNum3(void* ptr, short n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetNum4(void* ptr, unsigned int n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetNum2(void* ptr, unsigned short n, int base)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setNum(n, base));
}

void* QByteArray_SetRawData(void* ptr, char* data, unsigned int size)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->setRawData(const_cast<const char*>(data), size));
}

void* QByteArray_QByteArray_FromBase64(void* base64)
{
	return new QByteArray(QByteArray::fromBase64(*static_cast<QByteArray*>(base64)));
}

void* QByteArray_QByteArray_FromBase642(void* base64, long long options)
{
	return new QByteArray(QByteArray::fromBase64(*static_cast<QByteArray*>(base64), static_cast<QByteArray::Base64Option>(options)));
}

void* QByteArray_QByteArray_FromHex(void* hexEncoded)
{
	return new QByteArray(QByteArray::fromHex(*static_cast<QByteArray*>(hexEncoded)));
}

void* QByteArray_QByteArray_FromPercentEncoding(void* input, char* percent)
{
	return new QByteArray(QByteArray::fromPercentEncoding(*static_cast<QByteArray*>(input), *percent));
}

void* QByteArray_QByteArray_FromRawData(char* data, int size)
{
	return new QByteArray(QByteArray::fromRawData(const_cast<const char*>(data), size));
}

void* QByteArray_QByteArray_Number5(double n, char* ff, int prec)
{
	return new QByteArray(QByteArray::number(n, *ff, prec));
}

void* QByteArray_QByteArray_Number(int n, int base)
{
	return new QByteArray(QByteArray::number(n, base));
}

void* QByteArray_QByteArray_Number3(long long n, int base)
{
	return new QByteArray(QByteArray::number(n, base));
}

void* QByteArray_QByteArray_Number4(unsigned long long n, int base)
{
	return new QByteArray(QByteArray::number(n, base));
}

void* QByteArray_QByteArray_Number2(unsigned int n, int base)
{
	return new QByteArray(QByteArray::number(n, base));
}

void* QByteArray_NewQByteArray()
{
	return new QByteArray();
}

void* QByteArray_NewQByteArray6(void* other)
{
	return new QByteArray(*static_cast<QByteArray*>(other));
}

void* QByteArray_NewQByteArray5(void* other)
{
	return new QByteArray(*static_cast<QByteArray*>(other));
}

void* QByteArray_NewQByteArray2(char* data, int size)
{
	return new QByteArray(const_cast<const char*>(data), size);
}

void* QByteArray_NewQByteArray3(int size, char* ch)
{
	return new QByteArray(size, *ch);
}

struct QtCore_PackedString QByteArray_Data(void* ptr)
{
	return QtCore_PackedString { static_cast<QByteArray*>(ptr)->data(), static_cast<QByteArray*>(ptr)->size() };
}

void QByteArray_Chop(void* ptr, int n)
{
	static_cast<QByteArray*>(ptr)->chop(n);
}

void QByteArray_Clear(void* ptr)
{
	static_cast<QByteArray*>(ptr)->clear();
}

void QByteArray_Push_back3(void* ptr, char* ch)
{
	static_cast<QByteArray*>(ptr)->push_back(*ch);
}

void QByteArray_Push_back(void* ptr, void* other)
{
	static_cast<QByteArray*>(ptr)->push_back(*static_cast<QByteArray*>(other));
}

void QByteArray_Push_back2(void* ptr, char* str)
{
	static_cast<QByteArray*>(ptr)->push_back(const_cast<const char*>(str));
}

void QByteArray_Push_front3(void* ptr, char* ch)
{
	static_cast<QByteArray*>(ptr)->push_front(*ch);
}

void QByteArray_Push_front(void* ptr, void* other)
{
	static_cast<QByteArray*>(ptr)->push_front(*static_cast<QByteArray*>(other));
}

void QByteArray_Push_front2(void* ptr, char* str)
{
	static_cast<QByteArray*>(ptr)->push_front(const_cast<const char*>(str));
}

void QByteArray_Reserve(void* ptr, int size)
{
	static_cast<QByteArray*>(ptr)->reserve(size);
}

void QByteArray_Resize(void* ptr, int size)
{
	static_cast<QByteArray*>(ptr)->resize(size);
}

void QByteArray_Shrink_to_fit(void* ptr)
{
	static_cast<QByteArray*>(ptr)->shrink_to_fit();
}

void QByteArray_Squeeze(void* ptr)
{
	static_cast<QByteArray*>(ptr)->squeeze();
}

void QByteArray_Swap(void* ptr, void* other)
{
	static_cast<QByteArray*>(ptr)->swap(*static_cast<QByteArray*>(other));
}

void QByteArray_Truncate(void* ptr, int pos)
{
	static_cast<QByteArray*>(ptr)->truncate(pos);
}

void QByteArray_DestroyQByteArray(void* ptr)
{
	static_cast<QByteArray*>(ptr)->~QByteArray();
}

void* QByteArray_Chopped(void* ptr, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->chopped(l));
}

void* QByteArray_Left(void* ptr, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->left(l));
}

void* QByteArray_LeftJustified(void* ptr, int width, char* fill, char truncate)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->leftJustified(width, *fill, truncate != 0));
}

void* QByteArray_Mid(void* ptr, int pos, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->mid(pos, l));
}

void* QByteArray_Repeated(void* ptr, int times)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->repeated(times));
}

void* QByteArray_Right(void* ptr, int l)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->right(l));
}

void* QByteArray_RightJustified(void* ptr, int width, char* fill, char truncate)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->rightJustified(width, *fill, truncate != 0));
}

void* QByteArray_Simplified(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->simplified());
}

void* QByteArray_ToBase64(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toBase64());
}

void* QByteArray_ToBase642(void* ptr, long long options)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toBase64(static_cast<QByteArray::Base64Option>(options)));
}

void* QByteArray_ToHex(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toHex());
}

void* QByteArray_ToHex2(void* ptr, char* separator)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toHex(*separator));
}

void* QByteArray_ToLower(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toLower());
}

void* QByteArray_ToPercentEncoding(void* ptr, void* exclude, void* include, char* percent)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toPercentEncoding(*static_cast<QByteArray*>(exclude), *static_cast<QByteArray*>(include), *percent));
}

void* QByteArray_ToUpper(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->toUpper());
}

void* QByteArray_Trimmed(void* ptr)
{
	return new QByteArray(static_cast<QByteArray*>(ptr)->trimmed());
}

struct QtCore_PackedList QByteArray_Split(void* ptr, char* sep)
{
	return ({ QList<QByteArray>* tmpValue17cac8 = new QList<QByteArray>(static_cast<QByteArray*>(ptr)->split(*sep)); QtCore_PackedList { tmpValue17cac8, tmpValue17cac8->size() }; });
}

char QByteArray_Contains3(void* ptr, char* ch)
{
	return static_cast<QByteArray*>(ptr)->contains(*ch);
}

char QByteArray_Contains(void* ptr, void* ba)
{
	return static_cast<QByteArray*>(ptr)->contains(*static_cast<QByteArray*>(ba));
}

char QByteArray_Contains2(void* ptr, char* str)
{
	return static_cast<QByteArray*>(ptr)->contains(const_cast<const char*>(str));
}

char QByteArray_EndsWith2(void* ptr, char* ch)
{
	return static_cast<QByteArray*>(ptr)->endsWith(*ch);
}

char QByteArray_EndsWith(void* ptr, void* ba)
{
	return static_cast<QByteArray*>(ptr)->endsWith(*static_cast<QByteArray*>(ba));
}

char QByteArray_EndsWith3(void* ptr, char* str)
{
	return static_cast<QByteArray*>(ptr)->endsWith(const_cast<const char*>(str));
}

char QByteArray_IsEmpty(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->isEmpty();
}

char QByteArray_IsLower(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->isLower();
}

char QByteArray_IsNull(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->isNull();
}

char QByteArray_IsUpper(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->isUpper();
}

char QByteArray_StartsWith2(void* ptr, char* ch)
{
	return static_cast<QByteArray*>(ptr)->startsWith(*ch);
}

char QByteArray_StartsWith(void* ptr, void* ba)
{
	return static_cast<QByteArray*>(ptr)->startsWith(*static_cast<QByteArray*>(ba));
}

char QByteArray_StartsWith3(void* ptr, char* str)
{
	return static_cast<QByteArray*>(ptr)->startsWith(const_cast<const char*>(str));
}

struct QtCore_PackedString QByteArray_At(void* ptr, int i)
{
	return ({ char t8d8fc5 = static_cast<QByteArray*>(ptr)->at(i); QtCore_PackedString { &t8d8fc5, -1 }; });
}

struct QtCore_PackedString QByteArray_Back(void* ptr)
{
	return ({ char te8eea8 = static_cast<QByteArray*>(ptr)->back(); QtCore_PackedString { &te8eea8, -1 }; });
}

struct QtCore_PackedString QByteArray_Front(void* ptr)
{
	return ({ char td65117 = static_cast<QByteArray*>(ptr)->front(); QtCore_PackedString { &td65117, -1 }; });
}

struct QtCore_PackedString QByteArray_ConstData(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QByteArray*>(ptr)->constData()), static_cast<QByteArray*>(ptr)->size() };
}

struct QtCore_PackedString QByteArray_Data2(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QByteArray*>(ptr)->data()), static_cast<QByteArray*>(ptr)->size() };
}

double QByteArray_ToDouble(void* ptr, char* ok)
{
	return static_cast<QByteArray*>(ptr)->toDouble(reinterpret_cast<bool*>(ok));
}

float QByteArray_ToFloat(void* ptr, char* ok)
{
	return static_cast<QByteArray*>(ptr)->toFloat(reinterpret_cast<bool*>(ok));
}

int QByteArray_Capacity(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->capacity();
}

int QByteArray_Compare2(void* ptr, void* a, long long cs)
{
	return static_cast<QByteArray*>(ptr)->compare(*static_cast<QByteArray*>(a), static_cast<Qt::CaseSensitivity>(cs));
}

int QByteArray_Compare(void* ptr, char* c, long long cs)
{
	return static_cast<QByteArray*>(ptr)->compare(const_cast<const char*>(c), static_cast<Qt::CaseSensitivity>(cs));
}

int QByteArray_Count4(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->count();
}

int QByteArray_Count3(void* ptr, char* ch)
{
	return static_cast<QByteArray*>(ptr)->count(*ch);
}

int QByteArray_Count(void* ptr, void* ba)
{
	return static_cast<QByteArray*>(ptr)->count(*static_cast<QByteArray*>(ba));
}

int QByteArray_Count2(void* ptr, char* str)
{
	return static_cast<QByteArray*>(ptr)->count(const_cast<const char*>(str));
}

int QByteArray_IndexOf3(void* ptr, char* ch, int from)
{
	return static_cast<QByteArray*>(ptr)->indexOf(*ch, from);
}

int QByteArray_IndexOf(void* ptr, void* ba, int from)
{
	return static_cast<QByteArray*>(ptr)->indexOf(*static_cast<QByteArray*>(ba), from);
}

int QByteArray_IndexOf4(void* ptr, struct QtCore_PackedString str, int from)
{
	return static_cast<QByteArray*>(ptr)->indexOf(QString::fromUtf8(str.data, str.len), from);
}

int QByteArray_IndexOf2(void* ptr, char* str, int from)
{
	return static_cast<QByteArray*>(ptr)->indexOf(const_cast<const char*>(str), from);
}

int QByteArray_LastIndexOf3(void* ptr, char* ch, int from)
{
	return static_cast<QByteArray*>(ptr)->lastIndexOf(*ch, from);
}

int QByteArray_LastIndexOf(void* ptr, void* ba, int from)
{
	return static_cast<QByteArray*>(ptr)->lastIndexOf(*static_cast<QByteArray*>(ba), from);
}

int QByteArray_LastIndexOf4(void* ptr, struct QtCore_PackedString str, int from)
{
	return static_cast<QByteArray*>(ptr)->lastIndexOf(QString::fromUtf8(str.data, str.len), from);
}

int QByteArray_LastIndexOf2(void* ptr, char* str, int from)
{
	return static_cast<QByteArray*>(ptr)->lastIndexOf(const_cast<const char*>(str), from);
}

int QByteArray_Length(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->length();
}

int QByteArray_Size(void* ptr)
{
	return static_cast<QByteArray*>(ptr)->size();
}

int QByteArray_ToInt(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toInt(reinterpret_cast<bool*>(ok), base);
}

long QByteArray_ToLong(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toLong(reinterpret_cast<bool*>(ok), base);
}

long long QByteArray_ToLongLong(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toLongLong(reinterpret_cast<bool*>(ok), base);
}

unsigned long long QByteArray_ToULongLong(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toULongLong(reinterpret_cast<bool*>(ok), base);
}

short QByteArray_ToShort(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toShort(reinterpret_cast<bool*>(ok), base);
}

unsigned int QByteArray_ToUInt(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toUInt(reinterpret_cast<bool*>(ok), base);
}

unsigned long QByteArray_ToULong(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toULong(reinterpret_cast<bool*>(ok), base);
}

unsigned short QByteArray_ToUShort(void* ptr, char* ok, int base)
{
	return static_cast<QByteArray*>(ptr)->toUShort(reinterpret_cast<bool*>(ok), base);
}

void* QByteArray___split_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QByteArray___split_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QByteArray___split_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QByteArrayList_Join(void* ptr)
{
	return new QByteArray(static_cast<QByteArrayList*>(ptr)->join());
}

void* QByteArrayList_Join3(void* ptr, char* separator)
{
	return new QByteArray(static_cast<QByteArrayList*>(ptr)->join(*separator));
}

void* QByteArrayList_Join2(void* ptr, void* separator)
{
	return new QByteArray(static_cast<QByteArrayList*>(ptr)->join(*static_cast<QByteArray*>(separator)));
}

int QCborValue_False_Type()
{
	return QCborValue::False;
}

int QCborValue_True_Type()
{
	return QCborValue::True;
}

int QCborValue_Null_Type()
{
	return QCborValue::Null;
}

int QCborValue_Undefined_Type()
{
	return QCborValue::Undefined;
}

Q_DECLARE_METATYPE(QChar)
Q_DECLARE_METATYPE(QChar*)
void* QChar_QChar_FromLatin1(char* c)
{
	return new QChar(QChar::fromLatin1(*c));
}

void* QChar_NewQChar()
{
	return new QChar();
}

void* QChar_NewQChar7(long long ch)
{
	return new QChar(static_cast<QChar::SpecialCharacter>(ch));
}

void* QChar_NewQChar8(void* ch)
{
	return new QChar(*static_cast<QLatin1Char*>(ch));
}

void* QChar_NewQChar11(char* ch)
{
	return new QChar(*ch);
}

void* QChar_NewQChar6(int code)
{
	return new QChar(code);
}

void* QChar_NewQChar4(short code)
{
	return new QChar(code);
}

void* QChar_NewQChar3(char* cell, char* row)
{
	return new QChar(*static_cast<uchar*>(static_cast<void*>(cell)), *static_cast<uchar*>(static_cast<void*>(row)));
}

void* QChar_NewQChar12(char* ch)
{
	return new QChar(*static_cast<uchar*>(static_cast<void*>(ch)));
}

void* QChar_NewQChar5(unsigned int code)
{
	return new QChar(code);
}

void* QChar_NewQChar2(unsigned short code)
{
	return new QChar(code);
}

long long QChar_QChar_Category2(unsigned int ucs4)
{
	return QChar::category(ucs4);
}

long long QChar_QChar_DecompositionTag2(unsigned int ucs4)
{
	return QChar::decompositionTag(ucs4);
}

long long QChar_QChar_Direction2(unsigned int ucs4)
{
	return QChar::direction(ucs4);
}

long long QChar_QChar_JoiningType2(unsigned int ucs4)
{
	return QChar::joiningType(ucs4);
}

long long QChar_QChar_Script2(unsigned int ucs4)
{
	return QChar::script(ucs4);
}

long long QChar_QChar_CurrentUnicodeVersion()
{
	return QChar::currentUnicodeVersion();
}

long long QChar_QChar_UnicodeVersion2(unsigned int ucs4)
{
	return QChar::unicodeVersion(ucs4);
}

struct QtCore_PackedString QChar_QChar_Decomposition2(unsigned int ucs4)
{
	return ({ QByteArray tae885b = QChar::decomposition(ucs4).toUtf8(); QtCore_PackedString { const_cast<char*>(tae885b.prepend("WHITESPACE").constData()+10), tae885b.size()-10 }; });
}

char QChar_QChar_HasMirrored2(unsigned int ucs4)
{
	return QChar::hasMirrored(ucs4);
}

char QChar_QChar_IsDigit2(unsigned int ucs4)
{
	return QChar::isDigit(ucs4);
}

char QChar_QChar_IsHighSurrogate2(unsigned int ucs4)
{
	return QChar::isHighSurrogate(ucs4);
}

char QChar_QChar_IsLetter2(unsigned int ucs4)
{
	return QChar::isLetter(ucs4);
}

char QChar_QChar_IsLetterOrNumber2(unsigned int ucs4)
{
	return QChar::isLetterOrNumber(ucs4);
}

char QChar_QChar_IsLowSurrogate2(unsigned int ucs4)
{
	return QChar::isLowSurrogate(ucs4);
}

char QChar_QChar_IsLower2(unsigned int ucs4)
{
	return QChar::isLower(ucs4);
}

char QChar_QChar_IsMark2(unsigned int ucs4)
{
	return QChar::isMark(ucs4);
}

char QChar_QChar_IsNonCharacter2(unsigned int ucs4)
{
	return QChar::isNonCharacter(ucs4);
}

char QChar_QChar_IsNumber2(unsigned int ucs4)
{
	return QChar::isNumber(ucs4);
}

char QChar_QChar_IsPrint2(unsigned int ucs4)
{
	return QChar::isPrint(ucs4);
}

char QChar_QChar_IsPunct2(unsigned int ucs4)
{
	return QChar::isPunct(ucs4);
}

char QChar_QChar_IsSpace2(unsigned int ucs4)
{
	return QChar::isSpace(ucs4);
}

char QChar_QChar_IsSurrogate2(unsigned int ucs4)
{
	return QChar::isSurrogate(ucs4);
}

char QChar_QChar_IsSymbol2(unsigned int ucs4)
{
	return QChar::isSymbol(ucs4);
}

char QChar_QChar_IsTitleCase2(unsigned int ucs4)
{
	return QChar::isTitleCase(ucs4);
}

char QChar_QChar_IsUpper2(unsigned int ucs4)
{
	return QChar::isUpper(ucs4);
}

char QChar_QChar_RequiresSurrogates(unsigned int ucs4)
{
	return QChar::requiresSurrogates(ucs4);
}

int QChar_QChar_DigitValue2(unsigned int ucs4)
{
	return QChar::digitValue(ucs4);
}

unsigned int QChar_QChar_MirroredChar2(unsigned int ucs4)
{
	return QChar::mirroredChar(ucs4);
}

unsigned int QChar_QChar_SurrogateToUcs42(void* high, void* low)
{
	return QChar::surrogateToUcs4(*static_cast<QChar*>(high), *static_cast<QChar*>(low));
}

unsigned int QChar_QChar_SurrogateToUcs4(unsigned short high, unsigned short low)
{
	return QChar::surrogateToUcs4(high, low);
}

unsigned int QChar_QChar_ToCaseFolded2(unsigned int ucs4)
{
	return QChar::toCaseFolded(ucs4);
}

unsigned int QChar_QChar_ToLower2(unsigned int ucs4)
{
	return QChar::toLower(ucs4);
}

unsigned int QChar_QChar_ToTitleCase2(unsigned int ucs4)
{
	return QChar::toTitleCase(ucs4);
}

unsigned int QChar_QChar_ToUpper2(unsigned int ucs4)
{
	return QChar::toUpper(ucs4);
}

unsigned short QChar_Unicode2(void* ptr)
{
	return static_cast<QChar*>(ptr)->unicode();
}

unsigned short QChar_QChar_HighSurrogate(unsigned int ucs4)
{
	return QChar::highSurrogate(ucs4);
}

unsigned short QChar_QChar_LowSurrogate(unsigned int ucs4)
{
	return QChar::lowSurrogate(ucs4);
}

void* QChar_MirroredChar(void* ptr)
{
	return new QChar(static_cast<QChar*>(ptr)->mirroredChar());
}

void* QChar_ToCaseFolded(void* ptr)
{
	return new QChar(static_cast<QChar*>(ptr)->toCaseFolded());
}

void* QChar_ToLower(void* ptr)
{
	return new QChar(static_cast<QChar*>(ptr)->toLower());
}

void* QChar_ToTitleCase(void* ptr)
{
	return new QChar(static_cast<QChar*>(ptr)->toTitleCase());
}

void* QChar_ToUpper(void* ptr)
{
	return new QChar(static_cast<QChar*>(ptr)->toUpper());
}

long long QChar_Category(void* ptr)
{
	return static_cast<QChar*>(ptr)->category();
}

long long QChar_DecompositionTag(void* ptr)
{
	return static_cast<QChar*>(ptr)->decompositionTag();
}

long long QChar_Direction(void* ptr)
{
	return static_cast<QChar*>(ptr)->direction();
}

long long QChar_JoiningType(void* ptr)
{
	return static_cast<QChar*>(ptr)->joiningType();
}

long long QChar_Script(void* ptr)
{
	return static_cast<QChar*>(ptr)->script();
}

long long QChar_UnicodeVersion(void* ptr)
{
	return static_cast<QChar*>(ptr)->unicodeVersion();
}

struct QtCore_PackedString QChar_Decomposition(void* ptr)
{
	return ({ QByteArray t1c0ad1 = static_cast<QChar*>(ptr)->decomposition().toUtf8(); QtCore_PackedString { const_cast<char*>(t1c0ad1.prepend("WHITESPACE").constData()+10), t1c0ad1.size()-10 }; });
}

char QChar_HasMirrored(void* ptr)
{
	return static_cast<QChar*>(ptr)->hasMirrored();
}

char QChar_IsDigit(void* ptr)
{
	return static_cast<QChar*>(ptr)->isDigit();
}

char QChar_IsHighSurrogate(void* ptr)
{
	return static_cast<QChar*>(ptr)->isHighSurrogate();
}

char QChar_IsLetter(void* ptr)
{
	return static_cast<QChar*>(ptr)->isLetter();
}

char QChar_IsLetterOrNumber(void* ptr)
{
	return static_cast<QChar*>(ptr)->isLetterOrNumber();
}

char QChar_IsLowSurrogate(void* ptr)
{
	return static_cast<QChar*>(ptr)->isLowSurrogate();
}

char QChar_IsLower(void* ptr)
{
	return static_cast<QChar*>(ptr)->isLower();
}

char QChar_IsMark(void* ptr)
{
	return static_cast<QChar*>(ptr)->isMark();
}

char QChar_IsNonCharacter(void* ptr)
{
	return static_cast<QChar*>(ptr)->isNonCharacter();
}

char QChar_IsNull(void* ptr)
{
	return static_cast<QChar*>(ptr)->isNull();
}

char QChar_IsNumber(void* ptr)
{
	return static_cast<QChar*>(ptr)->isNumber();
}

char QChar_IsPrint(void* ptr)
{
	return static_cast<QChar*>(ptr)->isPrint();
}

char QChar_IsPunct(void* ptr)
{
	return static_cast<QChar*>(ptr)->isPunct();
}

char QChar_IsSpace(void* ptr)
{
	return static_cast<QChar*>(ptr)->isSpace();
}

char QChar_IsSurrogate(void* ptr)
{
	return static_cast<QChar*>(ptr)->isSurrogate();
}

char QChar_IsSymbol(void* ptr)
{
	return static_cast<QChar*>(ptr)->isSymbol();
}

char QChar_IsTitleCase(void* ptr)
{
	return static_cast<QChar*>(ptr)->isTitleCase();
}

char QChar_IsUpper(void* ptr)
{
	return static_cast<QChar*>(ptr)->isUpper();
}

struct QtCore_PackedString QChar_ToLatin1(void* ptr)
{
	return ({ char t24c86e = static_cast<QChar*>(ptr)->toLatin1(); QtCore_PackedString { &t24c86e, -1 }; });
}

int QChar_DigitValue(void* ptr)
{
	return static_cast<QChar*>(ptr)->digitValue();
}

struct QtCore_PackedString QChar_Cell(void* ptr)
{
	return ({ uchar pret5084cd = static_cast<QChar*>(ptr)->cell(); char* t5084cd = static_cast<char*>(static_cast<void*>(&pret5084cd)); QtCore_PackedString { t5084cd, -1 }; });
}

struct QtCore_PackedString QChar_Row(void* ptr)
{
	return ({ uchar pret52b865 = static_cast<QChar*>(ptr)->row(); char* t52b865 = static_cast<char*>(static_cast<void*>(&pret52b865)); QtCore_PackedString { t52b865, -1 }; });
}

unsigned short QChar_Unicode(void* ptr)
{
	return static_cast<QChar*>(ptr)->unicode();
}

class MyQChildEvent: public QChildEvent
{
public:
	MyQChildEvent(QEvent::Type ty, QObject *child) : QChildEvent(ty, child) {QChildEvent_QChildEvent_QRegisterMetaType();};
};

Q_DECLARE_METATYPE(QChildEvent*)
Q_DECLARE_METATYPE(MyQChildEvent*)

int QChildEvent_QChildEvent_QRegisterMetaType(){qRegisterMetaType<QChildEvent*>(); return qRegisterMetaType<MyQChildEvent*>();}

void* QChildEvent_NewQChildEvent(long long ty, void* child)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(child))) {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QGraphicsObject*>(child));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(child))) {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QGraphicsWidget*>(child));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(child))) {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QLayout*>(child));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(child))) {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QWidget*>(child));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(child))) {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QWindow*>(child));
	} else {
		return new MyQChildEvent(static_cast<QEvent::Type>(ty), static_cast<QObject*>(child));
	}
}

void* QChildEvent_Child(void* ptr)
{
	return static_cast<QChildEvent*>(ptr)->child();
}

char QChildEvent_Added(void* ptr)
{
	return static_cast<QChildEvent*>(ptr)->added();
}

char QChildEvent_Polished(void* ptr)
{
	return static_cast<QChildEvent*>(ptr)->polished();
}

char QChildEvent_Removed(void* ptr)
{
	return static_cast<QChildEvent*>(ptr)->removed();
}

void* QChildEvent_C(void* ptr)
{
	return static_cast<QChildEvent*>(ptr)->c;
}

void QChildEvent_SetC(void* ptr, void* vqo)
{
	static_cast<QChildEvent*>(ptr)->c = static_cast<QObject*>(vqo);
}

class MyQCoreApplication: public QCoreApplication
{
public:
	MyQCoreApplication(int &argc, char **argv) : QCoreApplication(argc, argv) {QCoreApplication_QCoreApplication_QRegisterMetaType();};
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	void Signal_AboutToQuit() { callbackQCoreApplication_AboutToQuit(this); };
	void quit() { callbackQCoreApplication_Quit(this); };
	 ~MyQCoreApplication() { callbackQCoreApplication_DestroyQCoreApplication(this); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QCoreApplication*)
Q_DECLARE_METATYPE(MyQCoreApplication*)

int QCoreApplication_QCoreApplication_QRegisterMetaType(){qRegisterMetaType<QCoreApplication*>(); return qRegisterMetaType<MyQCoreApplication*>();}

void* QCoreApplication_QCoreApplication_EventDispatcher()
{
	return QCoreApplication::eventDispatcher();
}

void* QCoreApplication_QCoreApplication_Instance()
{
	return QCoreApplication::instance();
}

void* QCoreApplication_NewQCoreApplication(int argc, char* argv)
{
	static int argcs = argc;
	static char** argvs = static_cast<char**>(malloc(argcs * sizeof(char*)));

	QList<QByteArray> aList = QByteArray(argv).split('|');
	for (int i = 0; i < argcs; i++)
		argvs[i] = (new QByteArray(aList.at(i)))->data();

	return new MyQCoreApplication(argcs, argvs);
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_ApplicationDirPath()
{
	return ({ QByteArray t3c2a71 = QCoreApplication::applicationDirPath().toUtf8(); QtCore_PackedString { const_cast<char*>(t3c2a71.prepend("WHITESPACE").constData()+10), t3c2a71.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_ApplicationFilePath()
{
	return ({ QByteArray t189694 = QCoreApplication::applicationFilePath().toUtf8(); QtCore_PackedString { const_cast<char*>(t189694.prepend("WHITESPACE").constData()+10), t189694.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_ApplicationName()
{
	return ({ QByteArray t704b73 = QCoreApplication::applicationName().toUtf8(); QtCore_PackedString { const_cast<char*>(t704b73.prepend("WHITESPACE").constData()+10), t704b73.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_ApplicationVersion()
{
	return ({ QByteArray t9f1c49 = QCoreApplication::applicationVersion().toUtf8(); QtCore_PackedString { const_cast<char*>(t9f1c49.prepend("WHITESPACE").constData()+10), t9f1c49.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_OrganizationDomain()
{
	return ({ QByteArray t013a2e = QCoreApplication::organizationDomain().toUtf8(); QtCore_PackedString { const_cast<char*>(t013a2e.prepend("WHITESPACE").constData()+10), t013a2e.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_OrganizationName()
{
	return ({ QByteArray t6f3f58 = QCoreApplication::organizationName().toUtf8(); QtCore_PackedString { const_cast<char*>(t6f3f58.prepend("WHITESPACE").constData()+10), t6f3f58.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_Translate(char* context, char* sourceText, char* disambiguation, int n)
{
	return ({ QByteArray t901eb0 = QCoreApplication::translate(const_cast<const char*>(context), const_cast<const char*>(sourceText), const_cast<const char*>(disambiguation), n).toUtf8(); QtCore_PackedString { const_cast<char*>(t901eb0.prepend("WHITESPACE").constData()+10), t901eb0.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_Arguments()
{
	return ({ QByteArray tee588f = QCoreApplication::arguments().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tee588f.prepend("WHITESPACE").constData()+10), tee588f.size()-10 }; });
}

struct QtCore_PackedString QCoreApplication_QCoreApplication_LibraryPaths()
{
	return ({ QByteArray tec17c7 = QCoreApplication::libraryPaths().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tec17c7.prepend("WHITESPACE").constData()+10), tec17c7.size()-10 }; });
}

char QCoreApplication_QCoreApplication_ClosingDown()
{
	return QCoreApplication::closingDown();
}

char QCoreApplication_QCoreApplication_InstallTranslator(void* translationFile)
{
	return QCoreApplication::installTranslator(static_cast<QTranslator*>(translationFile));
}

char QCoreApplication_QCoreApplication_IsQuitLockEnabled()
{
	return QCoreApplication::isQuitLockEnabled();
}

char QCoreApplication_QCoreApplication_IsSetuidAllowed()
{
	return QCoreApplication::isSetuidAllowed();
}

char QCoreApplication_QCoreApplication_RemoveTranslator(void* translationFile)
{
	return QCoreApplication::removeTranslator(static_cast<QTranslator*>(translationFile));
}

char QCoreApplication_QCoreApplication_SendEvent(void* receiver, void* event)
{
	return QCoreApplication::sendEvent(static_cast<QObject*>(receiver), static_cast<QEvent*>(event));
}

char QCoreApplication_QCoreApplication_StartingUp()
{
	return QCoreApplication::startingUp();
}

char QCoreApplication_QCoreApplication_TestAttribute(long long attribute)
{
	return QCoreApplication::testAttribute(static_cast<Qt::ApplicationAttribute>(attribute));
}

int QCoreApplication_QCoreApplication_Exec()
{
	return QCoreApplication::exec();
}

long long QCoreApplication_QCoreApplication_ApplicationPid()
{
	return QCoreApplication::applicationPid();
}

void QCoreApplication_ConnectAboutToQuit(void* ptr, long long t)
{
	QObject::connect(static_cast<QCoreApplication*>(ptr), &QCoreApplication::aboutToQuit, static_cast<MyQCoreApplication*>(ptr), static_cast<void (MyQCoreApplication::*)()>(&MyQCoreApplication::Signal_AboutToQuit), static_cast<Qt::ConnectionType>(t));
}

void QCoreApplication_DisconnectAboutToQuit(void* ptr)
{
	QObject::disconnect(static_cast<QCoreApplication*>(ptr), &QCoreApplication::aboutToQuit, static_cast<MyQCoreApplication*>(ptr), static_cast<void (MyQCoreApplication::*)()>(&MyQCoreApplication::Signal_AboutToQuit));
}

void QCoreApplication_QCoreApplication_AddLibraryPath(struct QtCore_PackedString path)
{
	QCoreApplication::addLibraryPath(QString::fromUtf8(path.data, path.len));
}

void QCoreApplication_QCoreApplication_Exit(int returnCode)
{
	QCoreApplication::exit(returnCode);
}

void QCoreApplication_InstallNativeEventFilter(void* ptr, void* filterObj)
{
	static_cast<QCoreApplication*>(ptr)->installNativeEventFilter(static_cast<QAbstractNativeEventFilter*>(filterObj));
}

void QCoreApplication_QCoreApplication_PostEvent(void* receiver, void* event, int priority)
{
	QCoreApplication::postEvent(static_cast<QObject*>(receiver), static_cast<QEvent*>(event), priority);
}

void QCoreApplication_QCoreApplication_ProcessEvents(long long flags)
{
	QCoreApplication::processEvents(static_cast<QEventLoop::ProcessEventsFlag>(flags));
}

void QCoreApplication_QCoreApplication_ProcessEvents2(long long flags, int maxtime)
{
	QCoreApplication::processEvents(static_cast<QEventLoop::ProcessEventsFlag>(flags), maxtime);
}

void QCoreApplication_Quit(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QCoreApplication*>(ptr), "quit");
}

void QCoreApplication_QuitDefault(void* ptr)
{
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::quit();
}

void QCoreApplication_QCoreApplication_RemoveLibraryPath(struct QtCore_PackedString path)
{
	QCoreApplication::removeLibraryPath(QString::fromUtf8(path.data, path.len));
}

void QCoreApplication_RemoveNativeEventFilter(void* ptr, void* filterObject)
{
	static_cast<QCoreApplication*>(ptr)->removeNativeEventFilter(static_cast<QAbstractNativeEventFilter*>(filterObject));
}

void QCoreApplication_QCoreApplication_RemovePostedEvents(void* receiver, int eventType)
{
	QCoreApplication::removePostedEvents(static_cast<QObject*>(receiver), eventType);
}

void QCoreApplication_QCoreApplication_SendPostedEvents(void* receiver, int event_type)
{
	QCoreApplication::sendPostedEvents(static_cast<QObject*>(receiver), event_type);
}

void QCoreApplication_QCoreApplication_SetApplicationName(struct QtCore_PackedString application)
{
	QCoreApplication::setApplicationName(QString::fromUtf8(application.data, application.len));
}

void QCoreApplication_QCoreApplication_SetApplicationVersion(struct QtCore_PackedString version)
{
	QCoreApplication::setApplicationVersion(QString::fromUtf8(version.data, version.len));
}

void QCoreApplication_QCoreApplication_SetAttribute(long long attribute, char on)
{
	QCoreApplication::setAttribute(static_cast<Qt::ApplicationAttribute>(attribute), on != 0);
}

void QCoreApplication_QCoreApplication_SetEventDispatcher(void* eventDispatcher)
{
	QCoreApplication::setEventDispatcher(static_cast<QAbstractEventDispatcher*>(eventDispatcher));
}

void QCoreApplication_QCoreApplication_SetLibraryPaths(struct QtCore_PackedString paths)
{
	QCoreApplication::setLibraryPaths(QString::fromUtf8(paths.data, paths.len).split("¡¦!", QString::SkipEmptyParts));
}

void QCoreApplication_QCoreApplication_SetOrganizationDomain(struct QtCore_PackedString orgDomain)
{
	QCoreApplication::setOrganizationDomain(QString::fromUtf8(orgDomain.data, orgDomain.len));
}

void QCoreApplication_QCoreApplication_SetOrganizationName(struct QtCore_PackedString orgName)
{
	QCoreApplication::setOrganizationName(QString::fromUtf8(orgName.data, orgName.len));
}

void QCoreApplication_QCoreApplication_SetQuitLockEnabled(char enabled)
{
	QCoreApplication::setQuitLockEnabled(enabled != 0);
}

void QCoreApplication_QCoreApplication_SetSetuidAllowed(char allow)
{
	QCoreApplication::setSetuidAllowed(allow != 0);
}

void QCoreApplication_DestroyQCoreApplication(void* ptr)
{
	static_cast<QCoreApplication*>(ptr)->~QCoreApplication();
}

void QCoreApplication_DestroyQCoreApplicationDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

Q_DECLARE_METATYPE(QDataStream*)
void* QDataStream_NewQDataStream()
{
	return new QDataStream();
}

void* QDataStream_NewQDataStream3(void* a, long long mode)
{
	return new QDataStream(static_cast<QByteArray*>(a), static_cast<QIODevice::OpenModeFlag>(mode));
}

void* QDataStream_NewQDataStream2(void* d)
{
	return new QDataStream(static_cast<QIODevice*>(d));
}

void* QDataStream_NewQDataStream4(void* a)
{
	return new QDataStream(*static_cast<QByteArray*>(a));
}

char QDataStream_CommitTransaction(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->commitTransaction();
}

int QDataStream_ReadRawData(void* ptr, char* s, int l)
{
	return static_cast<QDataStream*>(ptr)->readRawData(s, l);
}

int QDataStream_SkipRawData(void* ptr, int l)
{
	return static_cast<QDataStream*>(ptr)->skipRawData(l);
}

int QDataStream_WriteRawData(void* ptr, char* s, int l)
{
	return static_cast<QDataStream*>(ptr)->writeRawData(const_cast<const char*>(s), l);
}

void QDataStream_AbortTransaction(void* ptr)
{
	static_cast<QDataStream*>(ptr)->abortTransaction();
}

void QDataStream_ResetStatus(void* ptr)
{
	static_cast<QDataStream*>(ptr)->resetStatus();
}

void QDataStream_RollbackTransaction(void* ptr)
{
	static_cast<QDataStream*>(ptr)->rollbackTransaction();
}

void QDataStream_SetByteOrder(void* ptr, long long bo)
{
	static_cast<QDataStream*>(ptr)->setByteOrder(static_cast<QDataStream::ByteOrder>(bo));
}

void QDataStream_SetDevice(void* ptr, void* d)
{
	static_cast<QDataStream*>(ptr)->setDevice(static_cast<QIODevice*>(d));
}

void QDataStream_SetFloatingPointPrecision(void* ptr, long long precision)
{
	static_cast<QDataStream*>(ptr)->setFloatingPointPrecision(static_cast<QDataStream::FloatingPointPrecision>(precision));
}

void QDataStream_SetStatus(void* ptr, long long status)
{
	static_cast<QDataStream*>(ptr)->setStatus(static_cast<QDataStream::Status>(status));
}

void QDataStream_SetVersion(void* ptr, int v)
{
	static_cast<QDataStream*>(ptr)->setVersion(v);
}

void QDataStream_StartTransaction(void* ptr)
{
	static_cast<QDataStream*>(ptr)->startTransaction();
}

void QDataStream_DestroyQDataStream(void* ptr)
{
	static_cast<QDataStream*>(ptr)->~QDataStream();
}

long long QDataStream_ByteOrder(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->byteOrder();
}

long long QDataStream_FloatingPointPrecision(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->floatingPointPrecision();
}

long long QDataStream_Status(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->status();
}

void* QDataStream_Device(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->device();
}

char QDataStream_AtEnd(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->atEnd();
}

int QDataStream_Version(void* ptr)
{
	return static_cast<QDataStream*>(ptr)->version();
}

Q_DECLARE_METATYPE(QDate)
Q_DECLARE_METATYPE(QDate*)
void* QDate_QDate_CurrentDate()
{
	return new QDate(QDate::currentDate());
}

void* QDate_QDate_FromJulianDay(long long jd)
{
	return new QDate(QDate::fromJulianDay(jd));
}

void* QDate_QDate_FromString(struct QtCore_PackedString stri, long long format)
{
	return new QDate(QDate::fromString(QString::fromUtf8(stri.data, stri.len), static_cast<Qt::DateFormat>(format)));
}

void* QDate_QDate_FromString2(struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QDate(QDate::fromString(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

void* QDate_NewQDate()
{
	return new QDate();
}

void* QDate_NewQDate3(int y, int m, int d)
{
	return new QDate(y, m, d);
}

char QDate_QDate_IsLeapYear(int year)
{
	return QDate::isLeapYear(year);
}

char QDate_QDate_IsValid2(int year, int month, int day)
{
	return QDate::isValid(year, month, day);
}

char QDate_SetDate(void* ptr, int year, int month, int day)
{
	return static_cast<QDate*>(ptr)->setDate(year, month, day);
}

void* QDate_AddDays(void* ptr, long long ndays)
{
	return new QDate(static_cast<QDate*>(ptr)->addDays(ndays));
}

void* QDate_AddMonths(void* ptr, int nmonths)
{
	return new QDate(static_cast<QDate*>(ptr)->addMonths(nmonths));
}

void* QDate_AddYears(void* ptr, int nyears)
{
	return new QDate(static_cast<QDate*>(ptr)->addYears(nyears));
}

struct QtCore_PackedString QDate_ToString3(void* ptr, void* format)
{
	return ({ QByteArray tab5488 = static_cast<QDate*>(ptr)->toString(*static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(tab5488.prepend("WHITESPACE").constData()+10), tab5488.size()-10 }; });
}

struct QtCore_PackedString QDate_ToString2(void* ptr, long long format)
{
	return ({ QByteArray tfa9ec6 = static_cast<QDate*>(ptr)->toString(static_cast<Qt::DateFormat>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(tfa9ec6.prepend("WHITESPACE").constData()+10), tfa9ec6.size()-10 }; });
}

struct QtCore_PackedString QDate_ToString(void* ptr, struct QtCore_PackedString format)
{
	return ({ QByteArray te68bf6 = static_cast<QDate*>(ptr)->toString(QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(te68bf6.prepend("WHITESPACE").constData()+10), te68bf6.size()-10 }; });
}

char QDate_IsNull(void* ptr)
{
	return static_cast<QDate*>(ptr)->isNull();
}

char QDate_IsValid(void* ptr)
{
	return static_cast<QDate*>(ptr)->isValid();
}

int QDate_Day(void* ptr)
{
	return static_cast<QDate*>(ptr)->day();
}

int QDate_DayOfWeek(void* ptr)
{
	return static_cast<QDate*>(ptr)->dayOfWeek();
}

int QDate_DayOfYear(void* ptr)
{
	return static_cast<QDate*>(ptr)->dayOfYear();
}

int QDate_DaysInMonth(void* ptr)
{
	return static_cast<QDate*>(ptr)->daysInMonth();
}

int QDate_DaysInYear(void* ptr)
{
	return static_cast<QDate*>(ptr)->daysInYear();
}

int QDate_Month(void* ptr)
{
	return static_cast<QDate*>(ptr)->month();
}

int QDate_WeekNumber(void* ptr, int yearNumber)
{
	return static_cast<QDate*>(ptr)->weekNumber(&yearNumber);
}

int QDate_Year(void* ptr)
{
	return static_cast<QDate*>(ptr)->year();
}

long long QDate_DaysTo(void* ptr, void* d)
{
	return static_cast<QDate*>(ptr)->daysTo(*static_cast<QDate*>(d));
}

long long QDate_ToJulianDay(void* ptr)
{
	return static_cast<QDate*>(ptr)->toJulianDay();
}

void QDate_GetDate(void* ptr, int year, int month, int day)
{
	static_cast<QDate*>(ptr)->getDate(&year, &month, &day);
}

Q_DECLARE_METATYPE(QDateTime)
Q_DECLARE_METATYPE(QDateTime*)
void* QDateTime_QDateTime_CurrentDateTime()
{
	return new QDateTime(QDateTime::currentDateTime());
}

void* QDateTime_QDateTime_CurrentDateTimeUtc()
{
	return new QDateTime(QDateTime::currentDateTimeUtc());
}

void* QDateTime_QDateTime_FromMSecsSinceEpoch(long long msecs)
{
	return new QDateTime(QDateTime::fromMSecsSinceEpoch(msecs));
}

void* QDateTime_QDateTime_FromMSecsSinceEpoch2(long long msecs, long long spec, int offsetSeconds)
{
	return new QDateTime(QDateTime::fromMSecsSinceEpoch(msecs, static_cast<Qt::TimeSpec>(spec), offsetSeconds));
}

void* QDateTime_QDateTime_FromMSecsSinceEpoch3(long long msecs, void* timeZone)
{
	return new QDateTime(QDateTime::fromMSecsSinceEpoch(msecs, *static_cast<QTimeZone*>(timeZone)));
}

void* QDateTime_QDateTime_FromSecsSinceEpoch(long long secs, long long spec, int offsetSeconds)
{
	return new QDateTime(QDateTime::fromSecsSinceEpoch(secs, static_cast<Qt::TimeSpec>(spec), offsetSeconds));
}

void* QDateTime_QDateTime_FromSecsSinceEpoch2(long long secs, void* timeZone)
{
	return new QDateTime(QDateTime::fromSecsSinceEpoch(secs, *static_cast<QTimeZone*>(timeZone)));
}

void* QDateTime_QDateTime_FromString(struct QtCore_PackedString stri, long long format)
{
	return new QDateTime(QDateTime::fromString(QString::fromUtf8(stri.data, stri.len), static_cast<Qt::DateFormat>(format)));
}

void* QDateTime_QDateTime_FromString2(struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QDateTime(QDateTime::fromString(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

void* QDateTime_NewQDateTime()
{
	return new QDateTime();
}

void* QDateTime_NewQDateTime7(void* other)
{
	return new QDateTime(*static_cast<QDateTime*>(other));
}

void* QDateTime_NewQDateTime2(void* date)
{
	return new QDateTime(*static_cast<QDate*>(date));
}

void* QDateTime_NewQDateTime3(void* date, void* ti, long long spec)
{
	return new QDateTime(*static_cast<QDate*>(date), *static_cast<QTime*>(ti), static_cast<Qt::TimeSpec>(spec));
}

void* QDateTime_NewQDateTime4(void* date, void* ti, long long spec, int offsetSeconds)
{
	return new QDateTime(*static_cast<QDate*>(date), *static_cast<QTime*>(ti), static_cast<Qt::TimeSpec>(spec), offsetSeconds);
}

void* QDateTime_NewQDateTime5(void* date, void* ti, void* timeZone)
{
	return new QDateTime(*static_cast<QDate*>(date), *static_cast<QTime*>(ti), *static_cast<QTimeZone*>(timeZone));
}

void* QDateTime_NewQDateTime6(void* other)
{
	return new QDateTime(*static_cast<QDateTime*>(other));
}

long long QDateTime_QDateTime_CurrentMSecsSinceEpoch()
{
	return QDateTime::currentMSecsSinceEpoch();
}

long long QDateTime_QDateTime_CurrentSecsSinceEpoch()
{
	return QDateTime::currentSecsSinceEpoch();
}

void QDateTime_SetDate(void* ptr, void* date)
{
	static_cast<QDateTime*>(ptr)->setDate(*static_cast<QDate*>(date));
}

void QDateTime_SetMSecsSinceEpoch(void* ptr, long long msecs)
{
	static_cast<QDateTime*>(ptr)->setMSecsSinceEpoch(msecs);
}

void QDateTime_SetOffsetFromUtc(void* ptr, int offsetSeconds)
{
	static_cast<QDateTime*>(ptr)->setOffsetFromUtc(offsetSeconds);
}

void QDateTime_SetSecsSinceEpoch(void* ptr, long long secs)
{
	static_cast<QDateTime*>(ptr)->setSecsSinceEpoch(secs);
}

void QDateTime_SetTime(void* ptr, void* ti)
{
	static_cast<QDateTime*>(ptr)->setTime(*static_cast<QTime*>(ti));
}

void QDateTime_SetTimeSpec(void* ptr, long long spec)
{
	static_cast<QDateTime*>(ptr)->setTimeSpec(static_cast<Qt::TimeSpec>(spec));
}

void QDateTime_SetTimeZone(void* ptr, void* toZone)
{
	static_cast<QDateTime*>(ptr)->setTimeZone(*static_cast<QTimeZone*>(toZone));
}

void QDateTime_Swap(void* ptr, void* other)
{
	static_cast<QDateTime*>(ptr)->swap(*static_cast<QDateTime*>(other));
}

void QDateTime_DestroyQDateTime(void* ptr)
{
	static_cast<QDateTime*>(ptr)->~QDateTime();
}

void* QDateTime_Date(void* ptr)
{
	return new QDate(static_cast<QDateTime*>(ptr)->date());
}

void* QDateTime_AddDays(void* ptr, long long ndays)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->addDays(ndays));
}

void* QDateTime_AddMSecs(void* ptr, long long msecs)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->addMSecs(msecs));
}

void* QDateTime_AddMonths(void* ptr, int nmonths)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->addMonths(nmonths));
}

void* QDateTime_AddSecs(void* ptr, long long s)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->addSecs(s));
}

void* QDateTime_AddYears(void* ptr, int nyears)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->addYears(nyears));
}

void* QDateTime_ToLocalTime(void* ptr)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->toLocalTime());
}

void* QDateTime_ToOffsetFromUtc(void* ptr, int offsetSeconds)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->toOffsetFromUtc(offsetSeconds));
}

void* QDateTime_ToTimeSpec(void* ptr, long long spec)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->toTimeSpec(static_cast<Qt::TimeSpec>(spec)));
}

void* QDateTime_ToTimeZone(void* ptr, void* timeZone)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->toTimeZone(*static_cast<QTimeZone*>(timeZone)));
}

void* QDateTime_ToUTC(void* ptr)
{
	return new QDateTime(static_cast<QDateTime*>(ptr)->toUTC());
}

struct QtCore_PackedString QDateTime_TimeZoneAbbreviation(void* ptr)
{
	return ({ QByteArray te524d2 = static_cast<QDateTime*>(ptr)->timeZoneAbbreviation().toUtf8(); QtCore_PackedString { const_cast<char*>(te524d2.prepend("WHITESPACE").constData()+10), te524d2.size()-10 }; });
}

struct QtCore_PackedString QDateTime_ToString3(void* ptr, void* format)
{
	return ({ QByteArray t95196e = static_cast<QDateTime*>(ptr)->toString(*static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t95196e.prepend("WHITESPACE").constData()+10), t95196e.size()-10 }; });
}

struct QtCore_PackedString QDateTime_ToString2(void* ptr, long long format)
{
	return ({ QByteArray tbd5547 = static_cast<QDateTime*>(ptr)->toString(static_cast<Qt::DateFormat>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(tbd5547.prepend("WHITESPACE").constData()+10), tbd5547.size()-10 }; });
}

struct QtCore_PackedString QDateTime_ToString(void* ptr, struct QtCore_PackedString format)
{
	return ({ QByteArray t78bcae = static_cast<QDateTime*>(ptr)->toString(QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t78bcae.prepend("WHITESPACE").constData()+10), t78bcae.size()-10 }; });
}

void* QDateTime_Time(void* ptr)
{
	return new QTime(static_cast<QDateTime*>(ptr)->time());
}

void* QDateTime_TimeZone(void* ptr)
{
	return new QTimeZone(static_cast<QDateTime*>(ptr)->timeZone());
}

long long QDateTime_TimeSpec(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->timeSpec();
}

char QDateTime_IsDaylightTime(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->isDaylightTime();
}

char QDateTime_IsNull(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->isNull();
}

char QDateTime_IsValid(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->isValid();
}

int QDateTime_OffsetFromUtc(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->offsetFromUtc();
}

long long QDateTime_DaysTo(void* ptr, void* other)
{
	return static_cast<QDateTime*>(ptr)->daysTo(*static_cast<QDateTime*>(other));
}

long long QDateTime_MsecsTo(void* ptr, void* other)
{
	return static_cast<QDateTime*>(ptr)->msecsTo(*static_cast<QDateTime*>(other));
}

long long QDateTime_SecsTo(void* ptr, void* other)
{
	return static_cast<QDateTime*>(ptr)->secsTo(*static_cast<QDateTime*>(other));
}

long long QDateTime_ToMSecsSinceEpoch(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->toMSecsSinceEpoch();
}

long long QDateTime_ToSecsSinceEpoch(void* ptr)
{
	return static_cast<QDateTime*>(ptr)->toSecsSinceEpoch();
}

Q_DECLARE_METATYPE(QEasingCurve*)
void* QEasingCurve_NewQEasingCurve3(void* other)
{
	return new QEasingCurve(*static_cast<QEasingCurve*>(other));
}

void* QEasingCurve_NewQEasingCurve(long long ty)
{
	return new QEasingCurve(static_cast<QEasingCurve::Type>(ty));
}

void* QEasingCurve_NewQEasingCurve2(void* other)
{
	return new QEasingCurve(*static_cast<QEasingCurve*>(other));
}

void QEasingCurve_AddCubicBezierSegment(void* ptr, void* c1, void* c2, void* endPoint)
{
	static_cast<QEasingCurve*>(ptr)->addCubicBezierSegment(*static_cast<QPointF*>(c1), *static_cast<QPointF*>(c2), *static_cast<QPointF*>(endPoint));
}

void QEasingCurve_AddTCBSegment(void* ptr, void* nextPoint, double t, double c, double b)
{
	static_cast<QEasingCurve*>(ptr)->addTCBSegment(*static_cast<QPointF*>(nextPoint), t, c, b);
}

void QEasingCurve_SetAmplitude(void* ptr, double amplitude)
{
	static_cast<QEasingCurve*>(ptr)->setAmplitude(amplitude);
}

void QEasingCurve_SetOvershoot(void* ptr, double overshoot)
{
	static_cast<QEasingCurve*>(ptr)->setOvershoot(overshoot);
}

void QEasingCurve_SetPeriod(void* ptr, double period)
{
	static_cast<QEasingCurve*>(ptr)->setPeriod(period);
}

void QEasingCurve_SetType(void* ptr, long long ty)
{
	static_cast<QEasingCurve*>(ptr)->setType(static_cast<QEasingCurve::Type>(ty));
}

void QEasingCurve_Swap(void* ptr, void* other)
{
	static_cast<QEasingCurve*>(ptr)->swap(*static_cast<QEasingCurve*>(other));
}

void QEasingCurve_DestroyQEasingCurve(void* ptr)
{
	static_cast<QEasingCurve*>(ptr)->~QEasingCurve();
}

long long QEasingCurve_Type(void* ptr)
{
	return static_cast<QEasingCurve*>(ptr)->type();
}

struct QtCore_PackedList QEasingCurve_ToCubicSpline(void* ptr)
{
	return ({ QVector<QPointF>* tmpValueb4db1b = new QVector<QPointF>(static_cast<QEasingCurve*>(ptr)->toCubicSpline()); QtCore_PackedList { tmpValueb4db1b, tmpValueb4db1b->size() }; });
}

double QEasingCurve_Amplitude(void* ptr)
{
	return static_cast<QEasingCurve*>(ptr)->amplitude();
}

double QEasingCurve_Overshoot(void* ptr)
{
	return static_cast<QEasingCurve*>(ptr)->overshoot();
}

double QEasingCurve_Period(void* ptr)
{
	return static_cast<QEasingCurve*>(ptr)->period();
}

double QEasingCurve_ValueForProgress(void* ptr, double progress)
{
	return static_cast<QEasingCurve*>(ptr)->valueForProgress(progress);
}

void* QEasingCurve___cubicBezierSpline_atList(void* ptr, int i)
{
	return ({ QPointF tmpValue = ({QPointF tmp = static_cast<QList<QPointF>*>(ptr)->at(i); if (i == static_cast<QList<QPointF>*>(ptr)->size()-1) { static_cast<QList<QPointF>*>(ptr)->~QList(); free(ptr); }; tmp; }); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void QEasingCurve___cubicBezierSpline_setList(void* ptr, void* i)
{
	static_cast<QList<QPointF>*>(ptr)->append(*static_cast<QPointF*>(i));
}

void* QEasingCurve___cubicBezierSpline_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QPointF>();
}

void* QEasingCurve___toCubicSpline_atList(void* ptr, int i)
{
	return ({ QPointF tmpValue = ({QPointF tmp = static_cast<QVector<QPointF>*>(ptr)->at(i); if (i == static_cast<QVector<QPointF>*>(ptr)->size()-1) { static_cast<QVector<QPointF>*>(ptr)->~QVector(); free(ptr); }; tmp; }); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void QEasingCurve___toCubicSpline_setList(void* ptr, void* i)
{
	static_cast<QVector<QPointF>*>(ptr)->append(*static_cast<QPointF*>(i));
}

void* QEasingCurve___toCubicSpline_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<QPointF>();
}

class MyQEvent: public QEvent
{
public:
	MyQEvent(QEvent::Type ty) : QEvent(ty) {QEvent_QEvent_QRegisterMetaType();};
	 ~MyQEvent() { callbackQEvent_DestroyQEvent(this); };
};

Q_DECLARE_METATYPE(QEvent*)
Q_DECLARE_METATYPE(MyQEvent*)

int QEvent_QEvent_QRegisterMetaType(){qRegisterMetaType<QEvent*>(); return qRegisterMetaType<MyQEvent*>();}

void* QEvent_NewQEvent(long long ty)
{
	return new MyQEvent(static_cast<QEvent::Type>(ty));
}

int QEvent_QEvent_RegisterEventType(int hint)
{
	return QEvent::registerEventType(hint);
}

void QEvent_Accept(void* ptr)
{
	static_cast<QEvent*>(ptr)->accept();
}

void QEvent_Ignore(void* ptr)
{
	static_cast<QEvent*>(ptr)->ignore();
}

void QEvent_SetAccepted(void* ptr, char accepted)
{
	static_cast<QEvent*>(ptr)->setAccepted(accepted != 0);
}

void QEvent_DestroyQEvent(void* ptr)
{
	static_cast<QEvent*>(ptr)->~QEvent();
}

void QEvent_DestroyQEventDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

long long QEvent_Type(void* ptr)
{
	return static_cast<QEvent*>(ptr)->type();
}

char QEvent_IsAccepted(void* ptr)
{
	return static_cast<QEvent*>(ptr)->isAccepted();
}

char QEvent_Spontaneous(void* ptr)
{
	return static_cast<QEvent*>(ptr)->spontaneous();
}

unsigned short QEvent_T(void* ptr)
{
	return static_cast<QEvent*>(ptr)->t;
}

void QEvent_SetT(void* ptr, unsigned short vus)
{
	static_cast<QEvent*>(ptr)->t = vus;
}

Q_DECLARE_METATYPE(QGenericArgument*)
void* QGenericArgument_NewQGenericArgument(char* name, void* data)
{
	return new QGenericArgument(const_cast<const char*>(name), data);
}

struct QtCore_PackedString QGenericArgument_Name(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QGenericArgument*>(ptr)->name()), -1 };
}

void* QGenericArgument_Data(void* ptr)
{
	return static_cast<QGenericArgument*>(ptr)->data();
}

Q_DECLARE_METATYPE(QGenericReturnArgument*)
void* QGenericReturnArgument_NewQGenericReturnArgument(char* name, void* data)
{
	return new QGenericReturnArgument(const_cast<const char*>(name), data);
}

class MyQIODevice: public QIODevice
{
public:
	MyQIODevice() : QIODevice() {QIODevice_QIODevice_QRegisterMetaType();};
	MyQIODevice(QObject *parent) : QIODevice(parent) {QIODevice_QIODevice_QRegisterMetaType();};
	bool open(QIODevice::OpenMode mode) { return callbackQIODevice_Open(this, mode) != 0; };
	bool reset() { return callbackQIODevice_Reset(this) != 0; };
	bool seek(qint64 pos) { return callbackQIODevice_Seek(this, pos) != 0; };
	bool waitForBytesWritten(int msecs) { return callbackQIODevice_WaitForBytesWritten(this, msecs) != 0; };
	bool waitForReadyRead(int msecs) { return callbackQIODevice_WaitForReadyRead(this, msecs) != 0; };
	qint64 readData(char * data, qint64 maxSize) { QtCore_PackedString dataPacked = { data, maxSize };return callbackQIODevice_ReadData(this, dataPacked, maxSize); };
	qint64 readLineData(char * data, qint64 maxSize) { QtCore_PackedString dataPacked = { data, maxSize };return callbackQIODevice_ReadLineData(this, dataPacked, maxSize); };
	qint64 writeData(const char * data, qint64 maxSize) { QtCore_PackedString dataPacked = { const_cast<char*>(data), maxSize };return callbackQIODevice_WriteData(this, dataPacked, maxSize); };
	void Signal_AboutToClose() { callbackQIODevice_AboutToClose(this); };
	void Signal_BytesWritten(qint64 bytes) { callbackQIODevice_BytesWritten(this, bytes); };
	void Signal_ChannelBytesWritten(int channel, qint64 bytes) { callbackQIODevice_ChannelBytesWritten(this, channel, bytes); };
	void Signal_ChannelReadyRead(int channel) { callbackQIODevice_ChannelReadyRead(this, channel); };
	void close() { callbackQIODevice_Close(this); };
	void Signal_ReadChannelFinished() { callbackQIODevice_ReadChannelFinished(this); };
	void Signal_ReadyRead() { callbackQIODevice_ReadyRead(this); };
	 ~MyQIODevice() { callbackQIODevice_DestroyQIODevice(this); };
	bool atEnd() const { return callbackQIODevice_AtEnd(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	bool canReadLine() const { return callbackQIODevice_CanReadLine(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	bool isSequential() const { return callbackQIODevice_IsSequential(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	qint64 bytesAvailable() const { return callbackQIODevice_BytesAvailable(const_cast<void*>(static_cast<const void*>(this))); };
	qint64 bytesToWrite() const { return callbackQIODevice_BytesToWrite(const_cast<void*>(static_cast<const void*>(this))); };
	qint64 pos() const { return callbackQIODevice_Pos(const_cast<void*>(static_cast<const void*>(this))); };
	qint64 size() const { return callbackQIODevice_Size(const_cast<void*>(static_cast<const void*>(this))); };
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QIODevice*)
Q_DECLARE_METATYPE(MyQIODevice*)

int QIODevice_QIODevice_QRegisterMetaType(){qRegisterMetaType<QIODevice*>(); return qRegisterMetaType<MyQIODevice*>();}

void* QIODevice_Peek2(void* ptr, long long maxSize)
{
	return new QByteArray(static_cast<QIODevice*>(ptr)->peek(maxSize));
}

void* QIODevice_Read2(void* ptr, long long maxSize)
{
	return new QByteArray(static_cast<QIODevice*>(ptr)->read(maxSize));
}

void* QIODevice_ReadAll(void* ptr)
{
	return new QByteArray(static_cast<QIODevice*>(ptr)->readAll());
}

void* QIODevice_ReadLine2(void* ptr, long long maxSize)
{
	return new QByteArray(static_cast<QIODevice*>(ptr)->readLine(maxSize));
}

void* QIODevice_NewQIODevice()
{
	return new MyQIODevice();
}

void* QIODevice_NewQIODevice2(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQIODevice(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQIODevice(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQIODevice(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQIODevice(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQIODevice(static_cast<QWindow*>(parent));
	} else {
		return new MyQIODevice(static_cast<QObject*>(parent));
	}
}

char QIODevice_GetChar(void* ptr, char* c)
{
	return static_cast<QIODevice*>(ptr)->getChar(c);
}

char QIODevice_Open(void* ptr, long long mode)
{
	return static_cast<QIODevice*>(ptr)->open(static_cast<QIODevice::OpenModeFlag>(mode));
}

char QIODevice_OpenDefault(void* ptr, long long mode)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::open(static_cast<QIODevice::OpenModeFlag>(mode));
}

char QIODevice_PutChar(void* ptr, char* c)
{
	return static_cast<QIODevice*>(ptr)->putChar(*c);
}

char QIODevice_Reset(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->reset();
}

char QIODevice_ResetDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::reset();
}

char QIODevice_Seek(void* ptr, long long pos)
{
	return static_cast<QIODevice*>(ptr)->seek(pos);
}

char QIODevice_SeekDefault(void* ptr, long long pos)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::seek(pos);
}

char QIODevice_WaitForBytesWritten(void* ptr, int msecs)
{
	return static_cast<QIODevice*>(ptr)->waitForBytesWritten(msecs);
}

char QIODevice_WaitForBytesWrittenDefault(void* ptr, int msecs)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::waitForBytesWritten(msecs);
}

char QIODevice_WaitForReadyRead(void* ptr, int msecs)
{
	return static_cast<QIODevice*>(ptr)->waitForReadyRead(msecs);
}

char QIODevice_WaitForReadyReadDefault(void* ptr, int msecs)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::waitForReadyRead(msecs);
}

long long QIODevice_Peek(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->peek(data, maxSize);
}

long long QIODevice_Read(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->read(data, maxSize);
}

long long QIODevice_ReadData(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->readData(data, maxSize);
}

long long QIODevice_ReadLine(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->readLine(data, maxSize);
}

long long QIODevice_ReadLineData(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->readLineData(data, maxSize);
}

long long QIODevice_ReadLineDataDefault(void* ptr, char* data, long long maxSize)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::readLineData(data, maxSize);
}

long long QIODevice_Skip(void* ptr, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->skip(maxSize);
}

long long QIODevice_Write3(void* ptr, void* byteArray)
{
	return static_cast<QIODevice*>(ptr)->write(*static_cast<QByteArray*>(byteArray));
}

long long QIODevice_Write2(void* ptr, char* data)
{
	return static_cast<QIODevice*>(ptr)->write(const_cast<const char*>(data));
}

long long QIODevice_Write(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->write(const_cast<const char*>(data), maxSize);
}

long long QIODevice_WriteData(void* ptr, char* data, long long maxSize)
{
	return static_cast<QIODevice*>(ptr)->writeData(const_cast<const char*>(data), maxSize);
}

void QIODevice_ConnectAboutToClose(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::aboutToClose), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_AboutToClose), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectAboutToClose(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::aboutToClose), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_AboutToClose));
}

void QIODevice_AboutToClose(void* ptr)
{
	static_cast<QIODevice*>(ptr)->aboutToClose();
}

void QIODevice_ConnectBytesWritten(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(qint64)>(&QIODevice::bytesWritten), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(qint64)>(&MyQIODevice::Signal_BytesWritten), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectBytesWritten(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(qint64)>(&QIODevice::bytesWritten), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(qint64)>(&MyQIODevice::Signal_BytesWritten));
}

void QIODevice_BytesWritten(void* ptr, long long bytes)
{
	static_cast<QIODevice*>(ptr)->bytesWritten(bytes);
}

void QIODevice_ConnectChannelBytesWritten(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(int, qint64)>(&QIODevice::channelBytesWritten), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(int, qint64)>(&MyQIODevice::Signal_ChannelBytesWritten), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectChannelBytesWritten(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(int, qint64)>(&QIODevice::channelBytesWritten), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(int, qint64)>(&MyQIODevice::Signal_ChannelBytesWritten));
}

void QIODevice_ChannelBytesWritten(void* ptr, int channel, long long bytes)
{
	static_cast<QIODevice*>(ptr)->channelBytesWritten(channel, bytes);
}

void QIODevice_ConnectChannelReadyRead(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(int)>(&QIODevice::channelReadyRead), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(int)>(&MyQIODevice::Signal_ChannelReadyRead), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectChannelReadyRead(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)(int)>(&QIODevice::channelReadyRead), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)(int)>(&MyQIODevice::Signal_ChannelReadyRead));
}

void QIODevice_ChannelReadyRead(void* ptr, int channel)
{
	static_cast<QIODevice*>(ptr)->channelReadyRead(channel);
}

void QIODevice_Close(void* ptr)
{
	static_cast<QIODevice*>(ptr)->close();
}

void QIODevice_CloseDefault(void* ptr)
{
		static_cast<QIODevice*>(ptr)->QIODevice::close();
}

void QIODevice_CommitTransaction(void* ptr)
{
	static_cast<QIODevice*>(ptr)->commitTransaction();
}

void QIODevice_ConnectReadChannelFinished(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::readChannelFinished), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_ReadChannelFinished), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectReadChannelFinished(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::readChannelFinished), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_ReadChannelFinished));
}

void QIODevice_ReadChannelFinished(void* ptr)
{
	static_cast<QIODevice*>(ptr)->readChannelFinished();
}

void QIODevice_ConnectReadyRead(void* ptr, long long t)
{
	QObject::connect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::readyRead), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_ReadyRead), static_cast<Qt::ConnectionType>(t));
}

void QIODevice_DisconnectReadyRead(void* ptr)
{
	QObject::disconnect(static_cast<QIODevice*>(ptr), static_cast<void (QIODevice::*)()>(&QIODevice::readyRead), static_cast<MyQIODevice*>(ptr), static_cast<void (MyQIODevice::*)()>(&MyQIODevice::Signal_ReadyRead));
}

void QIODevice_ReadyRead(void* ptr)
{
	static_cast<QIODevice*>(ptr)->readyRead();
}

void QIODevice_RollbackTransaction(void* ptr)
{
	static_cast<QIODevice*>(ptr)->rollbackTransaction();
}

void QIODevice_SetCurrentReadChannel(void* ptr, int channel)
{
	static_cast<QIODevice*>(ptr)->setCurrentReadChannel(channel);
}

void QIODevice_SetCurrentWriteChannel(void* ptr, int channel)
{
	static_cast<QIODevice*>(ptr)->setCurrentWriteChannel(channel);
}

void QIODevice_SetErrorString(void* ptr, struct QtCore_PackedString str)
{
	static_cast<QIODevice*>(ptr)->setErrorString(QString::fromUtf8(str.data, str.len));
}

void QIODevice_SetOpenMode(void* ptr, long long openMode)
{
	static_cast<QIODevice*>(ptr)->setOpenMode(static_cast<QIODevice::OpenModeFlag>(openMode));
}

void QIODevice_SetTextModeEnabled(void* ptr, char enabled)
{
	static_cast<QIODevice*>(ptr)->setTextModeEnabled(enabled != 0);
}

void QIODevice_StartTransaction(void* ptr)
{
	static_cast<QIODevice*>(ptr)->startTransaction();
}

void QIODevice_UngetChar(void* ptr, char* c)
{
	static_cast<QIODevice*>(ptr)->ungetChar(*c);
}

void QIODevice_DestroyQIODevice(void* ptr)
{
	static_cast<QIODevice*>(ptr)->~QIODevice();
}

void QIODevice_DestroyQIODeviceDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

long long QIODevice_OpenMode(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->openMode();
}

struct QtCore_PackedString QIODevice_ErrorString(void* ptr)
{
	return ({ QByteArray t7db24b = static_cast<QIODevice*>(ptr)->errorString().toUtf8(); QtCore_PackedString { const_cast<char*>(t7db24b.prepend("WHITESPACE").constData()+10), t7db24b.size()-10 }; });
}

char QIODevice_AtEnd(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->atEnd();
}

char QIODevice_AtEndDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::atEnd();
}

char QIODevice_CanReadLine(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->canReadLine();
}

char QIODevice_CanReadLineDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::canReadLine();
}

char QIODevice_IsOpen(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isOpen();
}

char QIODevice_IsReadable(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isReadable();
}

char QIODevice_IsSequential(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isSequential();
}

char QIODevice_IsSequentialDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::isSequential();
}

char QIODevice_IsTextModeEnabled(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isTextModeEnabled();
}

char QIODevice_IsTransactionStarted(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isTransactionStarted();
}

char QIODevice_IsWritable(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->isWritable();
}

int QIODevice_CurrentReadChannel(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->currentReadChannel();
}

int QIODevice_CurrentWriteChannel(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->currentWriteChannel();
}

int QIODevice_ReadChannelCount(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->readChannelCount();
}

int QIODevice_WriteChannelCount(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->writeChannelCount();
}

long long QIODevice_BytesAvailable(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->bytesAvailable();
}

long long QIODevice_BytesAvailableDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::bytesAvailable();
}

long long QIODevice_BytesToWrite(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->bytesToWrite();
}

long long QIODevice_BytesToWriteDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::bytesToWrite();
}

long long QIODevice_Pos(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->pos();
}

long long QIODevice_PosDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::pos();
}

long long QIODevice_Size(void* ptr)
{
	return static_cast<QIODevice*>(ptr)->size();
}

long long QIODevice_SizeDefault(void* ptr)
{
		return static_cast<QIODevice*>(ptr)->QIODevice::size();
}

Q_DECLARE_METATYPE(QJsonArray)
Q_DECLARE_METATYPE(QJsonArray*)
void* QJsonArray_QJsonArray_FromStringList(struct QtCore_PackedString list)
{
	return new QJsonArray(QJsonArray::fromStringList(QString::fromUtf8(list.data, list.len).split("¡¦!", QString::SkipEmptyParts)));
}

void* QJsonArray_QJsonArray_FromVariantList(void* list)
{
	return new QJsonArray(QJsonArray::fromVariantList(({ QList<QVariant>* tmpP = static_cast<QList<QVariant>*>(list); QList<QVariant> tmpV = *tmpP; tmpP->~QList(); free(tmpP); tmpV; })));
}

void* QJsonArray_NewQJsonArray()
{
	return new QJsonArray();
}

void* QJsonArray_NewQJsonArray4(void* other)
{
	return new QJsonArray(*static_cast<QJsonArray*>(other));
}

void* QJsonArray_NewQJsonArray3(void* other)
{
	return new QJsonArray(*static_cast<QJsonArray*>(other));
}

void* QJsonArray_TakeAt(void* ptr, int i)
{
	return new QJsonValue(static_cast<QJsonArray*>(ptr)->takeAt(i));
}

void QJsonArray_Append(void* ptr, void* value)
{
	static_cast<QJsonArray*>(ptr)->append(*static_cast<QJsonValue*>(value));
}

void QJsonArray_Insert(void* ptr, int i, void* value)
{
	static_cast<QJsonArray*>(ptr)->insert(i, *static_cast<QJsonValue*>(value));
}

void QJsonArray_Pop_back(void* ptr)
{
	static_cast<QJsonArray*>(ptr)->pop_back();
}

void QJsonArray_Pop_front(void* ptr)
{
	static_cast<QJsonArray*>(ptr)->pop_front();
}

void QJsonArray_Prepend(void* ptr, void* value)
{
	static_cast<QJsonArray*>(ptr)->prepend(*static_cast<QJsonValue*>(value));
}

void QJsonArray_Push_back(void* ptr, void* value)
{
	static_cast<QJsonArray*>(ptr)->push_back(*static_cast<QJsonValue*>(value));
}

void QJsonArray_Push_front(void* ptr, void* value)
{
	static_cast<QJsonArray*>(ptr)->push_front(*static_cast<QJsonValue*>(value));
}

void QJsonArray_RemoveAt(void* ptr, int i)
{
	static_cast<QJsonArray*>(ptr)->removeAt(i);
}

void QJsonArray_RemoveFirst(void* ptr)
{
	static_cast<QJsonArray*>(ptr)->removeFirst();
}

void QJsonArray_RemoveLast(void* ptr)
{
	static_cast<QJsonArray*>(ptr)->removeLast();
}

void QJsonArray_Replace(void* ptr, int i, void* value)
{
	static_cast<QJsonArray*>(ptr)->replace(i, *static_cast<QJsonValue*>(value));
}

void QJsonArray_Swap(void* ptr, void* other)
{
	static_cast<QJsonArray*>(ptr)->swap(*static_cast<QJsonArray*>(other));
}

void QJsonArray_DestroyQJsonArray(void* ptr)
{
	static_cast<QJsonArray*>(ptr)->~QJsonArray();
}

void* QJsonArray_At(void* ptr, int i)
{
	return new QJsonValue(static_cast<QJsonArray*>(ptr)->at(i));
}

void* QJsonArray_First(void* ptr)
{
	return new QJsonValue(static_cast<QJsonArray*>(ptr)->first());
}

void* QJsonArray_Last(void* ptr)
{
	return new QJsonValue(static_cast<QJsonArray*>(ptr)->last());
}

struct QtCore_PackedList QJsonArray_ToVariantList(void* ptr)
{
	return ({ QList<QVariant>* tmpValue10940c = new QList<QVariant>(static_cast<QJsonArray*>(ptr)->toVariantList()); QtCore_PackedList { tmpValue10940c, tmpValue10940c->size() }; });
}

char QJsonArray_Contains(void* ptr, void* value)
{
	return static_cast<QJsonArray*>(ptr)->contains(*static_cast<QJsonValue*>(value));
}

char QJsonArray_Empty(void* ptr)
{
	return static_cast<QJsonArray*>(ptr)->empty();
}

char QJsonArray_IsEmpty(void* ptr)
{
	return static_cast<QJsonArray*>(ptr)->isEmpty();
}

int QJsonArray_Count(void* ptr)
{
	return static_cast<QJsonArray*>(ptr)->count();
}

int QJsonArray_Size(void* ptr)
{
	return static_cast<QJsonArray*>(ptr)->size();
}

void* QJsonArray___fromVariantList_list_atList(void* ptr, int i)
{
	return new QVariant(({QVariant tmp = static_cast<QList<QVariant>*>(ptr)->at(i); if (i == static_cast<QList<QVariant>*>(ptr)->size()-1) { static_cast<QList<QVariant>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QJsonArray___fromVariantList_list_setList(void* ptr, void* i)
{
	static_cast<QList<QVariant>*>(ptr)->append(*static_cast<QVariant*>(i));
}

void* QJsonArray___fromVariantList_list_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QVariant>();
}

void* QJsonArray___toVariantList_atList(void* ptr, int i)
{
	return new QVariant(({QVariant tmp = static_cast<QList<QVariant>*>(ptr)->at(i); if (i == static_cast<QList<QVariant>*>(ptr)->size()-1) { static_cast<QList<QVariant>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QJsonArray___toVariantList_setList(void* ptr, void* i)
{
	static_cast<QList<QVariant>*>(ptr)->append(*static_cast<QVariant*>(i));
}

void* QJsonArray___toVariantList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QVariant>();
}

Q_DECLARE_METATYPE(QJsonDocument)
Q_DECLARE_METATYPE(QJsonDocument*)
void* QJsonDocument_QJsonDocument_FromBinaryData(void* data, long long validation)
{
	return new QJsonDocument(QJsonDocument::fromBinaryData(*static_cast<QByteArray*>(data), static_cast<QJsonDocument::DataValidation>(validation)));
}

void* QJsonDocument_QJsonDocument_FromJson(void* json, void* error)
{
	return new QJsonDocument(QJsonDocument::fromJson(*static_cast<QByteArray*>(json), static_cast<QJsonParseError*>(error)));
}

void* QJsonDocument_QJsonDocument_FromRawData(char* data, int size, long long validation)
{
	return new QJsonDocument(QJsonDocument::fromRawData(const_cast<const char*>(data), size, static_cast<QJsonDocument::DataValidation>(validation)));
}

void* QJsonDocument_QJsonDocument_FromVariant(void* variant)
{
	return new QJsonDocument(QJsonDocument::fromVariant(*static_cast<QVariant*>(variant)));
}

void* QJsonDocument_NewQJsonDocument()
{
	return new QJsonDocument();
}

void* QJsonDocument_NewQJsonDocument5(void* other)
{
	return new QJsonDocument(*static_cast<QJsonDocument*>(other));
}

void* QJsonDocument_NewQJsonDocument3(void* array)
{
	return new QJsonDocument(*static_cast<QJsonArray*>(array));
}

void* QJsonDocument_NewQJsonDocument4(void* other)
{
	return new QJsonDocument(*static_cast<QJsonDocument*>(other));
}

void* QJsonDocument_NewQJsonDocument2(void* object)
{
	return new QJsonDocument(*static_cast<QJsonObject*>(object));
}

void QJsonDocument_SetArray(void* ptr, void* array)
{
	static_cast<QJsonDocument*>(ptr)->setArray(*static_cast<QJsonArray*>(array));
}

void QJsonDocument_SetObject(void* ptr, void* object)
{
	static_cast<QJsonDocument*>(ptr)->setObject(*static_cast<QJsonObject*>(object));
}

void QJsonDocument_Swap(void* ptr, void* other)
{
	static_cast<QJsonDocument*>(ptr)->swap(*static_cast<QJsonDocument*>(other));
}

void QJsonDocument_DestroyQJsonDocument(void* ptr)
{
	static_cast<QJsonDocument*>(ptr)->~QJsonDocument();
}

void* QJsonDocument_ToBinaryData(void* ptr)
{
	return new QByteArray(static_cast<QJsonDocument*>(ptr)->toBinaryData());
}

void* QJsonDocument_ToJson(void* ptr)
{
	return new QByteArray(static_cast<QJsonDocument*>(ptr)->toJson());
}

void* QJsonDocument_ToJson2(void* ptr, long long format)
{
	return new QByteArray(static_cast<QJsonDocument*>(ptr)->toJson(static_cast<QJsonDocument::JsonFormat>(format)));
}

void* QJsonDocument_Array(void* ptr)
{
	return new QJsonArray(static_cast<QJsonDocument*>(ptr)->array());
}

void* QJsonDocument_Object(void* ptr)
{
	return new QJsonObject(static_cast<QJsonDocument*>(ptr)->object());
}

void* QJsonDocument_ToVariant(void* ptr)
{
	return new QVariant(static_cast<QJsonDocument*>(ptr)->toVariant());
}

char QJsonDocument_IsArray(void* ptr)
{
	return static_cast<QJsonDocument*>(ptr)->isArray();
}

char QJsonDocument_IsEmpty(void* ptr)
{
	return static_cast<QJsonDocument*>(ptr)->isEmpty();
}

char QJsonDocument_IsNull(void* ptr)
{
	return static_cast<QJsonDocument*>(ptr)->isNull();
}

char QJsonDocument_IsObject(void* ptr)
{
	return static_cast<QJsonDocument*>(ptr)->isObject();
}

struct QtCore_PackedString QJsonDocument_RawData(void* ptr, int size)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QJsonDocument*>(ptr)->rawData(&size)), size };
}

Q_DECLARE_METATYPE(QJsonObject)
Q_DECLARE_METATYPE(QJsonObject*)
void* QJsonObject_QJsonObject_FromVariantHash(void* hash)
{
	return new QJsonObject(QJsonObject::fromVariantHash(({ QHash<QString, QVariant>* tmpP = static_cast<QHash<QString, QVariant>*>(hash); QHash<QString, QVariant> tmpV = *tmpP; tmpP->~QHash(); free(tmpP); tmpV; })));
}

void* QJsonObject_NewQJsonObject()
{
	return new QJsonObject();
}

void* QJsonObject_NewQJsonObject4(void* other)
{
	return new QJsonObject(*static_cast<QJsonObject*>(other));
}

void* QJsonObject_NewQJsonObject3(void* other)
{
	return new QJsonObject(*static_cast<QJsonObject*>(other));
}

void* QJsonObject_Take(void* ptr, struct QtCore_PackedString key)
{
	return new QJsonValue(static_cast<QJsonObject*>(ptr)->take(QString::fromUtf8(key.data, key.len)));
}

void QJsonObject_Remove(void* ptr, struct QtCore_PackedString key)
{
	static_cast<QJsonObject*>(ptr)->remove(QString::fromUtf8(key.data, key.len));
}

void QJsonObject_Swap(void* ptr, void* other)
{
	static_cast<QJsonObject*>(ptr)->swap(*static_cast<QJsonObject*>(other));
}

void QJsonObject_DestroyQJsonObject(void* ptr)
{
	static_cast<QJsonObject*>(ptr)->~QJsonObject();
}

void* QJsonObject_Value2(void* ptr, void* key)
{
	return new QJsonValue(static_cast<QJsonObject*>(ptr)->value(*static_cast<QLatin1String*>(key)));
}

void* QJsonObject_Value(void* ptr, struct QtCore_PackedString key)
{
	return new QJsonValue(static_cast<QJsonObject*>(ptr)->value(QString::fromUtf8(key.data, key.len)));
}

struct QtCore_PackedString QJsonObject_Keys(void* ptr)
{
	return ({ QByteArray t6c6b45 = static_cast<QJsonObject*>(ptr)->keys().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t6c6b45.prepend("WHITESPACE").constData()+10), t6c6b45.size()-10 }; });
}

struct QtCore_PackedList QJsonObject_ToVariantHash(void* ptr)
{
	return ({ QHash<QString, QVariant>* tmpValue275a06 = new QHash<QString, QVariant>(static_cast<QJsonObject*>(ptr)->toVariantHash()); QtCore_PackedList { tmpValue275a06, tmpValue275a06->size() }; });
}

struct QtCore_PackedList QJsonObject_ToVariantMap(void* ptr)
{
	return ({ QMap<QString, QVariant>* tmpValuebc2a1c = new QMap<QString, QVariant>(static_cast<QJsonObject*>(ptr)->toVariantMap()); QtCore_PackedList { tmpValuebc2a1c, tmpValuebc2a1c->size() }; });
}

char QJsonObject_Contains2(void* ptr, void* key)
{
	return static_cast<QJsonObject*>(ptr)->contains(*static_cast<QLatin1String*>(key));
}

char QJsonObject_Contains(void* ptr, struct QtCore_PackedString key)
{
	return static_cast<QJsonObject*>(ptr)->contains(QString::fromUtf8(key.data, key.len));
}

char QJsonObject_Empty(void* ptr)
{
	return static_cast<QJsonObject*>(ptr)->empty();
}

char QJsonObject_IsEmpty(void* ptr)
{
	return static_cast<QJsonObject*>(ptr)->isEmpty();
}

int QJsonObject_Count(void* ptr)
{
	return static_cast<QJsonObject*>(ptr)->count();
}

int QJsonObject_Length(void* ptr)
{
	return static_cast<QJsonObject*>(ptr)->length();
}

int QJsonObject_Size(void* ptr)
{
	return static_cast<QJsonObject*>(ptr)->size();
}

void* QJsonObject___fromVariantHash_hash_atList(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QHash<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QHash<QString, QVariant>*>(ptr)->size()-1) { static_cast<QHash<QString, QVariant>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QJsonObject___fromVariantHash_hash_setList(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QHash<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QJsonObject___fromVariantHash_hash_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<QString, QVariant>();
}

struct QtCore_PackedList QJsonObject___fromVariantHash_hash_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValuef43bc5 = new QList<QString>(static_cast<QHash<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValuef43bc5, tmpValuef43bc5->size() }; });
}

void* QJsonObject___toVariantHash_atList(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QHash<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QHash<QString, QVariant>*>(ptr)->size()-1) { static_cast<QHash<QString, QVariant>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QJsonObject___toVariantHash_setList(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QHash<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QJsonObject___toVariantHash_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<QString, QVariant>();
}

struct QtCore_PackedList QJsonObject___toVariantHash_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValuef43bc5 = new QList<QString>(static_cast<QHash<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValuef43bc5, tmpValuef43bc5->size() }; });
}

void* QJsonObject___toVariantMap_atList(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QMap<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QMap<QString, QVariant>*>(ptr)->size()-1) { static_cast<QMap<QString, QVariant>*>(ptr)->~QMap(); free(ptr); }; tmp; }));
}

void QJsonObject___toVariantMap_setList(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QMap<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QJsonObject___toVariantMap_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<QString, QVariant>();
}

struct QtCore_PackedList QJsonObject___toVariantMap_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValue1ab909 = new QList<QString>(static_cast<QMap<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValue1ab909, tmpValue1ab909->size() }; });
}

struct QtCore_PackedString QJsonObject_____fromVariantHash_hash_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QJsonObject_____fromVariantHash_hash_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QJsonObject_____fromVariantHash_hash_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QJsonObject_____fromVariantMap_map_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QJsonObject_____fromVariantMap_map_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QJsonObject_____fromVariantMap_map_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QJsonObject_____toVariantHash_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QJsonObject_____toVariantHash_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QJsonObject_____toVariantHash_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QJsonObject_____toVariantMap_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QJsonObject_____toVariantMap_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QJsonObject_____toVariantMap_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QJsonParseError_ErrorString(void* ptr)
{
	return ({ QByteArray t740a50 = static_cast<QJsonParseError*>(ptr)->errorString().toUtf8(); QtCore_PackedString { const_cast<char*>(t740a50.prepend("WHITESPACE").constData()+10), t740a50.size()-10 }; });
}

long long QJsonParseError_Error(void* ptr)
{
	return static_cast<QJsonParseError*>(ptr)->error;
}

void QJsonParseError_SetError(void* ptr, long long vqj)
{
	static_cast<QJsonParseError*>(ptr)->error = static_cast<QJsonParseError::ParseError>(vqj);
}

int QJsonParseError_Offset(void* ptr)
{
	return static_cast<QJsonParseError*>(ptr)->offset;
}

void QJsonParseError_SetOffset(void* ptr, int vin)
{
	static_cast<QJsonParseError*>(ptr)->offset = vin;
}

Q_DECLARE_METATYPE(QJsonValue*)
void* QJsonValue_QJsonValue_FromVariant(void* variant)
{
	return new QJsonValue(QJsonValue::fromVariant(*static_cast<QVariant*>(variant)));
}

void* QJsonValue_NewQJsonValue12(void* other)
{
	return new QJsonValue(*static_cast<QJsonValue*>(other));
}

void* QJsonValue_NewQJsonValue(long long ty)
{
	return new QJsonValue(static_cast<QJsonValue::Type>(ty));
}

void* QJsonValue_NewQJsonValue7(void* s)
{
	return new QJsonValue(*static_cast<QLatin1String*>(s));
}

void* QJsonValue_NewQJsonValue2(char b)
{
	return new QJsonValue(b != 0);
}

void* QJsonValue_NewQJsonValue9(void* a)
{
	return new QJsonValue(*static_cast<QJsonArray*>(a));
}

void* QJsonValue_NewQJsonValue10(void* o)
{
	return new QJsonValue(*static_cast<QJsonObject*>(o));
}

void* QJsonValue_NewQJsonValue11(void* other)
{
	return new QJsonValue(*static_cast<QJsonValue*>(other));
}

void* QJsonValue_NewQJsonValue6(struct QtCore_PackedString s)
{
	return new QJsonValue(QString::fromUtf8(s.data, s.len));
}

void* QJsonValue_NewQJsonValue8(char* s)
{
	return new QJsonValue(const_cast<const char*>(s));
}

void* QJsonValue_NewQJsonValue3(double n)
{
	return new QJsonValue(n);
}

void* QJsonValue_NewQJsonValue4(int n)
{
	return new QJsonValue(n);
}

void* QJsonValue_NewQJsonValue5(long long n)
{
	return new QJsonValue(n);
}

void QJsonValue_Swap(void* ptr, void* other)
{
	static_cast<QJsonValue*>(ptr)->swap(*static_cast<QJsonValue*>(other));
}

void QJsonValue_DestroyQJsonValue(void* ptr)
{
	static_cast<QJsonValue*>(ptr)->~QJsonValue();
}

void* QJsonValue_ToArray2(void* ptr)
{
	return new QJsonArray(static_cast<QJsonValue*>(ptr)->toArray());
}

void* QJsonValue_ToArray(void* ptr, void* defaultValue)
{
	return new QJsonArray(static_cast<QJsonValue*>(ptr)->toArray(*static_cast<QJsonArray*>(defaultValue)));
}

void* QJsonValue_ToObject2(void* ptr)
{
	return new QJsonObject(static_cast<QJsonValue*>(ptr)->toObject());
}

void* QJsonValue_ToObject(void* ptr, void* defaultValue)
{
	return new QJsonObject(static_cast<QJsonValue*>(ptr)->toObject(*static_cast<QJsonObject*>(defaultValue)));
}

long long QJsonValue_Type(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->type();
}

struct QtCore_PackedString QJsonValue_ToString(void* ptr)
{
	return ({ QByteArray t54cc8a = static_cast<QJsonValue*>(ptr)->toString().toUtf8(); QtCore_PackedString { const_cast<char*>(t54cc8a.prepend("WHITESPACE").constData()+10), t54cc8a.size()-10 }; });
}

struct QtCore_PackedString QJsonValue_ToString2(void* ptr, struct QtCore_PackedString defaultValue)
{
	return ({ QByteArray tb25a8c = static_cast<QJsonValue*>(ptr)->toString(QString::fromUtf8(defaultValue.data, defaultValue.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(tb25a8c.prepend("WHITESPACE").constData()+10), tb25a8c.size()-10 }; });
}

void* QJsonValue_ToVariant(void* ptr)
{
	return new QVariant(static_cast<QJsonValue*>(ptr)->toVariant());
}

char QJsonValue_IsArray(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isArray();
}

char QJsonValue_IsBool(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isBool();
}

char QJsonValue_IsDouble(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isDouble();
}

char QJsonValue_IsNull(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isNull();
}

char QJsonValue_IsObject(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isObject();
}

char QJsonValue_IsString(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isString();
}

char QJsonValue_IsUndefined(void* ptr)
{
	return static_cast<QJsonValue*>(ptr)->isUndefined();
}

char QJsonValue_ToBool(void* ptr, char defaultValue)
{
	return static_cast<QJsonValue*>(ptr)->toBool(defaultValue != 0);
}

double QJsonValue_ToDouble(void* ptr, double defaultValue)
{
	return static_cast<QJsonValue*>(ptr)->toDouble(defaultValue);
}

int QJsonValue_ToInt(void* ptr, int defaultValue)
{
	return static_cast<QJsonValue*>(ptr)->toInt(defaultValue);
}

Q_DECLARE_METATYPE(QLatin1Char*)
void* QLatin1Char_NewQLatin1Char(char* c)
{
	return new QLatin1Char(*c);
}

struct QtCore_PackedString QLatin1Char_ToLatin1(void* ptr)
{
	return ({ char te73025 = static_cast<QLatin1Char*>(ptr)->toLatin1(); QtCore_PackedString { &te73025, -1 }; });
}

unsigned short QLatin1Char_Unicode(void* ptr)
{
	return static_cast<QLatin1Char*>(ptr)->unicode();
}

Q_DECLARE_METATYPE(QLatin1String)
Q_DECLARE_METATYPE(QLatin1String*)
void* QLatin1String_NewQLatin1String()
{
	return new QLatin1String();
}

void* QLatin1String_NewQLatin1String5(void* str)
{
	return new QLatin1String(*static_cast<QByteArray*>(str));
}

void* QLatin1String_NewQLatin1String3(char* first, char* last)
{
	return new QLatin1String(const_cast<const char*>(first), const_cast<const char*>(last));
}

void* QLatin1String_NewQLatin1String2(char* str)
{
	return new QLatin1String(const_cast<const char*>(str));
}

void* QLatin1String_NewQLatin1String4(char* str, int size)
{
	return new QLatin1String(const_cast<const char*>(str), size);
}

void QLatin1String_Chop(void* ptr, int length)
{
	static_cast<QLatin1String*>(ptr)->chop(length);
}

void QLatin1String_Truncate(void* ptr, int length)
{
	static_cast<QLatin1String*>(ptr)->truncate(length);
}

void* QLatin1String_Chopped(void* ptr, int length)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->chopped(length));
}

void* QLatin1String_Left(void* ptr, int length)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->left(length));
}

void* QLatin1String_Mid(void* ptr, int start)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->mid(start));
}

void* QLatin1String_Mid2(void* ptr, int start, int length)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->mid(start, length));
}

void* QLatin1String_Right(void* ptr, int length)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->right(length));
}

void* QLatin1String_Trimmed(void* ptr)
{
	return new QLatin1String(static_cast<QLatin1String*>(ptr)->trimmed());
}

char QLatin1String_EndsWith3(void* ptr, void* ch)
{
	return static_cast<QLatin1String*>(ptr)->endsWith(*static_cast<QChar*>(ch));
}

char QLatin1String_EndsWith4(void* ptr, void* ch, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->endsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QLatin1String_EndsWith2(void* ptr, void* l1, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->endsWith(*static_cast<QLatin1String*>(l1), static_cast<Qt::CaseSensitivity>(cs));
}

char QLatin1String_EndsWith(void* ptr, void* str, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->endsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QLatin1String_IsEmpty(void* ptr)
{
	return static_cast<QLatin1String*>(ptr)->isEmpty();
}

char QLatin1String_IsNull(void* ptr)
{
	return static_cast<QLatin1String*>(ptr)->isNull();
}

char QLatin1String_StartsWith3(void* ptr, void* ch)
{
	return static_cast<QLatin1String*>(ptr)->startsWith(*static_cast<QChar*>(ch));
}

char QLatin1String_StartsWith4(void* ptr, void* ch, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->startsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QLatin1String_StartsWith2(void* ptr, void* l1, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->startsWith(*static_cast<QLatin1String*>(l1), static_cast<Qt::CaseSensitivity>(cs));
}

char QLatin1String_StartsWith(void* ptr, void* str, long long cs)
{
	return static_cast<QLatin1String*>(ptr)->startsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

struct QtCore_PackedString QLatin1String_Data(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QLatin1String*>(ptr)->data()), static_cast<QLatin1String*>(ptr)->size() };
}

struct QtCore_PackedString QLatin1String_Latin1(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QLatin1String*>(ptr)->latin1()), -1 };
}

int QLatin1String_Size(void* ptr)
{
	return static_cast<QLatin1String*>(ptr)->size();
}

Q_DECLARE_METATYPE(QLine)
Q_DECLARE_METATYPE(QLine*)
void* QLine_NewQLine()
{
	return new QLine();
}

void* QLine_NewQLine2(void* p1, void* p2)
{
	return new QLine(*static_cast<QPoint*>(p1), *static_cast<QPoint*>(p2));
}

void* QLine_NewQLine3(int x1, int y1, int x2, int y2)
{
	return new QLine(x1, y1, x2, y2);
}

void QLine_SetLine(void* ptr, int x1, int y1, int x2, int y2)
{
	static_cast<QLine*>(ptr)->setLine(x1, y1, x2, y2);
}

void QLine_SetP1(void* ptr, void* p1)
{
	static_cast<QLine*>(ptr)->setP1(*static_cast<QPoint*>(p1));
}

void QLine_SetP2(void* ptr, void* p2)
{
	static_cast<QLine*>(ptr)->setP2(*static_cast<QPoint*>(p2));
}

void QLine_SetPoints(void* ptr, void* p1, void* p2)
{
	static_cast<QLine*>(ptr)->setPoints(*static_cast<QPoint*>(p1), *static_cast<QPoint*>(p2));
}

void QLine_Translate(void* ptr, void* offset)
{
	static_cast<QLine*>(ptr)->translate(*static_cast<QPoint*>(offset));
}

void QLine_Translate2(void* ptr, int dx, int dy)
{
	static_cast<QLine*>(ptr)->translate(dx, dy);
}

void* QLine_Translated(void* ptr, void* offset)
{
	return ({ QLine tmpValue = static_cast<QLine*>(ptr)->translated(*static_cast<QPoint*>(offset)); new QLine(tmpValue.p1(), tmpValue.p2()); });
}

void* QLine_Translated2(void* ptr, int dx, int dy)
{
	return ({ QLine tmpValue = static_cast<QLine*>(ptr)->translated(dx, dy); new QLine(tmpValue.p1(), tmpValue.p2()); });
}

void* QLine_Center(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QLine*>(ptr)->center(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QLine_P1(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QLine*>(ptr)->p1(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QLine_P2(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QLine*>(ptr)->p2(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

char QLine_IsNull(void* ptr)
{
	return static_cast<QLine*>(ptr)->isNull();
}

int QLine_Dx(void* ptr)
{
	return static_cast<QLine*>(ptr)->dx();
}

int QLine_Dy(void* ptr)
{
	return static_cast<QLine*>(ptr)->dy();
}

int QLine_X1(void* ptr)
{
	return static_cast<QLine*>(ptr)->x1();
}

int QLine_X2(void* ptr)
{
	return static_cast<QLine*>(ptr)->x2();
}

int QLine_Y1(void* ptr)
{
	return static_cast<QLine*>(ptr)->y1();
}

int QLine_Y2(void* ptr)
{
	return static_cast<QLine*>(ptr)->y2();
}

Q_DECLARE_METATYPE(QLineF)
Q_DECLARE_METATYPE(QLineF*)
void* QLineF_QLineF_FromPolar(double length, double angle)
{
	return ({ QLineF tmpValue = QLineF::fromPolar(length, angle); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

void* QLineF_NewQLineF()
{
	return new QLineF();
}

void* QLineF_NewQLineF4(void* line)
{
	return new QLineF(*static_cast<QLine*>(line));
}

void* QLineF_NewQLineF2(void* p1, void* p2)
{
	return new QLineF(*static_cast<QPointF*>(p1), *static_cast<QPointF*>(p2));
}

void* QLineF_NewQLineF3(double x1, double y1, double x2, double y2)
{
	return new QLineF(x1, y1, x2, y2);
}

void QLineF_SetAngle(void* ptr, double angle)
{
	static_cast<QLineF*>(ptr)->setAngle(angle);
}

void QLineF_SetLength(void* ptr, double length)
{
	static_cast<QLineF*>(ptr)->setLength(length);
}

void QLineF_SetLine(void* ptr, double x1, double y1, double x2, double y2)
{
	static_cast<QLineF*>(ptr)->setLine(x1, y1, x2, y2);
}

void QLineF_SetP1(void* ptr, void* p1)
{
	static_cast<QLineF*>(ptr)->setP1(*static_cast<QPointF*>(p1));
}

void QLineF_SetP2(void* ptr, void* p2)
{
	static_cast<QLineF*>(ptr)->setP2(*static_cast<QPointF*>(p2));
}

void QLineF_SetPoints(void* ptr, void* p1, void* p2)
{
	static_cast<QLineF*>(ptr)->setPoints(*static_cast<QPointF*>(p1), *static_cast<QPointF*>(p2));
}

void QLineF_Translate(void* ptr, void* offset)
{
	static_cast<QLineF*>(ptr)->translate(*static_cast<QPointF*>(offset));
}

void QLineF_Translate2(void* ptr, double dx, double dy)
{
	static_cast<QLineF*>(ptr)->translate(dx, dy);
}

void* QLineF_ToLine(void* ptr)
{
	return ({ QLine tmpValue = static_cast<QLineF*>(ptr)->toLine(); new QLine(tmpValue.p1(), tmpValue.p2()); });
}

void* QLineF_NormalVector(void* ptr)
{
	return ({ QLineF tmpValue = static_cast<QLineF*>(ptr)->normalVector(); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

void* QLineF_Translated(void* ptr, void* offset)
{
	return ({ QLineF tmpValue = static_cast<QLineF*>(ptr)->translated(*static_cast<QPointF*>(offset)); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

void* QLineF_Translated2(void* ptr, double dx, double dy)
{
	return ({ QLineF tmpValue = static_cast<QLineF*>(ptr)->translated(dx, dy); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

void* QLineF_UnitVector(void* ptr)
{
	return ({ QLineF tmpValue = static_cast<QLineF*>(ptr)->unitVector(); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

long long QLineF_Intersect(void* ptr, void* line, void* intersectionPoint)
{
	return static_cast<QLineF*>(ptr)->intersect(*static_cast<QLineF*>(line), static_cast<QPointF*>(intersectionPoint));
}

void* QLineF_Center(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QLineF*>(ptr)->center(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QLineF_P1(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QLineF*>(ptr)->p1(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QLineF_P2(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QLineF*>(ptr)->p2(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QLineF_PointAt(void* ptr, double t)
{
	return ({ QPointF tmpValue = static_cast<QLineF*>(ptr)->pointAt(t); new QPointF(tmpValue.x(), tmpValue.y()); });
}

char QLineF_IsNull(void* ptr)
{
	return static_cast<QLineF*>(ptr)->isNull();
}

double QLineF_Angle(void* ptr)
{
	return static_cast<QLineF*>(ptr)->angle();
}

double QLineF_AngleTo(void* ptr, void* line)
{
	return static_cast<QLineF*>(ptr)->angleTo(*static_cast<QLineF*>(line));
}

double QLineF_Dx(void* ptr)
{
	return static_cast<QLineF*>(ptr)->dx();
}

double QLineF_Dy(void* ptr)
{
	return static_cast<QLineF*>(ptr)->dy();
}

double QLineF_Length(void* ptr)
{
	return static_cast<QLineF*>(ptr)->length();
}

double QLineF_X1(void* ptr)
{
	return static_cast<QLineF*>(ptr)->x1();
}

double QLineF_X2(void* ptr)
{
	return static_cast<QLineF*>(ptr)->x2();
}

double QLineF_Y1(void* ptr)
{
	return static_cast<QLineF*>(ptr)->y1();
}

double QLineF_Y2(void* ptr)
{
	return static_cast<QLineF*>(ptr)->y2();
}

Q_DECLARE_METATYPE(QLocale)
Q_DECLARE_METATYPE(QLocale*)
struct QtCore_PackedList QLocale_QLocale_MatchingLocales(long long language, long long scri, long long country)
{
	return ({ QList<QLocale>* tmpValue0a12b0 = new QList<QLocale>(QLocale::matchingLocales(static_cast<QLocale::Language>(language), static_cast<QLocale::Script>(scri), static_cast<QLocale::Country>(country))); QtCore_PackedList { tmpValue0a12b0, tmpValue0a12b0->size() }; });
}

void* QLocale_QLocale_C()
{
	return new QLocale(QLocale::c());
}

void* QLocale_QLocale_System()
{
	return new QLocale(QLocale::system());
}

void* QLocale_NewQLocale()
{
	return new QLocale();
}

void* QLocale_NewQLocale3(long long language, long long country)
{
	return new QLocale(static_cast<QLocale::Language>(language), static_cast<QLocale::Country>(country));
}

void* QLocale_NewQLocale4(long long language, long long scri, long long country)
{
	return new QLocale(static_cast<QLocale::Language>(language), static_cast<QLocale::Script>(scri), static_cast<QLocale::Country>(country));
}

void* QLocale_NewQLocale5(void* other)
{
	return new QLocale(*static_cast<QLocale*>(other));
}

void* QLocale_NewQLocale2(struct QtCore_PackedString name)
{
	return new QLocale(QString::fromUtf8(name.data, name.len));
}

struct QtCore_PackedString QLocale_QLocale_CountryToString(long long country)
{
	return ({ QByteArray tbdb30e = QLocale::countryToString(static_cast<QLocale::Country>(country)).toUtf8(); QtCore_PackedString { const_cast<char*>(tbdb30e.prepend("WHITESPACE").constData()+10), tbdb30e.size()-10 }; });
}

struct QtCore_PackedString QLocale_FormattedDataSize(void* ptr, long long bytes, int precision, long long format)
{
	return ({ QByteArray t3e7c75 = static_cast<QLocale*>(ptr)->formattedDataSize(bytes, precision, static_cast<QLocale::DataSizeFormat>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t3e7c75.prepend("WHITESPACE").constData()+10), t3e7c75.size()-10 }; });
}

struct QtCore_PackedString QLocale_QLocale_LanguageToString(long long language)
{
	return ({ QByteArray t29d017 = QLocale::languageToString(static_cast<QLocale::Language>(language)).toUtf8(); QtCore_PackedString { const_cast<char*>(t29d017.prepend("WHITESPACE").constData()+10), t29d017.size()-10 }; });
}

struct QtCore_PackedString QLocale_QLocale_ScriptToString(long long scri)
{
	return ({ QByteArray t535509 = QLocale::scriptToString(static_cast<QLocale::Script>(scri)).toUtf8(); QtCore_PackedString { const_cast<char*>(t535509.prepend("WHITESPACE").constData()+10), t535509.size()-10 }; });
}

void QLocale_QLocale_SetDefault(void* locale)
{
	QLocale::setDefault(*static_cast<QLocale*>(locale));
}

void QLocale_SetNumberOptions(void* ptr, long long options)
{
	static_cast<QLocale*>(ptr)->setNumberOptions(static_cast<QLocale::NumberOption>(options));
}

void QLocale_Swap(void* ptr, void* other)
{
	static_cast<QLocale*>(ptr)->swap(*static_cast<QLocale*>(other));
}

void QLocale_DestroyQLocale(void* ptr)
{
	static_cast<QLocale*>(ptr)->~QLocale();
}

void* QLocale_DecimalPoint(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->decimalPoint());
}

void* QLocale_Exponential(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->exponential());
}

void* QLocale_GroupSeparator(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->groupSeparator());
}

void* QLocale_NegativeSign(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->negativeSign());
}

void* QLocale_Percent(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->percent());
}

void* QLocale_PositiveSign(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->positiveSign());
}

void* QLocale_ZeroDigit(void* ptr)
{
	return new QChar(static_cast<QLocale*>(ptr)->zeroDigit());
}

void* QLocale_ToDate(void* ptr, struct QtCore_PackedString stri, long long format)
{
	return new QDate(static_cast<QLocale*>(ptr)->toDate(QString::fromUtf8(stri.data, stri.len), static_cast<QLocale::FormatType>(format)));
}

void* QLocale_ToDate2(void* ptr, struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QDate(static_cast<QLocale*>(ptr)->toDate(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

void* QLocale_ToDateTime(void* ptr, struct QtCore_PackedString stri, long long format)
{
	return new QDateTime(static_cast<QLocale*>(ptr)->toDateTime(QString::fromUtf8(stri.data, stri.len), static_cast<QLocale::FormatType>(format)));
}

void* QLocale_ToDateTime2(void* ptr, struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QDateTime(static_cast<QLocale*>(ptr)->toDateTime(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

struct QtCore_PackedList QLocale_Weekdays(void* ptr)
{
	return ({ QList<Qt::DayOfWeek>* tmpValueae25dd = new QList<Qt::DayOfWeek>(static_cast<QLocale*>(ptr)->weekdays()); QtCore_PackedList { tmpValueae25dd, tmpValueae25dd->size() }; });
}

long long QLocale_Country(void* ptr)
{
	return static_cast<QLocale*>(ptr)->country();
}

long long QLocale_Language(void* ptr)
{
	return static_cast<QLocale*>(ptr)->language();
}

long long QLocale_MeasurementSystem(void* ptr)
{
	return static_cast<QLocale*>(ptr)->measurementSystem();
}

long long QLocale_NumberOptions(void* ptr)
{
	return static_cast<QLocale*>(ptr)->numberOptions();
}

long long QLocale_Script(void* ptr)
{
	return static_cast<QLocale*>(ptr)->script();
}

struct QtCore_PackedString QLocale_AmText(void* ptr)
{
	return ({ QByteArray t5fc4d4 = static_cast<QLocale*>(ptr)->amText().toUtf8(); QtCore_PackedString { const_cast<char*>(t5fc4d4.prepend("WHITESPACE").constData()+10), t5fc4d4.size()-10 }; });
}

struct QtCore_PackedString QLocale_Bcp47Name(void* ptr)
{
	return ({ QByteArray t0246a7 = static_cast<QLocale*>(ptr)->bcp47Name().toUtf8(); QtCore_PackedString { const_cast<char*>(t0246a7.prepend("WHITESPACE").constData()+10), t0246a7.size()-10 }; });
}

struct QtCore_PackedString QLocale_CreateSeparatedList(void* ptr, struct QtCore_PackedString list)
{
	return ({ QByteArray t6f2da9 = static_cast<QLocale*>(ptr)->createSeparatedList(QString::fromUtf8(list.data, list.len).split("¡¦!", QString::SkipEmptyParts)).toUtf8(); QtCore_PackedString { const_cast<char*>(t6f2da9.prepend("WHITESPACE").constData()+10), t6f2da9.size()-10 }; });
}

struct QtCore_PackedString QLocale_CurrencySymbol(void* ptr, long long format)
{
	return ({ QByteArray t19bd4c = static_cast<QLocale*>(ptr)->currencySymbol(static_cast<QLocale::CurrencySymbolFormat>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t19bd4c.prepend("WHITESPACE").constData()+10), t19bd4c.size()-10 }; });
}

struct QtCore_PackedString QLocale_DateFormat(void* ptr, long long format)
{
	return ({ QByteArray t3ea82c = static_cast<QLocale*>(ptr)->dateFormat(static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t3ea82c.prepend("WHITESPACE").constData()+10), t3ea82c.size()-10 }; });
}

struct QtCore_PackedString QLocale_DateTimeFormat(void* ptr, long long format)
{
	return ({ QByteArray t3e01fc = static_cast<QLocale*>(ptr)->dateTimeFormat(static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t3e01fc.prepend("WHITESPACE").constData()+10), t3e01fc.size()-10 }; });
}

struct QtCore_PackedString QLocale_DayName(void* ptr, int day, long long ty)
{
	return ({ QByteArray t4220d0 = static_cast<QLocale*>(ptr)->dayName(day, static_cast<QLocale::FormatType>(ty)).toUtf8(); QtCore_PackedString { const_cast<char*>(t4220d0.prepend("WHITESPACE").constData()+10), t4220d0.size()-10 }; });
}

struct QtCore_PackedString QLocale_MonthName(void* ptr, int month, long long ty)
{
	return ({ QByteArray t17d183 = static_cast<QLocale*>(ptr)->monthName(month, static_cast<QLocale::FormatType>(ty)).toUtf8(); QtCore_PackedString { const_cast<char*>(t17d183.prepend("WHITESPACE").constData()+10), t17d183.size()-10 }; });
}

struct QtCore_PackedString QLocale_Name(void* ptr)
{
	return ({ QByteArray tee867e = static_cast<QLocale*>(ptr)->name().toUtf8(); QtCore_PackedString { const_cast<char*>(tee867e.prepend("WHITESPACE").constData()+10), tee867e.size()-10 }; });
}

struct QtCore_PackedString QLocale_NativeCountryName(void* ptr)
{
	return ({ QByteArray t08c386 = static_cast<QLocale*>(ptr)->nativeCountryName().toUtf8(); QtCore_PackedString { const_cast<char*>(t08c386.prepend("WHITESPACE").constData()+10), t08c386.size()-10 }; });
}

struct QtCore_PackedString QLocale_NativeLanguageName(void* ptr)
{
	return ({ QByteArray t34cbe6 = static_cast<QLocale*>(ptr)->nativeLanguageName().toUtf8(); QtCore_PackedString { const_cast<char*>(t34cbe6.prepend("WHITESPACE").constData()+10), t34cbe6.size()-10 }; });
}

struct QtCore_PackedString QLocale_PmText(void* ptr)
{
	return ({ QByteArray t37d9b2 = static_cast<QLocale*>(ptr)->pmText().toUtf8(); QtCore_PackedString { const_cast<char*>(t37d9b2.prepend("WHITESPACE").constData()+10), t37d9b2.size()-10 }; });
}

struct QtCore_PackedString QLocale_QuoteString(void* ptr, struct QtCore_PackedString str, long long style)
{
	return ({ QByteArray t76145a = static_cast<QLocale*>(ptr)->quoteString(QString::fromUtf8(str.data, str.len), static_cast<QLocale::QuotationStyle>(style)).toUtf8(); QtCore_PackedString { const_cast<char*>(t76145a.prepend("WHITESPACE").constData()+10), t76145a.size()-10 }; });
}

struct QtCore_PackedString QLocale_QuoteString2(void* ptr, void* str, long long style)
{
	return ({ QByteArray tef32e3 = static_cast<QLocale*>(ptr)->quoteString(*static_cast<QStringRef*>(str), static_cast<QLocale::QuotationStyle>(style)).toUtf8(); QtCore_PackedString { const_cast<char*>(tef32e3.prepend("WHITESPACE").constData()+10), tef32e3.size()-10 }; });
}

struct QtCore_PackedString QLocale_StandaloneDayName(void* ptr, int day, long long ty)
{
	return ({ QByteArray t7850cf = static_cast<QLocale*>(ptr)->standaloneDayName(day, static_cast<QLocale::FormatType>(ty)).toUtf8(); QtCore_PackedString { const_cast<char*>(t7850cf.prepend("WHITESPACE").constData()+10), t7850cf.size()-10 }; });
}

struct QtCore_PackedString QLocale_StandaloneMonthName(void* ptr, int month, long long ty)
{
	return ({ QByteArray t9ff9e7 = static_cast<QLocale*>(ptr)->standaloneMonthName(month, static_cast<QLocale::FormatType>(ty)).toUtf8(); QtCore_PackedString { const_cast<char*>(t9ff9e7.prepend("WHITESPACE").constData()+10), t9ff9e7.size()-10 }; });
}

struct QtCore_PackedString QLocale_TimeFormat(void* ptr, long long format)
{
	return ({ QByteArray t94be08 = static_cast<QLocale*>(ptr)->timeFormat(static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t94be08.prepend("WHITESPACE").constData()+10), t94be08.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString7(void* ptr, double value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString8(void* ptr, double value, struct QtCore_PackedString symbol, int precision)
{
	return ({ QByteArray t891a06 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len), precision).toUtf8(); QtCore_PackedString { const_cast<char*>(t891a06.prepend("WHITESPACE").constData()+10), t891a06.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString10(void* ptr, float i, struct QtCore_PackedString symbol, int precision)
{
	return ({ QByteArray t32b253 = static_cast<QLocale*>(ptr)->toCurrencyString(i, QString::fromUtf8(symbol.data, symbol.len), precision).toUtf8(); QtCore_PackedString { const_cast<char*>(t32b253.prepend("WHITESPACE").constData()+10), t32b253.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString9(void* ptr, float value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString5(void* ptr, int value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString(void* ptr, long long value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString2(void* ptr, unsigned long long value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString3(void* ptr, short value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString6(void* ptr, unsigned int value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToCurrencyString4(void* ptr, unsigned short value, struct QtCore_PackedString symbol)
{
	return ({ QByteArray t0fa4d2 = static_cast<QLocale*>(ptr)->toCurrencyString(value, QString::fromUtf8(symbol.data, symbol.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0fa4d2.prepend("WHITESPACE").constData()+10), t0fa4d2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToLower(void* ptr, struct QtCore_PackedString str)
{
	return ({ QByteArray t112fbe = static_cast<QLocale*>(ptr)->toLower(QString::fromUtf8(str.data, str.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t112fbe.prepend("WHITESPACE").constData()+10), t112fbe.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString15(void* ptr, void* date, long long format)
{
	return ({ QByteArray t1fa262 = static_cast<QLocale*>(ptr)->toString(*static_cast<QDate*>(date), static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t1fa262.prepend("WHITESPACE").constData()+10), t1fa262.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString12(void* ptr, void* date, void* format)
{
	return ({ QByteArray t08b601 = static_cast<QLocale*>(ptr)->toString(*static_cast<QDate*>(date), *static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t08b601.prepend("WHITESPACE").constData()+10), t08b601.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString9(void* ptr, void* date, struct QtCore_PackedString format)
{
	return ({ QByteArray t198629 = static_cast<QLocale*>(ptr)->toString(*static_cast<QDate*>(date), QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t198629.prepend("WHITESPACE").constData()+10), t198629.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString17(void* ptr, void* dateTime, long long format)
{
	return ({ QByteArray t96745f = static_cast<QLocale*>(ptr)->toString(*static_cast<QDateTime*>(dateTime), static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t96745f.prepend("WHITESPACE").constData()+10), t96745f.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString14(void* ptr, void* dateTime, void* format)
{
	return ({ QByteArray t5abf1a = static_cast<QLocale*>(ptr)->toString(*static_cast<QDateTime*>(dateTime), *static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t5abf1a.prepend("WHITESPACE").constData()+10), t5abf1a.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString11(void* ptr, void* dateTime, struct QtCore_PackedString format)
{
	return ({ QByteArray t336e5f = static_cast<QLocale*>(ptr)->toString(*static_cast<QDateTime*>(dateTime), QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t336e5f.prepend("WHITESPACE").constData()+10), t336e5f.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString16(void* ptr, void* ti, long long format)
{
	return ({ QByteArray tb6230e = static_cast<QLocale*>(ptr)->toString(*static_cast<QTime*>(ti), static_cast<QLocale::FormatType>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(tb6230e.prepend("WHITESPACE").constData()+10), tb6230e.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString13(void* ptr, void* ti, void* format)
{
	return ({ QByteArray t697961 = static_cast<QLocale*>(ptr)->toString(*static_cast<QTime*>(ti), *static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t697961.prepend("WHITESPACE").constData()+10), t697961.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString10(void* ptr, void* ti, struct QtCore_PackedString format)
{
	return ({ QByteArray t607af9 = static_cast<QLocale*>(ptr)->toString(*static_cast<QTime*>(ti), QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t607af9.prepend("WHITESPACE").constData()+10), t607af9.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString7(void* ptr, double i, char* ff, int prec)
{
	return ({ QByteArray t07d146 = static_cast<QLocale*>(ptr)->toString(i, *ff, prec).toUtf8(); QtCore_PackedString { const_cast<char*>(t07d146.prepend("WHITESPACE").constData()+10), t07d146.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString8(void* ptr, float i, char* ff, int prec)
{
	return ({ QByteArray t07d146 = static_cast<QLocale*>(ptr)->toString(i, *ff, prec).toUtf8(); QtCore_PackedString { const_cast<char*>(t07d146.prepend("WHITESPACE").constData()+10), t07d146.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString5(void* ptr, int i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString(void* ptr, long long i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString2(void* ptr, unsigned long long i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString3(void* ptr, short i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString6(void* ptr, unsigned int i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToString4(void* ptr, unsigned short i)
{
	return ({ QByteArray teea9c2 = static_cast<QLocale*>(ptr)->toString(i).toUtf8(); QtCore_PackedString { const_cast<char*>(teea9c2.prepend("WHITESPACE").constData()+10), teea9c2.size()-10 }; });
}

struct QtCore_PackedString QLocale_ToUpper(void* ptr, struct QtCore_PackedString str)
{
	return ({ QByteArray t6969d0 = static_cast<QLocale*>(ptr)->toUpper(QString::fromUtf8(str.data, str.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t6969d0.prepend("WHITESPACE").constData()+10), t6969d0.size()-10 }; });
}

struct QtCore_PackedString QLocale_UiLanguages(void* ptr)
{
	return ({ QByteArray tf4f58b = static_cast<QLocale*>(ptr)->uiLanguages().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tf4f58b.prepend("WHITESPACE").constData()+10), tf4f58b.size()-10 }; });
}

void* QLocale_ToTime(void* ptr, struct QtCore_PackedString stri, long long format)
{
	return new QTime(static_cast<QLocale*>(ptr)->toTime(QString::fromUtf8(stri.data, stri.len), static_cast<QLocale::FormatType>(format)));
}

void* QLocale_ToTime2(void* ptr, struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QTime(static_cast<QLocale*>(ptr)->toTime(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

long long QLocale_FirstDayOfWeek(void* ptr)
{
	return static_cast<QLocale*>(ptr)->firstDayOfWeek();
}

long long QLocale_TextDirection(void* ptr)
{
	return static_cast<QLocale*>(ptr)->textDirection();
}

double QLocale_ToDouble3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toDouble(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

double QLocale_ToDouble(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toDouble(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

double QLocale_ToDouble2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toDouble(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

float QLocale_ToFloat3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toFloat(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

float QLocale_ToFloat(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toFloat(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

float QLocale_ToFloat2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toFloat(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

int QLocale_ToInt3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toInt(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

int QLocale_ToInt(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toInt(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

int QLocale_ToInt2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toInt(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

long long QLocale_ToLongLong3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toLongLong(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

long long QLocale_ToLongLong(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toLongLong(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

long long QLocale_ToLongLong2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toLongLong(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

unsigned long long QLocale_ToULongLong3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toULongLong(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

unsigned long long QLocale_ToULongLong(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toULongLong(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

unsigned long long QLocale_ToULongLong2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toULongLong(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

short QLocale_ToShort3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toShort(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

short QLocale_ToShort(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toShort(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

short QLocale_ToShort2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toShort(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

unsigned int QLocale_ToUInt3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUInt(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

unsigned int QLocale_ToUInt(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUInt(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

unsigned int QLocale_ToUInt2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUInt(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

unsigned short QLocale_ToUShort3(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUShort(*static_cast<QStringView*>(s), reinterpret_cast<bool*>(ok));
}

unsigned short QLocale_ToUShort(void* ptr, struct QtCore_PackedString s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUShort(QString::fromUtf8(s.data, s.len), reinterpret_cast<bool*>(ok));
}

unsigned short QLocale_ToUShort2(void* ptr, void* s, char* ok)
{
	return static_cast<QLocale*>(ptr)->toUShort(*static_cast<QStringRef*>(s), reinterpret_cast<bool*>(ok));
}

void* QLocale___matchingLocales_atList(void* ptr, int i)
{
	return new QLocale(({QLocale tmp = static_cast<QList<QLocale>*>(ptr)->at(i); if (i == static_cast<QList<QLocale>*>(ptr)->size()-1) { static_cast<QList<QLocale>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QLocale___matchingLocales_setList(void* ptr, void* i)
{
	static_cast<QList<QLocale>*>(ptr)->append(*static_cast<QLocale*>(i));
}

void* QLocale___matchingLocales_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QLocale>();
}

long long QLocale___weekdays_atList(void* ptr, int i)
{
	return ({Qt::DayOfWeek tmp = static_cast<QList<Qt::DayOfWeek>*>(ptr)->at(i); if (i == static_cast<QList<Qt::DayOfWeek>*>(ptr)->size()-1) { static_cast<QList<Qt::DayOfWeek>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QLocale___weekdays_setList(void* ptr, long long i)
{
	static_cast<QList<Qt::DayOfWeek>*>(ptr)->append(static_cast<Qt::DayOfWeek>(i));
}

void* QLocale___weekdays_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<Qt::DayOfWeek>();
}

Q_DECLARE_METATYPE(QMargins)
Q_DECLARE_METATYPE(QMargins*)
void* QMargins_NewQMargins()
{
	return new QMargins();
}

void* QMargins_NewQMargins2(int left, int top, int right, int bottom)
{
	return new QMargins(left, top, right, bottom);
}

void QMargins_SetBottom(void* ptr, int bottom)
{
	static_cast<QMargins*>(ptr)->setBottom(bottom);
}

void QMargins_SetLeft(void* ptr, int left)
{
	static_cast<QMargins*>(ptr)->setLeft(left);
}

void QMargins_SetRight(void* ptr, int right)
{
	static_cast<QMargins*>(ptr)->setRight(right);
}

void QMargins_SetTop(void* ptr, int Top)
{
	static_cast<QMargins*>(ptr)->setTop(Top);
}

char QMargins_IsNull(void* ptr)
{
	return static_cast<QMargins*>(ptr)->isNull();
}

int QMargins_Bottom(void* ptr)
{
	return static_cast<QMargins*>(ptr)->bottom();
}

int QMargins_Left(void* ptr)
{
	return static_cast<QMargins*>(ptr)->left();
}

int QMargins_Right(void* ptr)
{
	return static_cast<QMargins*>(ptr)->right();
}

int QMargins_Top(void* ptr)
{
	return static_cast<QMargins*>(ptr)->top();
}

Q_DECLARE_METATYPE(QMarginsF)
Q_DECLARE_METATYPE(QMarginsF*)
void* QMarginsF_NewQMarginsF()
{
	return new QMarginsF();
}

void* QMarginsF_NewQMarginsF3(void* margins)
{
	return new QMarginsF(*static_cast<QMargins*>(margins));
}

void* QMarginsF_NewQMarginsF2(double left, double top, double right, double bottom)
{
	return new QMarginsF(left, top, right, bottom);
}

void QMarginsF_SetBottom(void* ptr, double bottom)
{
	static_cast<QMarginsF*>(ptr)->setBottom(bottom);
}

void QMarginsF_SetLeft(void* ptr, double left)
{
	static_cast<QMarginsF*>(ptr)->setLeft(left);
}

void QMarginsF_SetRight(void* ptr, double right)
{
	static_cast<QMarginsF*>(ptr)->setRight(right);
}

void QMarginsF_SetTop(void* ptr, double Top)
{
	static_cast<QMarginsF*>(ptr)->setTop(Top);
}

void* QMarginsF_ToMargins(void* ptr)
{
	return ({ QMargins tmpValue = static_cast<QMarginsF*>(ptr)->toMargins(); new QMargins(tmpValue.left(), tmpValue.top(), tmpValue.right(), tmpValue.bottom()); });
}

char QMarginsF_IsNull(void* ptr)
{
	return static_cast<QMarginsF*>(ptr)->isNull();
}

double QMarginsF_Bottom(void* ptr)
{
	return static_cast<QMarginsF*>(ptr)->bottom();
}

double QMarginsF_Left(void* ptr)
{
	return static_cast<QMarginsF*>(ptr)->left();
}

double QMarginsF_Right(void* ptr)
{
	return static_cast<QMarginsF*>(ptr)->right();
}

double QMarginsF_Top(void* ptr)
{
	return static_cast<QMarginsF*>(ptr)->top();
}

struct QtCore_PackedString QMetaClassInfo_Name(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaClassInfo*>(ptr)->name()), -1 };
}

struct QtCore_PackedString QMetaClassInfo_Value(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaClassInfo*>(ptr)->value()), -1 };
}

void* QMetaEnum_ValueToKeys(void* ptr, int value)
{
	return new QByteArray(static_cast<QMetaEnum*>(ptr)->valueToKeys(value));
}

char QMetaEnum_IsFlag(void* ptr)
{
	return static_cast<QMetaEnum*>(ptr)->isFlag();
}

char QMetaEnum_IsScoped(void* ptr)
{
	return static_cast<QMetaEnum*>(ptr)->isScoped();
}

char QMetaEnum_IsValid(void* ptr)
{
	return static_cast<QMetaEnum*>(ptr)->isValid();
}

struct QtCore_PackedString QMetaEnum_EnumName(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaEnum*>(ptr)->enumName()), -1 };
}

struct QtCore_PackedString QMetaEnum_Key(void* ptr, int index)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaEnum*>(ptr)->key(index)), index };
}

struct QtCore_PackedString QMetaEnum_Name(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaEnum*>(ptr)->name()), -1 };
}

struct QtCore_PackedString QMetaEnum_Scope(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaEnum*>(ptr)->scope()), -1 };
}

struct QtCore_PackedString QMetaEnum_ValueToKey(void* ptr, int value)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaEnum*>(ptr)->valueToKey(value)), value };
}

int QMetaEnum_KeyCount(void* ptr)
{
	return static_cast<QMetaEnum*>(ptr)->keyCount();
}

int QMetaEnum_KeyToValue(void* ptr, char* key, char* ok)
{
	return static_cast<QMetaEnum*>(ptr)->keyToValue(const_cast<const char*>(key), reinterpret_cast<bool*>(ok));
}

int QMetaEnum_KeysToValue(void* ptr, char* keys, char* ok)
{
	return static_cast<QMetaEnum*>(ptr)->keysToValue(const_cast<const char*>(keys), reinterpret_cast<bool*>(ok));
}

int QMetaEnum_Value(void* ptr, int index)
{
	return static_cast<QMetaEnum*>(ptr)->value(index);
}

void* QMetaMethod_MethodSignature(void* ptr)
{
	return new QByteArray(static_cast<QMetaMethod*>(ptr)->methodSignature());
}

void* QMetaMethod_Name(void* ptr)
{
	return new QByteArray(static_cast<QMetaMethod*>(ptr)->name());
}

struct QtCore_PackedList QMetaMethod_ParameterNames(void* ptr)
{
	return ({ QList<QByteArray>* tmpValuec7ea97 = new QList<QByteArray>(static_cast<QMetaMethod*>(ptr)->parameterNames()); QtCore_PackedList { tmpValuec7ea97, tmpValuec7ea97->size() }; });
}

struct QtCore_PackedList QMetaMethod_ParameterTypes(void* ptr)
{
	return ({ QList<QByteArray>* tmpValue4f9e78 = new QList<QByteArray>(static_cast<QMetaMethod*>(ptr)->parameterTypes()); QtCore_PackedList { tmpValue4f9e78, tmpValue4f9e78->size() }; });
}

long long QMetaMethod_Access(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->access();
}

long long QMetaMethod_MethodType(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->methodType();
}

char QMetaMethod_Invoke4(void* ptr, void* object, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invoke(static_cast<QObject*>(object), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_Invoke2(void* ptr, void* object, void* returnValue, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invoke(static_cast<QObject*>(object), *static_cast<QGenericReturnArgument*>(returnValue), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_Invoke3(void* ptr, void* object, long long connectionType, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invoke(static_cast<QObject*>(object), static_cast<Qt::ConnectionType>(connectionType), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_Invoke(void* ptr, void* object, long long connectionType, void* returnValue, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invoke(static_cast<QObject*>(object), static_cast<Qt::ConnectionType>(connectionType), *static_cast<QGenericReturnArgument*>(returnValue), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_InvokeOnGadget2(void* ptr, void* gadget, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invokeOnGadget(gadget, *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_InvokeOnGadget(void* ptr, void* gadget, void* returnValue, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaMethod*>(ptr)->invokeOnGadget(gadget, *static_cast<QGenericReturnArgument*>(returnValue), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaMethod_IsValid(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->isValid();
}

struct QtCore_PackedString QMetaMethod_Tag(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaMethod*>(ptr)->tag()), -1 };
}

struct QtCore_PackedString QMetaMethod_TypeName(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaMethod*>(ptr)->typeName()), -1 };
}

int QMetaMethod_MethodIndex(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->methodIndex();
}

int QMetaMethod_ParameterCount(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->parameterCount();
}

int QMetaMethod_ParameterType(void* ptr, int index)
{
	return static_cast<QMetaMethod*>(ptr)->parameterType(index);
}

int QMetaMethod_ReturnType(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->returnType();
}

int QMetaMethod_Revision(void* ptr)
{
	return static_cast<QMetaMethod*>(ptr)->revision();
}

void* QMetaMethod___parameterNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QMetaMethod___parameterNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QMetaMethod___parameterNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QMetaMethod___parameterTypes_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QMetaMethod___parameterTypes_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QMetaMethod___parameterTypes_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QMetaObject_QMetaObject_NormalizedSignature(char* method)
{
	return new QByteArray(QMetaObject::normalizedSignature(const_cast<const char*>(method)));
}

void* QMetaObject_QMetaObject_NormalizedType(char* ty)
{
	return new QByteArray(QMetaObject::normalizedType(const_cast<const char*>(ty)));
}

char QMetaObject_QMetaObject_CheckConnectArgs2(void* sign, void* method)
{
	return QMetaObject::checkConnectArgs(*static_cast<QMetaMethod*>(sign), *static_cast<QMetaMethod*>(method));
}

char QMetaObject_QMetaObject_CheckConnectArgs(char* sign, char* method)
{
	return QMetaObject::checkConnectArgs(const_cast<const char*>(sign), const_cast<const char*>(method));
}

char QMetaObject_QMetaObject_InvokeMethod4(void* obj, char* member, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return QMetaObject::invokeMethod(static_cast<QObject*>(obj), const_cast<const char*>(member), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaObject_QMetaObject_InvokeMethod2(void* obj, char* member, void* ret, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return QMetaObject::invokeMethod(static_cast<QObject*>(obj), const_cast<const char*>(member), *static_cast<QGenericReturnArgument*>(ret), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaObject_QMetaObject_InvokeMethod3(void* obj, char* member, long long ty, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return QMetaObject::invokeMethod(static_cast<QObject*>(obj), const_cast<const char*>(member), static_cast<Qt::ConnectionType>(ty), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaObject_QMetaObject_InvokeMethod(void* obj, char* member, long long ty, void* ret, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return QMetaObject::invokeMethod(static_cast<QObject*>(obj), const_cast<const char*>(member), static_cast<Qt::ConnectionType>(ty), *static_cast<QGenericReturnArgument*>(ret), *static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

void QMetaObject_QMetaObject_ConnectSlotsByName(void* object)
{
	QMetaObject::connectSlotsByName(static_cast<QObject*>(object));
}

void* QMetaObject_Constructor(void* ptr, int index)
{
	return new QMetaMethod(static_cast<QMetaObject*>(ptr)->constructor(index));
}

void* QMetaObject_Method(void* ptr, int index)
{
	return new QMetaMethod(static_cast<QMetaObject*>(ptr)->method(index));
}

void* QMetaObject_NewInstance(void* ptr, void* val0, void* val1, void* val2, void* val3, void* val4, void* val5, void* val6, void* val7, void* val8, void* val9)
{
	return static_cast<QMetaObject*>(ptr)->newInstance(*static_cast<QGenericArgument*>(val0), *static_cast<QGenericArgument*>(val1), *static_cast<QGenericArgument*>(val2), *static_cast<QGenericArgument*>(val3), *static_cast<QGenericArgument*>(val4), *static_cast<QGenericArgument*>(val5), *static_cast<QGenericArgument*>(val6), *static_cast<QGenericArgument*>(val7), *static_cast<QGenericArgument*>(val8), *static_cast<QGenericArgument*>(val9));
}

char QMetaObject_Inherits(void* ptr, void* metaObject)
{
	return static_cast<QMetaObject*>(ptr)->inherits(static_cast<QMetaObject*>(metaObject));
}

void* QMetaObject_SuperClass(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QMetaObject*>(ptr)->superClass());
}

struct QtCore_PackedString QMetaObject_ClassName(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaObject*>(ptr)->className()), -1 };
}

int QMetaObject_ClassInfoCount(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->classInfoCount();
}

int QMetaObject_ClassInfoOffset(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->classInfoOffset();
}

int QMetaObject_ConstructorCount(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->constructorCount();
}

int QMetaObject_EnumeratorCount(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->enumeratorCount();
}

int QMetaObject_EnumeratorOffset(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->enumeratorOffset();
}

int QMetaObject_IndexOfClassInfo(void* ptr, char* name)
{
	return static_cast<QMetaObject*>(ptr)->indexOfClassInfo(const_cast<const char*>(name));
}

int QMetaObject_IndexOfConstructor(void* ptr, char* constructor)
{
	return static_cast<QMetaObject*>(ptr)->indexOfConstructor(const_cast<const char*>(constructor));
}

int QMetaObject_IndexOfEnumerator(void* ptr, char* name)
{
	return static_cast<QMetaObject*>(ptr)->indexOfEnumerator(const_cast<const char*>(name));
}

int QMetaObject_IndexOfMethod(void* ptr, char* method)
{
	return static_cast<QMetaObject*>(ptr)->indexOfMethod(const_cast<const char*>(method));
}

int QMetaObject_IndexOfProperty(void* ptr, char* name)
{
	return static_cast<QMetaObject*>(ptr)->indexOfProperty(const_cast<const char*>(name));
}

int QMetaObject_IndexOfSignal(void* ptr, char* sign)
{
	return static_cast<QMetaObject*>(ptr)->indexOfSignal(const_cast<const char*>(sign));
}

int QMetaObject_IndexOfSlot(void* ptr, char* slot)
{
	return static_cast<QMetaObject*>(ptr)->indexOfSlot(const_cast<const char*>(slot));
}

int QMetaObject_MethodCount(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->methodCount();
}

int QMetaObject_MethodOffset(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->methodOffset();
}

int QMetaObject_PropertyCount(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->propertyCount();
}

int QMetaObject_PropertyOffset(void* ptr)
{
	return static_cast<QMetaObject*>(ptr)->propertyOffset();
}

void* QMetaProperty_NotifySignal(void* ptr)
{
	return new QMetaMethod(static_cast<QMetaProperty*>(ptr)->notifySignal());
}

void* QMetaProperty_Read(void* ptr, void* object)
{
	return new QVariant(static_cast<QMetaProperty*>(ptr)->read(static_cast<QObject*>(object)));
}

void* QMetaProperty_ReadOnGadget(void* ptr, void* gadget)
{
	return new QVariant(static_cast<QMetaProperty*>(ptr)->readOnGadget(gadget));
}

long long QMetaProperty_Type(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->type();
}

char QMetaProperty_HasNotifySignal(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->hasNotifySignal();
}

char QMetaProperty_IsConstant(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isConstant();
}

char QMetaProperty_IsDesignable(void* ptr, void* object)
{
	return static_cast<QMetaProperty*>(ptr)->isDesignable(static_cast<QObject*>(object));
}

char QMetaProperty_IsEnumType(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isEnumType();
}

char QMetaProperty_IsFinal(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isFinal();
}

char QMetaProperty_IsFlagType(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isFlagType();
}

char QMetaProperty_IsReadable(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isReadable();
}

char QMetaProperty_IsResettable(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isResettable();
}

char QMetaProperty_IsScriptable(void* ptr, void* object)
{
	return static_cast<QMetaProperty*>(ptr)->isScriptable(static_cast<QObject*>(object));
}

char QMetaProperty_IsStored(void* ptr, void* object)
{
	return static_cast<QMetaProperty*>(ptr)->isStored(static_cast<QObject*>(object));
}

char QMetaProperty_IsUser(void* ptr, void* object)
{
	return static_cast<QMetaProperty*>(ptr)->isUser(static_cast<QObject*>(object));
}

char QMetaProperty_IsValid(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isValid();
}

char QMetaProperty_IsWritable(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->isWritable();
}

char QMetaProperty_Reset(void* ptr, void* object)
{
	return static_cast<QMetaProperty*>(ptr)->reset(static_cast<QObject*>(object));
}

char QMetaProperty_ResetOnGadget(void* ptr, void* gadget)
{
	return static_cast<QMetaProperty*>(ptr)->resetOnGadget(gadget);
}

char QMetaProperty_Write(void* ptr, void* object, void* value)
{
	return static_cast<QMetaProperty*>(ptr)->write(static_cast<QObject*>(object), *static_cast<QVariant*>(value));
}

char QMetaProperty_WriteOnGadget(void* ptr, void* gadget, void* value)
{
	return static_cast<QMetaProperty*>(ptr)->writeOnGadget(gadget, *static_cast<QVariant*>(value));
}

struct QtCore_PackedString QMetaProperty_Name(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaProperty*>(ptr)->name()), -1 };
}

struct QtCore_PackedString QMetaProperty_TypeName(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QMetaProperty*>(ptr)->typeName()), -1 };
}

int QMetaProperty_NotifySignalIndex(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->notifySignalIndex();
}

int QMetaProperty_PropertyIndex(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->propertyIndex();
}

int QMetaProperty_Revision(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->revision();
}

int QMetaProperty_UserType(void* ptr)
{
	return static_cast<QMetaProperty*>(ptr)->userType();
}

class MyQMimeData: public QMimeData
{
public:
	MyQMimeData() : QMimeData() {QMimeData_QMimeData_QRegisterMetaType();};
	 ~MyQMimeData() { callbackQMimeData_DestroyQMimeData(this); };
	QStringList formats() const { return ({ QtCore_PackedString tempVal = callbackQMimeData_Formats(const_cast<void*>(static_cast<const void*>(this))); QStringList ret = QString::fromUtf8(tempVal.data, tempVal.len).split("¡¦!", QString::SkipEmptyParts); free(tempVal.data); ret; }); };
	QVariant retrieveData(const QString & mimeType, QVariant::Type ty) const { QByteArray t3313b8 = mimeType.toUtf8(); QtCore_PackedString mimeTypePacked = { const_cast<char*>(t3313b8.prepend("WHITESPACE").constData()+10), t3313b8.size()-10 };return *static_cast<QVariant*>(callbackQMimeData_RetrieveData(const_cast<void*>(static_cast<const void*>(this)), mimeTypePacked, ty)); };
	bool hasFormat(const QString & mimeType) const { QByteArray t3313b8 = mimeType.toUtf8(); QtCore_PackedString mimeTypePacked = { const_cast<char*>(t3313b8.prepend("WHITESPACE").constData()+10), t3313b8.size()-10 };return callbackQMimeData_HasFormat(const_cast<void*>(static_cast<const void*>(this)), mimeTypePacked) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QMimeData*)
Q_DECLARE_METATYPE(MyQMimeData*)

int QMimeData_QMimeData_QRegisterMetaType(){qRegisterMetaType<QMimeData*>(); return qRegisterMetaType<MyQMimeData*>();}

void* QMimeData_NewQMimeData()
{
	return new MyQMimeData();
}

void QMimeData_Clear(void* ptr)
{
	static_cast<QMimeData*>(ptr)->clear();
}

void QMimeData_RemoveFormat(void* ptr, struct QtCore_PackedString mimeType)
{
	static_cast<QMimeData*>(ptr)->removeFormat(QString::fromUtf8(mimeType.data, mimeType.len));
}

void QMimeData_SetColorData(void* ptr, void* color)
{
	static_cast<QMimeData*>(ptr)->setColorData(*static_cast<QVariant*>(color));
}

void QMimeData_SetData(void* ptr, struct QtCore_PackedString mimeType, void* data)
{
	static_cast<QMimeData*>(ptr)->setData(QString::fromUtf8(mimeType.data, mimeType.len), *static_cast<QByteArray*>(data));
}

void QMimeData_SetHtml(void* ptr, struct QtCore_PackedString html)
{
	static_cast<QMimeData*>(ptr)->setHtml(QString::fromUtf8(html.data, html.len));
}

void QMimeData_SetImageData(void* ptr, void* image)
{
	static_cast<QMimeData*>(ptr)->setImageData(*static_cast<QVariant*>(image));
}

void QMimeData_SetText(void* ptr, struct QtCore_PackedString text)
{
	static_cast<QMimeData*>(ptr)->setText(QString::fromUtf8(text.data, text.len));
}

void QMimeData_SetUrls(void* ptr, void* urls)
{
	static_cast<QMimeData*>(ptr)->setUrls(*static_cast<QList<QUrl>*>(urls));
}

void QMimeData_DestroyQMimeData(void* ptr)
{
	static_cast<QMimeData*>(ptr)->~QMimeData();
}

void QMimeData_DestroyQMimeDataDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void* QMimeData_Data(void* ptr, struct QtCore_PackedString mimeType)
{
	return new QByteArray(static_cast<QMimeData*>(ptr)->data(QString::fromUtf8(mimeType.data, mimeType.len)));
}

struct QtCore_PackedList QMimeData_Urls(void* ptr)
{
	return ({ QList<QUrl>* tmpValuea61c1b = new QList<QUrl>(static_cast<QMimeData*>(ptr)->urls()); QtCore_PackedList { tmpValuea61c1b, tmpValuea61c1b->size() }; });
}

struct QtCore_PackedString QMimeData_Html(void* ptr)
{
	return ({ QByteArray te6f56b = static_cast<QMimeData*>(ptr)->html().toUtf8(); QtCore_PackedString { const_cast<char*>(te6f56b.prepend("WHITESPACE").constData()+10), te6f56b.size()-10 }; });
}

struct QtCore_PackedString QMimeData_Text(void* ptr)
{
	return ({ QByteArray t2355ec = static_cast<QMimeData*>(ptr)->text().toUtf8(); QtCore_PackedString { const_cast<char*>(t2355ec.prepend("WHITESPACE").constData()+10), t2355ec.size()-10 }; });
}

struct QtCore_PackedString QMimeData_Formats(void* ptr)
{
	return ({ QByteArray t353e58 = static_cast<QMimeData*>(ptr)->formats().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t353e58.prepend("WHITESPACE").constData()+10), t353e58.size()-10 }; });
}

struct QtCore_PackedString QMimeData_FormatsDefault(void* ptr)
{
		return ({ QByteArray td5c1b6 = static_cast<QMimeData*>(ptr)->QMimeData::formats().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(td5c1b6.prepend("WHITESPACE").constData()+10), td5c1b6.size()-10 }; });
}

void* QMimeData_ColorData(void* ptr)
{
	return new QVariant(static_cast<QMimeData*>(ptr)->colorData());
}

void* QMimeData_ImageData(void* ptr)
{
	return new QVariant(static_cast<QMimeData*>(ptr)->imageData());
}

void* QMimeData_RetrieveData(void* ptr, struct QtCore_PackedString mimeType, long long ty)
{
	return new QVariant(static_cast<QMimeData*>(ptr)->retrieveData(QString::fromUtf8(mimeType.data, mimeType.len), static_cast<QVariant::Type>(ty)));
}

void* QMimeData_RetrieveDataDefault(void* ptr, struct QtCore_PackedString mimeType, long long ty)
{
		return new QVariant(static_cast<QMimeData*>(ptr)->QMimeData::retrieveData(QString::fromUtf8(mimeType.data, mimeType.len), static_cast<QVariant::Type>(ty)));
}

char QMimeData_HasColor(void* ptr)
{
	return static_cast<QMimeData*>(ptr)->hasColor();
}

char QMimeData_HasFormat(void* ptr, struct QtCore_PackedString mimeType)
{
	return static_cast<QMimeData*>(ptr)->hasFormat(QString::fromUtf8(mimeType.data, mimeType.len));
}

char QMimeData_HasFormatDefault(void* ptr, struct QtCore_PackedString mimeType)
{
		return static_cast<QMimeData*>(ptr)->QMimeData::hasFormat(QString::fromUtf8(mimeType.data, mimeType.len));
}

char QMimeData_HasHtml(void* ptr)
{
	return static_cast<QMimeData*>(ptr)->hasHtml();
}

char QMimeData_HasImage(void* ptr)
{
	return static_cast<QMimeData*>(ptr)->hasImage();
}

char QMimeData_HasText(void* ptr)
{
	return static_cast<QMimeData*>(ptr)->hasText();
}

char QMimeData_HasUrls(void* ptr)
{
	return static_cast<QMimeData*>(ptr)->hasUrls();
}

void* QMimeData___setUrls_urls_atList(void* ptr, int i)
{
	return new QUrl(({QUrl tmp = static_cast<QList<QUrl>*>(ptr)->at(i); if (i == static_cast<QList<QUrl>*>(ptr)->size()-1) { static_cast<QList<QUrl>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QMimeData___setUrls_urls_setList(void* ptr, void* i)
{
	static_cast<QList<QUrl>*>(ptr)->append(*static_cast<QUrl*>(i));
}

void* QMimeData___setUrls_urls_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QUrl>();
}

void* QMimeData___urls_atList(void* ptr, int i)
{
	return new QUrl(({QUrl tmp = static_cast<QList<QUrl>*>(ptr)->at(i); if (i == static_cast<QList<QUrl>*>(ptr)->size()-1) { static_cast<QList<QUrl>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QMimeData___urls_setList(void* ptr, void* i)
{
	static_cast<QList<QUrl>*>(ptr)->append(*static_cast<QUrl*>(i));
}

void* QMimeData___urls_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QUrl>();
}

Q_DECLARE_METATYPE(QModelIndex)
Q_DECLARE_METATYPE(QModelIndex*)
void* QModelIndex_NewQModelIndex()
{
	return new QModelIndex();
}

void* QModelIndex_Parent(void* ptr)
{
	return new QModelIndex(static_cast<QModelIndex*>(ptr)->parent());
}

void* QModelIndex_Sibling(void* ptr, int row, int column)
{
	return new QModelIndex(static_cast<QModelIndex*>(ptr)->sibling(row, column));
}

void* QModelIndex_SiblingAtColumn(void* ptr, int column)
{
	return new QModelIndex(static_cast<QModelIndex*>(ptr)->siblingAtColumn(column));
}

void* QModelIndex_SiblingAtRow(void* ptr, int row)
{
	return new QModelIndex(static_cast<QModelIndex*>(ptr)->siblingAtRow(row));
}

void* QModelIndex_Data(void* ptr, int role)
{
	return new QVariant(static_cast<QModelIndex*>(ptr)->data(role));
}

long long QModelIndex_Flags(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->flags();
}

char QModelIndex_IsValid(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->isValid();
}

void* QModelIndex_Model(void* ptr)
{
	return const_cast<QAbstractItemModel*>(static_cast<QModelIndex*>(ptr)->model());
}

int QModelIndex_Column(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->column();
}

int QModelIndex_Row(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->row();
}

uintptr_t QModelIndex_InternalId(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->internalId();
}

void* QModelIndex_InternalPointer(void* ptr)
{
	return static_cast<QModelIndex*>(ptr)->internalPointer();
}

class MyQObject: public QObject
{
public:
	MyQObject(QObject *parent = Q_NULLPTR) : QObject(parent) {QObject_QObject_QRegisterMetaType();};
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
	 ~MyQObject() { callbackQObject_DestroyQObject(this); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
};

Q_DECLARE_METATYPE(MyQObject*)

int QObject_QObject_QRegisterMetaType(){qRegisterMetaType<QObject*>(); return qRegisterMetaType<MyQObject*>();}

void* QObject_NewQObject(void* parent)
{
	return new MyQObject(static_cast<QObject*>(parent));
}

struct QtCore_PackedString QObject_QObject_Tr(char* sourceText, char* disambiguation, int n)
{
	return ({ QByteArray te5b32b = QObject::tr(const_cast<const char*>(sourceText), const_cast<const char*>(disambiguation), n).toUtf8(); QtCore_PackedString { const_cast<char*>(te5b32b.prepend("WHITESPACE").constData()+10), te5b32b.size()-10 }; });
}

char QObject_BlockSignals(void* ptr, char block)
{
	return static_cast<QObject*>(ptr)->blockSignals(block != 0);
}

char QObject_QObject_Disconnect2(void* sender, void* sign, void* receiver, void* method)
{
	return QObject::disconnect(static_cast<QObject*>(sender), *static_cast<QMetaMethod*>(sign), static_cast<QObject*>(receiver), *static_cast<QMetaMethod*>(method));
}

char QObject_QObject_Disconnect(void* sender, char* sign, void* receiver, char* method)
{
	return QObject::disconnect(static_cast<QObject*>(sender), const_cast<const char*>(sign), static_cast<QObject*>(receiver), const_cast<const char*>(method));
}

char QObject_Event(void* ptr, void* e)
{
	return static_cast<QObject*>(ptr)->event(static_cast<QEvent*>(e));
}

char QObject_EventDefault(void* ptr, void* e)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		return static_cast<QTranslator*>(ptr)->QTranslator::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		return static_cast<QThread*>(ptr)->QThread::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		return static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		return static_cast<QMimeData*>(ptr)->QMimeData::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		return static_cast<QIODevice*>(ptr)->QIODevice::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		return static_cast<QCoreApplication*>(ptr)->QCoreApplication::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::event(static_cast<QEvent*>(e));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		return static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::event(static_cast<QEvent*>(e));
	} else {
		return static_cast<QObject*>(ptr)->QObject::event(static_cast<QEvent*>(e));
	}
}

char QObject_EventFilter(void* ptr, void* watched, void* event)
{
	return static_cast<QObject*>(ptr)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

char QObject_EventFilterDefault(void* ptr, void* watched, void* event)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		return static_cast<QTranslator*>(ptr)->QTranslator::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		return static_cast<QThread*>(ptr)->QThread::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		return static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		return static_cast<QMimeData*>(ptr)->QMimeData::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		return static_cast<QIODevice*>(ptr)->QIODevice::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		return static_cast<QCoreApplication*>(ptr)->QCoreApplication::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		return static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		return static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	} else {
		return static_cast<QObject*>(ptr)->QObject::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
	}
}

char QObject_SetProperty(void* ptr, char* name, void* value)
{
	return static_cast<QObject*>(ptr)->setProperty(const_cast<const char*>(name), *static_cast<QVariant*>(value));
}

int QObject_StartTimer(void* ptr, int interval, long long timerType)
{
	return static_cast<QObject*>(ptr)->startTimer(interval, static_cast<Qt::TimerType>(timerType));
}

void QObject_ChildEvent(void* ptr, void* event)
{
	static_cast<QObject*>(ptr)->childEvent(static_cast<QChildEvent*>(event));
}

void QObject_ChildEventDefault(void* ptr, void* event)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::childEvent(static_cast<QChildEvent*>(event));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::childEvent(static_cast<QChildEvent*>(event));
	} else {
		static_cast<QObject*>(ptr)->QObject::childEvent(static_cast<QChildEvent*>(event));
	}
}

void QObject_ConnectNotify(void* ptr, void* sign)
{
	static_cast<QObject*>(ptr)->connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QObject_ConnectNotifyDefault(void* ptr, void* sign)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::connectNotify(*static_cast<QMetaMethod*>(sign));
	} else {
		static_cast<QObject*>(ptr)->QObject::connectNotify(*static_cast<QMetaMethod*>(sign));
	}
}

void QObject_CustomEvent(void* ptr, void* event)
{
	static_cast<QObject*>(ptr)->customEvent(static_cast<QEvent*>(event));
}

void QObject_CustomEventDefault(void* ptr, void* event)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::customEvent(static_cast<QEvent*>(event));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::customEvent(static_cast<QEvent*>(event));
	} else {
		static_cast<QObject*>(ptr)->QObject::customEvent(static_cast<QEvent*>(event));
	}
}

void QObject_DeleteLater(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QObject*>(ptr), "deleteLater");
}

void QObject_DeleteLaterDefault(void* ptr)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::deleteLater();
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::deleteLater();
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::deleteLater();
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::deleteLater();
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::deleteLater();
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::deleteLater();
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::deleteLater();
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::deleteLater();
	} else {
		static_cast<QObject*>(ptr)->QObject::deleteLater();
	}
}

void QObject_ConnectDestroyed(void* ptr, long long t)
{
	QObject::connect(static_cast<QObject*>(ptr), static_cast<void (QObject::*)(QObject *)>(&QObject::destroyed), static_cast<MyQObject*>(ptr), static_cast<void (MyQObject::*)(QObject *)>(&MyQObject::Signal_Destroyed), static_cast<Qt::ConnectionType>(t));
}

void QObject_DisconnectDestroyed(void* ptr)
{
	QObject::disconnect(static_cast<QObject*>(ptr), static_cast<void (QObject::*)(QObject *)>(&QObject::destroyed), static_cast<MyQObject*>(ptr), static_cast<void (MyQObject::*)(QObject *)>(&MyQObject::Signal_Destroyed));
}

void QObject_Destroyed(void* ptr, void* obj)
{
	static_cast<QObject*>(ptr)->destroyed(static_cast<QObject*>(obj));
}

void QObject_DisconnectNotify(void* ptr, void* sign)
{
	static_cast<QObject*>(ptr)->disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QObject_DisconnectNotifyDefault(void* ptr, void* sign)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	} else {
		static_cast<QObject*>(ptr)->QObject::disconnectNotify(*static_cast<QMetaMethod*>(sign));
	}
}

void QObject_InstallEventFilter(void* ptr, void* filterObj)
{
	static_cast<QObject*>(ptr)->installEventFilter(static_cast<QObject*>(filterObj));
}

void QObject_KillTimer(void* ptr, int id)
{
	static_cast<QObject*>(ptr)->killTimer(id);
}

void QObject_MoveToThread(void* ptr, void* targetThread)
{
	static_cast<QObject*>(ptr)->moveToThread(static_cast<QThread*>(targetThread));
}

void QObject_ConnectObjectNameChanged(void* ptr, long long t)
{
	QObject::connect(static_cast<QObject*>(ptr), &QObject::objectNameChanged, static_cast<MyQObject*>(ptr), static_cast<void (MyQObject::*)(const QString &)>(&MyQObject::Signal_ObjectNameChanged), static_cast<Qt::ConnectionType>(t));
}

void QObject_DisconnectObjectNameChanged(void* ptr)
{
	QObject::disconnect(static_cast<QObject*>(ptr), &QObject::objectNameChanged, static_cast<MyQObject*>(ptr), static_cast<void (MyQObject::*)(const QString &)>(&MyQObject::Signal_ObjectNameChanged));
}

void QObject_RemoveEventFilter(void* ptr, void* obj)
{
	static_cast<QObject*>(ptr)->removeEventFilter(static_cast<QObject*>(obj));
}

void QObject_SetObjectName(void* ptr, struct QtCore_PackedString name)
{
	static_cast<QObject*>(ptr)->setObjectName(QString::fromUtf8(name.data, name.len));
}

void QObject_SetParent(void* ptr, void* parent)
{
	static_cast<QObject*>(ptr)->setParent(static_cast<QObject*>(parent));
}

void QObject_TimerEvent(void* ptr, void* event)
{
	static_cast<QObject*>(ptr)->timerEvent(static_cast<QTimerEvent*>(event));
}

void QObject_TimerEventDefault(void* ptr, void* event)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		static_cast<QTranslator*>(ptr)->QTranslator::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		static_cast<QThread*>(ptr)->QThread::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		static_cast<QMimeData*>(ptr)->QMimeData::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		static_cast<QIODevice*>(ptr)->QIODevice::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		static_cast<QCoreApplication*>(ptr)->QCoreApplication::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::timerEvent(static_cast<QTimerEvent*>(event));
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::timerEvent(static_cast<QTimerEvent*>(event));
	} else {
		static_cast<QObject*>(ptr)->QObject::timerEvent(static_cast<QTimerEvent*>(event));
	}
}

void QObject_DestroyQObject(void* ptr)
{
	static_cast<QObject*>(ptr)->~QObject();
}

void QObject_DestroyQObjectDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

struct QtCore_PackedList QObject_DynamicPropertyNames(void* ptr)
{
	return ({ QList<QByteArray>* tmpValue9188e5 = new QList<QByteArray>(static_cast<QObject*>(ptr)->dynamicPropertyNames()); QtCore_PackedList { tmpValue9188e5, tmpValue9188e5->size() }; });
}

struct QtCore_PackedList QObject_FindChildren2(void* ptr, void* regExp, long long options)
{
	return ({ QList<QObject*>* tmpValuef533dc = new QList<QObject*>(static_cast<QObject*>(ptr)->findChildren<QObject*>(*static_cast<QRegExp*>(regExp), static_cast<Qt::FindChildOption>(options))); QtCore_PackedList { tmpValuef533dc, tmpValuef533dc->size() }; });
}

struct QtCore_PackedList QObject_FindChildren3(void* ptr, void* re, long long options)
{
	return ({ QList<QObject*>* tmpValuec8bf88 = new QList<QObject*>(static_cast<QObject*>(ptr)->findChildren<QObject*>(*static_cast<QRegularExpression*>(re), static_cast<Qt::FindChildOption>(options))); QtCore_PackedList { tmpValuec8bf88, tmpValuec8bf88->size() }; });
}

struct QtCore_PackedList QObject_FindChildren(void* ptr, struct QtCore_PackedString name, long long options)
{
	return ({ QList<QObject*>* tmpValue03dce3 = new QList<QObject*>(static_cast<QObject*>(ptr)->findChildren<QObject*>(QString::fromUtf8(name.data, name.len), static_cast<Qt::FindChildOption>(options))); QtCore_PackedList { tmpValue03dce3, tmpValue03dce3->size() }; });
}

void* QObject_Parent(void* ptr)
{
	return static_cast<QObject*>(ptr)->parent();
}

void* QObject_Sender(void* ptr)
{
	return static_cast<QObject*>(ptr)->sender();
}

struct QtCore_PackedString QObject_ObjectName(void* ptr)
{
	return ({ QByteArray te77be1 = static_cast<QObject*>(ptr)->objectName().toUtf8(); QtCore_PackedString { const_cast<char*>(te77be1.prepend("WHITESPACE").constData()+10), te77be1.size()-10 }; });
}

void* QObject_Thread(void* ptr)
{
	return static_cast<QObject*>(ptr)->thread();
}

void* QObject_Property(void* ptr, char* name)
{
	return new QVariant(static_cast<QObject*>(ptr)->property(const_cast<const char*>(name)));
}

void* QObject_FindChild(void* ptr, struct QtCore_PackedString name, long long options)
{
	return static_cast<QObject*>(ptr)->findChild<QObject*>(QString::fromUtf8(name.data, name.len), static_cast<Qt::FindChildOption>(options));
}

char QObject_Disconnect4(void* ptr, void* receiver, char* method)
{
	return static_cast<QObject*>(ptr)->disconnect(static_cast<QObject*>(receiver), const_cast<const char*>(method));
}

char QObject_Disconnect3(void* ptr, char* sign, void* receiver, char* method)
{
	return static_cast<QObject*>(ptr)->disconnect(const_cast<const char*>(sign), static_cast<QObject*>(receiver), const_cast<const char*>(method));
}

char QObject_Inherits(void* ptr, char* className)
{
	return static_cast<QObject*>(ptr)->inherits(const_cast<const char*>(className));
}

char QObject_IsSignalConnected(void* ptr, void* sign)
{
	return static_cast<QObject*>(ptr)->isSignalConnected(*static_cast<QMetaMethod*>(sign));
}

char QObject_IsWidgetType(void* ptr)
{
	return static_cast<QObject*>(ptr)->isWidgetType();
}

char QObject_IsWindowType(void* ptr)
{
	return static_cast<QObject*>(ptr)->isWindowType();
}

char QObject_SignalsBlocked(void* ptr)
{
	return static_cast<QObject*>(ptr)->signalsBlocked();
}

void* QObject_MetaObject(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QObject*>(ptr)->metaObject());
}

void* QObject_MetaObjectDefault(void* ptr)
{
	if (dynamic_cast<QTranslator*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QTranslator*>(ptr)->QTranslator::metaObject());
	} else if (dynamic_cast<QThread*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QThread*>(ptr)->QThread::metaObject());
	} else if (dynamic_cast<QSocketNotifier*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::metaObject());
	} else if (dynamic_cast<QMimeData*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QMimeData*>(ptr)->QMimeData::metaObject());
	} else if (dynamic_cast<QIODevice*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QIODevice*>(ptr)->QIODevice::metaObject());
	} else if (dynamic_cast<QCoreApplication*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QCoreApplication*>(ptr)->QCoreApplication::metaObject());
	} else if (dynamic_cast<QAbstractItemModel*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QAbstractItemModel*>(ptr)->QAbstractItemModel::metaObject());
	} else if (dynamic_cast<QAbstractEventDispatcher*>(static_cast<QObject*>(ptr))) {
		return const_cast<QMetaObject*>(static_cast<QAbstractEventDispatcher*>(ptr)->QAbstractEventDispatcher::metaObject());
	} else {
		return const_cast<QMetaObject*>(static_cast<QObject*>(ptr)->QObject::metaObject());
	}
}

struct QtCore_PackedList QObject_Children(void* ptr)
{
	return ({ QList<QObject *>* tmpValue53f390 = new QList<QObject *>(static_cast<QObject*>(ptr)->children()); QtCore_PackedList { tmpValue53f390, tmpValue53f390->size() }; });
}

int QObject_Receivers(void* ptr, char* sign)
{
	return static_cast<QObject*>(ptr)->receivers(const_cast<const char*>(sign));
}

int QObject_SenderSignalIndex(void* ptr)
{
	return static_cast<QObject*>(ptr)->senderSignalIndex();
}

void QObject_DumpObjectInfo(void* ptr)
{
	static_cast<QObject*>(ptr)->dumpObjectInfo();
}

void QObject_DumpObjectTree(void* ptr)
{
	static_cast<QObject*>(ptr)->dumpObjectTree();
}

void* QObject_InvokeMethod(void* ptr, char* name, void* arg)
{
	QVariant returnArg;
	if (arg)
		QMetaObject::invokeMethod(static_cast<QObject*>(ptr), const_cast<const char*>(name), Q_RETURN_ARG(QVariant, returnArg), Q_ARG(QVariant, *static_cast<QVariant*>(arg)));
	else
		QMetaObject::invokeMethod(static_cast<QObject*>(ptr), const_cast<const char*>(name), Q_RETURN_ARG(QVariant, returnArg));
	return new QVariant(returnArg);
}

void* QObject_ToVariant(void* ptr)
{
	return new QVariant(QVariant::fromValue(static_cast<QObject*>(ptr)));
}

void* QObject___dynamicPropertyNames_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QObject___dynamicPropertyNames_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QObject___dynamicPropertyNames_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QObject___findChildren_atList2(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QObject___findChildren_setList2(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QObject___findChildren_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QObject___findChildren_atList3(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QObject___findChildren_setList3(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QObject___findChildren_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QObject___findChildren_atList(void* ptr, int i)
{
	return ({QObject* tmp = static_cast<QList<QObject*>*>(ptr)->at(i); if (i == static_cast<QList<QObject*>*>(ptr)->size()-1) { static_cast<QList<QObject*>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QObject___findChildren_setList(void* ptr, void* i)
{
	static_cast<QList<QObject*>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QObject___findChildren_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject*>();
}

void* QObject___children_atList(void* ptr, int i)
{
	return ({QObject * tmp = static_cast<QList<QObject *>*>(ptr)->at(i); if (i == static_cast<QList<QObject *>*>(ptr)->size()-1) { static_cast<QList<QObject *>*>(ptr)->~QList(); free(ptr); }; tmp; });
}

void QObject___children_setList(void* ptr, void* i)
{
	static_cast<QList<QObject *>*>(ptr)->append(static_cast<QObject*>(i));
}

void* QObject___children_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QObject *>();
}

Q_DECLARE_METATYPE(QPersistentModelIndex*)
void* QPersistentModelIndex_NewQPersistentModelIndex4(void* other)
{
	return new QPersistentModelIndex(*static_cast<QPersistentModelIndex*>(other));
}

void* QPersistentModelIndex_NewQPersistentModelIndex(void* index)
{
	return new QPersistentModelIndex(*static_cast<QModelIndex*>(index));
}

void* QPersistentModelIndex_NewQPersistentModelIndex3(void* other)
{
	return new QPersistentModelIndex(*static_cast<QPersistentModelIndex*>(other));
}

void QPersistentModelIndex_Swap(void* ptr, void* other)
{
	static_cast<QPersistentModelIndex*>(ptr)->swap(*static_cast<QPersistentModelIndex*>(other));
}

void* QPersistentModelIndex_Parent(void* ptr)
{
	return new QModelIndex(static_cast<QPersistentModelIndex*>(ptr)->parent());
}

void* QPersistentModelIndex_Sibling(void* ptr, int row, int column)
{
	return new QModelIndex(static_cast<QPersistentModelIndex*>(ptr)->sibling(row, column));
}

void* QPersistentModelIndex_Data(void* ptr, int role)
{
	return new QVariant(static_cast<QPersistentModelIndex*>(ptr)->data(role));
}

long long QPersistentModelIndex_Flags(void* ptr)
{
	return static_cast<QPersistentModelIndex*>(ptr)->flags();
}

char QPersistentModelIndex_IsValid(void* ptr)
{
	return static_cast<QPersistentModelIndex*>(ptr)->isValid();
}

void* QPersistentModelIndex_Model(void* ptr)
{
	return const_cast<QAbstractItemModel*>(static_cast<QPersistentModelIndex*>(ptr)->model());
}

int QPersistentModelIndex_Column(void* ptr)
{
	return static_cast<QPersistentModelIndex*>(ptr)->column();
}

int QPersistentModelIndex_Row(void* ptr)
{
	return static_cast<QPersistentModelIndex*>(ptr)->row();
}

Q_DECLARE_METATYPE(QPoint)
Q_DECLARE_METATYPE(QPoint*)
void* QPoint_NewQPoint()
{
	return new QPoint();
}

void* QPoint_NewQPoint2(int xpos, int ypos)
{
	return new QPoint(xpos, ypos);
}

int QPoint_Rx(void* ptr)
{
	return static_cast<QPoint*>(ptr)->rx();
}

int QPoint_Ry(void* ptr)
{
	return static_cast<QPoint*>(ptr)->ry();
}

int QPoint_QPoint_DotProduct(void* p1, void* p2)
{
	return QPoint::dotProduct(*static_cast<QPoint*>(p1), *static_cast<QPoint*>(p2));
}

void QPoint_SetX(void* ptr, int x)
{
	static_cast<QPoint*>(ptr)->setX(x);
}

void QPoint_SetY(void* ptr, int y)
{
	static_cast<QPoint*>(ptr)->setY(y);
}

char QPoint_IsNull(void* ptr)
{
	return static_cast<QPoint*>(ptr)->isNull();
}

int QPoint_ManhattanLength(void* ptr)
{
	return static_cast<QPoint*>(ptr)->manhattanLength();
}

int QPoint_X(void* ptr)
{
	return static_cast<QPoint*>(ptr)->x();
}

int QPoint_Y(void* ptr)
{
	return static_cast<QPoint*>(ptr)->y();
}

Q_DECLARE_METATYPE(QPointF)
Q_DECLARE_METATYPE(QPointF*)
void* QPointF_NewQPointF()
{
	return new QPointF();
}

void* QPointF_NewQPointF2(void* point)
{
	return new QPointF(*static_cast<QPoint*>(point));
}

void* QPointF_NewQPointF3(double xpos, double ypos)
{
	return new QPointF(xpos, ypos);
}

double QPointF_Rx(void* ptr)
{
	return static_cast<QPointF*>(ptr)->rx();
}

double QPointF_Ry(void* ptr)
{
	return static_cast<QPointF*>(ptr)->ry();
}

double QPointF_QPointF_DotProduct(void* p1, void* p2)
{
	return QPointF::dotProduct(*static_cast<QPointF*>(p1), *static_cast<QPointF*>(p2));
}

void QPointF_SetX(void* ptr, double x)
{
	static_cast<QPointF*>(ptr)->setX(x);
}

void QPointF_SetY(void* ptr, double y)
{
	static_cast<QPointF*>(ptr)->setY(y);
}

void* QPointF_ToPoint(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QPointF*>(ptr)->toPoint(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

char QPointF_IsNull(void* ptr)
{
	return static_cast<QPointF*>(ptr)->isNull();
}

double QPointF_ManhattanLength(void* ptr)
{
	return static_cast<QPointF*>(ptr)->manhattanLength();
}

double QPointF_X(void* ptr)
{
	return static_cast<QPointF*>(ptr)->x();
}

double QPointF_Y(void* ptr)
{
	return static_cast<QPointF*>(ptr)->y();
}

Q_DECLARE_METATYPE(QRect)
Q_DECLARE_METATYPE(QRect*)
void* QRect_NewQRect()
{
	return new QRect();
}

void* QRect_NewQRect2(void* topLeft, void* bottomRight)
{
	return new QRect(*static_cast<QPoint*>(topLeft), *static_cast<QPoint*>(bottomRight));
}

void* QRect_NewQRect3(void* topLeft, void* size)
{
	return new QRect(*static_cast<QPoint*>(topLeft), *static_cast<QSize*>(size));
}

void* QRect_NewQRect4(int x, int y, int width, int height)
{
	return new QRect(x, y, width, height);
}

void QRect_Adjust(void* ptr, int dx1, int dy1, int dx2, int dy2)
{
	static_cast<QRect*>(ptr)->adjust(dx1, dy1, dx2, dy2);
}

void QRect_MoveBottom(void* ptr, int y)
{
	static_cast<QRect*>(ptr)->moveBottom(y);
}

void QRect_MoveBottomLeft(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveBottomLeft(*static_cast<QPoint*>(position));
}

void QRect_MoveBottomRight(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveBottomRight(*static_cast<QPoint*>(position));
}

void QRect_MoveCenter(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveCenter(*static_cast<QPoint*>(position));
}

void QRect_MoveLeft(void* ptr, int x)
{
	static_cast<QRect*>(ptr)->moveLeft(x);
}

void QRect_MoveRight(void* ptr, int x)
{
	static_cast<QRect*>(ptr)->moveRight(x);
}

void QRect_MoveTo2(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveTo(*static_cast<QPoint*>(position));
}

void QRect_MoveTo(void* ptr, int x, int y)
{
	static_cast<QRect*>(ptr)->moveTo(x, y);
}

void QRect_MoveTop(void* ptr, int y)
{
	static_cast<QRect*>(ptr)->moveTop(y);
}

void QRect_MoveTopLeft(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveTopLeft(*static_cast<QPoint*>(position));
}

void QRect_MoveTopRight(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->moveTopRight(*static_cast<QPoint*>(position));
}

void QRect_SetBottom(void* ptr, int y)
{
	static_cast<QRect*>(ptr)->setBottom(y);
}

void QRect_SetBottomLeft(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->setBottomLeft(*static_cast<QPoint*>(position));
}

void QRect_SetBottomRight(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->setBottomRight(*static_cast<QPoint*>(position));
}

void QRect_SetCoords(void* ptr, int x1, int y1, int x2, int y2)
{
	static_cast<QRect*>(ptr)->setCoords(x1, y1, x2, y2);
}

void QRect_SetHeight(void* ptr, int height)
{
	static_cast<QRect*>(ptr)->setHeight(height);
}

void QRect_SetLeft(void* ptr, int x)
{
	static_cast<QRect*>(ptr)->setLeft(x);
}

void QRect_SetRect(void* ptr, int x, int y, int width, int height)
{
	static_cast<QRect*>(ptr)->setRect(x, y, width, height);
}

void QRect_SetRight(void* ptr, int x)
{
	static_cast<QRect*>(ptr)->setRight(x);
}

void QRect_SetSize(void* ptr, void* size)
{
	static_cast<QRect*>(ptr)->setSize(*static_cast<QSize*>(size));
}

void QRect_SetTop(void* ptr, int y)
{
	static_cast<QRect*>(ptr)->setTop(y);
}

void QRect_SetTopLeft(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->setTopLeft(*static_cast<QPoint*>(position));
}

void QRect_SetTopRight(void* ptr, void* position)
{
	static_cast<QRect*>(ptr)->setTopRight(*static_cast<QPoint*>(position));
}

void QRect_SetWidth(void* ptr, int width)
{
	static_cast<QRect*>(ptr)->setWidth(width);
}

void QRect_SetX(void* ptr, int x)
{
	static_cast<QRect*>(ptr)->setX(x);
}

void QRect_SetY(void* ptr, int y)
{
	static_cast<QRect*>(ptr)->setY(y);
}

void QRect_Translate2(void* ptr, void* offset)
{
	static_cast<QRect*>(ptr)->translate(*static_cast<QPoint*>(offset));
}

void QRect_Translate(void* ptr, int dx, int dy)
{
	static_cast<QRect*>(ptr)->translate(dx, dy);
}

void* QRect_BottomLeft(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QRect*>(ptr)->bottomLeft(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QRect_BottomRight(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QRect*>(ptr)->bottomRight(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QRect_Center(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QRect*>(ptr)->center(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QRect_TopLeft(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QRect*>(ptr)->topLeft(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QRect_TopRight(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QRect*>(ptr)->topRight(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QRect_Adjusted(void* ptr, int dx1, int dy1, int dx2, int dy2)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->adjusted(dx1, dy1, dx2, dy2); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Intersected(void* ptr, void* rectangle)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->intersected(*static_cast<QRect*>(rectangle)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_MarginsAdded(void* ptr, void* margins)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->marginsAdded(*static_cast<QMargins*>(margins)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_MarginsRemoved(void* ptr, void* margins)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->marginsRemoved(*static_cast<QMargins*>(margins)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Normalized(void* ptr)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->normalized(); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Translated2(void* ptr, void* offset)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->translated(*static_cast<QPoint*>(offset)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Translated(void* ptr, int dx, int dy)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->translated(dx, dy); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Transposed(void* ptr)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->transposed(); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_United(void* ptr, void* rectangle)
{
	return ({ QRect tmpValue = static_cast<QRect*>(ptr)->united(*static_cast<QRect*>(rectangle)); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRect_Size(void* ptr)
{
	return ({ QSize tmpValue = static_cast<QRect*>(ptr)->size(); new QSize(tmpValue.width(), tmpValue.height()); });
}

char QRect_Contains(void* ptr, void* point, char proper)
{
	return static_cast<QRect*>(ptr)->contains(*static_cast<QPoint*>(point), proper != 0);
}

char QRect_Contains2(void* ptr, void* rectangle, char proper)
{
	return static_cast<QRect*>(ptr)->contains(*static_cast<QRect*>(rectangle), proper != 0);
}

char QRect_Contains3(void* ptr, int x, int y)
{
	return static_cast<QRect*>(ptr)->contains(x, y);
}

char QRect_Contains4(void* ptr, int x, int y, char proper)
{
	return static_cast<QRect*>(ptr)->contains(x, y, proper != 0);
}

char QRect_Intersects(void* ptr, void* rectangle)
{
	return static_cast<QRect*>(ptr)->intersects(*static_cast<QRect*>(rectangle));
}

char QRect_IsEmpty(void* ptr)
{
	return static_cast<QRect*>(ptr)->isEmpty();
}

char QRect_IsNull(void* ptr)
{
	return static_cast<QRect*>(ptr)->isNull();
}

char QRect_IsValid(void* ptr)
{
	return static_cast<QRect*>(ptr)->isValid();
}

int QRect_Bottom(void* ptr)
{
	return static_cast<QRect*>(ptr)->bottom();
}

int QRect_Height(void* ptr)
{
	return static_cast<QRect*>(ptr)->height();
}

int QRect_Left(void* ptr)
{
	return static_cast<QRect*>(ptr)->left();
}

int QRect_Right(void* ptr)
{
	return static_cast<QRect*>(ptr)->right();
}

int QRect_Top(void* ptr)
{
	return static_cast<QRect*>(ptr)->top();
}

int QRect_Width(void* ptr)
{
	return static_cast<QRect*>(ptr)->width();
}

int QRect_X(void* ptr)
{
	return static_cast<QRect*>(ptr)->x();
}

int QRect_Y(void* ptr)
{
	return static_cast<QRect*>(ptr)->y();
}

void QRect_GetCoords(void* ptr, int x1, int y1, int x2, int y2)
{
	static_cast<QRect*>(ptr)->getCoords(&x1, &y1, &x2, &y2);
}

void QRect_GetRect(void* ptr, int x, int y, int width, int height)
{
	static_cast<QRect*>(ptr)->getRect(&x, &y, &width, &height);
}

Q_DECLARE_METATYPE(QRectF)
Q_DECLARE_METATYPE(QRectF*)
void* QRectF_NewQRectF()
{
	return new QRectF();
}

void* QRectF_NewQRectF3(void* topLeft, void* bottomRight)
{
	return new QRectF(*static_cast<QPointF*>(topLeft), *static_cast<QPointF*>(bottomRight));
}

void* QRectF_NewQRectF2(void* topLeft, void* size)
{
	return new QRectF(*static_cast<QPointF*>(topLeft), *static_cast<QSizeF*>(size));
}

void* QRectF_NewQRectF5(void* rectangle)
{
	return new QRectF(*static_cast<QRect*>(rectangle));
}

void* QRectF_NewQRectF4(double x, double y, double width, double height)
{
	return new QRectF(x, y, width, height);
}

void QRectF_Adjust(void* ptr, double dx1, double dy1, double dx2, double dy2)
{
	static_cast<QRectF*>(ptr)->adjust(dx1, dy1, dx2, dy2);
}

void QRectF_MoveBottom(void* ptr, double y)
{
	static_cast<QRectF*>(ptr)->moveBottom(y);
}

void QRectF_MoveBottomLeft(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveBottomLeft(*static_cast<QPointF*>(position));
}

void QRectF_MoveBottomRight(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveBottomRight(*static_cast<QPointF*>(position));
}

void QRectF_MoveCenter(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveCenter(*static_cast<QPointF*>(position));
}

void QRectF_MoveLeft(void* ptr, double x)
{
	static_cast<QRectF*>(ptr)->moveLeft(x);
}

void QRectF_MoveRight(void* ptr, double x)
{
	static_cast<QRectF*>(ptr)->moveRight(x);
}

void QRectF_MoveTo2(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveTo(*static_cast<QPointF*>(position));
}

void QRectF_MoveTo(void* ptr, double x, double y)
{
	static_cast<QRectF*>(ptr)->moveTo(x, y);
}

void QRectF_MoveTop(void* ptr, double y)
{
	static_cast<QRectF*>(ptr)->moveTop(y);
}

void QRectF_MoveTopLeft(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveTopLeft(*static_cast<QPointF*>(position));
}

void QRectF_MoveTopRight(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->moveTopRight(*static_cast<QPointF*>(position));
}

void QRectF_SetBottom(void* ptr, double y)
{
	static_cast<QRectF*>(ptr)->setBottom(y);
}

void QRectF_SetBottomLeft(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->setBottomLeft(*static_cast<QPointF*>(position));
}

void QRectF_SetBottomRight(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->setBottomRight(*static_cast<QPointF*>(position));
}

void QRectF_SetCoords(void* ptr, double x1, double y1, double x2, double y2)
{
	static_cast<QRectF*>(ptr)->setCoords(x1, y1, x2, y2);
}

void QRectF_SetHeight(void* ptr, double height)
{
	static_cast<QRectF*>(ptr)->setHeight(height);
}

void QRectF_SetLeft(void* ptr, double x)
{
	static_cast<QRectF*>(ptr)->setLeft(x);
}

void QRectF_SetRect(void* ptr, double x, double y, double width, double height)
{
	static_cast<QRectF*>(ptr)->setRect(x, y, width, height);
}

void QRectF_SetRight(void* ptr, double x)
{
	static_cast<QRectF*>(ptr)->setRight(x);
}

void QRectF_SetSize(void* ptr, void* size)
{
	static_cast<QRectF*>(ptr)->setSize(*static_cast<QSizeF*>(size));
}

void QRectF_SetTop(void* ptr, double y)
{
	static_cast<QRectF*>(ptr)->setTop(y);
}

void QRectF_SetTopLeft(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->setTopLeft(*static_cast<QPointF*>(position));
}

void QRectF_SetTopRight(void* ptr, void* position)
{
	static_cast<QRectF*>(ptr)->setTopRight(*static_cast<QPointF*>(position));
}

void QRectF_SetWidth(void* ptr, double width)
{
	static_cast<QRectF*>(ptr)->setWidth(width);
}

void QRectF_SetX(void* ptr, double x)
{
	static_cast<QRectF*>(ptr)->setX(x);
}

void QRectF_SetY(void* ptr, double y)
{
	static_cast<QRectF*>(ptr)->setY(y);
}

void QRectF_Translate2(void* ptr, void* offset)
{
	static_cast<QRectF*>(ptr)->translate(*static_cast<QPointF*>(offset));
}

void QRectF_Translate(void* ptr, double dx, double dy)
{
	static_cast<QRectF*>(ptr)->translate(dx, dy);
}

void* QRectF_BottomLeft(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QRectF*>(ptr)->bottomLeft(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QRectF_BottomRight(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QRectF*>(ptr)->bottomRight(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QRectF_Center(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QRectF*>(ptr)->center(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QRectF_TopLeft(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QRectF*>(ptr)->topLeft(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QRectF_TopRight(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QRectF*>(ptr)->topRight(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QRectF_ToAlignedRect(void* ptr)
{
	return ({ QRect tmpValue = static_cast<QRectF*>(ptr)->toAlignedRect(); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_ToRect(void* ptr)
{
	return ({ QRect tmpValue = static_cast<QRectF*>(ptr)->toRect(); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Adjusted(void* ptr, double dx1, double dy1, double dx2, double dy2)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->adjusted(dx1, dy1, dx2, dy2); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Intersected(void* ptr, void* rectangle)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->intersected(*static_cast<QRectF*>(rectangle)); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_MarginsAdded(void* ptr, void* margins)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->marginsAdded(*static_cast<QMarginsF*>(margins)); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_MarginsRemoved(void* ptr, void* margins)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->marginsRemoved(*static_cast<QMarginsF*>(margins)); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Normalized(void* ptr)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->normalized(); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Translated2(void* ptr, void* offset)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->translated(*static_cast<QPointF*>(offset)); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Translated(void* ptr, double dx, double dy)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->translated(dx, dy); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Transposed(void* ptr)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->transposed(); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_United(void* ptr, void* rectangle)
{
	return ({ QRectF tmpValue = static_cast<QRectF*>(ptr)->united(*static_cast<QRectF*>(rectangle)); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QRectF_Size(void* ptr)
{
	return ({ QSizeF tmpValue = static_cast<QRectF*>(ptr)->size(); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

char QRectF_Contains(void* ptr, void* point)
{
	return static_cast<QRectF*>(ptr)->contains(*static_cast<QPointF*>(point));
}

char QRectF_Contains2(void* ptr, void* rectangle)
{
	return static_cast<QRectF*>(ptr)->contains(*static_cast<QRectF*>(rectangle));
}

char QRectF_Contains3(void* ptr, double x, double y)
{
	return static_cast<QRectF*>(ptr)->contains(x, y);
}

char QRectF_Intersects(void* ptr, void* rectangle)
{
	return static_cast<QRectF*>(ptr)->intersects(*static_cast<QRectF*>(rectangle));
}

char QRectF_IsEmpty(void* ptr)
{
	return static_cast<QRectF*>(ptr)->isEmpty();
}

char QRectF_IsNull(void* ptr)
{
	return static_cast<QRectF*>(ptr)->isNull();
}

char QRectF_IsValid(void* ptr)
{
	return static_cast<QRectF*>(ptr)->isValid();
}

double QRectF_Bottom(void* ptr)
{
	return static_cast<QRectF*>(ptr)->bottom();
}

double QRectF_Height(void* ptr)
{
	return static_cast<QRectF*>(ptr)->height();
}

double QRectF_Left(void* ptr)
{
	return static_cast<QRectF*>(ptr)->left();
}

double QRectF_Right(void* ptr)
{
	return static_cast<QRectF*>(ptr)->right();
}

double QRectF_Top(void* ptr)
{
	return static_cast<QRectF*>(ptr)->top();
}

double QRectF_Width(void* ptr)
{
	return static_cast<QRectF*>(ptr)->width();
}

double QRectF_X(void* ptr)
{
	return static_cast<QRectF*>(ptr)->x();
}

double QRectF_Y(void* ptr)
{
	return static_cast<QRectF*>(ptr)->y();
}

void QRectF_GetCoords(void* ptr, double x1, double y1, double x2, double y2)
{
	static_cast<QRectF*>(ptr)->getCoords(&x1, &y1, &x2, &y2);
}

void QRectF_GetRect(void* ptr, double x, double y, double width, double height)
{
	static_cast<QRectF*>(ptr)->getRect(&x, &y, &width, &height);
}

Q_DECLARE_METATYPE(QRegExp)
Q_DECLARE_METATYPE(QRegExp*)
void* QRegExp_NewQRegExp()
{
	return new QRegExp();
}

void* QRegExp_NewQRegExp3(void* rx)
{
	return new QRegExp(*static_cast<QRegExp*>(rx));
}

void* QRegExp_NewQRegExp2(struct QtCore_PackedString pattern, long long cs, long long syntax)
{
	return new QRegExp(QString::fromUtf8(pattern.data, pattern.len), static_cast<Qt::CaseSensitivity>(cs), static_cast<QRegExp::PatternSyntax>(syntax));
}

struct QtCore_PackedString QRegExp_QRegExp_Escape(struct QtCore_PackedString str)
{
	return ({ QByteArray tf416e0 = QRegExp::escape(QString::fromUtf8(str.data, str.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(tf416e0.prepend("WHITESPACE").constData()+10), tf416e0.size()-10 }; });
}

void QRegExp_SetCaseSensitivity(void* ptr, long long cs)
{
	static_cast<QRegExp*>(ptr)->setCaseSensitivity(static_cast<Qt::CaseSensitivity>(cs));
}

void QRegExp_SetMinimal(void* ptr, char minimal)
{
	static_cast<QRegExp*>(ptr)->setMinimal(minimal != 0);
}

void QRegExp_SetPattern(void* ptr, struct QtCore_PackedString pattern)
{
	static_cast<QRegExp*>(ptr)->setPattern(QString::fromUtf8(pattern.data, pattern.len));
}

void QRegExp_SetPatternSyntax(void* ptr, long long syntax)
{
	static_cast<QRegExp*>(ptr)->setPatternSyntax(static_cast<QRegExp::PatternSyntax>(syntax));
}

void QRegExp_Swap(void* ptr, void* other)
{
	static_cast<QRegExp*>(ptr)->swap(*static_cast<QRegExp*>(other));
}

void QRegExp_DestroyQRegExp(void* ptr)
{
	static_cast<QRegExp*>(ptr)->~QRegExp();
}

long long QRegExp_PatternSyntax(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->patternSyntax();
}

struct QtCore_PackedString QRegExp_Cap(void* ptr, int nth)
{
	return ({ QByteArray t6327b9 = static_cast<QRegExp*>(ptr)->cap(nth).toUtf8(); QtCore_PackedString { const_cast<char*>(t6327b9.prepend("WHITESPACE").constData()+10), t6327b9.size()-10 }; });
}

struct QtCore_PackedString QRegExp_ErrorString(void* ptr)
{
	return ({ QByteArray t53d00c = static_cast<QRegExp*>(ptr)->errorString().toUtf8(); QtCore_PackedString { const_cast<char*>(t53d00c.prepend("WHITESPACE").constData()+10), t53d00c.size()-10 }; });
}

struct QtCore_PackedString QRegExp_Pattern(void* ptr)
{
	return ({ QByteArray t70b801 = static_cast<QRegExp*>(ptr)->pattern().toUtf8(); QtCore_PackedString { const_cast<char*>(t70b801.prepend("WHITESPACE").constData()+10), t70b801.size()-10 }; });
}

struct QtCore_PackedString QRegExp_CapturedTexts(void* ptr)
{
	return ({ QByteArray t69e4cf = static_cast<QRegExp*>(ptr)->capturedTexts().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t69e4cf.prepend("WHITESPACE").constData()+10), t69e4cf.size()-10 }; });
}

long long QRegExp_CaseSensitivity(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->caseSensitivity();
}

char QRegExp_ExactMatch(void* ptr, struct QtCore_PackedString str)
{
	return static_cast<QRegExp*>(ptr)->exactMatch(QString::fromUtf8(str.data, str.len));
}

char QRegExp_IsEmpty(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->isEmpty();
}

char QRegExp_IsMinimal(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->isMinimal();
}

char QRegExp_IsValid(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->isValid();
}

int QRegExp_CaptureCount(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->captureCount();
}

int QRegExp_IndexIn(void* ptr, struct QtCore_PackedString str, int offset, long long caretMode)
{
	return static_cast<QRegExp*>(ptr)->indexIn(QString::fromUtf8(str.data, str.len), offset, static_cast<QRegExp::CaretMode>(caretMode));
}

int QRegExp_LastIndexIn(void* ptr, struct QtCore_PackedString str, int offset, long long caretMode)
{
	return static_cast<QRegExp*>(ptr)->lastIndexIn(QString::fromUtf8(str.data, str.len), offset, static_cast<QRegExp::CaretMode>(caretMode));
}

int QRegExp_MatchedLength(void* ptr)
{
	return static_cast<QRegExp*>(ptr)->matchedLength();
}

int QRegExp_Pos(void* ptr, int nth)
{
	return static_cast<QRegExp*>(ptr)->pos(nth);
}

Q_DECLARE_METATYPE(QRegularExpression)
Q_DECLARE_METATYPE(QRegularExpression*)
void* QRegularExpression_NewQRegularExpression()
{
	return new QRegularExpression();
}

void* QRegularExpression_NewQRegularExpression3(void* re)
{
	return new QRegularExpression(*static_cast<QRegularExpression*>(re));
}

void* QRegularExpression_NewQRegularExpression2(struct QtCore_PackedString pattern, long long options)
{
	return new QRegularExpression(QString::fromUtf8(pattern.data, pattern.len), static_cast<QRegularExpression::PatternOption>(options));
}

struct QtCore_PackedString QRegularExpression_QRegularExpression_AnchoredPattern(struct QtCore_PackedString expression)
{
	return ({ QByteArray t32c726 = QRegularExpression::anchoredPattern(QString::fromUtf8(expression.data, expression.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t32c726.prepend("WHITESPACE").constData()+10), t32c726.size()-10 }; });
}

struct QtCore_PackedString QRegularExpression_QRegularExpression_Escape(struct QtCore_PackedString str)
{
	return ({ QByteArray tf551fc = QRegularExpression::escape(QString::fromUtf8(str.data, str.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(tf551fc.prepend("WHITESPACE").constData()+10), tf551fc.size()-10 }; });
}

struct QtCore_PackedString QRegularExpression_QRegularExpression_WildcardToRegularExpression(struct QtCore_PackedString pattern)
{
	return ({ QByteArray ta3cf94 = QRegularExpression::wildcardToRegularExpression(QString::fromUtf8(pattern.data, pattern.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(ta3cf94.prepend("WHITESPACE").constData()+10), ta3cf94.size()-10 }; });
}

void QRegularExpression_SetPattern(void* ptr, struct QtCore_PackedString pattern)
{
	static_cast<QRegularExpression*>(ptr)->setPattern(QString::fromUtf8(pattern.data, pattern.len));
}

void QRegularExpression_SetPatternOptions(void* ptr, long long options)
{
	static_cast<QRegularExpression*>(ptr)->setPatternOptions(static_cast<QRegularExpression::PatternOption>(options));
}

void QRegularExpression_Swap(void* ptr, void* other)
{
	static_cast<QRegularExpression*>(ptr)->swap(*static_cast<QRegularExpression*>(other));
}

void QRegularExpression_DestroyQRegularExpression(void* ptr)
{
	static_cast<QRegularExpression*>(ptr)->~QRegularExpression();
}

long long QRegularExpression_PatternOptions(void* ptr)
{
	return static_cast<QRegularExpression*>(ptr)->patternOptions();
}

void* QRegularExpression_Match(void* ptr, struct QtCore_PackedString subject, int offset, long long matchType, long long matchOptions)
{
	return new QRegularExpressionMatch(static_cast<QRegularExpression*>(ptr)->match(QString::fromUtf8(subject.data, subject.len), offset, static_cast<QRegularExpression::MatchType>(matchType), static_cast<QRegularExpression::MatchOption>(matchOptions)));
}

void* QRegularExpression_Match2(void* ptr, void* subjectRef, int offset, long long matchType, long long matchOptions)
{
	return new QRegularExpressionMatch(static_cast<QRegularExpression*>(ptr)->match(*static_cast<QStringRef*>(subjectRef), offset, static_cast<QRegularExpression::MatchType>(matchType), static_cast<QRegularExpression::MatchOption>(matchOptions)));
}

void* QRegularExpression_GlobalMatch(void* ptr, struct QtCore_PackedString subject, int offset, long long matchType, long long matchOptions)
{
	return new QRegularExpressionMatchIterator(static_cast<QRegularExpression*>(ptr)->globalMatch(QString::fromUtf8(subject.data, subject.len), offset, static_cast<QRegularExpression::MatchType>(matchType), static_cast<QRegularExpression::MatchOption>(matchOptions)));
}

void* QRegularExpression_GlobalMatch2(void* ptr, void* subjectRef, int offset, long long matchType, long long matchOptions)
{
	return new QRegularExpressionMatchIterator(static_cast<QRegularExpression*>(ptr)->globalMatch(*static_cast<QStringRef*>(subjectRef), offset, static_cast<QRegularExpression::MatchType>(matchType), static_cast<QRegularExpression::MatchOption>(matchOptions)));
}

struct QtCore_PackedString QRegularExpression_ErrorString(void* ptr)
{
	return ({ QByteArray t85aa6b = static_cast<QRegularExpression*>(ptr)->errorString().toUtf8(); QtCore_PackedString { const_cast<char*>(t85aa6b.prepend("WHITESPACE").constData()+10), t85aa6b.size()-10 }; });
}

struct QtCore_PackedString QRegularExpression_Pattern(void* ptr)
{
	return ({ QByteArray t585ea0 = static_cast<QRegularExpression*>(ptr)->pattern().toUtf8(); QtCore_PackedString { const_cast<char*>(t585ea0.prepend("WHITESPACE").constData()+10), t585ea0.size()-10 }; });
}

struct QtCore_PackedString QRegularExpression_NamedCaptureGroups(void* ptr)
{
	return ({ QByteArray t5a80a4 = static_cast<QRegularExpression*>(ptr)->namedCaptureGroups().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t5a80a4.prepend("WHITESPACE").constData()+10), t5a80a4.size()-10 }; });
}

char QRegularExpression_IsValid(void* ptr)
{
	return static_cast<QRegularExpression*>(ptr)->isValid();
}

int QRegularExpression_CaptureCount(void* ptr)
{
	return static_cast<QRegularExpression*>(ptr)->captureCount();
}

int QRegularExpression_PatternErrorOffset(void* ptr)
{
	return static_cast<QRegularExpression*>(ptr)->patternErrorOffset();
}

void QRegularExpression_Optimize(void* ptr)
{
	static_cast<QRegularExpression*>(ptr)->optimize();
}

Q_DECLARE_METATYPE(QRegularExpressionMatch)
Q_DECLARE_METATYPE(QRegularExpressionMatch*)
void* QRegularExpressionMatch_NewQRegularExpressionMatch()
{
	return new QRegularExpressionMatch();
}

void* QRegularExpressionMatch_NewQRegularExpressionMatch2(void* match)
{
	return new QRegularExpressionMatch(*static_cast<QRegularExpressionMatch*>(match));
}

void QRegularExpressionMatch_Swap(void* ptr, void* other)
{
	static_cast<QRegularExpressionMatch*>(ptr)->swap(*static_cast<QRegularExpressionMatch*>(other));
}

void QRegularExpressionMatch_DestroyQRegularExpressionMatch(void* ptr)
{
	static_cast<QRegularExpressionMatch*>(ptr)->~QRegularExpressionMatch();
}

void* QRegularExpressionMatch_RegularExpression(void* ptr)
{
	return new QRegularExpression(static_cast<QRegularExpressionMatch*>(ptr)->regularExpression());
}

long long QRegularExpressionMatch_MatchOptions(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->matchOptions();
}

long long QRegularExpressionMatch_MatchType(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->matchType();
}

struct QtCore_PackedString QRegularExpressionMatch_Captured3(void* ptr, void* name)
{
	return ({ QByteArray t0ab4af = static_cast<QRegularExpressionMatch*>(ptr)->captured(*static_cast<QStringView*>(name)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0ab4af.prepend("WHITESPACE").constData()+10), t0ab4af.size()-10 }; });
}

struct QtCore_PackedString QRegularExpressionMatch_Captured2(void* ptr, struct QtCore_PackedString name)
{
	return ({ QByteArray te09a4d = static_cast<QRegularExpressionMatch*>(ptr)->captured(QString::fromUtf8(name.data, name.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(te09a4d.prepend("WHITESPACE").constData()+10), te09a4d.size()-10 }; });
}

struct QtCore_PackedString QRegularExpressionMatch_Captured(void* ptr, int nth)
{
	return ({ QByteArray t5bb134 = static_cast<QRegularExpressionMatch*>(ptr)->captured(nth).toUtf8(); QtCore_PackedString { const_cast<char*>(t5bb134.prepend("WHITESPACE").constData()+10), t5bb134.size()-10 }; });
}

struct QtCore_PackedString QRegularExpressionMatch_CapturedTexts(void* ptr)
{
	return ({ QByteArray t75c0a9 = static_cast<QRegularExpressionMatch*>(ptr)->capturedTexts().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t75c0a9.prepend("WHITESPACE").constData()+10), t75c0a9.size()-10 }; });
}

void* QRegularExpressionMatch_CapturedRef3(void* ptr, void* name)
{
	return new QStringRef(static_cast<QRegularExpressionMatch*>(ptr)->capturedRef(*static_cast<QStringView*>(name)));
}

void* QRegularExpressionMatch_CapturedRef2(void* ptr, struct QtCore_PackedString name)
{
	return new QStringRef(static_cast<QRegularExpressionMatch*>(ptr)->capturedRef(QString::fromUtf8(name.data, name.len)));
}

void* QRegularExpressionMatch_CapturedRef(void* ptr, int nth)
{
	return new QStringRef(static_cast<QRegularExpressionMatch*>(ptr)->capturedRef(nth));
}

void* QRegularExpressionMatch_CapturedView2(void* ptr, void* name)
{
	return new QStringView(static_cast<QRegularExpressionMatch*>(ptr)->capturedView(*static_cast<QStringView*>(name)));
}

void* QRegularExpressionMatch_CapturedView(void* ptr, int nth)
{
	return new QStringView(static_cast<QRegularExpressionMatch*>(ptr)->capturedView(nth));
}

char QRegularExpressionMatch_HasMatch(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->hasMatch();
}

char QRegularExpressionMatch_HasPartialMatch(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->hasPartialMatch();
}

char QRegularExpressionMatch_IsValid(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->isValid();
}

int QRegularExpressionMatch_CapturedEnd3(void* ptr, void* name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedEnd(*static_cast<QStringView*>(name));
}

int QRegularExpressionMatch_CapturedEnd2(void* ptr, struct QtCore_PackedString name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedEnd(QString::fromUtf8(name.data, name.len));
}

int QRegularExpressionMatch_CapturedEnd(void* ptr, int nth)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedEnd(nth);
}

int QRegularExpressionMatch_CapturedLength3(void* ptr, void* name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedLength(*static_cast<QStringView*>(name));
}

int QRegularExpressionMatch_CapturedLength2(void* ptr, struct QtCore_PackedString name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedLength(QString::fromUtf8(name.data, name.len));
}

int QRegularExpressionMatch_CapturedLength(void* ptr, int nth)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedLength(nth);
}

int QRegularExpressionMatch_CapturedStart3(void* ptr, void* name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedStart(*static_cast<QStringView*>(name));
}

int QRegularExpressionMatch_CapturedStart2(void* ptr, struct QtCore_PackedString name)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedStart(QString::fromUtf8(name.data, name.len));
}

int QRegularExpressionMatch_CapturedStart(void* ptr, int nth)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->capturedStart(nth);
}

int QRegularExpressionMatch_LastCapturedIndex(void* ptr)
{
	return static_cast<QRegularExpressionMatch*>(ptr)->lastCapturedIndex();
}

Q_DECLARE_METATYPE(QSize)
Q_DECLARE_METATYPE(QSize*)
void* QSize_NewQSize()
{
	return new QSize();
}

void* QSize_NewQSize2(int width, int height)
{
	return new QSize(width, height);
}

int QSize_Rheight(void* ptr)
{
	return static_cast<QSize*>(ptr)->rheight();
}

int QSize_Rwidth(void* ptr)
{
	return static_cast<QSize*>(ptr)->rwidth();
}

void QSize_Scale2(void* ptr, void* size, long long mode)
{
	static_cast<QSize*>(ptr)->scale(*static_cast<QSize*>(size), static_cast<Qt::AspectRatioMode>(mode));
}

void QSize_Scale(void* ptr, int width, int height, long long mode)
{
	static_cast<QSize*>(ptr)->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
}

void QSize_SetHeight(void* ptr, int height)
{
	static_cast<QSize*>(ptr)->setHeight(height);
}

void QSize_SetWidth(void* ptr, int width)
{
	static_cast<QSize*>(ptr)->setWidth(width);
}

void QSize_Transpose(void* ptr)
{
	static_cast<QSize*>(ptr)->transpose();
}

void* QSize_BoundedTo(void* ptr, void* otherSize)
{
	return ({ QSize tmpValue = static_cast<QSize*>(ptr)->boundedTo(*static_cast<QSize*>(otherSize)); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QSize_ExpandedTo(void* ptr, void* otherSize)
{
	return ({ QSize tmpValue = static_cast<QSize*>(ptr)->expandedTo(*static_cast<QSize*>(otherSize)); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QSize_Scaled2(void* ptr, void* s, long long mode)
{
	return ({ QSize tmpValue = static_cast<QSize*>(ptr)->scaled(*static_cast<QSize*>(s), static_cast<Qt::AspectRatioMode>(mode)); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QSize_Scaled(void* ptr, int width, int height, long long mode)
{
	return ({ QSize tmpValue = static_cast<QSize*>(ptr)->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode)); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QSize_Transposed(void* ptr)
{
	return ({ QSize tmpValue = static_cast<QSize*>(ptr)->transposed(); new QSize(tmpValue.width(), tmpValue.height()); });
}

char QSize_IsEmpty(void* ptr)
{
	return static_cast<QSize*>(ptr)->isEmpty();
}

char QSize_IsNull(void* ptr)
{
	return static_cast<QSize*>(ptr)->isNull();
}

char QSize_IsValid(void* ptr)
{
	return static_cast<QSize*>(ptr)->isValid();
}

int QSize_Height(void* ptr)
{
	return static_cast<QSize*>(ptr)->height();
}

int QSize_Width(void* ptr)
{
	return static_cast<QSize*>(ptr)->width();
}

Q_DECLARE_METATYPE(QSizeF)
Q_DECLARE_METATYPE(QSizeF*)
void* QSizeF_NewQSizeF()
{
	return new QSizeF();
}

void* QSizeF_NewQSizeF2(void* size)
{
	return new QSizeF(*static_cast<QSize*>(size));
}

void* QSizeF_NewQSizeF3(double width, double height)
{
	return new QSizeF(width, height);
}

double QSizeF_Rheight(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->rheight();
}

double QSizeF_Rwidth(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->rwidth();
}

void QSizeF_Scale2(void* ptr, void* size, long long mode)
{
	static_cast<QSizeF*>(ptr)->scale(*static_cast<QSizeF*>(size), static_cast<Qt::AspectRatioMode>(mode));
}

void QSizeF_Scale(void* ptr, double width, double height, long long mode)
{
	static_cast<QSizeF*>(ptr)->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
}

void QSizeF_SetHeight(void* ptr, double height)
{
	static_cast<QSizeF*>(ptr)->setHeight(height);
}

void QSizeF_SetWidth(void* ptr, double width)
{
	static_cast<QSizeF*>(ptr)->setWidth(width);
}

void QSizeF_Transpose(void* ptr)
{
	static_cast<QSizeF*>(ptr)->transpose();
}

void* QSizeF_ToSize(void* ptr)
{
	return ({ QSize tmpValue = static_cast<QSizeF*>(ptr)->toSize(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QSizeF_BoundedTo(void* ptr, void* otherSize)
{
	return ({ QSizeF tmpValue = static_cast<QSizeF*>(ptr)->boundedTo(*static_cast<QSizeF*>(otherSize)); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

void* QSizeF_ExpandedTo(void* ptr, void* otherSize)
{
	return ({ QSizeF tmpValue = static_cast<QSizeF*>(ptr)->expandedTo(*static_cast<QSizeF*>(otherSize)); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

void* QSizeF_Scaled2(void* ptr, void* s, long long mode)
{
	return ({ QSizeF tmpValue = static_cast<QSizeF*>(ptr)->scaled(*static_cast<QSizeF*>(s), static_cast<Qt::AspectRatioMode>(mode)); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

void* QSizeF_Scaled(void* ptr, double width, double height, long long mode)
{
	return ({ QSizeF tmpValue = static_cast<QSizeF*>(ptr)->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode)); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

void* QSizeF_Transposed(void* ptr)
{
	return ({ QSizeF tmpValue = static_cast<QSizeF*>(ptr)->transposed(); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

char QSizeF_IsEmpty(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->isEmpty();
}

char QSizeF_IsNull(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->isNull();
}

char QSizeF_IsValid(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->isValid();
}

double QSizeF_Height(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->height();
}

double QSizeF_Width(void* ptr)
{
	return static_cast<QSizeF*>(ptr)->width();
}

class MyQSocketNotifier: public QSocketNotifier
{
public:
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	void Signal_Activated(int socket) { callbackQSocketNotifier_Activated(this, socket); };
	void setEnabled(bool enable) { callbackQSocketNotifier_SetEnabled(this, enable); };
	 ~MyQSocketNotifier() { callbackQSocketNotifier_DestroyQSocketNotifier(this); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QSocketNotifier*)
Q_DECLARE_METATYPE(MyQSocketNotifier*)

int QSocketNotifier_QSocketNotifier_QRegisterMetaType(){qRegisterMetaType<QSocketNotifier*>(); return qRegisterMetaType<MyQSocketNotifier*>();}

void QSocketNotifier_ConnectActivated(void* ptr, long long t)
{
	QObject::connect(static_cast<QSocketNotifier*>(ptr), &QSocketNotifier::activated, static_cast<MyQSocketNotifier*>(ptr), static_cast<void (MyQSocketNotifier::*)(int)>(&MyQSocketNotifier::Signal_Activated), static_cast<Qt::ConnectionType>(t));
}

void QSocketNotifier_DisconnectActivated(void* ptr)
{
	QObject::disconnect(static_cast<QSocketNotifier*>(ptr), &QSocketNotifier::activated, static_cast<MyQSocketNotifier*>(ptr), static_cast<void (MyQSocketNotifier::*)(int)>(&MyQSocketNotifier::Signal_Activated));
}

void QSocketNotifier_SetEnabled(void* ptr, char enable)
{
	QMetaObject::invokeMethod(static_cast<QSocketNotifier*>(ptr), "setEnabled", Q_ARG(bool, enable != 0));
}

void QSocketNotifier_SetEnabledDefault(void* ptr, char enable)
{
		static_cast<QSocketNotifier*>(ptr)->QSocketNotifier::setEnabled(enable != 0);
}

void QSocketNotifier_DestroyQSocketNotifier(void* ptr)
{
	static_cast<QSocketNotifier*>(ptr)->~QSocketNotifier();
}

void QSocketNotifier_DestroyQSocketNotifierDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

long long QSocketNotifier_Type(void* ptr)
{
	return static_cast<QSocketNotifier*>(ptr)->type();
}

char QSocketNotifier_IsEnabled(void* ptr)
{
	return static_cast<QSocketNotifier*>(ptr)->isEnabled();
}

Q_DECLARE_METATYPE(QStringRef)
Q_DECLARE_METATYPE(QStringRef*)
void* QStringRef_NewQStringRef()
{
	return new QStringRef();
}

void* QStringRef_NewQStringRef5(void* other)
{
	return new QStringRef(*static_cast<QStringRef*>(other));
}

void* QStringRef_NewQStringRef3(struct QtCore_PackedString stri)
{
	return new QStringRef(new QString(QString::fromUtf8(stri.data, stri.len)));
}

void* QStringRef_NewQStringRef2(struct QtCore_PackedString stri, int position, int length)
{
	return new QStringRef(new QString(QString::fromUtf8(stri.data, stri.len)), position, length);
}

void* QStringRef_NewQStringRef4(void* other)
{
	return new QStringRef(*static_cast<QStringRef*>(other));
}

int QStringRef_QStringRef_Compare7(void* s1, void* s2, long long cs)
{
	return QStringRef::compare(*static_cast<QStringRef*>(s1), *static_cast<QLatin1String*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_QStringRef_Compare(void* s1, struct QtCore_PackedString s2, long long cs)
{
	return QStringRef::compare(*static_cast<QStringRef*>(s1), QString::fromUtf8(s2.data, s2.len), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_QStringRef_Compare6(void* s1, void* s2, long long cs)
{
	return QStringRef::compare(*static_cast<QStringRef*>(s1), *static_cast<QStringRef*>(s2), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_QStringRef_LocaleAwareCompare(void* s1, struct QtCore_PackedString s2)
{
	return QStringRef::localeAwareCompare(*static_cast<QStringRef*>(s1), QString::fromUtf8(s2.data, s2.len));
}

int QStringRef_QStringRef_LocaleAwareCompare4(void* s1, void* s2)
{
	return QStringRef::localeAwareCompare(*static_cast<QStringRef*>(s1), *static_cast<QStringRef*>(s2));
}

void QStringRef_Chop(void* ptr, int n)
{
	static_cast<QStringRef*>(ptr)->chop(n);
}

void QStringRef_Clear(void* ptr)
{
	static_cast<QStringRef*>(ptr)->clear();
}

void QStringRef_Truncate(void* ptr, int position)
{
	static_cast<QStringRef*>(ptr)->truncate(position);
}

void QStringRef_DestroyQStringRef(void* ptr)
{
	static_cast<QStringRef*>(ptr)->~QStringRef();
}

void* QStringRef_ToLatin1(void* ptr)
{
	return new QByteArray(static_cast<QStringRef*>(ptr)->toLatin1());
}

void* QStringRef_ToLocal8Bit(void* ptr)
{
	return new QByteArray(static_cast<QStringRef*>(ptr)->toLocal8Bit());
}

void* QStringRef_ToUtf8(void* ptr)
{
	return new QByteArray(static_cast<QStringRef*>(ptr)->toUtf8());
}

void* QStringRef_Back(void* ptr)
{
	return new QChar(static_cast<QStringRef*>(ptr)->back());
}

void* QStringRef_Front(void* ptr)
{
	return new QChar(static_cast<QStringRef*>(ptr)->front());
}

struct QtCore_PackedString QStringRef_ToString(void* ptr)
{
	return ({ QByteArray t336448 = static_cast<QStringRef*>(ptr)->toString().toUtf8(); QtCore_PackedString { const_cast<char*>(t336448.prepend("WHITESPACE").constData()+10), t336448.size()-10 }; });
}

void* QStringRef_AppendTo(void* ptr, struct QtCore_PackedString stri)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->appendTo(new QString(QString::fromUtf8(stri.data, stri.len))));
}

void* QStringRef_Chopped(void* ptr, int l)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->chopped(l));
}

void* QStringRef_Left(void* ptr, int n)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->left(n));
}

void* QStringRef_Mid(void* ptr, int position, int n)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->mid(position, n));
}

void* QStringRef_Right(void* ptr, int n)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->right(n));
}

void* QStringRef_Trimmed(void* ptr)
{
	return new QStringRef(static_cast<QStringRef*>(ptr)->trimmed());
}

struct QtCore_PackedList QStringRef_Split2(void* ptr, void* sep, long long behavior, long long cs)
{
	return ({ QVector<QStringRef>* tmpValue643751 = new QVector<QStringRef>(static_cast<QStringRef*>(ptr)->split(*static_cast<QChar*>(sep), static_cast<QString::SplitBehavior>(behavior), static_cast<Qt::CaseSensitivity>(cs))); QtCore_PackedList { tmpValue643751, tmpValue643751->size() }; });
}

struct QtCore_PackedList QStringRef_Split(void* ptr, struct QtCore_PackedString sep, long long behavior, long long cs)
{
	return ({ QVector<QStringRef>* tmpValued1bf8d = new QVector<QStringRef>(static_cast<QStringRef*>(ptr)->split(QString::fromUtf8(sep.data, sep.len), static_cast<QString::SplitBehavior>(behavior), static_cast<Qt::CaseSensitivity>(cs))); QtCore_PackedList { tmpValued1bf8d, tmpValued1bf8d->size() }; });
}

struct QtCore_PackedList QStringRef_ToUcs4(void* ptr)
{
	return ({ QVector<uint>* tmpValue6487a2 = new QVector<uint>(static_cast<QStringRef*>(ptr)->toUcs4()); QtCore_PackedList { tmpValue6487a2, tmpValue6487a2->size() }; });
}

char QStringRef_Contains2(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringRef*>(ptr)->contains(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_Contains3(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->contains(*static_cast<QLatin1String*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_Contains(void* ptr, struct QtCore_PackedString str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->contains(QString::fromUtf8(str.data, str.len), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_Contains4(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->contains(*static_cast<QStringRef*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_EndsWith3(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringRef*>(ptr)->endsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_EndsWith2(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->endsWith(*static_cast<QLatin1String*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_EndsWith4(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->endsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_EndsWith(void* ptr, struct QtCore_PackedString str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->endsWith(QString::fromUtf8(str.data, str.len), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_EndsWith5(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->endsWith(*static_cast<QStringRef*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_IsEmpty(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->isEmpty();
}

char QStringRef_IsNull(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->isNull();
}

char QStringRef_IsRightToLeft(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->isRightToLeft();
}

char QStringRef_StartsWith3(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringRef*>(ptr)->startsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_StartsWith2(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->startsWith(*static_cast<QLatin1String*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_StartsWith4(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->startsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_StartsWith(void* ptr, struct QtCore_PackedString str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->startsWith(QString::fromUtf8(str.data, str.len), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringRef_StartsWith5(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->startsWith(*static_cast<QStringRef*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

void* QStringRef_ConstData(void* ptr)
{
	return const_cast<QChar*>(static_cast<QStringRef*>(ptr)->constData());
}

void* QStringRef_Data(void* ptr)
{
	return const_cast<QChar*>(static_cast<QStringRef*>(ptr)->data());
}

void* QStringRef_Unicode(void* ptr)
{
	return const_cast<QChar*>(static_cast<QStringRef*>(ptr)->unicode());
}

void* QStringRef_At(void* ptr, int position)
{
	return new QChar(static_cast<QStringRef*>(ptr)->at(position));
}

struct QtCore_PackedString QStringRef_String(void* ptr)
{
	return ({ QByteArray t75a779 = static_cast<QStringRef*>(ptr)->string()->toUtf8(); QtCore_PackedString { const_cast<char*>(t75a779.prepend("WHITESPACE").constData()+10), t75a779.size()-10 }; });
}

double QStringRef_ToDouble(void* ptr, char* ok)
{
	return static_cast<QStringRef*>(ptr)->toDouble(reinterpret_cast<bool*>(ok));
}

float QStringRef_ToFloat(void* ptr, char* ok)
{
	return static_cast<QStringRef*>(ptr)->toFloat(reinterpret_cast<bool*>(ok));
}

int QStringRef_Compare3(void* ptr, void* other, long long cs)
{
	return static_cast<QStringRef*>(ptr)->compare(*static_cast<QLatin1String*>(other), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Compare4(void* ptr, void* other, long long cs)
{
	return static_cast<QStringRef*>(ptr)->compare(*static_cast<QByteArray*>(other), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Compare5(void* ptr, struct QtCore_PackedString other, long long cs)
{
	return static_cast<QStringRef*>(ptr)->compare(QString::fromUtf8(other.data, other.len), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Compare2(void* ptr, void* other, long long cs)
{
	return static_cast<QStringRef*>(ptr)->compare(*static_cast<QStringRef*>(other), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Count(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->count();
}

int QStringRef_Count3(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringRef*>(ptr)->count(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Count2(void* ptr, struct QtCore_PackedString str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->count(QString::fromUtf8(str.data, str.len), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Count4(void* ptr, void* str, long long cs)
{
	return static_cast<QStringRef*>(ptr)->count(*static_cast<QStringRef*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_IndexOf2(void* ptr, void* ch, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->indexOf(*static_cast<QChar*>(ch), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_IndexOf3(void* ptr, void* str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->indexOf(*static_cast<QLatin1String*>(str), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_IndexOf(void* ptr, struct QtCore_PackedString str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->indexOf(QString::fromUtf8(str.data, str.len), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_IndexOf4(void* ptr, void* str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->indexOf(*static_cast<QStringRef*>(str), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_LastIndexOf2(void* ptr, void* ch, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->lastIndexOf(*static_cast<QChar*>(ch), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_LastIndexOf3(void* ptr, void* str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->lastIndexOf(*static_cast<QLatin1String*>(str), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_LastIndexOf(void* ptr, struct QtCore_PackedString str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->lastIndexOf(QString::fromUtf8(str.data, str.len), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_LastIndexOf4(void* ptr, void* str, int from, long long cs)
{
	return static_cast<QStringRef*>(ptr)->lastIndexOf(*static_cast<QStringRef*>(str), from, static_cast<Qt::CaseSensitivity>(cs));
}

int QStringRef_Length(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->length();
}

int QStringRef_LocaleAwareCompare3(void* ptr, struct QtCore_PackedString other)
{
	return static_cast<QStringRef*>(ptr)->localeAwareCompare(QString::fromUtf8(other.data, other.len));
}

int QStringRef_LocaleAwareCompare2(void* ptr, void* other)
{
	return static_cast<QStringRef*>(ptr)->localeAwareCompare(*static_cast<QStringRef*>(other));
}

int QStringRef_Position(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->position();
}

int QStringRef_Size(void* ptr)
{
	return static_cast<QStringRef*>(ptr)->size();
}

int QStringRef_ToInt(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toInt(reinterpret_cast<bool*>(ok), base);
}

long QStringRef_ToLong(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toLong(reinterpret_cast<bool*>(ok), base);
}

long long QStringRef_ToLongLong(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toLongLong(reinterpret_cast<bool*>(ok), base);
}

unsigned long long QStringRef_ToULongLong(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toULongLong(reinterpret_cast<bool*>(ok), base);
}

short QStringRef_ToShort(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toShort(reinterpret_cast<bool*>(ok), base);
}

unsigned int QStringRef_ToUInt(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toUInt(reinterpret_cast<bool*>(ok), base);
}

unsigned long QStringRef_ToULong(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toULong(reinterpret_cast<bool*>(ok), base);
}

unsigned short QStringRef_ToUShort(void* ptr, char* ok, int base)
{
	return static_cast<QStringRef*>(ptr)->toUShort(reinterpret_cast<bool*>(ok), base);
}

void* QStringRef___split_atList2(void* ptr, int i)
{
	return new QStringRef(({QStringRef tmp = static_cast<QVector<QStringRef>*>(ptr)->at(i); if (i == static_cast<QVector<QStringRef>*>(ptr)->size()-1) { static_cast<QVector<QStringRef>*>(ptr)->~QVector(); free(ptr); }; tmp; }));
}

void QStringRef___split_setList2(void* ptr, void* i)
{
	static_cast<QVector<QStringRef>*>(ptr)->append(*static_cast<QStringRef*>(i));
}

void* QStringRef___split_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<QStringRef>();
}

void* QStringRef___split_atList(void* ptr, int i)
{
	return new QStringRef(({QStringRef tmp = static_cast<QVector<QStringRef>*>(ptr)->at(i); if (i == static_cast<QVector<QStringRef>*>(ptr)->size()-1) { static_cast<QVector<QStringRef>*>(ptr)->~QVector(); free(ptr); }; tmp; }));
}

void QStringRef___split_setList(void* ptr, void* i)
{
	static_cast<QVector<QStringRef>*>(ptr)->append(*static_cast<QStringRef*>(i));
}

void* QStringRef___split_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<QStringRef>();
}

unsigned int QStringRef___toUcs4_atList(void* ptr, int i)
{
	return ({uint tmp = static_cast<QVector<uint>*>(ptr)->at(i); if (i == static_cast<QVector<uint>*>(ptr)->size()-1) { static_cast<QVector<uint>*>(ptr)->~QVector(); free(ptr); }; tmp; });
}

void QStringRef___toUcs4_setList(void* ptr, unsigned int i)
{
	static_cast<QVector<uint>*>(ptr)->append(i);
}

void* QStringRef___toUcs4_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<uint>();
}

Q_DECLARE_METATYPE(QStringView)
Q_DECLARE_METATYPE(QStringView*)
void* QStringView_NewQStringView()
{
	return new QStringView();
}

void* QStringView_NewQStringView7(struct QtCore_PackedString str)
{
	return new QStringView(QString::fromUtf8(str.data, str.len));
}

void* QStringView_NewQStringView8(void* str)
{
	return new QStringView(*static_cast<QStringRef*>(str));
}

void* QStringView_ToLatin1(void* ptr)
{
	return new QByteArray(static_cast<QStringView*>(ptr)->toLatin1());
}

void* QStringView_ToLocal8Bit(void* ptr)
{
	return new QByteArray(static_cast<QStringView*>(ptr)->toLocal8Bit());
}

void* QStringView_ToUtf8(void* ptr)
{
	return new QByteArray(static_cast<QStringView*>(ptr)->toUtf8());
}

void* QStringView_Back(void* ptr)
{
	return new QChar(static_cast<QStringView*>(ptr)->back());
}

void* QStringView_First(void* ptr)
{
	return new QChar(static_cast<QStringView*>(ptr)->first());
}

void* QStringView_Front(void* ptr)
{
	return new QChar(static_cast<QStringView*>(ptr)->front());
}

void* QStringView_Last(void* ptr)
{
	return new QChar(static_cast<QStringView*>(ptr)->last());
}

struct QtCore_PackedString QStringView_ToString(void* ptr)
{
	return ({ QByteArray t401ff3 = static_cast<QStringView*>(ptr)->toString().toUtf8(); QtCore_PackedString { const_cast<char*>(t401ff3.prepend("WHITESPACE").constData()+10), t401ff3.size()-10 }; });
}

void* QStringView_Trimmed(void* ptr)
{
	return new QStringView(static_cast<QStringView*>(ptr)->trimmed());
}

struct QtCore_PackedList QStringView_ToUcs4(void* ptr)
{
	return ({ QVector<uint>* tmpValue713c7b = new QVector<uint>(static_cast<QStringView*>(ptr)->toUcs4()); QtCore_PackedList { tmpValue713c7b, tmpValue713c7b->size() }; });
}

char QStringView_Empty(void* ptr)
{
	return static_cast<QStringView*>(ptr)->empty();
}

char QStringView_EndsWith3(void* ptr, void* ch)
{
	return static_cast<QStringView*>(ptr)->endsWith(*static_cast<QChar*>(ch));
}

char QStringView_EndsWith4(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringView*>(ptr)->endsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringView_EndsWith2(void* ptr, void* l1, long long cs)
{
	return static_cast<QStringView*>(ptr)->endsWith(*static_cast<QLatin1String*>(l1), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringView_EndsWith(void* ptr, void* str, long long cs)
{
	return static_cast<QStringView*>(ptr)->endsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringView_IsEmpty(void* ptr)
{
	return static_cast<QStringView*>(ptr)->isEmpty();
}

char QStringView_IsNull(void* ptr)
{
	return static_cast<QStringView*>(ptr)->isNull();
}

char QStringView_IsRightToLeft(void* ptr)
{
	return static_cast<QStringView*>(ptr)->isRightToLeft();
}

char QStringView_StartsWith3(void* ptr, void* ch)
{
	return static_cast<QStringView*>(ptr)->startsWith(*static_cast<QChar*>(ch));
}

char QStringView_StartsWith4(void* ptr, void* ch, long long cs)
{
	return static_cast<QStringView*>(ptr)->startsWith(*static_cast<QChar*>(ch), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringView_StartsWith2(void* ptr, void* l1, long long cs)
{
	return static_cast<QStringView*>(ptr)->startsWith(*static_cast<QLatin1String*>(l1), static_cast<Qt::CaseSensitivity>(cs));
}

char QStringView_StartsWith(void* ptr, void* str, long long cs)
{
	return static_cast<QStringView*>(ptr)->startsWith(*static_cast<QStringView*>(str), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringView_Compare(void* ptr, void* other, long long cs)
{
	return static_cast<QStringView*>(ptr)->compare(*static_cast<QStringView*>(other), static_cast<Qt::CaseSensitivity>(cs));
}

int QStringView_Length(void* ptr)
{
	return static_cast<QStringView*>(ptr)->length();
}

unsigned int QStringView___toUcs4_atList(void* ptr, int i)
{
	return ({uint tmp = static_cast<QVector<uint>*>(ptr)->at(i); if (i == static_cast<QVector<uint>*>(ptr)->size()-1) { static_cast<QVector<uint>*>(ptr)->~QVector(); free(ptr); }; tmp; });
}

void QStringView___toUcs4_setList(void* ptr, unsigned int i)
{
	static_cast<QVector<uint>*>(ptr)->append(i);
}

void* QStringView___toUcs4_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QVector<uint>();
}

int QSysInfo_WordSize_Type()
{
	return QSysInfo::WordSize;
}

class MyQThread: public QThread
{
public:
	MyQThread(QObject *parent = Q_NULLPTR) : QThread(parent) {QThread_QThread_QRegisterMetaType();};
	bool event(QEvent * event) { return callbackQObject_Event(this, event) != 0; };
	void Signal_Finished() { callbackQThread_Finished(this); };
	void quit() { callbackQThread_Quit(this); };
	void run() { callbackQThread_Run(this); };
	void start() { callbackQThread_Start(this); };
	void Signal_Started() { callbackQThread_Started(this); };
	void terminate() { callbackQThread_Terminate(this); };
	 ~MyQThread() { callbackQThread_DestroyQThread(this); };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QThread*)
Q_DECLARE_METATYPE(MyQThread*)

int QThread_QThread_QRegisterMetaType(){qRegisterMetaType<QThread*>(); return qRegisterMetaType<MyQThread*>();}

void* QThread_QThread_CurrentThread()
{
	return QThread::currentThread();
}

void* QThread_NewQThread(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQThread(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQThread(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQThread(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQThread(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQThread(static_cast<QWindow*>(parent));
	} else {
		return new MyQThread(static_cast<QObject*>(parent));
	}
}

char QThread_Wait(void* ptr, unsigned long ti)
{
	return static_cast<QThread*>(ptr)->wait(ti);
}

int QThread_Exec(void* ptr)
{
	return static_cast<QThread*>(ptr)->exec();
}

int QThread_QThread_IdealThreadCount()
{
	return QThread::idealThreadCount();
}

void QThread_Exit(void* ptr, int returnCode)
{
	static_cast<QThread*>(ptr)->exit(returnCode);
}

void QThread_ConnectFinished(void* ptr, long long t)
{
	QObject::connect(static_cast<QThread*>(ptr), &QThread::finished, static_cast<MyQThread*>(ptr), static_cast<void (MyQThread::*)()>(&MyQThread::Signal_Finished), static_cast<Qt::ConnectionType>(t));
}

void QThread_DisconnectFinished(void* ptr)
{
	QObject::disconnect(static_cast<QThread*>(ptr), &QThread::finished, static_cast<MyQThread*>(ptr), static_cast<void (MyQThread::*)()>(&MyQThread::Signal_Finished));
}

void QThread_QThread_Msleep(unsigned long msecs)
{
	QThread::msleep(msecs);
}

void QThread_Quit(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QThread*>(ptr), "quit");
}

void QThread_QuitDefault(void* ptr)
{
		static_cast<QThread*>(ptr)->QThread::quit();
}

void QThread_RequestInterruption(void* ptr)
{
	static_cast<QThread*>(ptr)->requestInterruption();
}

void QThread_Run(void* ptr)
{
	static_cast<QThread*>(ptr)->run();
}

void QThread_RunDefault(void* ptr)
{
		static_cast<QThread*>(ptr)->QThread::run();
}

void QThread_SetEventDispatcher(void* ptr, void* eventDispatcher)
{
	static_cast<QThread*>(ptr)->setEventDispatcher(static_cast<QAbstractEventDispatcher*>(eventDispatcher));
}

void QThread_SetPriority(void* ptr, long long priority)
{
	static_cast<QThread*>(ptr)->setPriority(static_cast<QThread::Priority>(priority));
}

void QThread_SetStackSize(void* ptr, unsigned int stackSize)
{
	static_cast<QThread*>(ptr)->setStackSize(stackSize);
}

void QThread_QThread_SetTerminationEnabled(char enabled)
{
	QThread::setTerminationEnabled(enabled != 0);
}

void QThread_QThread_Sleep(unsigned long secs)
{
	QThread::sleep(secs);
}

void QThread_Start(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QThread*>(ptr), "start");
}

void QThread_StartDefault(void* ptr)
{
		static_cast<QThread*>(ptr)->QThread::start();
}

void QThread_ConnectStarted(void* ptr, long long t)
{
	QObject::connect(static_cast<QThread*>(ptr), &QThread::started, static_cast<MyQThread*>(ptr), static_cast<void (MyQThread::*)()>(&MyQThread::Signal_Started), static_cast<Qt::ConnectionType>(t));
}

void QThread_DisconnectStarted(void* ptr)
{
	QObject::disconnect(static_cast<QThread*>(ptr), &QThread::started, static_cast<MyQThread*>(ptr), static_cast<void (MyQThread::*)()>(&MyQThread::Signal_Started));
}

void QThread_Terminate(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QThread*>(ptr), "terminate");
}

void QThread_TerminateDefault(void* ptr)
{
		static_cast<QThread*>(ptr)->QThread::terminate();
}

void QThread_QThread_Usleep(unsigned long usecs)
{
	QThread::usleep(usecs);
}

void QThread_QThread_YieldCurrentThread()
{
	QThread::yieldCurrentThread();
}

void QThread_DestroyQThread(void* ptr)
{
	static_cast<QThread*>(ptr)->~QThread();
}

void QThread_DestroyQThreadDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

void* QThread_EventDispatcher(void* ptr)
{
	return static_cast<QThread*>(ptr)->eventDispatcher();
}

long long QThread_Priority(void* ptr)
{
	return static_cast<QThread*>(ptr)->priority();
}

char QThread_IsFinished(void* ptr)
{
	return static_cast<QThread*>(ptr)->isFinished();
}

char QThread_IsInterruptionRequested(void* ptr)
{
	return static_cast<QThread*>(ptr)->isInterruptionRequested();
}

char QThread_IsRunning(void* ptr)
{
	return static_cast<QThread*>(ptr)->isRunning();
}

int QThread_LoopLevel(void* ptr)
{
	return static_cast<QThread*>(ptr)->loopLevel();
}

unsigned int QThread_StackSize(void* ptr)
{
	return static_cast<QThread*>(ptr)->stackSize();
}

Q_DECLARE_METATYPE(QTime)
Q_DECLARE_METATYPE(QTime*)
void* QTime_QTime_CurrentTime()
{
	return new QTime(QTime::currentTime());
}

void* QTime_QTime_FromMSecsSinceStartOfDay(int msecs)
{
	return new QTime(QTime::fromMSecsSinceStartOfDay(msecs));
}

void* QTime_QTime_FromString(struct QtCore_PackedString stri, long long format)
{
	return new QTime(QTime::fromString(QString::fromUtf8(stri.data, stri.len), static_cast<Qt::DateFormat>(format)));
}

void* QTime_QTime_FromString2(struct QtCore_PackedString stri, struct QtCore_PackedString format)
{
	return new QTime(QTime::fromString(QString::fromUtf8(stri.data, stri.len), QString::fromUtf8(format.data, format.len)));
}

void* QTime_NewQTime()
{
	return new QTime();
}

void* QTime_NewQTime3(int h, int m, int s, int ms)
{
	return new QTime(h, m, s, ms);
}

char QTime_QTime_IsValid2(int h, int m, int s, int ms)
{
	return QTime::isValid(h, m, s, ms);
}

char QTime_SetHMS(void* ptr, int h, int m, int s, int ms)
{
	return static_cast<QTime*>(ptr)->setHMS(h, m, s, ms);
}

int QTime_Restart(void* ptr)
{
	return static_cast<QTime*>(ptr)->restart();
}

void QTime_Start(void* ptr)
{
	static_cast<QTime*>(ptr)->start();
}

struct QtCore_PackedString QTime_ToString3(void* ptr, void* format)
{
	return ({ QByteArray t3aabc8 = static_cast<QTime*>(ptr)->toString(*static_cast<QStringView*>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(t3aabc8.prepend("WHITESPACE").constData()+10), t3aabc8.size()-10 }; });
}

struct QtCore_PackedString QTime_ToString2(void* ptr, long long format)
{
	return ({ QByteArray tb222d7 = static_cast<QTime*>(ptr)->toString(static_cast<Qt::DateFormat>(format)).toUtf8(); QtCore_PackedString { const_cast<char*>(tb222d7.prepend("WHITESPACE").constData()+10), tb222d7.size()-10 }; });
}

struct QtCore_PackedString QTime_ToString(void* ptr, struct QtCore_PackedString format)
{
	return ({ QByteArray t864fb5 = static_cast<QTime*>(ptr)->toString(QString::fromUtf8(format.data, format.len)).toUtf8(); QtCore_PackedString { const_cast<char*>(t864fb5.prepend("WHITESPACE").constData()+10), t864fb5.size()-10 }; });
}

void* QTime_AddMSecs(void* ptr, int ms)
{
	return new QTime(static_cast<QTime*>(ptr)->addMSecs(ms));
}

void* QTime_AddSecs(void* ptr, int s)
{
	return new QTime(static_cast<QTime*>(ptr)->addSecs(s));
}

char QTime_IsNull(void* ptr)
{
	return static_cast<QTime*>(ptr)->isNull();
}

char QTime_IsValid(void* ptr)
{
	return static_cast<QTime*>(ptr)->isValid();
}

int QTime_Elapsed(void* ptr)
{
	return static_cast<QTime*>(ptr)->elapsed();
}

int QTime_Hour(void* ptr)
{
	return static_cast<QTime*>(ptr)->hour();
}

int QTime_Minute(void* ptr)
{
	return static_cast<QTime*>(ptr)->minute();
}

int QTime_Msec(void* ptr)
{
	return static_cast<QTime*>(ptr)->msec();
}

int QTime_MsecsSinceStartOfDay(void* ptr)
{
	return static_cast<QTime*>(ptr)->msecsSinceStartOfDay();
}

int QTime_MsecsTo(void* ptr, void* t)
{
	return static_cast<QTime*>(ptr)->msecsTo(*static_cast<QTime*>(t));
}

int QTime_Second(void* ptr)
{
	return static_cast<QTime*>(ptr)->second();
}

int QTime_SecsTo(void* ptr, void* t)
{
	return static_cast<QTime*>(ptr)->secsTo(*static_cast<QTime*>(t));
}

Q_DECLARE_METATYPE(QTimeZone)
Q_DECLARE_METATYPE(QTimeZone*)
void* QTimeZone_QTimeZone_IanaIdToWindowsId(void* ianaId)
{
	return new QByteArray(QTimeZone::ianaIdToWindowsId(*static_cast<QByteArray*>(ianaId)));
}

void* QTimeZone_QTimeZone_SystemTimeZoneId()
{
	return new QByteArray(QTimeZone::systemTimeZoneId());
}

void* QTimeZone_QTimeZone_WindowsIdToDefaultIanaId(void* windowsId)
{
	return new QByteArray(QTimeZone::windowsIdToDefaultIanaId(*static_cast<QByteArray*>(windowsId)));
}

void* QTimeZone_QTimeZone_WindowsIdToDefaultIanaId2(void* windowsId, long long country)
{
	return new QByteArray(QTimeZone::windowsIdToDefaultIanaId(*static_cast<QByteArray*>(windowsId), static_cast<QLocale::Country>(country)));
}

struct QtCore_PackedList QTimeZone_QTimeZone_AvailableTimeZoneIds()
{
	return ({ QList<QByteArray>* tmpValue9dfc57 = new QList<QByteArray>(QTimeZone::availableTimeZoneIds()); QtCore_PackedList { tmpValue9dfc57, tmpValue9dfc57->size() }; });
}

struct QtCore_PackedList QTimeZone_QTimeZone_AvailableTimeZoneIds2(long long country)
{
	return ({ QList<QByteArray>* tmpValueb51557 = new QList<QByteArray>(QTimeZone::availableTimeZoneIds(static_cast<QLocale::Country>(country))); QtCore_PackedList { tmpValueb51557, tmpValueb51557->size() }; });
}

struct QtCore_PackedList QTimeZone_QTimeZone_AvailableTimeZoneIds3(int offsetSeconds)
{
	return ({ QList<QByteArray>* tmpValue137a2a = new QList<QByteArray>(QTimeZone::availableTimeZoneIds(offsetSeconds)); QtCore_PackedList { tmpValue137a2a, tmpValue137a2a->size() }; });
}

struct QtCore_PackedList QTimeZone_QTimeZone_WindowsIdToIanaIds(void* windowsId)
{
	return ({ QList<QByteArray>* tmpValue7576fc = new QList<QByteArray>(QTimeZone::windowsIdToIanaIds(*static_cast<QByteArray*>(windowsId))); QtCore_PackedList { tmpValue7576fc, tmpValue7576fc->size() }; });
}

struct QtCore_PackedList QTimeZone_QTimeZone_WindowsIdToIanaIds2(void* windowsId, long long country)
{
	return ({ QList<QByteArray>* tmpValue5be00a = new QList<QByteArray>(QTimeZone::windowsIdToIanaIds(*static_cast<QByteArray*>(windowsId), static_cast<QLocale::Country>(country))); QtCore_PackedList { tmpValue5be00a, tmpValue5be00a->size() }; });
}

void* QTimeZone_QTimeZone_SystemTimeZone()
{
	return new QTimeZone(QTimeZone::systemTimeZone());
}

void* QTimeZone_QTimeZone_Utc()
{
	return new QTimeZone(QTimeZone::utc());
}

void* QTimeZone_NewQTimeZone()
{
	return new QTimeZone();
}

void* QTimeZone_NewQTimeZone2(void* ianaId)
{
	return new QTimeZone(*static_cast<QByteArray*>(ianaId));
}

void* QTimeZone_NewQTimeZone4(void* ianaId, int offsetSeconds, struct QtCore_PackedString name, struct QtCore_PackedString abbreviation, long long country, struct QtCore_PackedString comment)
{
	return new QTimeZone(*static_cast<QByteArray*>(ianaId), offsetSeconds, QString::fromUtf8(name.data, name.len), QString::fromUtf8(abbreviation.data, abbreviation.len), static_cast<QLocale::Country>(country), QString::fromUtf8(comment.data, comment.len));
}

void* QTimeZone_NewQTimeZone5(void* other)
{
	return new QTimeZone(*static_cast<QTimeZone*>(other));
}

void* QTimeZone_NewQTimeZone3(int offsetSeconds)
{
	return new QTimeZone(offsetSeconds);
}

char QTimeZone_QTimeZone_IsTimeZoneIdAvailable(void* ianaId)
{
	return QTimeZone::isTimeZoneIdAvailable(*static_cast<QByteArray*>(ianaId));
}

void QTimeZone_Swap(void* ptr, void* other)
{
	static_cast<QTimeZone*>(ptr)->swap(*static_cast<QTimeZone*>(other));
}

void QTimeZone_DestroyQTimeZone(void* ptr)
{
	static_cast<QTimeZone*>(ptr)->~QTimeZone();
}

void* QTimeZone_Id(void* ptr)
{
	return new QByteArray(static_cast<QTimeZone*>(ptr)->id());
}

long long QTimeZone_Country(void* ptr)
{
	return static_cast<QTimeZone*>(ptr)->country();
}

struct QtCore_PackedString QTimeZone_Abbreviation(void* ptr, void* atDateTime)
{
	return ({ QByteArray t82ae84 = static_cast<QTimeZone*>(ptr)->abbreviation(*static_cast<QDateTime*>(atDateTime)).toUtf8(); QtCore_PackedString { const_cast<char*>(t82ae84.prepend("WHITESPACE").constData()+10), t82ae84.size()-10 }; });
}

struct QtCore_PackedString QTimeZone_Comment(void* ptr)
{
	return ({ QByteArray t2b73f6 = static_cast<QTimeZone*>(ptr)->comment().toUtf8(); QtCore_PackedString { const_cast<char*>(t2b73f6.prepend("WHITESPACE").constData()+10), t2b73f6.size()-10 }; });
}

struct QtCore_PackedString QTimeZone_DisplayName2(void* ptr, long long timeType, long long nameType, void* locale)
{
	return ({ QByteArray tc6cf47 = static_cast<QTimeZone*>(ptr)->displayName(static_cast<QTimeZone::TimeType>(timeType), static_cast<QTimeZone::NameType>(nameType), *static_cast<QLocale*>(locale)).toUtf8(); QtCore_PackedString { const_cast<char*>(tc6cf47.prepend("WHITESPACE").constData()+10), tc6cf47.size()-10 }; });
}

struct QtCore_PackedString QTimeZone_DisplayName(void* ptr, void* atDateTime, long long nameType, void* locale)
{
	return ({ QByteArray t168cd9 = static_cast<QTimeZone*>(ptr)->displayName(*static_cast<QDateTime*>(atDateTime), static_cast<QTimeZone::NameType>(nameType), *static_cast<QLocale*>(locale)).toUtf8(); QtCore_PackedString { const_cast<char*>(t168cd9.prepend("WHITESPACE").constData()+10), t168cd9.size()-10 }; });
}

char QTimeZone_HasDaylightTime(void* ptr)
{
	return static_cast<QTimeZone*>(ptr)->hasDaylightTime();
}

char QTimeZone_HasTransitions(void* ptr)
{
	return static_cast<QTimeZone*>(ptr)->hasTransitions();
}

char QTimeZone_IsDaylightTime(void* ptr, void* atDateTime)
{
	return static_cast<QTimeZone*>(ptr)->isDaylightTime(*static_cast<QDateTime*>(atDateTime));
}

char QTimeZone_IsValid(void* ptr)
{
	return static_cast<QTimeZone*>(ptr)->isValid();
}

int QTimeZone_DaylightTimeOffset(void* ptr, void* atDateTime)
{
	return static_cast<QTimeZone*>(ptr)->daylightTimeOffset(*static_cast<QDateTime*>(atDateTime));
}

int QTimeZone_OffsetFromUtc(void* ptr, void* atDateTime)
{
	return static_cast<QTimeZone*>(ptr)->offsetFromUtc(*static_cast<QDateTime*>(atDateTime));
}

int QTimeZone_StandardTimeOffset(void* ptr, void* atDateTime)
{
	return static_cast<QTimeZone*>(ptr)->standardTimeOffset(*static_cast<QDateTime*>(atDateTime));
}

void* QTimeZone___availableTimeZoneIds_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QTimeZone___availableTimeZoneIds_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QTimeZone___availableTimeZoneIds_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QTimeZone___availableTimeZoneIds_atList2(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QTimeZone___availableTimeZoneIds_setList2(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QTimeZone___availableTimeZoneIds_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QTimeZone___availableTimeZoneIds_atList3(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QTimeZone___availableTimeZoneIds_setList3(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QTimeZone___availableTimeZoneIds_newList3(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QTimeZone___windowsIdToIanaIds_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QTimeZone___windowsIdToIanaIds_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QTimeZone___windowsIdToIanaIds_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

void* QTimeZone___windowsIdToIanaIds_atList2(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QTimeZone___windowsIdToIanaIds_setList2(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QTimeZone___windowsIdToIanaIds_newList2(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

class MyQTimerEvent: public QTimerEvent
{
public:
	MyQTimerEvent(int timerId) : QTimerEvent(timerId) {QTimerEvent_QTimerEvent_QRegisterMetaType();};
};

Q_DECLARE_METATYPE(QTimerEvent*)
Q_DECLARE_METATYPE(MyQTimerEvent*)

int QTimerEvent_QTimerEvent_QRegisterMetaType(){qRegisterMetaType<QTimerEvent*>(); return qRegisterMetaType<MyQTimerEvent*>();}

void* QTimerEvent_NewQTimerEvent(int timerId)
{
	return new MyQTimerEvent(timerId);
}

int QTimerEvent_TimerId(void* ptr)
{
	return static_cast<QTimerEvent*>(ptr)->timerId();
}

int QTimerEvent_Id(void* ptr)
{
	return static_cast<QTimerEvent*>(ptr)->id;
}

void QTimerEvent_SetId(void* ptr, int vin)
{
	static_cast<QTimerEvent*>(ptr)->id = vin;
}

class MyQTranslator: public QTranslator
{
public:
	MyQTranslator(QObject *parent = Q_NULLPTR) : QTranslator(parent) {QTranslator_QTranslator_QRegisterMetaType();};
	 ~MyQTranslator() { callbackQTranslator_DestroyQTranslator(this); };
	QString translate(const char * context, const char * sourceText, const char * disambiguation, int n) const { QtCore_PackedString contextPacked = { const_cast<char*>(context), n };QtCore_PackedString sourceTextPacked = { const_cast<char*>(sourceText), n };QtCore_PackedString disambiguationPacked = { const_cast<char*>(disambiguation), n };return ({ QtCore_PackedString tempVal = callbackQTranslator_Translate(const_cast<void*>(static_cast<const void*>(this)), contextPacked, sourceTextPacked, disambiguationPacked, n); QString ret = QString::fromUtf8(tempVal.data, tempVal.len); free(tempVal.data); ret; }); };
	bool isEmpty() const { return callbackQTranslator_IsEmpty(const_cast<void*>(static_cast<const void*>(this))) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQObject_MetaObject(const_cast<void*>(static_cast<const void*>(this)))); };
	bool event(QEvent * e) { return callbackQObject_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQObject_EventFilter(this, watched, event) != 0; };
	void childEvent(QChildEvent * event) { callbackQObject_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQObject_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQObject_CustomEvent(this, event); };
	void deleteLater() { callbackQObject_DeleteLater(this); };
	void Signal_Destroyed(QObject * obj) { callbackQObject_Destroyed(this, obj); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQObject_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void Signal_ObjectNameChanged(const QString & objectName) { QByteArray taa2c4f = objectName.toUtf8(); QtCore_PackedString objectNamePacked = { const_cast<char*>(taa2c4f.prepend("WHITESPACE").constData()+10), taa2c4f.size()-10 };callbackQObject_ObjectNameChanged(this, objectNamePacked); };
	void timerEvent(QTimerEvent * event) { callbackQObject_TimerEvent(this, event); };
};

Q_DECLARE_METATYPE(QTranslator*)
Q_DECLARE_METATYPE(MyQTranslator*)

int QTranslator_QTranslator_QRegisterMetaType(){qRegisterMetaType<QTranslator*>(); return qRegisterMetaType<MyQTranslator*>();}

void* QTranslator_NewQTranslator(void* parent)
{
	if (dynamic_cast<QGraphicsObject*>(static_cast<QObject*>(parent))) {
		return new MyQTranslator(static_cast<QGraphicsObject*>(parent));
	} else if (dynamic_cast<QGraphicsWidget*>(static_cast<QObject*>(parent))) {
		return new MyQTranslator(static_cast<QGraphicsWidget*>(parent));
	} else if (dynamic_cast<QLayout*>(static_cast<QObject*>(parent))) {
		return new MyQTranslator(static_cast<QLayout*>(parent));
	} else if (dynamic_cast<QWidget*>(static_cast<QObject*>(parent))) {
		return new MyQTranslator(static_cast<QWidget*>(parent));
	} else if (dynamic_cast<QWindow*>(static_cast<QObject*>(parent))) {
		return new MyQTranslator(static_cast<QWindow*>(parent));
	} else {
		return new MyQTranslator(static_cast<QObject*>(parent));
	}
}

char QTranslator_Load2(void* ptr, void* locale, struct QtCore_PackedString filename, struct QtCore_PackedString prefix, struct QtCore_PackedString directory, struct QtCore_PackedString suffix)
{
	return static_cast<QTranslator*>(ptr)->load(*static_cast<QLocale*>(locale), QString::fromUtf8(filename.data, filename.len), QString::fromUtf8(prefix.data, prefix.len), QString::fromUtf8(directory.data, directory.len), QString::fromUtf8(suffix.data, suffix.len));
}

char QTranslator_Load(void* ptr, struct QtCore_PackedString filename, struct QtCore_PackedString directory, struct QtCore_PackedString search_delimiters, struct QtCore_PackedString suffix)
{
	return static_cast<QTranslator*>(ptr)->load(QString::fromUtf8(filename.data, filename.len), QString::fromUtf8(directory.data, directory.len), QString::fromUtf8(search_delimiters.data, search_delimiters.len), QString::fromUtf8(suffix.data, suffix.len));
}

char QTranslator_Load3(void* ptr, char* data, int l, struct QtCore_PackedString directory)
{
	return static_cast<QTranslator*>(ptr)->load(const_cast<const uchar*>(static_cast<uchar*>(static_cast<void*>(data))), l, QString::fromUtf8(directory.data, directory.len));
}

void QTranslator_DestroyQTranslator(void* ptr)
{
	static_cast<QTranslator*>(ptr)->~QTranslator();
}

void QTranslator_DestroyQTranslatorDefault(void* ptr)
{
	Q_UNUSED(ptr);

}

struct QtCore_PackedString QTranslator_Translate(void* ptr, char* context, char* sourceText, char* disambiguation, int n)
{
	return ({ QByteArray tb6b80e = static_cast<QTranslator*>(ptr)->translate(const_cast<const char*>(context), const_cast<const char*>(sourceText), const_cast<const char*>(disambiguation), n).toUtf8(); QtCore_PackedString { const_cast<char*>(tb6b80e.prepend("WHITESPACE").constData()+10), tb6b80e.size()-10 }; });
}

struct QtCore_PackedString QTranslator_TranslateDefault(void* ptr, char* context, char* sourceText, char* disambiguation, int n)
{
		return ({ QByteArray t5511a2 = static_cast<QTranslator*>(ptr)->QTranslator::translate(const_cast<const char*>(context), const_cast<const char*>(sourceText), const_cast<const char*>(disambiguation), n).toUtf8(); QtCore_PackedString { const_cast<char*>(t5511a2.prepend("WHITESPACE").constData()+10), t5511a2.size()-10 }; });
}

char QTranslator_IsEmpty(void* ptr)
{
	return static_cast<QTranslator*>(ptr)->isEmpty();
}

char QTranslator_IsEmptyDefault(void* ptr)
{
		return static_cast<QTranslator*>(ptr)->QTranslator::isEmpty();
}

Q_DECLARE_METATYPE(QUrl)
Q_DECLARE_METATYPE(QUrl*)
void* QUrl_QUrl_ToAce(struct QtCore_PackedString domain)
{
	return new QByteArray(QUrl::toAce(QString::fromUtf8(domain.data, domain.len)));
}

void* QUrl_QUrl_ToPercentEncoding(struct QtCore_PackedString input, void* exclude, void* include)
{
	return new QByteArray(QUrl::toPercentEncoding(QString::fromUtf8(input.data, input.len), *static_cast<QByteArray*>(exclude), *static_cast<QByteArray*>(include)));
}

struct QtCore_PackedList QUrl_QUrl_FromStringList(struct QtCore_PackedString urls, long long mode)
{
	return ({ QList<QUrl>* tmpValue5751dc = new QList<QUrl>(QUrl::fromStringList(QString::fromUtf8(urls.data, urls.len).split("¡¦!", QString::SkipEmptyParts), static_cast<QUrl::ParsingMode>(mode))); QtCore_PackedList { tmpValue5751dc, tmpValue5751dc->size() }; });
}

struct QtCore_PackedString QUrl_QUrl_FromAce(void* domain)
{
	return ({ QByteArray t0cf8b9 = QUrl::fromAce(*static_cast<QByteArray*>(domain)).toUtf8(); QtCore_PackedString { const_cast<char*>(t0cf8b9.prepend("WHITESPACE").constData()+10), t0cf8b9.size()-10 }; });
}

struct QtCore_PackedString QUrl_QUrl_FromPercentEncoding(void* input)
{
	return ({ QByteArray t95c42a = QUrl::fromPercentEncoding(*static_cast<QByteArray*>(input)).toUtf8(); QtCore_PackedString { const_cast<char*>(t95c42a.prepend("WHITESPACE").constData()+10), t95c42a.size()-10 }; });
}

struct QtCore_PackedString QUrl_QUrl_IdnWhitelist()
{
	return ({ QByteArray t7d801d = QUrl::idnWhitelist().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(t7d801d.prepend("WHITESPACE").constData()+10), t7d801d.size()-10 }; });
}

struct QtCore_PackedString QUrl_QUrl_ToStringList(void* urls, long long options)
{
	return ({ QByteArray tc32440 = QUrl::toStringList(*static_cast<QList<QUrl>*>(urls), static_cast<QUrl::UrlFormattingOption>(options)).join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tc32440.prepend("WHITESPACE").constData()+10), tc32440.size()-10 }; });
}

void* QUrl_QUrl_FromEncoded(void* input, long long parsingMode)
{
	return new QUrl(QUrl::fromEncoded(*static_cast<QByteArray*>(input), static_cast<QUrl::ParsingMode>(parsingMode)));
}

void* QUrl_QUrl_FromLocalFile(struct QtCore_PackedString localFile)
{
	return new QUrl(QUrl::fromLocalFile(QString::fromUtf8(localFile.data, localFile.len)));
}

void* QUrl_QUrl_FromUserInput(struct QtCore_PackedString userInput)
{
	return new QUrl(QUrl::fromUserInput(QString::fromUtf8(userInput.data, userInput.len)));
}

void* QUrl_QUrl_FromUserInput2(struct QtCore_PackedString userInput, struct QtCore_PackedString workingDirectory, long long options)
{
	return new QUrl(QUrl::fromUserInput(QString::fromUtf8(userInput.data, userInput.len), QString::fromUtf8(workingDirectory.data, workingDirectory.len), static_cast<QUrl::UserInputResolutionOption>(options)));
}

void* QUrl_NewQUrl()
{
	return new QUrl();
}

void* QUrl_NewQUrl4(void* other)
{
	return new QUrl(*static_cast<QUrl*>(other));
}

void* QUrl_NewQUrl3(struct QtCore_PackedString url, long long parsingMode)
{
	return new QUrl(QString::fromUtf8(url.data, url.len), static_cast<QUrl::ParsingMode>(parsingMode));
}

void* QUrl_NewQUrl2(void* other)
{
	return new QUrl(*static_cast<QUrl*>(other));
}

void QUrl_Clear(void* ptr)
{
	static_cast<QUrl*>(ptr)->clear();
}

void QUrl_SetAuthority(void* ptr, struct QtCore_PackedString authority, long long mode)
{
	static_cast<QUrl*>(ptr)->setAuthority(QString::fromUtf8(authority.data, authority.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetFragment(void* ptr, struct QtCore_PackedString fragment, long long mode)
{
	static_cast<QUrl*>(ptr)->setFragment(QString::fromUtf8(fragment.data, fragment.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetHost(void* ptr, struct QtCore_PackedString host, long long mode)
{
	static_cast<QUrl*>(ptr)->setHost(QString::fromUtf8(host.data, host.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_QUrl_SetIdnWhitelist(struct QtCore_PackedString list)
{
	QUrl::setIdnWhitelist(QString::fromUtf8(list.data, list.len).split("¡¦!", QString::SkipEmptyParts));
}

void QUrl_SetPassword(void* ptr, struct QtCore_PackedString password, long long mode)
{
	static_cast<QUrl*>(ptr)->setPassword(QString::fromUtf8(password.data, password.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetPath(void* ptr, struct QtCore_PackedString path, long long mode)
{
	static_cast<QUrl*>(ptr)->setPath(QString::fromUtf8(path.data, path.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetPort(void* ptr, int port)
{
	static_cast<QUrl*>(ptr)->setPort(port);
}

void QUrl_SetQuery(void* ptr, struct QtCore_PackedString query, long long mode)
{
	static_cast<QUrl*>(ptr)->setQuery(QString::fromUtf8(query.data, query.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetQuery2(void* ptr, void* query)
{
	static_cast<QUrl*>(ptr)->setQuery(*static_cast<QUrlQuery*>(query));
}

void QUrl_SetScheme(void* ptr, struct QtCore_PackedString scheme)
{
	static_cast<QUrl*>(ptr)->setScheme(QString::fromUtf8(scheme.data, scheme.len));
}

void QUrl_SetUrl(void* ptr, struct QtCore_PackedString url, long long parsingMode)
{
	static_cast<QUrl*>(ptr)->setUrl(QString::fromUtf8(url.data, url.len), static_cast<QUrl::ParsingMode>(parsingMode));
}

void QUrl_SetUserInfo(void* ptr, struct QtCore_PackedString userInfo, long long mode)
{
	static_cast<QUrl*>(ptr)->setUserInfo(QString::fromUtf8(userInfo.data, userInfo.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_SetUserName(void* ptr, struct QtCore_PackedString userName, long long mode)
{
	static_cast<QUrl*>(ptr)->setUserName(QString::fromUtf8(userName.data, userName.len), static_cast<QUrl::ParsingMode>(mode));
}

void QUrl_Swap(void* ptr, void* other)
{
	static_cast<QUrl*>(ptr)->swap(*static_cast<QUrl*>(other));
}

void QUrl_DestroyQUrl(void* ptr)
{
	static_cast<QUrl*>(ptr)->~QUrl();
}

void* QUrl_ToEncoded(void* ptr, long long options)
{
	return new QByteArray(static_cast<QUrl*>(ptr)->toEncoded(static_cast<QUrl::UrlFormattingOption>(options)));
}

struct QtCore_PackedString QUrl_Authority(void* ptr, long long options)
{
	return ({ QByteArray t5a26fa = static_cast<QUrl*>(ptr)->authority(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t5a26fa.prepend("WHITESPACE").constData()+10), t5a26fa.size()-10 }; });
}

struct QtCore_PackedString QUrl_ErrorString(void* ptr)
{
	return ({ QByteArray t35c6dc = static_cast<QUrl*>(ptr)->errorString().toUtf8(); QtCore_PackedString { const_cast<char*>(t35c6dc.prepend("WHITESPACE").constData()+10), t35c6dc.size()-10 }; });
}

struct QtCore_PackedString QUrl_FileName(void* ptr, long long options)
{
	return ({ QByteArray t4c468f = static_cast<QUrl*>(ptr)->fileName(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t4c468f.prepend("WHITESPACE").constData()+10), t4c468f.size()-10 }; });
}

struct QtCore_PackedString QUrl_Fragment(void* ptr, long long options)
{
	return ({ QByteArray t754185 = static_cast<QUrl*>(ptr)->fragment(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t754185.prepend("WHITESPACE").constData()+10), t754185.size()-10 }; });
}

struct QtCore_PackedString QUrl_Host(void* ptr, long long options)
{
	return ({ QByteArray tf93546 = static_cast<QUrl*>(ptr)->host(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(tf93546.prepend("WHITESPACE").constData()+10), tf93546.size()-10 }; });
}

struct QtCore_PackedString QUrl_Password(void* ptr, long long options)
{
	return ({ QByteArray t55f068 = static_cast<QUrl*>(ptr)->password(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t55f068.prepend("WHITESPACE").constData()+10), t55f068.size()-10 }; });
}

struct QtCore_PackedString QUrl_Path(void* ptr, long long options)
{
	return ({ QByteArray t70ef65 = static_cast<QUrl*>(ptr)->path(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t70ef65.prepend("WHITESPACE").constData()+10), t70ef65.size()-10 }; });
}

struct QtCore_PackedString QUrl_Query(void* ptr, long long options)
{
	return ({ QByteArray t911c73 = static_cast<QUrl*>(ptr)->query(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t911c73.prepend("WHITESPACE").constData()+10), t911c73.size()-10 }; });
}

struct QtCore_PackedString QUrl_Scheme(void* ptr)
{
	return ({ QByteArray t862954 = static_cast<QUrl*>(ptr)->scheme().toUtf8(); QtCore_PackedString { const_cast<char*>(t862954.prepend("WHITESPACE").constData()+10), t862954.size()-10 }; });
}

struct QtCore_PackedString QUrl_ToDisplayString(void* ptr, long long options)
{
	return ({ QByteArray tb72fa5 = static_cast<QUrl*>(ptr)->toDisplayString(static_cast<QUrl::UrlFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(tb72fa5.prepend("WHITESPACE").constData()+10), tb72fa5.size()-10 }; });
}

struct QtCore_PackedString QUrl_ToLocalFile(void* ptr)
{
	return ({ QByteArray tdd5812 = static_cast<QUrl*>(ptr)->toLocalFile().toUtf8(); QtCore_PackedString { const_cast<char*>(tdd5812.prepend("WHITESPACE").constData()+10), tdd5812.size()-10 }; });
}

struct QtCore_PackedString QUrl_ToString(void* ptr, long long options)
{
	return ({ QByteArray tc0d7b7 = static_cast<QUrl*>(ptr)->toString(static_cast<QUrl::UrlFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(tc0d7b7.prepend("WHITESPACE").constData()+10), tc0d7b7.size()-10 }; });
}

struct QtCore_PackedString QUrl_TopLevelDomain(void* ptr, long long options)
{
	return ({ QByteArray t06da8f = static_cast<QUrl*>(ptr)->topLevelDomain(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t06da8f.prepend("WHITESPACE").constData()+10), t06da8f.size()-10 }; });
}

struct QtCore_PackedString QUrl_Url(void* ptr, long long options)
{
	return ({ QByteArray t2ea726 = static_cast<QUrl*>(ptr)->url(static_cast<QUrl::UrlFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(t2ea726.prepend("WHITESPACE").constData()+10), t2ea726.size()-10 }; });
}

struct QtCore_PackedString QUrl_UserInfo(void* ptr, long long options)
{
	return ({ QByteArray tff62a1 = static_cast<QUrl*>(ptr)->userInfo(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(tff62a1.prepend("WHITESPACE").constData()+10), tff62a1.size()-10 }; });
}

struct QtCore_PackedString QUrl_UserName(void* ptr, long long options)
{
	return ({ QByteArray tb9c277 = static_cast<QUrl*>(ptr)->userName(static_cast<QUrl::ComponentFormattingOption>(options)).toUtf8(); QtCore_PackedString { const_cast<char*>(tb9c277.prepend("WHITESPACE").constData()+10), tb9c277.size()-10 }; });
}

void* QUrl_Adjusted(void* ptr, long long options)
{
	return new QUrl(static_cast<QUrl*>(ptr)->adjusted(static_cast<QUrl::UrlFormattingOption>(options)));
}

void* QUrl_Resolved(void* ptr, void* relative)
{
	return new QUrl(static_cast<QUrl*>(ptr)->resolved(*static_cast<QUrl*>(relative)));
}

char QUrl_HasFragment(void* ptr)
{
	return static_cast<QUrl*>(ptr)->hasFragment();
}

char QUrl_HasQuery(void* ptr)
{
	return static_cast<QUrl*>(ptr)->hasQuery();
}

char QUrl_IsEmpty(void* ptr)
{
	return static_cast<QUrl*>(ptr)->isEmpty();
}

char QUrl_IsLocalFile(void* ptr)
{
	return static_cast<QUrl*>(ptr)->isLocalFile();
}

char QUrl_IsParentOf(void* ptr, void* childUrl)
{
	return static_cast<QUrl*>(ptr)->isParentOf(*static_cast<QUrl*>(childUrl));
}

char QUrl_IsRelative(void* ptr)
{
	return static_cast<QUrl*>(ptr)->isRelative();
}

char QUrl_IsValid(void* ptr)
{
	return static_cast<QUrl*>(ptr)->isValid();
}

char QUrl_Matches(void* ptr, void* url, long long options)
{
	return static_cast<QUrl*>(ptr)->matches(*static_cast<QUrl*>(url), static_cast<QUrl::UrlFormattingOption>(options));
}

int QUrl_Port(void* ptr, int defaultPort)
{
	return static_cast<QUrl*>(ptr)->port(defaultPort);
}

void* QUrl___fromStringList_atList(void* ptr, int i)
{
	return new QUrl(({QUrl tmp = static_cast<QList<QUrl>*>(ptr)->at(i); if (i == static_cast<QList<QUrl>*>(ptr)->size()-1) { static_cast<QList<QUrl>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QUrl___fromStringList_setList(void* ptr, void* i)
{
	static_cast<QList<QUrl>*>(ptr)->append(*static_cast<QUrl*>(i));
}

void* QUrl___fromStringList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QUrl>();
}

void* QUrl___toStringList_urls_atList(void* ptr, int i)
{
	return new QUrl(({QUrl tmp = static_cast<QList<QUrl>*>(ptr)->at(i); if (i == static_cast<QList<QUrl>*>(ptr)->size()-1) { static_cast<QList<QUrl>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QUrl___toStringList_urls_setList(void* ptr, void* i)
{
	static_cast<QList<QUrl>*>(ptr)->append(*static_cast<QUrl*>(i));
}

void* QUrl___toStringList_urls_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QUrl>();
}

void* QUrl___allEncodedQueryItemValues_atList(void* ptr, int i)
{
	return new QByteArray(({QByteArray tmp = static_cast<QList<QByteArray>*>(ptr)->at(i); if (i == static_cast<QList<QByteArray>*>(ptr)->size()-1) { static_cast<QList<QByteArray>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QUrl___allEncodedQueryItemValues_setList(void* ptr, void* i)
{
	static_cast<QList<QByteArray>*>(ptr)->append(*static_cast<QByteArray*>(i));
}

void* QUrl___allEncodedQueryItemValues_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QByteArray>();
}

Q_DECLARE_METATYPE(QUrlQuery)
Q_DECLARE_METATYPE(QUrlQuery*)
void* QUrlQuery_QUrlQuery_DefaultQueryPairDelimiter()
{
	return new QChar(QUrlQuery::defaultQueryPairDelimiter());
}

void* QUrlQuery_QUrlQuery_DefaultQueryValueDelimiter()
{
	return new QChar(QUrlQuery::defaultQueryValueDelimiter());
}

void* QUrlQuery_NewQUrlQuery()
{
	return new QUrlQuery();
}

void* QUrlQuery_NewQUrlQuery3(struct QtCore_PackedString queryString)
{
	return new QUrlQuery(QString::fromUtf8(queryString.data, queryString.len));
}

void* QUrlQuery_NewQUrlQuery2(void* url)
{
	return new QUrlQuery(*static_cast<QUrl*>(url));
}

void* QUrlQuery_NewQUrlQuery4(void* other)
{
	return new QUrlQuery(*static_cast<QUrlQuery*>(other));
}

void QUrlQuery_AddQueryItem(void* ptr, struct QtCore_PackedString key, struct QtCore_PackedString value)
{
	static_cast<QUrlQuery*>(ptr)->addQueryItem(QString::fromUtf8(key.data, key.len), QString::fromUtf8(value.data, value.len));
}

void QUrlQuery_Clear(void* ptr)
{
	static_cast<QUrlQuery*>(ptr)->clear();
}

void QUrlQuery_RemoveAllQueryItems(void* ptr, struct QtCore_PackedString key)
{
	static_cast<QUrlQuery*>(ptr)->removeAllQueryItems(QString::fromUtf8(key.data, key.len));
}

void QUrlQuery_RemoveQueryItem(void* ptr, struct QtCore_PackedString key)
{
	static_cast<QUrlQuery*>(ptr)->removeQueryItem(QString::fromUtf8(key.data, key.len));
}

void QUrlQuery_SetQuery(void* ptr, struct QtCore_PackedString queryString)
{
	static_cast<QUrlQuery*>(ptr)->setQuery(QString::fromUtf8(queryString.data, queryString.len));
}

void QUrlQuery_SetQueryDelimiters(void* ptr, void* valueDelimiter, void* pairDelimiter)
{
	static_cast<QUrlQuery*>(ptr)->setQueryDelimiters(*static_cast<QChar*>(valueDelimiter), *static_cast<QChar*>(pairDelimiter));
}

void QUrlQuery_Swap(void* ptr, void* other)
{
	static_cast<QUrlQuery*>(ptr)->swap(*static_cast<QUrlQuery*>(other));
}

void QUrlQuery_DestroyQUrlQuery(void* ptr)
{
	static_cast<QUrlQuery*>(ptr)->~QUrlQuery();
}

void* QUrlQuery_QueryPairDelimiter(void* ptr)
{
	return new QChar(static_cast<QUrlQuery*>(ptr)->queryPairDelimiter());
}

void* QUrlQuery_QueryValueDelimiter(void* ptr)
{
	return new QChar(static_cast<QUrlQuery*>(ptr)->queryValueDelimiter());
}

struct QtCore_PackedString QUrlQuery_Query(void* ptr, long long encoding)
{
	return ({ QByteArray tc70807 = static_cast<QUrlQuery*>(ptr)->query(static_cast<QUrl::ComponentFormattingOption>(encoding)).toUtf8(); QtCore_PackedString { const_cast<char*>(tc70807.prepend("WHITESPACE").constData()+10), tc70807.size()-10 }; });
}

struct QtCore_PackedString QUrlQuery_QueryItemValue(void* ptr, struct QtCore_PackedString key, long long encoding)
{
	return ({ QByteArray t5453a9 = static_cast<QUrlQuery*>(ptr)->queryItemValue(QString::fromUtf8(key.data, key.len), static_cast<QUrl::ComponentFormattingOption>(encoding)).toUtf8(); QtCore_PackedString { const_cast<char*>(t5453a9.prepend("WHITESPACE").constData()+10), t5453a9.size()-10 }; });
}

struct QtCore_PackedString QUrlQuery_ToString(void* ptr, long long encoding)
{
	return ({ QByteArray t13eb00 = static_cast<QUrlQuery*>(ptr)->toString(static_cast<QUrl::ComponentFormattingOption>(encoding)).toUtf8(); QtCore_PackedString { const_cast<char*>(t13eb00.prepend("WHITESPACE").constData()+10), t13eb00.size()-10 }; });
}

struct QtCore_PackedString QUrlQuery_AllQueryItemValues(void* ptr, struct QtCore_PackedString key, long long encoding)
{
	return ({ QByteArray tad6e07 = static_cast<QUrlQuery*>(ptr)->allQueryItemValues(QString::fromUtf8(key.data, key.len), static_cast<QUrl::ComponentFormattingOption>(encoding)).join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tad6e07.prepend("WHITESPACE").constData()+10), tad6e07.size()-10 }; });
}

char QUrlQuery_HasQueryItem(void* ptr, struct QtCore_PackedString key)
{
	return static_cast<QUrlQuery*>(ptr)->hasQueryItem(QString::fromUtf8(key.data, key.len));
}

char QUrlQuery_IsEmpty(void* ptr)
{
	return static_cast<QUrlQuery*>(ptr)->isEmpty();
}

Q_DECLARE_METATYPE(QUuid)
Q_DECLARE_METATYPE(QUuid*)
void* QUuid_QUuid_CreateUuid()
{
	return new QUuid(QUuid::createUuid());
}

void* QUuid_QUuid_CreateUuidV3(void* ns, void* baseData)
{
	return new QUuid(QUuid::createUuidV3(*static_cast<QUuid*>(ns), *static_cast<QByteArray*>(baseData)));
}

void* QUuid_QUuid_CreateUuidV32(void* ns, struct QtCore_PackedString baseData)
{
	return new QUuid(QUuid::createUuidV3(*static_cast<QUuid*>(ns), QString::fromUtf8(baseData.data, baseData.len)));
}

void* QUuid_QUuid_CreateUuidV5(void* ns, void* baseData)
{
	return new QUuid(QUuid::createUuidV5(*static_cast<QUuid*>(ns), *static_cast<QByteArray*>(baseData)));
}

void* QUuid_QUuid_CreateUuidV52(void* ns, struct QtCore_PackedString baseData)
{
	return new QUuid(QUuid::createUuidV5(*static_cast<QUuid*>(ns), QString::fromUtf8(baseData.data, baseData.len)));
}

void* QUuid_QUuid_FromRfc4122(void* bytes)
{
	return new QUuid(QUuid::fromRfc4122(*static_cast<QByteArray*>(bytes)));
}

void* QUuid_QUuid_FromString2(void* text)
{
	return new QUuid(QUuid::fromString(*static_cast<QLatin1String*>(text)));
}

void* QUuid_QUuid_FromString(void* text)
{
	return new QUuid(QUuid::fromString(*static_cast<QStringView*>(text)));
}

void* QUuid_NewQUuid()
{
	return new QUuid();
}

void* QUuid_NewQUuid6(void* text)
{
	return new QUuid(*static_cast<QByteArray*>(text));
}

void* QUuid_NewQUuid4(struct QtCore_PackedString text)
{
	return new QUuid(QString::fromUtf8(text.data, text.len));
}

void* QUuid_NewQUuid3(unsigned int l, unsigned short w1, unsigned short w2, char* b1, char* b2, char* b3, char* b4, char* b5, char* b6, char* b7, char* b8)
{
	return new QUuid(l, w1, w2, *static_cast<uchar*>(static_cast<void*>(b1)), *static_cast<uchar*>(static_cast<void*>(b2)), *static_cast<uchar*>(static_cast<void*>(b3)), *static_cast<uchar*>(static_cast<void*>(b4)), *static_cast<uchar*>(static_cast<void*>(b5)), *static_cast<uchar*>(static_cast<void*>(b6)), *static_cast<uchar*>(static_cast<void*>(b7)), *static_cast<uchar*>(static_cast<void*>(b8)));
}

void* QUuid_ToByteArray(void* ptr)
{
	return new QByteArray(static_cast<QUuid*>(ptr)->toByteArray());
}

void* QUuid_ToByteArray2(void* ptr, long long mode)
{
	return new QByteArray(static_cast<QUuid*>(ptr)->toByteArray(static_cast<QUuid::StringFormat>(mode)));
}

void* QUuid_ToRfc4122(void* ptr)
{
	return new QByteArray(static_cast<QUuid*>(ptr)->toRfc4122());
}

struct QtCore_PackedString QUuid_ToString(void* ptr)
{
	return ({ QByteArray t6f28ec = static_cast<QUuid*>(ptr)->toString().toUtf8(); QtCore_PackedString { const_cast<char*>(t6f28ec.prepend("WHITESPACE").constData()+10), t6f28ec.size()-10 }; });
}

struct QtCore_PackedString QUuid_ToString2(void* ptr, long long mode)
{
	return ({ QByteArray taf9869 = static_cast<QUuid*>(ptr)->toString(static_cast<QUuid::StringFormat>(mode)).toUtf8(); QtCore_PackedString { const_cast<char*>(taf9869.prepend("WHITESPACE").constData()+10), taf9869.size()-10 }; });
}

long long QUuid_Variant(void* ptr)
{
	return static_cast<QUuid*>(ptr)->variant();
}

long long QUuid_Version(void* ptr)
{
	return static_cast<QUuid*>(ptr)->version();
}

char QUuid_IsNull(void* ptr)
{
	return static_cast<QUuid*>(ptr)->isNull();
}

unsigned int QUuid_Data1(void* ptr)
{
	return static_cast<QUuid*>(ptr)->data1;
}

void QUuid_SetData1(void* ptr, unsigned int vui)
{
	static_cast<QUuid*>(ptr)->data1 = vui;
}

unsigned short QUuid_Data2(void* ptr)
{
	return static_cast<QUuid*>(ptr)->data2;
}

void QUuid_SetData2(void* ptr, unsigned short vus)
{
	static_cast<QUuid*>(ptr)->data2 = vus;
}

unsigned short QUuid_Data3(void* ptr)
{
	return static_cast<QUuid*>(ptr)->data3;
}

Q_DECLARE_METATYPE(QVariant*)
void* QVariant_NewQVariant()
{
	return new QVariant();
}

void* QVariant_NewQVariant20(void* c)
{
	return new QVariant(*static_cast<QChar*>(c));
}

void* QVariant_NewQVariant6(void* s)
{
	return new QVariant(*static_cast<QDataStream*>(s));
}

void* QVariant_NewQVariant18(void* val)
{
	return new QVariant(*static_cast<QLatin1String*>(val));
}

void* QVariant_NewQVariant47(void* other)
{
	return new QVariant(*static_cast<QVariant*>(other));
}

void* QVariant_NewQVariant2(long long ty)
{
	return new QVariant(static_cast<QVariant::Type>(ty));
}

void* QVariant_NewQVariant11(char val)
{
	return new QVariant(val != 0);
}

void* QVariant_NewQVariant16(void* val)
{
	return new QVariant(*static_cast<QBitArray*>(val));
}

void* QVariant_NewQVariant15(void* val)
{
	return new QVariant(*static_cast<QByteArray*>(val));
}

void* QVariant_NewQVariant21(void* val)
{
	return new QVariant(*static_cast<QDate*>(val));
}

void* QVariant_NewQVariant23(void* val)
{
	return new QVariant(*static_cast<QDateTime*>(val));
}

void* QVariant_NewQVariant39(void* val)
{
	return new QVariant(*static_cast<QEasingCurve*>(val));
}

void* QVariant_NewQVariant26(void* val)
{
	return new QVariant(*static_cast<QHash<QString, QVariant>*>(val));
}

void* QVariant_NewQVariant43(void* val)
{
	return new QVariant(*static_cast<QJsonArray*>(val));
}

void* QVariant_NewQVariant44(void* val)
{
	return new QVariant(*static_cast<QJsonDocument*>(val));
}

void* QVariant_NewQVariant42(void* val)
{
	return new QVariant(*static_cast<QJsonObject*>(val));
}

void* QVariant_NewQVariant41(void* val)
{
	return new QVariant(*static_cast<QJsonValue*>(val));
}

void* QVariant_NewQVariant31(void* val)
{
	return new QVariant(*static_cast<QLine*>(val));
}

void* QVariant_NewQVariant32(void* val)
{
	return new QVariant(*static_cast<QLineF*>(val));
}

void* QVariant_NewQVariant24(void* val)
{
	return new QVariant(*static_cast<QList<QVariant>*>(val));
}

void* QVariant_NewQVariant35(void* l)
{
	return new QVariant(*static_cast<QLocale*>(l));
}

void* QVariant_NewQVariant25(void* val)
{
	return new QVariant(*static_cast<QMap<QString, QVariant>*>(val));
}

void* QVariant_NewQVariant45(void* val)
{
	return new QVariant(*static_cast<QModelIndex*>(val));
}

void* QVariant_NewQVariant46(void* val)
{
	return new QVariant(*static_cast<QPersistentModelIndex*>(val));
}

void* QVariant_NewQVariant29(void* val)
{
	return new QVariant(*static_cast<QPoint*>(val));
}

void* QVariant_NewQVariant30(void* val)
{
	return new QVariant(*static_cast<QPointF*>(val));
}

void* QVariant_NewQVariant33(void* val)
{
	return new QVariant(*static_cast<QRect*>(val));
}

void* QVariant_NewQVariant34(void* val)
{
	return new QVariant(*static_cast<QRectF*>(val));
}

void* QVariant_NewQVariant36(void* regExp)
{
	return new QVariant(*static_cast<QRegExp*>(regExp));
}

void* QVariant_NewQVariant37(void* re)
{
	return new QVariant(*static_cast<QRegularExpression*>(re));
}

void* QVariant_NewQVariant27(void* val)
{
	return new QVariant(*static_cast<QSize*>(val));
}

void* QVariant_NewQVariant28(void* val)
{
	return new QVariant(*static_cast<QSizeF*>(val));
}

void* QVariant_NewQVariant17(struct QtCore_PackedString val)
{
	return new QVariant(QString::fromUtf8(val.data, val.len));
}

void* QVariant_NewQVariant19(struct QtCore_PackedString val)
{
	return new QVariant(QString::fromUtf8(val.data, val.len).split("¡¦!", QString::SkipEmptyParts));
}

void* QVariant_NewQVariant22(void* val)
{
	return new QVariant(*static_cast<QTime*>(val));
}

void* QVariant_NewQVariant38(void* val)
{
	return new QVariant(*static_cast<QUrl*>(val));
}

void* QVariant_NewQVariant40(void* val)
{
	return new QVariant(*static_cast<QUuid*>(val));
}

void* QVariant_NewQVariant5(void* p)
{
	return new QVariant(*static_cast<QVariant*>(p));
}

void* QVariant_NewQVariant14(char* val)
{
	return new QVariant(const_cast<const char*>(val));
}

void* QVariant_NewQVariant12(double val)
{
	return new QVariant(val);
}

void* QVariant_NewQVariant13(float val)
{
	return new QVariant(val);
}

void* QVariant_NewQVariant3(int typeId, void* copy)
{
	return new QVariant(typeId, copy);
}

void* QVariant_NewQVariant7(int val)
{
	return new QVariant(val);
}

void* QVariant_NewQVariant9(long long val)
{
	return new QVariant(val);
}

void* QVariant_NewQVariant10(unsigned long long val)
{
	return new QVariant(val);
}

void* QVariant_NewQVariant8(unsigned int val)
{
	return new QVariant(val);
}

long long QVariant_QVariant_NameToType(char* name)
{
	return QVariant::nameToType(const_cast<const char*>(name));
}

char QVariant_Convert(void* ptr, int targetTypeId)
{
	return static_cast<QVariant*>(ptr)->convert(targetTypeId);
}

struct QtCore_PackedString QVariant_QVariant_TypeToName(int typeId)
{
	return QtCore_PackedString { const_cast<char*>(QVariant::typeToName(typeId)), typeId };
}

void QVariant_Clear(void* ptr)
{
	static_cast<QVariant*>(ptr)->clear();
}

void QVariant_Swap(void* ptr, void* other)
{
	static_cast<QVariant*>(ptr)->swap(*static_cast<QVariant*>(other));
}

void QVariant_DestroyQVariant(void* ptr)
{
	static_cast<QVariant*>(ptr)->~QVariant();
}

void* QVariant_ToBitArray(void* ptr)
{
	return new QBitArray(static_cast<QVariant*>(ptr)->toBitArray());
}

void* QVariant_ToByteArray(void* ptr)
{
	return new QByteArray(static_cast<QVariant*>(ptr)->toByteArray());
}

void* QVariant_ToChar(void* ptr)
{
	return new QChar(static_cast<QVariant*>(ptr)->toChar());
}

void* QVariant_ToDate(void* ptr)
{
	return new QDate(static_cast<QVariant*>(ptr)->toDate());
}

void* QVariant_ToDateTime(void* ptr)
{
	return new QDateTime(static_cast<QVariant*>(ptr)->toDateTime());
}

void* QVariant_ToEasingCurve(void* ptr)
{
	return new QEasingCurve(static_cast<QVariant*>(ptr)->toEasingCurve());
}

struct QtCore_PackedList QVariant_ToHash(void* ptr)
{
	return ({ QHash<QString, QVariant>* tmpValue00701e = new QHash<QString, QVariant>(static_cast<QVariant*>(ptr)->toHash()); QtCore_PackedList { tmpValue00701e, tmpValue00701e->size() }; });
}

void* QVariant_ToJsonArray(void* ptr)
{
	return new QJsonArray(static_cast<QVariant*>(ptr)->toJsonArray());
}

void* QVariant_ToJsonDocument(void* ptr)
{
	return new QJsonDocument(static_cast<QVariant*>(ptr)->toJsonDocument());
}

void* QVariant_ToJsonObject(void* ptr)
{
	return new QJsonObject(static_cast<QVariant*>(ptr)->toJsonObject());
}

void* QVariant_ToJsonValue(void* ptr)
{
	return new QJsonValue(static_cast<QVariant*>(ptr)->toJsonValue());
}

void* QVariant_ToLine(void* ptr)
{
	return ({ QLine tmpValue = static_cast<QVariant*>(ptr)->toLine(); new QLine(tmpValue.p1(), tmpValue.p2()); });
}

void* QVariant_ToLineF(void* ptr)
{
	return ({ QLineF tmpValue = static_cast<QVariant*>(ptr)->toLineF(); new QLineF(tmpValue.p1(), tmpValue.p2()); });
}

struct QtCore_PackedList QVariant_ToList(void* ptr)
{
	return ({ QList<QVariant>* tmpValue8f6950 = new QList<QVariant>(static_cast<QVariant*>(ptr)->toList()); QtCore_PackedList { tmpValue8f6950, tmpValue8f6950->size() }; });
}

void* QVariant_ToLocale(void* ptr)
{
	return new QLocale(static_cast<QVariant*>(ptr)->toLocale());
}

struct QtCore_PackedList QVariant_ToMap(void* ptr)
{
	return ({ QMap<QString, QVariant>* tmpValue1e0d76 = new QMap<QString, QVariant>(static_cast<QVariant*>(ptr)->toMap()); QtCore_PackedList { tmpValue1e0d76, tmpValue1e0d76->size() }; });
}

void* QVariant_ToModelIndex(void* ptr)
{
	return new QModelIndex(static_cast<QVariant*>(ptr)->toModelIndex());
}

void* QVariant_ToPersistentModelIndex(void* ptr)
{
	return new QPersistentModelIndex(static_cast<QVariant*>(ptr)->toPersistentModelIndex());
}

void* QVariant_ToPoint(void* ptr)
{
	return ({ QPoint tmpValue = static_cast<QVariant*>(ptr)->toPoint(); new QPoint(tmpValue.x(), tmpValue.y()); });
}

void* QVariant_ToPointF(void* ptr)
{
	return ({ QPointF tmpValue = static_cast<QVariant*>(ptr)->toPointF(); new QPointF(tmpValue.x(), tmpValue.y()); });
}

void* QVariant_ToRect(void* ptr)
{
	return ({ QRect tmpValue = static_cast<QVariant*>(ptr)->toRect(); new QRect(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QVariant_ToRectF(void* ptr)
{
	return ({ QRectF tmpValue = static_cast<QVariant*>(ptr)->toRectF(); new QRectF(tmpValue.x(), tmpValue.y(), tmpValue.width(), tmpValue.height()); });
}

void* QVariant_ToRegExp(void* ptr)
{
	return new QRegExp(static_cast<QVariant*>(ptr)->toRegExp());
}

void* QVariant_ToRegularExpression(void* ptr)
{
	return new QRegularExpression(static_cast<QVariant*>(ptr)->toRegularExpression());
}

void* QVariant_ToSize(void* ptr)
{
	return ({ QSize tmpValue = static_cast<QVariant*>(ptr)->toSize(); new QSize(tmpValue.width(), tmpValue.height()); });
}

void* QVariant_ToSizeF(void* ptr)
{
	return ({ QSizeF tmpValue = static_cast<QVariant*>(ptr)->toSizeF(); new QSizeF(tmpValue.width(), tmpValue.height()); });
}

struct QtCore_PackedString QVariant_ToString(void* ptr)
{
	return ({ QByteArray tf9e1e4 = static_cast<QVariant*>(ptr)->toString().toUtf8(); QtCore_PackedString { const_cast<char*>(tf9e1e4.prepend("WHITESPACE").constData()+10), tf9e1e4.size()-10 }; });
}

struct QtCore_PackedString QVariant_ToStringList(void* ptr)
{
	return ({ QByteArray tf99cb6 = static_cast<QVariant*>(ptr)->toStringList().join("¡¦!").toUtf8(); QtCore_PackedString { const_cast<char*>(tf99cb6.prepend("WHITESPACE").constData()+10), tf99cb6.size()-10 }; });
}

void* QVariant_ToTime(void* ptr)
{
	return new QTime(static_cast<QVariant*>(ptr)->toTime());
}

void* QVariant_ToUrl(void* ptr)
{
	return new QUrl(static_cast<QVariant*>(ptr)->toUrl());
}

void* QVariant_ToUuid(void* ptr)
{
	return new QUuid(static_cast<QVariant*>(ptr)->toUuid());
}

long long QVariant_Type(void* ptr)
{
	return static_cast<QVariant*>(ptr)->type();
}

char QVariant_CanConvert(void* ptr, int targetTypeId)
{
	return static_cast<QVariant*>(ptr)->canConvert(targetTypeId);
}

char QVariant_IsNull(void* ptr)
{
	return static_cast<QVariant*>(ptr)->isNull();
}

char QVariant_IsValid(void* ptr)
{
	return static_cast<QVariant*>(ptr)->isValid();
}

char QVariant_ToBool(void* ptr)
{
	return static_cast<QVariant*>(ptr)->toBool();
}

struct QtCore_PackedString QVariant_TypeName(void* ptr)
{
	return QtCore_PackedString { const_cast<char*>(static_cast<QVariant*>(ptr)->typeName()), -1 };
}

double QVariant_ToDouble(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toDouble(reinterpret_cast<bool*>(ok));
}

float QVariant_ToFloat(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toFloat(reinterpret_cast<bool*>(ok));
}

int QVariant_ToInt(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toInt(reinterpret_cast<bool*>(ok));
}

int QVariant_UserType(void* ptr)
{
	return static_cast<QVariant*>(ptr)->userType();
}

long long QVariant_ToLongLong(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toLongLong(reinterpret_cast<bool*>(ok));
}

double QVariant_ToReal(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toReal(reinterpret_cast<bool*>(ok));
}

unsigned long long QVariant_ToULongLong(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toULongLong(reinterpret_cast<bool*>(ok));
}

unsigned int QVariant_ToUInt(void* ptr, char* ok)
{
	return static_cast<QVariant*>(ptr)->toUInt(reinterpret_cast<bool*>(ok));
}

void* QVariant_ToColor(void* ptr)
{
	return new QColor(qvariant_cast<QColor>(*static_cast<QVariant*>(ptr)));
}

void* QVariant_ToFont(void* ptr)
{
	return new QFont(qvariant_cast<QFont>(*static_cast<QVariant*>(ptr)));
}

void* QVariant_ToImage(void* ptr)
{
	return new QImage(qvariant_cast<QImage>(*static_cast<QVariant*>(ptr)));
}

void* QVariant_ToObject(void* ptr)
{
	return qvariant_cast<QObject*>(*static_cast<QVariant*>(ptr));
}

void* QVariant_ToIcon(void* ptr)
{
	return new QIcon(qvariant_cast<QIcon>(*static_cast<QVariant*>(ptr)));
}

void* QVariant_ToBrush(void* ptr)
{
	return new QBrush(qvariant_cast<QBrush>(*static_cast<QVariant*>(ptr)));
}

void* QVariant___QVariant_val_atList26(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QHash<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QHash<QString, QVariant>*>(ptr)->size()-1) { static_cast<QHash<QString, QVariant>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QVariant___QVariant_val_setList26(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QHash<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QVariant___QVariant_val_newList26(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<QString, QVariant>();
}

struct QtCore_PackedList QVariant___QVariant_val_keyList26(void* ptr)
{
	return ({ QList<QString>* tmpValuef43bc5 = new QList<QString>(static_cast<QHash<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValuef43bc5, tmpValuef43bc5->size() }; });
}

void* QVariant___QVariant_val_atList24(void* ptr, int i)
{
	return new QVariant(({QVariant tmp = static_cast<QList<QVariant>*>(ptr)->at(i); if (i == static_cast<QList<QVariant>*>(ptr)->size()-1) { static_cast<QList<QVariant>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QVariant___QVariant_val_setList24(void* ptr, void* i)
{
	static_cast<QList<QVariant>*>(ptr)->append(*static_cast<QVariant*>(i));
}

void* QVariant___QVariant_val_newList24(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QVariant>();
}

void* QVariant___QVariant_val_atList25(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QMap<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QMap<QString, QVariant>*>(ptr)->size()-1) { static_cast<QMap<QString, QVariant>*>(ptr)->~QMap(); free(ptr); }; tmp; }));
}

void QVariant___QVariant_val_setList25(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QMap<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QVariant___QVariant_val_newList25(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<QString, QVariant>();
}

struct QtCore_PackedList QVariant___QVariant_val_keyList25(void* ptr)
{
	return ({ QList<QString>* tmpValue1ab909 = new QList<QString>(static_cast<QMap<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValue1ab909, tmpValue1ab909->size() }; });
}

void* QVariant___toHash_atList(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QHash<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QHash<QString, QVariant>*>(ptr)->size()-1) { static_cast<QHash<QString, QVariant>*>(ptr)->~QHash(); free(ptr); }; tmp; }));
}

void QVariant___toHash_setList(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QHash<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QVariant___toHash_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QHash<QString, QVariant>();
}

struct QtCore_PackedList QVariant___toHash_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValuef43bc5 = new QList<QString>(static_cast<QHash<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValuef43bc5, tmpValuef43bc5->size() }; });
}

void* QVariant___toList_atList(void* ptr, int i)
{
	return new QVariant(({QVariant tmp = static_cast<QList<QVariant>*>(ptr)->at(i); if (i == static_cast<QList<QVariant>*>(ptr)->size()-1) { static_cast<QList<QVariant>*>(ptr)->~QList(); free(ptr); }; tmp; }));
}

void QVariant___toList_setList(void* ptr, void* i)
{
	static_cast<QList<QVariant>*>(ptr)->append(*static_cast<QVariant*>(i));
}

void* QVariant___toList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QVariant>();
}

void* QVariant___toMap_atList(void* ptr, struct QtCore_PackedString v, int i)
{
	return new QVariant(({ QVariant tmp = static_cast<QMap<QString, QVariant>*>(ptr)->value(QString::fromUtf8(v.data, v.len)); if (i == static_cast<QMap<QString, QVariant>*>(ptr)->size()-1) { static_cast<QMap<QString, QVariant>*>(ptr)->~QMap(); free(ptr); }; tmp; }));
}

void QVariant___toMap_setList(void* ptr, struct QtCore_PackedString key, void* i)
{
	static_cast<QMap<QString, QVariant>*>(ptr)->insert(QString::fromUtf8(key.data, key.len), *static_cast<QVariant*>(i));
}

void* QVariant___toMap_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QMap<QString, QVariant>();
}

struct QtCore_PackedList QVariant___toMap_keyList(void* ptr)
{
	return ({ QList<QString>* tmpValue1ab909 = new QList<QString>(static_cast<QMap<QString, QVariant>*>(ptr)->keys()); QtCore_PackedList { tmpValue1ab909, tmpValue1ab909->size() }; });
}

struct QtCore_PackedString QVariant_____QVariant_val_keyList_atList26(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QVariant_____QVariant_val_keyList_setList26(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QVariant_____QVariant_val_keyList_newList26(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QVariant_____QVariant_val_keyList_atList25(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QVariant_____QVariant_val_keyList_setList25(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QVariant_____QVariant_val_keyList_newList25(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QVariant_____toHash_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QVariant_____toHash_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QVariant_____toHash_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

struct QtCore_PackedString QVariant_____toMap_keyList_atList(void* ptr, int i)
{
	return ({ QByteArray t94aa5e = ({QString tmp = static_cast<QList<QString>*>(ptr)->at(i); if (i == static_cast<QList<QString>*>(ptr)->size()-1) { static_cast<QList<QString>*>(ptr)->~QList(); free(ptr); }; tmp; }).toUtf8(); QtCore_PackedString { const_cast<char*>(t94aa5e.prepend("WHITESPACE").constData()+10), t94aa5e.size()-10 }; });
}

void QVariant_____toMap_keyList_setList(void* ptr, struct QtCore_PackedString i)
{
	static_cast<QList<QString>*>(ptr)->append(QString::fromUtf8(i.data, i.len));
}

void* QVariant_____toMap_keyList_newList(void* ptr)
{
	Q_UNUSED(ptr);
	return new QList<QString>();
}

int Qt_LastGestureType_Type()
{
	return Qt::LastGestureType;
}

struct QtCore_PackedString Qt_Qt_ConvertFromPlainText(struct QtCore_PackedString plain, long long mode)
{
	return ({ QByteArray t896db1 = Qt::convertFromPlainText(QString::fromUtf8(plain.data, plain.len), static_cast<Qt::WhiteSpaceMode>(mode)).toUtf8(); QtCore_PackedString { const_cast<char*>(t896db1.prepend("WHITESPACE").constData()+10), t896db1.size()-10 }; });
}

char Qt_Qt_MightBeRichText(struct QtCore_PackedString text)
{
	return Qt::mightBeRichText(QString::fromUtf8(text.data, text.len));
}

