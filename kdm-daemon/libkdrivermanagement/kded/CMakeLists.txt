include_directories (${CMAKE_CURRENT_BINARY_DIR}/..)

add_library(kdrivermanagementdevicedetector MODULE devicedetector.cpp)

kcoreaddons_desktop_to_json(kdrivermanagementdevicedetector kdrivermanagementdevicedetector.desktop)

target_link_libraries(kdrivermanagementdevicedetector
                        KF5::DBusAddons
                        KF5::CoreAddons
                        kdrivermanagement)
                        
install(TARGETS kdrivermanagementdevicedetector DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/kded)
