/**
 * lraspi.cpp - NEKERAFA - 28th january 2020
 * Stand-alone program
 */

#include "external/lua54/src/lua.hpp"
#include "lraspi.h"
#include "external/raylib/src/raylib.h"

int main(int argc, char** argv) {  
    lraspi::init();

    lraspi::font* default_font = new lraspi::font("OpenSans.ttf");
    lraspi::color32* black = new lraspi::color32(0, 0, 0, 0);

    while(!WindowShouldClose()) {
    	lraspi::screen::clear(*black);

	DrawTextEx(default_font->data(), "Hello world", (Vector2){ 10.0f, 24.0f }, default_font->data().baseSize, 1, WHITE);

	lraspi::screen::flip();
    }

    delete default_font;
    delete black;

    lraspi::close();

    return 0;
}
