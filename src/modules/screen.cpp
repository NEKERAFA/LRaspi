/**
 * screen.cpp - NEKERAFA - 30th january 2021
 * Screen manipulation implementation
 *
 * See "lraspi.h" for license information
 */

#include <string>
#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

void lraspi::screen::clear(lraspi::color* col) {
	BeginDrawing();
	ClearBackground(col->data());
}

void lraspi::screen::print(std::string text, int x, int y, lraspi::color* col) {
	DrawTextEx(
		lraspi::font::default_font()->data(),
		text.c_str(),
		(Vector2) {(float)x, (float)y},
		lraspi::font::default_font()->data().baseSize,
		0, col->data()
	);
}

void lraspi::screen::flip() {
	EndDrawing();
}
