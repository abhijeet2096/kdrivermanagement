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

#ifndef KDRIVERMANAGEMENTPLUGIN_H
#define KDRIVERMANAGEMENTPLUGIN_H

#include <QQmlExtensionPlugin>

namespace KDriverManagement
{

class KDriverManagementPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

private:
    void registerTypes(const char *uri) override;
};

}

#endif // KDRIVERMANAGEMENTPLUGIN_H
