/*
    include/lraspi/lfont.h - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_FONT_LUA_H
#define LRASPI_FONT_LUA_H

#include <lua.hpp>

/***
 * TrueType font reading and text rendering
 * @module Font
 */

/***
 * Initializes the font submodule. <br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function font.init
 */

/***
 * Loads a font from the disk onto the memory
 * @function font.new
 * @string path The path of the font file
 * @int[opt=12] size The size of the font in pixels
 * @treturn font A font object
 */

/***
 * Create a font using the default font (DejaVu) with a custom size
 * @function font.newdefault
 * @int[opt=12] size The size of the font in pixels
 * @treturn font A font object
 */

/***
 * Get the maximun height of the font
 * @function font.getheight
 * @tparam font font A font object
 * @treturn int The height of the font in pixels
 */

/***
 * Calculates the size of the text using font
 * @function font.getwidth
 * @tparam font font A font object
 * @string text The string to calculate the font
 * @treturn int The size in pixels of the resulting texture if the text was rendered using the font
 */

/***
 * Formats the text with a maximun text width size. <br>
 * This functions add new lines if the text width size reachs the given wrap limit
 * @function font.wrap
 * @tparam font font A font object
 * @string text The text that will be wrapped
 * @int width The maximun width in pixels of each line
 * @treturn string The text wrapped
 */

/***
 * Sets the rendering style of the text
 * @function font.setstyle
 * @tparam font font A font object
 * @string[opt='normal'] style The value "normal" for the default style or a list with the styles as the following values:
 * <ul>
 * <li><span class='parameter'>italic</span> Displays the font as a cursive style</li>
 * <li><span class='parameter'>bold</span> Displays the font as a strong style</li>
 * <li><span class='parameter'>underline</span> Displays the font with a line under the text</li>
 * <li><span class='parameter'>strikethrough</span> Displays the font with a line through the text</li>
 * </ul>
 */

/***
 * Gets the rendering style of the text
 * @function font.getstyle
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

/***
 * Gets the maximun ascent size of all glyphs of the font
 * @function font.ascent
 * @tparam font font A font object
 * @treturn int The maximun ascent in pixels
 */

/***
 * Gets the maximun descent size of all glyphs of the font
 * @function font.descent
 * @tparam font font A font object
 * @treturn int The maximun descent in pixels
 */

/***
 * Gets the recomended height of a rendered line of text of the font. <br>
 * This value is usually larger than the font height
 * @function font.lineskip
 * @tparam font font A font object
 * @treturn int The maximun height of all glyphs in the font in pixels
 */

/***
 * Sets the line height of the font. <br>
 * The space between lines is determined by the line height multiplied by the height of the font.
 * @function font.setlineheight
 * @tparam font font A font object
 * @number height The space between lines when the text is rendered. The default value is 1.0
 */

/***
 * Gets the line height of the font
 * @function font.getlineheight
 * @tparam font font A font object
 * @treturn number The space between lines when the text is rendered
 */

/***
 * Get the current family name of the font
 * @function font.familyname
 * @tparam font font A font object
 * @return A string with the family name of the font or nil if the information is not avaliable
 */

/***
 * Destroys a font object
 * @function font.free
 * @tparam font font A font object
 */

/***
 * Closes the font subsystem. <br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function font.close
 */

extern "C" {

int luaopen_font(lua_State* L);

}

#endif // LRASPI_FONT_LUA_H