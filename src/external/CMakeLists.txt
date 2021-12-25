# Add include directories
include_directories(
	${CMAKE_CURRENT_LIST_DIR}/lua54/src
	${CMAKE_CURRENT_LIST_DIR}/raylib4/src
)

# Lua 5.4 library
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lua54)

# LuaFileSystem
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lfs)

# RayLib 4.0.0 library
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/raylib4)
