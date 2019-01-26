project(kcm-KDriverManger)

cmake_minimum_required(VERSION 2.8.12)

find_package(ECM 0.0.14 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})
    
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

find_package(Qt5 5.0.0 CONFIG REQUIRED DBus)
find_package(KF5 5.0.0 REQUIRED
    COMPONENTS
        Config
        ConfigWidgets
        I18n
        TextWidgets)

add_definitions(-DTRANSLATION_DOMAIN=\"kcm-KDriverManager\")
add_subdirectory(src)
