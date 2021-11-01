#include "../external/raylib37/src/raylib.h"
#include "../lraspi.h"

#ifndef NDEBUG
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#else
#define SCREEN_WIDTH GetMonitorWidth(0)
#define SCREEN_HEIGHT GetMonitorHeight(0)
#endif

void lraspi_init()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LRaspi");
}

void lraspi_close()
{
    CloseWindow();
}

