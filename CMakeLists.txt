cmake_minimum_required(VERSION 3.0.0)
project(LuaRaspi VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Lua REQUIRED)

set(LRASPI_SRC_LUA_MODULES
        src/lraspi/lscreen.cc
        src/lraspi/limage.cc
    )

set(LRASPI_SRC_COMMON
        src/common/exceptionf.cc
    )

set(LRASPI_SRC_SCREEN_MODULE
        src/modules/screen/window.cc
    )

set(LRASPI_SRC_IMAGE_MODULE
    src/modules/image/texture.cc
    src/modules/image/image.cc
)

set(LRASPI_SRC
        ${LRASPI_SRC_LUA_MODULES}
        ${LRASPI_SRC_COMMON}
        ${LRASPI_SRC_SCREEN_MODULE}
        ${LRASPI_SRC_IMAGE_MODULE}
    )

include_directories(${PROJECT_SOURCE_DIR}/src/include)

add_library("lraspi.${PROJECT_VERSION}" SHARED ${LRASPI_SRC})

add_executable(lraspi src/lraspi.cc)
target_link_libraries(lraspi "lraspi.${PROJECT_VERSION}" SDL2::Main SDL2::Image ${LUA_LIBRARIES})