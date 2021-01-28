# Lua Raspi CMake project
cmake_minimum_required(VERSION 3.0.0)
project(LuaRaspi VERSION 0.0.5)

# Include another files
include(src/external/CMakeLists.txt)
include(src/CMakeLists.txt)

# Link all libraries
target_link_libraries(lraspi lua54 raylib)

