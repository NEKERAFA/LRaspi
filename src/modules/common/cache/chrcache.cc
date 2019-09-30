/*
    modules/common/cache/chrcache.h - NEKERAFA - 24th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <unordered_map>

#include "modules/font/font.h"
#include "modules/image/char.h"
#include "modules/common/cache/chrcache.h"

namespace lraspi
{

std::unordered_map<char16_t, Char*> _char_cache;
Font* _current_font;

void chrcache::setDefaultFont(Font* font)
{
    _current_font = font;
}


Font* chrcache::getDefaultFont()
{
    return _current_font;
}

Char* chrcache::getChar(char16_t glyph)
{
    auto it = _char_cache.find(glyph);
    Char* chr;

    if (it == _char_cache.end())
    {
        chr = new Char(_current_font, glyph);
        _char_cache.emplace(glyph, chr);
    }
    else
    {
        chr = it->second;
    }

    return chr;
}

void chrcache::clear()
{
    for (auto it = _char_cache.begin(); it != _char_cache.end(); it++)
    {
        delete it->second;
    }

    _char_cache.clear();
}

} // namespace lraspi