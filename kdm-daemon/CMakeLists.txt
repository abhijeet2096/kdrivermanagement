cmake_minimum_required(VERSION 3.0)

project(kdrivermanagement)
set(PROJECT_VERSION "1.0.0")
set(PROJECT_VERSION_MAJOR 1)

set(QT_MIN_VERSION "5.11")
set(KF5_MIN_VERSION "5.50.0")
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS Widgets Quick QuickWidgets Concurrent Test Network)
find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

find_package(PkgConfig REQUIRED)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMMarkNonGuiExecutable)
include(CMakePackageConfigHelpers)
include(WriteBasicConfigVersionFile)
include(CheckIncludeFiles)
include(FeatureSummary)
include(ECMOptionalAddSubdirectory)
include(ECMQtDeclareLoggingCategory)
include(KDEPackageAppTemplates)
include(GenerateExportHeader)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
                    Plasma Declarative DBusAddons CoreAddons)
find_package(KDED CONFIG REQUIRED)

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_definitions(-DQT_NO_URL_CAST_FROM_STRING)

pkg_check_modules(ldm IMPORTED_TARGET ldm-1.0>=1.0.3)

add_subdirectory(libkdrivermanagement)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
