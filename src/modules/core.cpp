/**
 * core.cpp - NEKERAFA - 30th january 2020
 * Initialize and close functions implementation
 *  
 * See "lraspi.h" for license notice 
 */

#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

#ifdef MODE_NATIVE
	#define SCREEN_WIDTH  GetMonitorWidth(0)
	#define SCREEN_HEIGHT GetMonitorHeight(0)	
#else
	#define SCREEN_WIDTH  1280 
	#define SCREEN_HEIGHT 720
#endif

void lraspi::init() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lua Raspi");
	lraspi::font::init();
}

void lraspi::close() {
	lraspi::font::close();
	CloseWindow();
}

