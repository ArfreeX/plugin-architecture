cmake_minimum_required(VERSION 3.16)

project(plugin_architecture LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PLUGIN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugin_lib)

# Plugins
add_library(can SHARED)
target_sources(
    can
    PRIVATE
    src/plugins/CAN/Can.cpp)
set_target_properties(
    can
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIRECTORY})

add_library(usb SHARED)
target_sources(
    usb
    PRIVATE
    src/plugins/USB/Usb.cpp)
set_target_properties(usb
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_OUTPUT_DIRECTORY})

# Binary
add_executable(plugin_system)
target_sources(plugin_system
    PRIVATE
    src/main.cpp
    src/PluginManager.cpp
    )
target_link_libraries(plugin_system
    stdc++fs
    ${CMAKE_DL_LIBS})

