set(EXTERNAL_LUA54
        ${CMAKE_CURRENT_LIST_DIR}/src/lapi.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lcode.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lctype.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ldebug.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ldo.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ldump.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lfunc.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lgc.c
        ${CMAKE_CURRENT_LIST_DIR}/src/llex.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lmem.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lobject.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lopcodes.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lparser.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lstate.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lstring.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ltable.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ltm.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lundump.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lvm.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lzio.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lauxlib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lbaselib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lcorolib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ldblib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/liolib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lmathlib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/loadlib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/loslib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lstrlib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/ltablib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/lutf8lib.c
        ${CMAKE_CURRENT_LIST_DIR}/src/linit.c
)

add_library(lua54 STATIC ${EXTERNAL_LUA54})
