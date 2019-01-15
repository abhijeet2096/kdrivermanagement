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
#include "deviceenumerator.h"

namespace KDriverManagement
{

// Class Constructor
DeviceEnumerator::DeviceEnumerator(QObject *parent)
    : QObject(parent)
    , m_ldm_device_manager(ldm_manager_new(LDM_MANAGER_FLAGS_NONE))
{
    // Get Devices from LDM
    g_autoptr(GPtrArray) devices = ldm_manager_get_devices(m_ldm_device_manager, LDM_DEVICE_TYPE_ANY);
    // Populate Class Device List 
    for(uint i = 0; i < devices->len; i++)
    {
        m_ldm_device_list.append((LdmDevice*)devices->pdata[i]);
    }
}

}