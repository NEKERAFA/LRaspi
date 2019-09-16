/*
    include/lraspi/ltext.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_TEXT_LUA_H
#define LRASPI_TEXT_LUA_H

#include <lua.hpp>

/***
 * This object represents a rendered text
 * @classmod text
 * @see texture
 */
extern "C" {

/***
 * Sets the quality to render text
 * @function text.setquality
 * @tparam text text A text object
 * @string quality A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */
int lraspi_text_set_quality(lua_State* L);

/***
 * Gets the quality to render text
 * @function text.getquality
 * @tparam text text A text object
 * @treturn string A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */
int lraspi_text_get_quality(lua_State* L);

/***
 * Replaces the content of the text with a new value
 * @function text.set
 * @tparam text text A text object
 * @string textstring The new content
 */
int lraspi_text_set(lua_State* L);

/***
 * Adds a new content to the rendered text
 * @function text.add
 * @tparam text text A text object
 * @string textstring The text to append
 */
int lraspi_text_add(lua_State* L);

/***
 * Clears the content of the rendered text
 * @function text.clear
 * @tparam text text A text object
 */
int lraspi_text_clear(lua_State* L);

int luaopen_text(lua_State* L);

}

#endif // LRASPI_TEXT_LUA_H