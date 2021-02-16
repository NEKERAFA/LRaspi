/**
 * lraspi.cpp - NEKERAFA - 28th january 2020
 * Stand-alone program
 */

#include <iostream>
#include <string>
#include "lraspi.h"

int main(int argc, char** argv) {  
	lraspi::init();

	lraspi::color* black = new lraspi::color(0, 0, 0, 255);
	lraspi::color* white = new lraspi::color(255, 255, 255, 255);

	auto devices = lraspi::device::list();

	while(!WindowShouldClose()) {
		lraspi::screen::clear(black);

		lraspi::screen::print("Devices: " + std::to_string(devices.size()), 10, 10, white);
		int y = 26;
		for (auto it = devices.begin(); it != devices.end(); ++it) {
			lraspi::screen::print(*it, 10, y, white);
			y += 14;
		}

		lraspi::screen::flip();
	}

	delete white;
	delete black;

	lraspi::close();

	return 0;
}
