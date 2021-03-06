# Lua Raspi CMake project
cmake_minimum_required(VERSION 3.0.0)
project(LuaRaspi VERSION 0.0.5)

# Configuration files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Include another files
include(src/external/CMakeLists.txt)
include(src/CMakeLists.txt)

# Add lua libraries
add_library(lfs SHARED src/external/lfs/src/lfs.c)
set_target_properties(lfs PROPERTIES PREFIX "")

# Include external files
configure_file(extra/font/OpenSans.ttf OpenSans.ttf COPYONLY)

# Link all libraries
target_link_libraries(lraspi "lraspi.${PROJECT_VERSION}" lua54 raylib udev)
