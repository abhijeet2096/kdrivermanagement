include_directories (${CMAKE_CURRENT_BINARY_DIR}/..)

add_library(kdrivermanagement MODULE driversolution.cpp)

kcoreaddons_desktop_to_json(kdrivermanagement kdrivermanagement.desktop)

target_link_libraries(kdrivermanagement 
                        ldm)
                        
install(TARGETS kdrivermanagement DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/kded)
