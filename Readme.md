# KDriverManager {K.D.M} [Under-Development](https://github.com/abhijeet2096/kdrivermanager)
Distro Independent Driver management Solution

## Introduction
Kdrivermanager is aimed to provide  distro independent driver management solution for KDE Plasma.  

The Kdrivermanager uses [linux-driver-management(https://github.com/solus-project/linux-driver-management) for device enumeration, hotplug capablities and device abstraction. Intial Proposal can be found [here](Discover_ldm-integration.pdf)


## Brief Overview

1. [**kdm-daemon**](./kdm-daemon) is a [KDED](https://api.kde.org/frameworks/kded/html/index.html) module to listen for new devices and able to suggest suitable driver on the go.

2. [**kdm-kcm**](./kdm-kcm) is the front-end for providing the driver management solution. It uses the standard KDE-KCM style and is subclassed from it.

## Developement Environment

As described above, this project is splitted into two sub-projects, `kdm-kcm` and  `kdm-daemon`. Both of these contain their own CMake files. For building these, make a build folder into the directory

```
1. $cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DKDE_INSTALL_LIBDIR=lib -DCMAKE_INSTALL_LIBEXECDIR=lib  -DBUILD_TESTING=OFF

2. $make
```
## To-Do [Very Naive work-flow]

1. Start basic code layout for CMake [Completed]

2. Complete the basic code for kded module and kcm and check for basic data exchange between them, via DBus.

3. Write Initializer for ldm-manager, to listen and enumerate device and display the same on kcm

4. Use some database/ldm-lib for driver solution and package-kit API Call to install the required driver.

5. Move the KDM-KCM from QWidgetStyle to QML

## Background 

I started this project back in Aug 2018, but could not focus much due to some other important engagement.

## References/Inspiration

1. https://github.com/solus-project/linux-driver-management

2. https://wiki.manjaro.org/index.php/Manjaro_Hardware_Detection

3. https://github.com/KDE/kubuntu-driver-kcm

4. https://userbase.kde.org/Color_Management

