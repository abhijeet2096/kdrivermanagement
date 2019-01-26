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

#include "Module.h"
#include "KDriverWidget.h"

#include <QDebug>
#include <QDir>
#include <QLabel>
#include <QUuid>
#include <QStringBuilder>

#include <KAboutData>
#include <KConfig>
#include <KConfigGroup>
#include <KLocalizedString>
#include <KPluginFactory>
#include <KMessageBox>
#include <KMessageWidget>
#include <KPixmapSequenceOverlayPainter>

#include "ui_Module.h"
#include "Version.h"

K_PLUGIN_FACTORY_DECLARATION(KcmDriverFactory);

Module::Module(QWidget *parent, const QVariantList &args)
    : KCModule(parent, args)
    , ui(new Ui::Module)
{
    KAboutData *aboutData = new KAboutData("KDriverManager",
                                    i18n("Driver Manager"),
                                    global_s_versionStringFull,
                                    QStringLiteral(""),
                                    KAboutLicense::LicenseKey::GPL_V3,
                                    i18n("Copyright 2018 Abhijeet Sharma"));
    aboutData->addAuthor(i18n("Abhijeet Sharma"), i18n("Author"), QStringLiteral("sharma.abhijeet2096@gmail.com")); 
    setAboutData(aboutData);
    ui->setupUi(this);
    ui->progressBar->setVisible(false);

    m_overlay = new KPixmapSequenceOverlayPainter(this);
    m_overlay->setWidget(this);

}

Module::~Module()
{
    delete ui;
}

void Module::load()
{
    m_overlay->start();
    ui->messageWidget->setMessageType(KMessageWidget::Information);
    ui->messageWidget->setText(i18nc("The backend is trying to figure out what drivers are suitable for the users system",
                                     "Collecting information about your system"));
    ui->messageWidget->animatedShow();

}

void Module::save()
{

}

void Module::defaults()
{
    load();
}
