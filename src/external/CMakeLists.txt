# Lua 5.4 library

set(EXTERNAL_LUA54
	src/external/lua54/src/lapi.c
        src/external/lua54/src/lcode.c
        src/external/lua54/src/lctype.c
        src/external/lua54/src/ldebug.c
        src/external/lua54/src/ldo.c
        src/external/lua54/src/ldump.c
        src/external/lua54/src/lfunc.c
        src/external/lua54/src/lgc.c
        src/external/lua54/src/llex.c
        src/external/lua54/src/lmem.c
        src/external/lua54/src/lobject.c
        src/external/lua54/src/lopcodes.c
        src/external/lua54/src/lparser.c
        src/external/lua54/src/lstate.c
        src/external/lua54/src/lstring.c
        src/external/lua54/src/ltable.c
        src/external/lua54/src/ltm.c
        src/external/lua54/src/lundump.c
        src/external/lua54/src/lvm.c
        src/external/lua54/src/lzio.c
        src/external/lua54/src/lauxlib.c
        src/external/lua54/src/lbaselib.c
        src/external/lua54/src/lcorolib.c
        src/external/lua54/src/ldblib.c
        src/external/lua54/src/liolib.c
        src/external/lua54/src/lmathlib.c
        src/external/lua54/src/loadlib.c
        src/external/lua54/src/loslib.c
        src/external/lua54/src/lstrlib.c
        src/external/lua54/src/ltablib.c
        src/external/lua54/src/lutf8lib.c
        src/external/lua54/src/linit.c
)

add_library(lua54 STATIC ${EXTERNAL_LUA54})

# RayLib 3.5.0
add_subdirectory(src/external/raylib)

