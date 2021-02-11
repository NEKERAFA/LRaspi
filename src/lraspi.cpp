/**
 * lraspi.cpp - NEKERAFA - 28th january 2020
 * Stand-alone program
 */

#include "external/lua54/src/lua.hpp"
#include "lraspi.h"

int main(int argc, char** argv) {  
    lraspi::init();

    lraspi::color32* black = new lraspi::color32(0, 0, 0, 255);
    lraspi::color32* white = new lraspi::color32(255, 255, 255, 255);

    while(!WindowShouldClose()) {
    	lraspi::screen::clear(black);

	lraspi::screen::print("Hello world!", 10, 10, white);

	lraspi::screen::flip();
    }

    delete white;
    delete black;

    lraspi::close();

    return 0;
}
