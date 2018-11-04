include_directories(${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_library(kdrivermanagementplugin SHARED kdrivermanagementplugin.cpp)

target_link_libraries(kdrivermanagementplugin
                      Qt5::Qml
                      kdrivermanagement)

install(TARGETS kdrivermanagementplugin DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/kdrivermanagement)
install(FILES qmldir DESTINATION ${KDE_INSTALL_QMLDIR}/org/kde/kdrivermanagement)
 
