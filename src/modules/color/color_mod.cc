#include <cstdint>

#include "modules/color/color.h"
#include "modules/color/color_mod.h"

namespace lraspi
{

namespace color
{

Color* white     = new Color(255, 255, 255);
Color* black     = new Color(  0,   0,   0);
Color* red       = new Color(255,   0,   0);
Color* green     = new Color(  0, 255,   0);
Color* blue      = new Color(  0,   0, 255);
Color* yellow    = new Color(255, 255,   0);
Color* cyan      = new Color(  0, 255, 255);
Color* magenta   = new Color(255,   0, 255);
Color* marron    = new Color(128,   0,   0);
Color* grass     = new Color(  0, 128,   0);
Color* navy      = new Color(  0,   0, 128);
Color* olive     = new Color(128, 128,   0);
Color* turquoise = new Color(  0, 128, 128);
Color* violet    = new Color(128,   0, 128);
Color* gray      = new Color(128, 128, 128);
Color* blank     = new Color(  0,   0,   0,   0);

Color* create(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    return new Color(red, green, blue, alpha);
}

} // namespace color

} // namespace lraspi
