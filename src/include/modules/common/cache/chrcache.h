/*
    include/modules/common/cache/chrcache.h - NEKERAFA - 24th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_CACHE_CHAR_H
#define LRASPI_CACHE_CHAR_H

#include <codecvt>
#include <locale>
#include <unordered_map>

#include "modules/font/font.h"
#include "modules/image/char.h"

namespace lraspi
{

/**
 * @brief This represents a glyph cache to render inmediate text onto the screen
 */
namespace chrcache
{

/**
 * @brief Set the default font to render al glyphs
 * 
 * @param A lraspi::Font object
 */
void setDefaultFont(Font* font);

/**
 * @brief Get the default font setted in the cache
 * 
 * @return A lraspi::Font object
 */
Font* getDefaultFont();

/**
 * @brief Get a rendered char.
 * If not exists in the chache, it renderer before
 * 
 * @param glyph The unicode character
 * @return Char* A lraspi::Char object
 */
Char* getChar(char16_t glyph);

/**
 * @brief Clear the cache, destroying all renderers.
 * Use it for clear memory
 */
void clear();

} // namespace chrcache

} // namespace lraspi

#endif // LRASPI_CACHE_CHAR_H