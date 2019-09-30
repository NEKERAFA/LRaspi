/*
    modules/font/font.cc - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <locale>
#include <string>
#include <sstream>
#include <codecvt>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "modules/common/exception.h"
#include "modules/common/type.h"
#include "modules/common/object.h"
#include "modules/font/font.h"
#include "modules/color/module.h"

namespace lraspi
{

Type Font::type(LRASPI_FONT_NAME, &Object::type);

Font::Font(const char* path, int size) : _size(size),
                                         _line_height(1.0)
{
    _font = TTF_OpenFont(path, size);
    if (!_font)
        throw Exception("Could not load font `%s' (%s)", path, TTF_GetError());
}

Font::Font(int size) : Font(LRASPI_FONT_DEFAULT, size)
{}

Font::Font() : Font(LRASPI_FONT_SIZE)
{}

Font::~Font()
{
    TTF_CloseFont(_font);
}

SDL_Surface* Font::getSdlSurface(const char* text)
{
    SDL_Surface* surface = TTF_RenderUTF8_Blended(_font, text, color::white->getSdlColor());
    
    if (surface == nullptr)
        throw Exception("Could not create renderer (%s)", TTF_GetError());

    return surface;
}

SDL_Surface* Font::getSdlSurface(char16_t glyph)
{
    SDL_Surface* surface = TTF_RenderGlyph_Blended(_font, glyph, color::white->getSdlColor());
    
    if (surface == nullptr)
        throw Exception("Could not create renderer (%s)", TTF_GetError());

    return surface;
}

int Font::getHeight()
{
    return TTF_FontHeight(_font);
}

int Font::getWidth(const char* text)
{
    int width;
    if (TTF_SizeUTF8(_font, text, &width, nullptr) != 0)
        throw Exception("Could not calculate width of `%s' (%s)", text, TTF_GetError());
    
    return width;
}

const char* Font::getWrap(const char* text, int width)
{

    std::stringstream _buffer;
    std::stringstream _word;
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> _convert;
    std::u32string _str = _convert.from_bytes(std::string(text));
    int _current_width = 0;
    int _space_width = getWidth(" ");

    auto concat_word = [&]()
    {
        std::u32string _tmp_word = _convert.from_bytes(_word.str());
        int _word_width = getWidth(_word.str().c_str());
        
        // Iterate all characters in word
        for (auto _it = _tmp_word.begin(); _it != _tmp_word.end(); ++_it)
        {
            // Get the size of the char
            int _char_width = getWidth(_convert.to_bytes(*_it).c_str());

            if (_char_width > width)
            {
                throw Exception("the width of character `%s' is greater that the width expecified", _convert.to_bytes(*_it).c_str());
            }

            // If word is bigger than the width specified, divide in lines
            if (_current_width+_char_width > width)
            {
                _buffer << '\n';
                _current_width = 0;
            }

            _buffer << _convert.to_bytes(*_it);
            _current_width += _char_width + TTF_GetFontKerning(_font);
        }

        _word.str(std::string());
    };

    // Iterate all character
    for (auto _it = _str.begin(); _it != _str.end(); ++_it)
    {
        // Space
        if (*_it == ' ' || *_it == '\t' || *_it == '\v')
        {
            int _word_width = getWidth(_word.str().c_str());
            // Checks if the word can enter in the line
            if (_current_width+_space_width+_word_width > width)
            {
                _buffer << '\n';
                _current_width = 0;
            }

            // Add the word to the buffer
            concat_word();
            
            // Checks if the space enter in the line
            if (_current_width+_space_width > width)
            {
                _buffer << '\n';
                _current_width = 0;
            }
            else
            {
                _buffer << ' ';
                _current_width;
            }
        }

        // New line
        else if (*_it == '\n')
        {
            concat_word();
            _buffer << '\n';
            _current_width = 0;
        }

        // Printable
        else if (*_it > 31)
        {
            _word << _convert.to_bytes(*_it);
        }
    }

    // If there are a word saved, concat them
    if (_word.gcount() > 0)
    {
        concat_word();
    }

    return _buffer.str().c_str();
}

void Font::setStyle(int style)
{
    TTF_SetFontStyle(_font, style);
}

int Font::getStyle()
{
    return TTF_GetFontStyle(_font);
}

void Font::setOutline(int outline)
{
    TTF_SetFontOutline(_font, outline);
}

int Font::getOutline()
{
    return TTF_GetFontOutline(_font);
}

void Font::setHintingMode(int hinting)
{
    TTF_SetFontHinting(_font, hinting);
}

int Font::getHintingMode()
{
    return TTF_GetFontHinting(_font);
}

int Font::getAscent()
{
    return TTF_FontAscent(_font);
}

int Font::getDescent()
{
    return TTF_FontDescent(_font);
}

int Font::getLineSkip()
{
    return TTF_FontLineSkip(_font);
}

void Font::setLineHeight(float height)
{
    _line_height = height;
}

float Font::getLineHeight()
{
    return _line_height;
}

const char* Font::getFamilyName()
{
    return TTF_FontFaceFamilyName(_font);
}

bool Font::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Font::name()
{
    return type.name();
}

} // namespace lraspi
