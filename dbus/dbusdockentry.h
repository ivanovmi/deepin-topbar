/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusDockEntry -p dbusdockentry dde-dock-entry-v1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSDOCKENTRY_H_1464922075
#define DBUSDOCKENTRY_H_1464922075

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

#include <QX11Info>

typedef QMap<quint32, QString> WindowDict;

/*
 * Proxy class for interface dde.dock.Entry
 */
class DBusDockEntry: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.dde.daemon.Dock.Entry")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
                Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.dde.daemon.Dock.Entry"; }

public:
    explicit DBusDockEntry(const QString &path, QObject *parent = 0);

    ~DBusDockEntry();

    Q_PROPERTY(bool IsActive READ active NOTIFY ActiveChanged)
    inline bool active() const
    { return qvariant_cast< bool >(property("IsActive")); }

    Q_PROPERTY(WindowDict WindowTitles READ titles NOTIFY TitlesChanged)
    inline WindowDict titles() const
    { return qvariant_cast< WindowDict >(property("WindowTitles")); }

    Q_PROPERTY(QString Id READ id NOTIFY IdChanged)
    inline QString id() const
    { return qvariant_cast< QString >(property("Id")); }

    Q_PROPERTY(QString Icon READ icon NOTIFY IconChanged)
    inline QString icon() const
    { return qvariant_cast< QString >(property("Icon")); }

    Q_PROPERTY(QString Menu READ menu NOTIFY MenuChanged)
    inline QString menu() const
    { return qvariant_cast< QString >(property("Menu")); }

    Q_PROPERTY(QString Name READ name NOTIFY NameChanged)
    inline QString name() const
    { return qvariant_cast< QString >(property("Name")); }

    Q_PROPERTY(quint32 CurrentWindow READ currentWindow NOTIFY CurrentWindowChanged)
    inline quint32 currentWindow() const
    { return qvariant_cast< quint32 >(property("CurrentWindow")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Activate()
    {
        QList<QVariant> argumentList;

        argumentList << QVariant::fromValue(quint32(QX11Info::getTimestamp()));

        return asyncCallWithArgumentList(QStringLiteral("Activate"), argumentList);
    }

    inline QDBusPendingReply<> NewInstance()
    {
        QList<QVariant> argumentList;

        argumentList << QVariant::fromValue(quint32(QX11Info::getTimestamp()));

        return asyncCallWithArgumentList(QStringLiteral("NewInstance"), argumentList);
    }

    inline QDBusPendingReply<> HandleMenuItem(const QString &item)
    {
        return asyncCall(QStringLiteral("HandleMenuItem"), QVariant::fromValue(quint32(QX11Info::getTimestamp())), item);
    }

    inline QDBusPendingReply<> HandleDragDrop(const QStringList &uriList)
    {
        return asyncCall(QStringLiteral("HandleDragDrop"), QVariant::fromValue(quint32(QX11Info::getTimestamp())), QVariant::fromValue(uriList));
    }

    inline QDBusPendingReply<> RequestDock()
    {
        return asyncCall(QStringLiteral("RequestDock"));
    }

    inline QDBusPendingReply<> Check()
    {
        return asyncCall(QStringLiteral("Check"));
    }

    inline QDBusPendingReply<> ForceQuit()
    {
        return asyncCall(QStringLiteral("ForceQuit"));
    }

    inline QDBusPendingReply<> RequestUndock()
    {
        return asyncCall(QStringLiteral("RequestUndock"));
    }

    inline QDBusPendingReply<> PresentWindows()
    {
        return asyncCall(QStringLiteral("PresentWindows"));
    }

Q_SIGNALS: // SIGNALS
// begin property changed signals
void ActiveChanged();
void TitlesChanged();
void DataChanged();
void IdChanged();
void TitleChanged();
void IconChanged();
void MenuChanged();
void NameChanged();
void CurrentWindowChanged();
};

namespace dde {
  namespace dock {
    typedef ::DBusDockEntry Entry;
  }
}
#endif
