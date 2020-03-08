cmake_minimum_required(VERSION 3.16)

project(plugin_architecture LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PLUGIN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugin_lib)

include_directories(include)

# Plugins
add_library(can SHARED)
target_sources(
    can
    PRIVATE
    src/plugins/CAN/connect.cpp)
set_target_properties(
    can
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIRECTORY})

add_library(usb SHARED)
target_sources(
    usb
    PRIVATE
    src/plugins/BasePlugin.cpp
    src/plugins/USB/Usb.cpp
    src/plugins/USB/connect.cpp)
set_target_properties(usb
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIRECTORY})

# Binary
add_executable(plugin_system)
target_sources(plugin_system
    PRIVATE
    src/main.cpp
    src/PluginManager.cpp
    src/plugins/BasePlugin.cpp
    )
target_link_libraries(plugin_system

    stdc++fs
    ${CMAKE_DL_LIBS})

