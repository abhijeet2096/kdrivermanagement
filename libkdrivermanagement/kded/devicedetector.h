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
#ifndef DEVICEDETECTOR_H
#define DEVICEDETECTOR_H

#include <kdedmodule.h>

namespace KDriverManagement
{
class DeviceEnumerator;
class SuitableDriver;
}

class DeviceDetector : public KDEDModule
{
    Q_OBJECT
public:
    DeviceDetector(QObject* parent, , const QList<QVariant> &);

public_Q_SLOTS:
    void sendDevice();

private:
    void resetDetector();

    KDriverManagement::DeviceEnumerator *m_enumerator = nullptr;
    KDriverManagement::SuitableDriver *m_suitabledriver = nullptr;
};

#endif // DEVICEDETECTOR_H