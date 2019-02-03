cmake_minimum_required(VERSION 2.8.12)

project(kcm-kdm)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Version.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/Version.h)


find_package(ECM 0.0.14 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})    

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
# include(GenerateExportHeader)

find_package(Qt5 5.0.0 CONFIG REQUIRED
    COMPONENTS 
        Core
        DBus
)
find_package(KF5 5.0.0 REQUIRED
    COMPONENTS
        Config
        ConfigWidgets
        I18n
        TextWidgets
)



add_definitions(-DTRANSLATION_DOMAIN=\"kcm-kdm\")

set(kcm_SRCS
    src/main.cpp
    src/Module.cpp
    src/KDriverWidget.cpp
    src/manager.cpp
    src/kdrivermanagerdbusinterface.cpp
)


qt5_add_dbus_adaptor( kcm_SRCS org.kde.kdm.KDriverManager.xml src/kdrivermanagerdbusinterface.h KDM::KDriverManagerDBusInterface kdrivermanageradaptor KDriverManagerAdaptor )
qt5_wrap_ui(kcm_SRCS src/Module.ui src/KDriverWidget.ui)

add_library(kcm_kdm MODULE ${kcm_SRCS})
# generate_export_header(kcm_kdm EXPORT_FILE_NAME kdm_export.h)
target_link_libraries(kcm_kdm
    Qt5::DBus
    KF5::ConfigWidgets
    KF5::I18n
)

install(TARGETS kcm_kdm DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES kcm_kdm.desktop DESTINATION ${SERVICES_INSTALL_DIR})
install(FILES org.kde.kdm.KDriverManager.xml DESTINATION ${KDE_INSTALL_DBUSINTERFACEDIR})
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/kdm_export.h DESTINATION ${INCLUDE_INSTALL_DIR} COMPONENT Devel)
