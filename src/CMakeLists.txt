# Add Lua Raspi modules
set(LRASPI_MODULES
#	src/modules/colors.cpp
	src/modules/core.c
#	src/modules/fonts.cpp
#	src/modules/screen.cpp
#	src/modules/usb.cpp
)

set(LRASPI_LUA_LIBS
#	src/laux.cpp
#	src/lcolor.cpp
#	src/lfont.cpp
#	src/lscreen.cpp
#	src/lusb.cpp
)

add_library("lraspi.${PROJECT_VERSION}" STATIC ${LRASPI_MODULES})# ${LRASPI_LUA_LIBS})

# Add Lua Raspi executable
set(LRASPI_EXECUTABLE
    src/lraspi.c
)

add_executable(lraspi ${LRASPI_EXECUTABLE})
