/*
    include/modules/color/module.h - NEKERAFA - 7th aug 2019

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

/**
 * @brief White color (255, 255, 255)
 */
extern Color* white;

/**
 * @brief Black color (0, 0, 0)
 */
extern Color* black;

/**
 * @brief Red color (255, 0, 0)
 */
extern Color* red;

/**
 * @brief Green color (0, 255, 0)
 */
extern Color* green;

/**
 * @brief Blue color (0, 0, 255)
 */
extern Color* blue;

/**
 * @brief Yellow color (255, 255, 0)
 */
extern Color* yellow;

/**
 * @brief Cyan color (0, 255, 255)
 */
extern Color* cyan;

/**
 * @brief Magenta color (255, 0, 255)
 */
extern Color* magenta;

/**
 * @brief Marron color (128, 0, 0)
 */
extern Color* marron;

/**
 * @brief Grass color (0, 128, 0)
 */
extern Color* grass;

/**
 * @brief Navy color (0, 0, 128)
 */
extern Color* navy;

/**
 * @brief Turquiose color (0, 128, 128)
 */
extern Color* turquoise;

/**
 * @brief Olive color (128, 128, 0)
 * 
 */
extern Color* olive;

/**
 * @brief Violet color (128, 0, 128)
 */
extern Color* violet;

/**
 * @brief Gray color (128, 128, 128)
 */
extern Color* gray;

/**
 * @brief Blank color (0, 0, 0, 0)
 */
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