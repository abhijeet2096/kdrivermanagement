/********************************************************************
Copyright 2018 Abhijeet Sharma <sharma.abhijeet2096@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/
#ifndef KDRIVERMANAGEMENT_DEVICEENUMERATOR_H
#define KDRIVERMANAGEMENT_DEVICEENUMERATOR_H

#include <QObject>
#include "kdrivermanagement_export.h"
#include "kdrivermanagementconstants.h"

extern "C" {
#include <ldm.h>
}

class QDBusInterface;

namespace KDriverManagement
{

class KDRIVERMANAGEMENT_EXPORT DeviceEnumerator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool running READ running NOTIFY runningChanged)

public:
    explicit DeviceEnumerator(QObject *parent = nullptr);
    ~DeviceEnumerator() override = default;

    bool running() const {
        return m_running;
    }

public Q_SLOTS:

Q_SIGNALS:

    void dataUpdated();
    void runningChanged();

private:
    bool m_running = false;

    LdmManager *m_ldm_device_manager;
    QList<LdmDevice*> m_ldm_device_list;
    QDBusInterface *m_iface;
    
    void UpdateDeviceList();

};

}

#endif // KDRIVERMANAGEMENT_DEVICEENUMERATOR_H
