# Lua 5.4 library
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lua54)

# RayLib 3.5.0 library
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/raylib)

# add include folders
include_directories(
	${CMAKE_CURRENT_LIST_DIR}/lua54
	${CMAKE_CURRENT_LIST_DIR}/raylib/src
)
