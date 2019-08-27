/*
    lraspi/lfont.cc - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>
#include <cstring>

#include <SDL2/SDL_ttf.h>
#include <lua.hpp>

#include "common/exception.h"
#include "modules/font/font.h"
#include "modules/font/font_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lfont.h"

/***
 * TrueType font reading and text rendering
 * @module Font
 */
extern "C"
{

/***
 * Initializes the font submodule.<br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function font.init
 */
static int lraspi_font_init(lua_State* L)
{
    try
    {
        lraspi::font::init();
    }
    catch(lraspi::Exception &e)
    {
        return luaL_error(L, e.what());
    }
    
    return 0;
}

/***
 * Loads a font from the disk onto the memory
 * @function font.load
 * @string path The path of the font file
 * @int[opt=12] size The size of the font in pixels
 * @treturn font A font object
 */
static int lraspi_font_load(lua_State* L)
{
    int argc = lua_gettop(L);
    
    const char* path = luaL_checkstring(L, 1);
    lua_Integer size = LRASPI_FONT_SIZE;

    if (argc == 2)
    {
        size = luaL_checkinteger(L, 2);
    }

    try
    {
        lraspi::Font* font = lraspi::font::loadFont(path, size);
        lraspi::lua::push(L, lraspi::Font::type, font);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

/***
 * Create a font using the default font (DejaVu) with a custom size
 * @function font.create
 * @int[opt=12] size The size of the font in pixels
 * @treturn font A font object
 */
static int lraspi_font_create(lua_State* L)
{
    int argc = lua_gettop(L);

    lua_Integer size = LRASPI_FONT_SIZE;

    if (argc == 1)
    {
        size = luaL_checkinteger(L, 1);
    }

    try
    {
        lraspi::Font* font = lraspi::font::createDefault(size);
        lraspi::lua::push(L, lraspi::Font::type, font);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

/***
 * Get the maximun height of the font
 * @function font.height
 * @tparam font font A font object
 * @treturn int The height of the font in pixels
 */
static int lraspi_font_height(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_Integer height = font->getHeight();
    lua_pushinteger(L, height);
    
    return 1;
}

/***
 * Calculates the size of the text using font
 * @function font.width
 * @tparam font font A font object
 * @string text The string to calculate the font
 * @treturn int The size in pixels of the resulting texture if the text was rendered using the font
 */
static int lraspi_font_width(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* text = luaL_checkstring(L, 2);

    try
    {
        lua_Integer width = font->getWidth(text);
        lua_pushinteger(L, width);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

/***
 * Formats the text with a maximun text width size.<br>
 * This functions add new lines if the text width size reachs the given wrap limit
 * @function font.wrap
 * @tparam font font A font object
 * @string text The text that will be wrapped
 * @int width The maximun width in pixels of each line
 * @treturn string The text wrapped
 */
static int lraspi_font_wrap(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* text = luaL_checkstring(L, 2);
    lua_Integer width = luaL_checkinteger(L, 3);

    try
    {
        const char* text_wrapped = font->getWrap(text, width);
        lua_pushstring(L, text_wrapped);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

/***
 * Sets the rendering style of the text
 * @function font.style
 * @tparam font font A font object
 * @param style The value "normal" for the default style or a list with the styles as the following values:
 * <ul>
 * <li><span class='parameter'>italic</span> Displays the font as a cursive style</li>
 * <li><span class='parameter'>bold</span> Displays the font as a strong style</li>
 * <li><span class='parameter'>underline</span> Displays the font with a line under the text</li>
 * <li><span class='parameter'>strikethrough</span> Displays the font with a line through the text</li>
 * </ul>
 */

/***
 * Gets the rendering style of the text
 * @function font.style
 * @tparam font font A font object
 * @treturn table A list with the styles as the following values:
 * <ul>
 * <li><span class='parameter'>normal</span> The default font style</li>
 * <li><span class='parameter'>italic</span> Displays the font as a cursive style</li>
 * <li><span class='parameter'>bold</span> Displays the font as a strong style</li>
 * <li><span class='parameter'>underline</span> Displays the font with a line under the text</li>
 * <li><span class='parameter'>strikethrough</span> Displays the font with a line through the text</li>
 * </ul>
 */
static int lraspi_font_style(lua_State* L)
{
    int ret = 0;
    int argc = lua_gettop(L);

    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));

    // Set style
    if (argc == 2)
    {
        // font.style(fnt, "normal")
        if (lua_isstring(L, 2))
        {
            const char* style = lua_tostring(L, 2);
            if (std::strcmp(style, "normal") != 0)
            {
                const char* msg = lua_pushfstring(L, "must be `normal' or a table with the values `italic', `bold', `underline' or `strikethrough'");
                return luaL_argerror(L, 2, msg);
            }

            font->setStyle(TTF_STYLE_NORMAL);
        }
        // font.style(fnt, {...})
        else if (lua_istable(L, 2))
        {
            int style = 0;

            while (lua_next(L, 2))
            {
                if (lua_isstring(L, -1))
                {
                    const char* style_mod = lua_tostring(L, -1);
                    if (std::strcmp(style_mod, "italic")  == 0)
                    {
                        style |= TTF_STYLE_ITALIC;
                    }
                    else if (std::strcmp(style_mod, "bold")  == 0)
                    {
                        style |= TTF_STYLE_BOLD;
                    }
                    else if (std::strcmp(style_mod, "underline")  == 0)
                    {
                        style |= TTF_STYLE_UNDERLINE;
                    }
                    else if (std::strcmp(style_mod, "strikethrough")  == 0)
                    {
                        style |= TTF_STYLE_STRIKETHROUGH;
                    }
                    else
                    {
                        const char* msg = lua_pushfstring(L, "must be `normal' or a table with the values `italic', `bold', `underline' or `strikethrough'");
                        return luaL_argerror(L, 2, msg);
                    }
                    
                }
                else
                {
                    const char* msg = lua_pushfstring(L, "the table must contains the following values: `italic', `bold', `underline' or `strikethrough'");
                    return luaL_argerror(L, 2, msg);
                }
                
                lua_remove(L, -1);
            }
            lua_remove(L, -2);

            font->setStyle(style);
        }
        else
        {
            const char* msg = lua_pushfstring(L, "expected string or table, got %s", luaL_typename(L, 2));
            return luaL_argerror(L, 2, msg);
        }
    }
    // Get style
    else
    {
        lua_newtable(L);
        int pos = 0;
        int style = font->getStyle();
        
        if (style == TTF_STYLE_NORMAL)
        {
            lua_pushliteral(L, "normal");
            lua_rawseti(L, -1, ++pos);
        }

        if (style & TTF_STYLE_BOLD)
        {
            lua_pushliteral(L, "bold");
            lua_rawseti(L, -1, ++pos);
        }
        
        if (style & TTF_STYLE_ITALIC)
        {
            lua_pushliteral(L, "italic");
            lua_rawseti(L, -1, ++pos);
        }

        if (style & TTF_STYLE_UNDERLINE)
        {
            lua_pushliteral(L, "underline");
            lua_rawseti(L, -1, ++pos);
        }

        if (style & TTF_STYLE_STRIKETHROUGH)
        {
            lua_pushliteral(L, "strikethrough");
            lua_rawseti(L, -1, ++pos);
        }

        ret = 1;
    }

    return ret;
}

/***
 * Sets the outline size of the font
 * @function font.outline
 * @tparam font font A font object
 * @treturn int The size of the outline in pixels
 */

/***
 * Gets the outline size of the font
 * @function font.outline
 * @tparam font font A font object
 * @int size The size of the outline in pixels
 */
static int lraspi_font_outline(lua_State* L)
{
    int ret = 0;
    int argc = lua_gettop(L);

    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));

    if (argc == 2)
    {
        lua_Integer outline = luaL_checkinteger(L, 2);
        font->setOutline(outline);
    }
    else
    {
        lua_Integer outline = font->getOutline();
        lua_pushinteger(L, outline);
        ret = 1;
    }

    return ret;
}

/***
 * Sets the hinting mode of the font
 * @function font.hintingmode
 * @tparam font font A font object
 * @string mode The hinting mode as the following values:
 * <ul>
 * <li><span class='parameter'>normal</span> For default hinting</li>
 * <li><span class='parameter'>light</span> Results in fuzzier text but can sometimes preserve the original glyph shapes of the text better than normal hinting</li>
 * <li><span class='parameter'>mono</span> Results in aliased / unsmoothed text with either full opacity or completely transparent pixels</li>
 * <li><span class='parameter'>none</span> For no hinting</li>
 * </ul>
 */
static int lraspi_font_hinting_mode(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (std::strcmp(mode, "normal"))
    {
        font->setHintingMode(TTF_HINTING_NORMAL);
    }
    else if (std::strcmp(mode, "light"))
    {
        font->setHintingMode(TTF_HINTING_LIGHT);
    }
    else if (std::strcmp(mode, "mono"))
    {
        font->setHintingMode(TTF_HINTING_MONO);
    }
    else if (std::strcmp(mode, "none"))
    {
        font->setHintingMode(TTF_HINTING_NONE);
    }

    return 0;
}

/***
 * Gets the maximun ascent size of all glyphs of the font
 * @function font.ascent
 * @tparam font font A font object
 * @treturn int The maximun ascent in pixels
 */
static int lraspi_font_ascent(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getAscent());

    return 1;
}

/***
 * Gets the maximun descent size of all glyphs of the font
 * @function font.descent
 * @tparam font font A font object
 * @treturn int The maximun descent in pixels
 */
static int lraspi_font_descent(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getDescent());

    return 1;
}

/***
 * Gets the recomended height of a rendered line of text of the font.<br>
 * This value is usually larger than the font height
 * @function font.lineskip
 * @tparam font font A font object
 * @treturn int The maximun height of all glyphs in the font in pixels
 */
static int lraspi_font_line_skip(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getLineSkip());

    return 1;
}

/***
 * Sets the line height of the font.<br>
 * The space between lines is determined by the line height multiplied by the height of the font.
 * @function font.lineheight
 * @tparam font font A font object
 * @number height The space between lines when the text is rendered. The default value is 1.0
 */

/***
 * Gets the line height of the font
 * @function font.lineheight
 * @tparam font font A font object
 * @treturn number The space between lines when the text is rendered
 */
static int lraspi_font_line_height(lua_State* L)
{
    int ret = 0;
    int argc = lua_gettop(L);

    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));

    if (argc == 2)
    {
        lua_Number height = luaL_checknumber(L, 2);
        font->setLineHeight(height);
    }
    else
    {
        lua_Number height = font->getLineHeight();
        lua_pushnumber(L, height);
        ret = 1;
    }
    

    return ret;
}

