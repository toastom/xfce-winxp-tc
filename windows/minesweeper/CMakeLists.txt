cmake_minimum_required(VERSION 3.5)

project(
    wintc-minesweeper
    VERSION 1.0
    DESCRIPTION "Windows Total Conversion Minesweeper application."
    LANGUAGES C
)

set(PROJECT_ANYARCH    false)
set(PROJECT_FREESTATUS true)
set(PROJECT_MAINTAINER "Rory Fewell <roryf@oddmatics.uk>")

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

include(GNUInstallDirs)

include(../../packaging/cmake-inc/common/CMakeLists.txt)
include(../../packaging/cmake-inc/linking/CMakeLists.txt)
include(../../packaging/cmake-inc/locale/CMakeLists.txt)
include(../../packaging/cmake-inc/packaging/CMakeLists.txt)
include(../../packaging/cmake-inc/resources/CMakeLists.txt)

wintc_resolve_library(glib-2.0      GLIB)
wintc_resolve_library(gtk+-3.0      GTK3)
wintc_resolve_library(wintc-comgtk  WINTC_COMGTK)
wintc_resolve_library(wintc-shllang WINTC_SHLLANG)

wintc_compile_resources()
wintc_create_meta_h()

add_executable(
    wintc-minesweeper
    src/application.c
    src/application.h
    src/main.c
    src/resources.c
    src/window.c
    src/window.h
)

set_target_properties(
    wintc-minesweeper
    PROPERTIES
    OUTPUT_NAME minesweeper
)

target_compile_options(
    wintc-minesweeper
    PRIVATE ${WINTC_COMPILE_OPTIONS}
)

target_include_directories(
    wintc-minesweeper
    SYSTEM
    PRIVATE ${GLIB_INCLUDE_DIRS}
    PRIVATE ${GTK3_INCLUDE_DIRS}
    PRIVATE ${WINTC_COMGTK_INCLUDE_DIRS}
    PRIVATE ${WINTC_SHLLANG_INCLUDE_DIRS}
)

target_link_directories(
    wintc-minesweeper
    PRIVATE ${GLIB_LIBRARY_DIRS}
    PRIVATE ${GTK3_LIBRARY_DIRS}
    PRIVATE ${WINTC_COMGTK_LIBRARY_DIRS}
    PRIVATE ${WINTC_SHLLANG_LIBRARY_DIRS}
)

target_link_libraries(
    wintc-minesweeper
    PRIVATE ${GLIB_LIBRARIES}
    PRIVATE ${GTK3_LIBRARIES}
    PRIVATE ${WINTC_COMGTK_LIBRARIES}
    PRIVATE ${WINTC_SHLLANG_LIBRARIES}
)

add_dependencies(
    wintc-minesweeper
    build-gresources
)

# Installation
#
wintc_configure_and_install_packaging()
wintc_install_icons_into_package()
wintc_compile_and_install_pofiles()

install(
    FILES minesweeper.desktop
    DESTINATION share/applications
)
install(
    TARGETS wintc-minesweeper
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
