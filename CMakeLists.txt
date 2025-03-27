cmake_minimum_required(VERSION 3.10)
project(JsonTreePlugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Set paths for CubeGUI (Change this path to match your CubeGUI installation)
set(CUBE_DIR "/home/atif/Desktop/cubegui")  # Adjust based on your Cube installation path
set(CUBE_INCLUDE_DIRS "${CUBE_DIR}/include/cubegui")
set(CUBE_LIBRARIES "${CUBE_DIR}/lib/libcube4gui.so")

# Include CubeGUI headers
include_directories(${CUBE_INCLUDE_DIRS})

# Add the plugin source files
add_library(JsonTreePlugin SHARED src/JsonTreePlugin.cpp)

# Link against Qt and CubeGUI libraries
target_link_libraries(JsonTreePlugin Qt5::Widgets ${CUBE_LIBRARIES})

# Define the Cube plugin installation directory
set(CUBE_PLUGIN_DIR "${CUBE_DIR}/lib/cube-plugins")

# Install the plugin into Cube's plugin directory
install(TARGETS JsonTreePlugin LIBRARY DESTINATION ${CUBE_PLUGIN_DIR})
