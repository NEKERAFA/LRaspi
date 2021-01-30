# Add Lua Raspi modules
set(LRASPI_MODULES
    src/modules/core.cpp
    src/modules/screen.cpp
)

add_library("lraspi.${PROJECT_VERSION}" STATIC ${LRASPI_MODULES})

# Add Lua Raspi executable

set(LRASPI_EXECUTABLE
	src/lraspi.cpp
)

add_executable(lraspi ${LRASPI_EXECUTABLE})

