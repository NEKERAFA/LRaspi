/*
 * lraspi.c - NEKERAFA - 25th october 2021
 * Lua Raspi stand-alone program
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>

#include "lua.h"
#include "lauxlib.h"
#include "laux.h"
#include "lraspi.h"

/*
int main(int argc, char** argv) {
    lraspi_init();

    lraspi_Image* image = lraspi_image_new("icon.png");
    lraspi_image_resize(image, 100, 100);
    lraspi_image_vflip(image, true);

    lraspi_Colour* fg = lraspi_colour_getbackground();
    lraspi_colour_setforeground(fg);

    while (!lraspi_isclosing()) {
        lraspi_screen_clear();
        //lraspi_image_rotate(image, lraspi_image_getrotation(image) + 0.01);
        
        lraspi_draw_print("Hello world", 10, 10);
        lraspi_draw_blit(image, 100, 100);

        lraspi_screen_flip();
    }

    lraspi_close();
}
*/


int main(int argc, char **argv)
{
    printf("Initializing Lua Raspi %s\n", LRASPI_LIB_VERSION);

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lraspi_init();
    lraspi_openlibs(L);

    lraspi_dofile(L, "main.lua");
    lua_close(L);

    lraspi_close();

    printf("Closing Lua Raspi\n");

    return 0;
}

