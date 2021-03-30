option(BUILD_SHARED_LIB "Build Lua Raspi as shared library" OFF)

set(BUILD_PLATFORM "DESKTOP" CACHE STRING "Build platform")
set(BUILD_PLATFORMS "DESKTOP;RPI_OS;RPI_4;RASPBERRY_PI")
set_property(CACHE BUILD_PLATFORM PROPERTY STRINGS ${BUILD_PLATFORMS})
if (NOT ";${BUILD_PLATFORMS};" MATCHES ";${BUILD_PLATFORM};")
	message(FATAL_ERROR "Bad argumment -DBUILD_PLATFORM. Expected ${BUILD_PLATFORMS}.")
endif()

if (BUILD_PLATFORM MATCHES "DESKTOP")
	message(STATUS "Detected DESKTOP config")
elseif (BUILD_PLATFORM MATCHES "RPI_OS")
	message(STATUS "Detected RPI_OS config")
	set(GRAPHICS "GRAPHICS_API_OPENGL_21")
elseif (BUILD_PLATFORM MATCHES "RPI_4")
	message(STATUS "Detected RPI_4 config")
	set(PLATFORM "DRM")
	add_compile_definitions("LRASPI_NATIVE")
elseif (BUILD_PLATFORM MATCHES "RASPBERRY_PI")
	message(STATUS "Detected RASPBERRY_PI config")
	set(PLATFORM "Raspberry Pi")
	add_compile_definitions("LRASPI_NATIVE")
endif()
