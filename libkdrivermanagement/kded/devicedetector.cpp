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
#include "devicedetector.h"

#include <KPluginFactory>
#include <KPluginLoader>

#include "../deviceenumerator.h"
#include "../suitabledriver.h"

K_PLUGIN_FACTORY_WITH_JSON(DeviceDetectorFactory,
                           "kdrivermanagementdevicedetector.json",
                           registerPlugin<DeviceDetector>();)

DeviceDetector::DeviceDetector(QObject *parent, const QList<QVariant> &)
{
    m_enumerator = new KDriverManagement::DeviceEnumerator(this);
    connect(m_enumerator,&KDriverManagement::DeviceEnumerator::dataUpdated, this
            &DeviceDetector::resetDetector);
    resetDetector();
}

void DeviceDetector::resetDetector()
{

}

void DeviceDetector::sendDevice()
{
    
}

#include "devicedetector.moc"