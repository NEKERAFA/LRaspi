# Lua Raspi CMake project
cmake_minimum_required(VERSION 3.0.0)
project(LuaRaspi VERSION 1.0.0)

# Configuration files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(cmake/BuildOptions)

# Include another files
include(src/external/CMakeLists.txt)
include(src/CMakeLists.txt)

# Include external files
configure_file(src/scripts/main.lua main.lua COPYONLY)
configure_file(extra/font/OpenSans.ttf OpenSans.ttf COPYONLY)
configure_file(extra/lua_logo.png lua_logo.png COPYONLY)

# Link all libraries
target_link_libraries(lraspi "lraspi.${PROJECT_VERSION}" lua54 raylib)
