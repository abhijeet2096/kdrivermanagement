configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Version.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/Version.h)

set(kcm_SRCS
    main.cpp
    Module.cpp
    KDriverWidget.cpp
)

qt5_wrap_ui(kcm_SRCS Module.ui KDriverWidget.ui)

add_library(kcm_KDriverManager MODULE ${kcm_SRCS})

target_link_libraries(kcm_KDriverManager
    Qt5::DBus
    KF5::ConfigWidgets
    KF5::I18n
)

install(TARGETS kcm_KDriverManager DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES kcm_KDriverManager.desktop DESTINATION ${SERVICES_INSTALL_DIR})
#install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/DriverManager_DBus DESTINATION ${LIBEXEC_INSTALL_DIR})
