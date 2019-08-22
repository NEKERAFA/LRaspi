/*
    include/modules/color/color_mod.h - NEKERAFA - 7th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_COLOR_H
#define LRASPI_MODULE_COLOR_H

#include <cstdint>

#include "modules/color/color.h"

namespace lraspi
{

namespace color
{

extern Color* white;
extern Color* black;
extern Color* red;
extern Color* green;
extern Color* blue;
extern Color* yellow;
extern Color* cyan;
extern Color* magenta;
extern Color* marron;
extern Color* grass;
extern Color* navy;
extern Color* turquoise;
extern Color* olive;
extern Color* violet;
extern Color* gray;
extern Color* blank;

/**
 * @brief Create a color object
 * 
 * @param red The red value
 * @param green The green value
 * @param blue The blue value
 * @param alpha The alpha value
 * @return A lraspi::Color object
 */
Color* create(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

} // namespace color

} // namespace lraspi

#endif // LRASPI_MODULE_COLOR_H