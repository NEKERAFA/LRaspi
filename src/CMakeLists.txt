# Add Lua Raspi modules
set(LRASPI_MODULES
	src/modules/core.c
	src/modules/screen.c
	src/modules/font.c
    src/modules/colour.c
)

set(LRASPI_LUA_LIBS
    src/laux.c
    src/lcore.c
	src/lscreen.c
    src/lfont.c
    src/lcolour.c
)

add_library("lraspi.${PROJECT_VERSION}" STATIC ${LRASPI_MODULES} ${LRASPI_LUA_LIBS})

# Add Lua Raspi executable
set(LRASPI_EXECUTABLE
    src/lraspi.c
)

add_executable(lraspi ${LRASPI_EXECUTABLE})
