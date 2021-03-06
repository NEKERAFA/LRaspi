# Add Lua Raspi modules
set(LRASPI_MODULES
	src/modules/colors.cpp
	src/modules/core.cpp
	src/modules/fonts.cpp
	src/modules/screen.cpp
	src/modules/usb.cpp
)

set(LRASPI_LUA_LIBS
	src/lauxlib.cpp
	src/lscreen.cpp
)

add_library("lraspi.${PROJECT_VERSION}" STATIC ${LRASPI_MODULES} ${LRASPI_LUA_LIBS})

# Add Lua Raspi executable

set(LRASPI_EXECUTABLE
    src/lraspi.cpp
)

add_executable(lraspi ${LRASPI_EXECUTABLE})
