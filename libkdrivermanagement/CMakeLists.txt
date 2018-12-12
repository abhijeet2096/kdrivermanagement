add_subdirectory(declarative)
add_subdirectory(kded)
set(kdrivermanagement_LIB_SRCS
    suitabledriver.cpp
    deviceenumerator.cpp
    )
add_library(kdrivermanagement ${kdrivermanagement_LIB_SRCS})
generate_export_header(kdrivermanagement)

target_include_directories(kdrivermanagement PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>" "$<INSTALL_INTERFACE:${KDE_INSTALL_INCLUDEDIR}/kdrivermanagement>")

target_link_libraries(kdrivermanagement
                    PUBLIC
                      KF5::Plasma

                      Qt5::Core
                    PRIVATE
                      KF5::I18n

                      Qt5::DBus)

set_target_properties(kdrivermanagement PROPERTIES
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      EXPORT_NAME LibKDriverManagement)


install(TARGETS kdrivermanagement EXPORT libkdrivermanagementLibraryTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )

install(FILES
    suitabledriver.cpp
    deviceenumerator.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/kdrivermanagement_export.h
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/kdrivermanagement COMPONENT Devel
)

write_basic_config_version_file(${CMAKE_CURRENT_BINARY_DIR}/LibKDriverManagementConfigVersion.cmake VERSION "${PROJECT_VERSION}" COMPATIBILITY AnyNewerVersion)

set(CMAKECONFIG_INSTALL_DIR ${KDE_INSTALL_LIBDIR}/cmake/KDriverManagement)

configure_package_config_file(LibKDriverManagementConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/LibKDriverManagementConfig.cmake"
    INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/LibKDriverManagementConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/LibKDriverManagementConfigVersion.cmake
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})

install(EXPORT libKDriverManagementLibraryTargets
        NAMESPACE PW:
        DESTINATION ${CMAKECONFIG_INSTALL_DIR}
        FILE LibKDriverManagementLibraryTargets.cmake )