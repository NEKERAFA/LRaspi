cmake_minimum_required(VERSION 3.0.0)
project(LuaRaspi VERSION 0.0.3)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Lua REQUIRED)

set(LRASPI_SRC_LUA_MODULES
        src/lraspi/lauxlib.cc
        src/lraspi/lcanvas.cc
        src/lraspi/lcolor.cc
        src/lraspi/ldraw.cc
        src/lraspi/lfont.cc
        src/lraspi/limage.cc
        src/lraspi/lscreen.cc
        src/lraspi/ltext.cc
        src/modules/lraspi/lraspi.cc
    )

set(LRASPI_SRC_COMMON
        src/common/exception.cc
        src/common/type.cc
        src/common/object.cc
    )

set(LRASPI_SRC_SCREEN_MODULE
        src/modules/screen/module.cc
    )

set(LRASPI_SRC_IMAGE_MODULE
    src/modules/image/image.cc
    src/modules/image/module.cc
)

set(LRASPI_SRC_COLOR_MODULE
    src/modules/color/color.cc
    src/modules/color/module.cc
)

set(LRASPI_SRC_FONT_MODULE
    src/modules/font/font.cc
    src/modules/font/module.cc
)

set(LRASPI_SRC_DRAW_MODULE
    src/modules/draw/canvas.cc
    src/modules/draw/text.cc
    src/modules/draw/texture.cc
    src/modules/draw/module.cc
)

set(LRASPI_SRC
        ${LRASPI_SRC_COMMON}
        ${LRASPI_SRC_LUA_MODULES}
        ${LRASPI_SRC_COLOR_MODULE}
        ${LRASPI_SRC_FONT_MODULE}
        ${LRASPI_SRC_IMAGE_MODULE}
        ${LRASPI_SRC_SCREEN_MODULE}
        ${LRASPI_SRC_DRAW_MODULE}
    )

set(LRASPI_SRC_EXECUTABLE
        src/interface/explorer.cc
        src/lraspi.cc
    )

include_directories(${PROJECT_SOURCE_DIR}/src/include ${LUA_INCLUDE_DIR})

add_library("lraspi.${PROJECT_VERSION}" SHARED ${LRASPI_SRC})

add_executable(lraspi ${LRASPI_SRC_EXECUTABLE})
target_link_libraries(lraspi "lraspi.${PROJECT_VERSION}" SDL2::Main SDL2::Image SDL2::TTF ${LUA_LIBRARIES})