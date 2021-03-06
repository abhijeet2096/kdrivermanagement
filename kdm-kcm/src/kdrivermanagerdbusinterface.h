/*
    Copyright (C) 2018 Abhijeet Sharma <sharma.abhijeet2096@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KDM_DBUS_INTERFACE_H
#define KDM_DBUS_INTERFACE_H

#include <QObject>
#include <QtDBus>


namespace KDM
{
    
class Manager;

class KDriverManagerDBusInterface : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdm.KDriverManager")

public:
    explicit KDriverManagerDBusInterface(Manager *parent);
    virtual ~KDriverManagerDBusInterface() = default;

public Q_SLOTS:
    /**
     * @brief For receiving new device updates, primarily through the KDE Daemon
     * @return void
     **/
    void deviceListAutoUpdate(QHash<QString, QVariant> data);

Q_SIGNALS:

    void deviceListChanged(QHash<QString, QVariant> data);

private:
    Manager *m_manager;
};

}

#endif // KDM_DBUS_INTERFACE_H