/***
 * Get the current family name of the font
 * @function font.familyname
 * @tparam font font A font object
 * @return A string with the family name of the font or nil if the information is not avaliable
 */
static int lraspi_font_family_name(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* family_name = font->getFamilyName();

    if (family_name != nullptr)
    {
        lua_pushstring(L, family_name);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}

/***
 * Destroys a font object
 * @function font.free
 * @tparam font font A font object
 */
static int lraspi_font__gc(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    delete font;

    return 0;
}

/***
 * Closes the font subsystem.
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function font.close
 */
static int lraspi_font_close(lua_State* L)
{
    try
    {
        lraspi::font::close();
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 0;
}

/***
 * This object represents a font
 * @type font
 */

/***
 * Get the maximun height of the font
 * @function font:height
 * @treturn int The height of the font in pixels
 */

/***
 * Calculates the size of the text using font
 * @function font:width
 * @string text The string to calculate the font
 * @treturn int The size in pixels of the resulting texture if the text was rendered using the font
 */

/***
 * Formats the text with a maximun text width size.<br>
 * This functions add new lines if the text width size reachs the given wrap limit.
 * @function font:wrap
 * @string text The text that will be wrapped
 * @int width The maximun width in pixels of each line
 * @treturn string The text wrapped
 */

/***
 * Sets the rendering style of the text
 * @function font:style
 * @param style The value "normal" for the default style or a list with the styles as the following values:
 * <ul>
 * <li><span class='parameter'>italic</span> Displays the font as a cursive style</li>
 * <li><span class='parameter'>bold</span> Displays the font as a strong style</li>
 * <li><span class='parameter'>underline</span> Displays the font with a line under the text</li>
 * <li><span class='parameter'>strikethrough</span> Displays the font with a line through the text</li>
 * </ul>
 */

/***
 * Gets the rendering style of the text
 * @function font:style
 * @treturn table A list with the styles as the following values:
 * <ul>
 * <li><span class='parameter'>normal</span> The default font style</li>
 * <li><span class='parameter'>italic</span> Displays the font as a cursive style</li>
 * <li><span class='parameter'>bold</span> Displays the font as a strong style</li>
 * <li><span class='parameter'>underline</span> Displays the font with a line under the text</li>
 * <li><span class='parameter'>strikethrough</span> Displays the font with a line through the text</li>
 * </ul>
 */

/***
 * Sets the outline size of the font
 * @function font:outline
 * @treturn int The size of the outline in pixels
 */

/***
 * Gets the outline size of the font
 * @function font:outline
 * @int size The size of the outline in pixels
 */

/***
 * Sets the hinting mode of the font
 * @function font:hintingmode
 * @string mode The hinting mode as the following values:
 * <ul>
 * <li><span class='parameter'>normal</span> For default hinting</li>
 * <li><span class='parameter'>light</span> Results in fuzzier text but can sometimes preserve the original glyph shapes of the text better than normal hinting</li>
 * <li><span class='parameter'>mono</span> Results in aliased / unsmoothed text with either full opacity or completely transparent pixels</li>
 * <li><span class='parameter'>none</span> For no hinting</li>
 * </ul>
 */

/***
 * Gets the maximun ascent size of all glyphs of the font
 * @function font:ascent
 * @treturn int The maximun ascent in pixels
 */

/***
 * Gets the maximun descent size of all glyphs of the font
 * @function font:descent
 * @treturn int The maximun descent in pixels
 */

/***
 * Gets the recomended height of a rendered line of text of the font.<br>
 * This value is usually larger than the font height
 * @function font:lineskip
 * @treturn int The maximun height of all glyphs in the font in pixels
 */

/***
 * Sets the line height of the font.<br>
 * The space between lines is determined by the line height multiplied by the height of the font.
 * @function font:lineheight
 * @number height The space between lines when the text is rendered. The default value is 1.0
 */

/***
 * Gets the line height of the font
 * @function font:lineheight
 * @treturn number The space between lines when the text is rendered
 */

/***
 * Get the current family name of the font
 * @function font:familyname
 * @return A string with the family name of the font or nil if the information is not avaliable
 */
static const luaL_Reg lraspi_font_object[] =
{
    {"height",      lraspi_font_height},
    {"width",       lraspi_font_width},
    {"wrap",        lraspi_font_wrap},
    {"style",       lraspi_font_style},
    {"outline",     lraspi_font_outline},
    {"hintingmode", lraspi_font_hinting_mode},
    {"ascent",      lraspi_font_ascent},
    {"descent",     lraspi_font_descent},
    {"lineskip",    lraspi_font_line_skip},
    {"lineheight",  lraspi_font_line_height},
    {"familyname",  lraspi_font_family_name},
    {"__gc",        lraspi_font__gc},
    {0, 0}
};

static const luaL_Reg lraspi_font[] =
{
    {"init",        lraspi_font_init},
    {"load",        lraspi_font_load},
    {"create",      lraspi_font_create},
    {"height",      lraspi_font_height},
    {"width",       lraspi_font_width},
    {"wrap",        lraspi_font_wrap},
    {"style",       lraspi_font_style},
    {"outline",     lraspi_font_outline},
    {"hintingmode", lraspi_font_hinting_mode},
    {"ascent",      lraspi_font_ascent},
    {"descent",     lraspi_font_descent},
    {"lineskip",    lraspi_font_line_skip},
    {"lineheight",  lraspi_font_line_height},
    {"familyname",  lraspi_font_family_name},
    {"free",        lraspi_font__gc},
    {"close",       lraspi_font_close},
    {0, 0}
};

int luaopen_font(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Font::type, lraspi_font_object);
    luaL_newlib(L, lraspi_font);
    return 1;
}

}
