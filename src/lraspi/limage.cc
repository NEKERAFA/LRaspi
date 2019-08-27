/*
    lraspi/limage.cc - NEKERAFA - 13th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"
#include "modules/image/image_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/limage.h"

/***
 * Image reading and manipulation and 2D accelerated rendering
 * @module Image
 */
extern "C"
{

/***
 * Initializes the image subsystem.<br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.init
 */
static int lraspi_image_init(lua_State* L)
{
    try
    {
        lraspi::image::init();
    }
    catch (lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

/***
 * Creates a blank texture
 * @function image.new
 * @int width The width dimension of the new texture in pixels
 * @int height The height dimension of the new texture in pixels
 * @treturn texture A texture object
 */ 
static int lraspi_image_new(lua_State* L)
{
    lua_Integer width = luaL_checkinteger(L, 1);
    lua_Integer height = luaL_checkinteger(L, 2);

    try
    {
        lraspi::Texture* texture = lraspi::image::createBlankTexture(width, height);
        lraspi::lua::push(L, lraspi::Texture::type, texture);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

/***
 * Loads an image from the disk onto the memory
 * @function image.load
 * @string path The path of the image file.
 * @treturn image An image object
 */ 
static int lraspi_image_load(lua_State* L)
{
    const char* path = luaL_checkstring(L, 1);

    try
    {
        lraspi::Image* image = lraspi::image::loadImage(path);
        lraspi::lua::push(L, lraspi::Image::type, image);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

/***
 * Creates a text texture
 * @function image.newtext
 * @tparam font A font object
 * @string text The text to render
 * @treturn text An text object
 */
static int lraspi_image_new_text(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* str = luaL_checkstring(L, 2);

    try
    {
        lraspi::Text* text = lraspi::image::createText(font, str);
        lraspi::lua::push(L, lraspi::Text::type, text);
    }
    catch (lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

/***
 * Resets the internal values (rotation, flip, resize, ...) of the texture
 * @function image.reset
 * @tparam texture texture A texture object
 */ 
static int lraspi_image_reset(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->reset();

    return 0;
}

/***
 * Changes the color modulation of the texture
 * @function image.tint
 * @tparam texture texture A texture object
 * @tparam color color A color object
 */ 
static int lraspi_image_tint(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 2));
    texture->tint(color);

    return 0;
}

/***
 * Changes the blend mode of the texture
 * @function image.blendmode
 * @tparam texture texture A texture object
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */
static int lraspi_image_blend_mode(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (std::strcmp(mode, "add") == 0) {
        texture->setSdlBlendMode(SDL_BLENDMODE_ADD);
    }
    else if (std::strcmp(mode, "mod") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_MOD);
    }
    else if (std::strcmp(mode, "blend") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_BLEND);
    }
    else if (std::strcmp(mode, "none") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_NONE);
    }
    else
    {
        const char* msg = lua_pushfstring(L, "must be `add', `mod', `blend' or `none'");
        return luaL_argerror(L, 2, msg);
    }

    return 0;
}

/***
 * Changes the alpha value of the texture. <br>
 * The texture must have an blend mode established
 * @function image.alpha
 * @tparam texture texture A texture object
 * @int alpha The alpha value
 */
static int lraspi_image_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer alpha = luaL_checkinteger(L, 2);
    texture->setAlpha(alpha);

    return 0;
}

/***
 * Gets the current width dimension of the texture
 * @function image.width
 * @tparam texture texture A texture object
 * @treturn int The current width dimension in pixels
 */
static int lraspi_image_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getWidth();
    lua_pushinteger(L, width);

    return 1;
}

/***
 * Gets the current height dimension of the texture
 * @function image.height
 * @tparam texture texture A texture object
 * @treturn int The current height dimension in pixels
 */
static int lraspi_image_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getHeight();
    lua_pushinteger(L, height);

    return 1;
}

/***
 * Gets the real width dimension of the texture
 * @function image.realwidth
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
static int lraspi_image_real_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getRealWidth();
    lua_pushinteger(L, width);

    return 1;   
}

/***
 * Gets the real width dimension of the texture
 * @function image.realheight
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
static int lraspi_image_real_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getRealHeight();
    lua_pushinteger(L, height);

    return 1;
}

/***
 * Resizes the texture
 * @function image.resize
 * @tparam texture texture A texture object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */
static int lraspi_image_resize(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    texture->setWidth(width);
    texture->setHeight(height);

    return 0;
}

/***
 * Rotates the texture
 * @function image.rotate
 * @tparam texture texture A texture object
 * @number angle The angle in degrees
 */
static int lraspi_image_rotate(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Number angle = luaL_checknumber(L, 2);
    texture->setAngle(angle);

    return 0;
}

/***
 * Sets the center of the texture
 * @function image.center
 * @tparam texture texture A texture object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */

/***
 * Gets the center of the texture
 * @function image.center
 * @tparam texture texture A texture object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */
static int lraspi_image_center(lua_State* L)
{
    int ret = 0;
    int argc = lua_gettop(L);

    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    
    if (argc == 3)
    {
        lua_Integer x = luaL_checkinteger(L, 2);
        lua_Integer y = luaL_checkinteger(L, 3);
        texture->setCenter(x, y);
    }
    else
    {
        SDL_Point point = texture->getSdlCenterPoint();
        lua_pushinteger(L, point.x);
        lua_pushinteger(L, point.y);

        ret = 2;
    }

    return ret;
}


/***
 * Flips a texture vertically
 * @tparam texture texture A texture object
 * @function image.vflip
 */
static int lraspi_image_v_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setVFlip();

    return 0;
}

/***
 * Flips a texture horizontally
 * @tparam texture texture A texture object
 * @function image.hflip
 */
static int lraspi_image_h_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setHFlip();

    return 0;
}

/***
 * Checks if the texture is flipped
 * @function image.flip
 * @tparam texture texture A texture object
 * @treturn boolean true if the texture is flipped vertically
 * @treturn boolean true if the texture if flipped horizontally
 */
static int lraspi_image_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_RendererFlip flip = texture->getSdlFlipStatus();
    lua_pushboolean(L, flip & SDL_FLIP_VERTICAL);
    lua_pushboolean(L, flip & SDL_FLIP_HORIZONTAL);

    return 2;
}

/***
 * Blits the texture onto another texture
 * @function image.blit
 * @tparam texture texture A texture object
 * @tparam texture origin The texture to blit
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 */
static int lraspi_image_blit(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Texture* other = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 2));
    lua_Integer x = luaL_checkinteger(L, 3);
    lua_Integer y = luaL_checkinteger(L, 4);
    texture->blit(other, x, y);

    return 0;
}

/***
 * Sets the quality to render text
 * @function image.textquality
 * @tparam text text A text object
 * @string quality A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */


/***
 * Gets the quality to render text
 * @function image.textquality
 * @tparam text text A text object
 * @treturn string A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */
static int lraspi_image_text_quality(lua_State* L)
{
    int argc = lua_gettop(L);
    int ret = 0;

    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));

    if (argc == 2)
    {
        const char* quality = luaL_checkstring(L, 2);

        if (std::strcmp(quality, "fast") == 0)
        {
            text->setQuality(lraspi::TextQuality::FAST);
        }
        else if (std::strcmp(quality, "normal") == 0)
        {
            text->setQuality(lraspi::TextQuality::NORMAL);
        }
        else
        {
            const char* msg = lua_pushfstring(L, "must be `fast' or `normal'");
            luaL_argerror(L, 2, msg);
        }
    }
    else
    {
        switch (text->getQuality())
        {
        case lraspi::TextQuality::FAST:
            lua_pushliteral(L, "fast");
            break;
        case lraspi::TextQuality::NORMAL:
            lua_pushliteral(L, "normal");
            break;
        }

        ret = 1;
    }
    

    return ret;
}

/***
 * Replaces the content of the text with a new value
 * @function image.set
 * @tparam text text A text object
 * @string textstring The new content
 */
static int lraspi_image_set_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->setText(str);
    return 0;
}

/***
 * Adds a new content to the rendered text
 * @function image.add
 * @tparam text text A text object
 * @string textstring The text to append
 */
static int lraspi_image_add_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->addText(str);
    return 0;
}

/***
 * Clears the content of the rendered text
 * @function image.clear
 * @tparam text text A text object
 */
static int lraspi_image_clear_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->clear();
    return 0;
}

/***
 * Destroys a texture object
 * @function image.free
 * @tparam texture texture A texture object
 */
static int lraspi_image__gc(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    delete texture;

    return 0;
}

/***
 * Closes the image subsystem.
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.close
 */
static int lraspi_image_close(lua_State* L)
{
    try
    {
        lraspi::image::close();
    }
    catch(lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

/***
 * This object represents a texture
 * @type texture
 */

/***
 * Resets the internal values (rotation, flip, resize, ...) of the texture
 * @function texture:reset
 */ 

/***
 * Changes the color modulation of the texture
 * @function texture:tint
 * @tparam color color A color object
 */

/***
 * Changes the blend mode of the textue
 * @function texture:blendmode
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><pre>add</pre> for additive blending</li>
 * <li><pre>mod</pre> for color modulation</li>
 * <li><pre>blend</pre> for alpha blending</li>
 * <li><pre>none</pre> for no blending</li>
 * </ul>
 */

/***
 * Changes the alpha value of the texture. The texture must have an blend mode established.
 * @function texture:alpha
 * @int alpha The alpha value
 */

/***
 * Gets the current width dimension of the texture
 * @function texture:width
 * @treturn int The current width dimension in pixels
 */

/***
 * Gets the current height dimension of the texture
 * @function texture:height
 * @treturn int The current height dimension in pixels
 */

/***
 * Gets the real width dimension of the texture
 * @function texture:realwidth
 * @treturn int The real width dimension in pixels
 */

/***
 * Gets the real height dimension of the texture
 * @function texture:realheight
 * @treturn int The real height dimension in pixels
 */

/***
 * Resizes the texture
 * @function texture:resize
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */

/***
 * Rotates the texture
 * @function texture:rotate
 * @number angle The angle in degrees
 */

/***
 * Sets the center of the texture
 * @function texture:center
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */

/***
 * Gets the center of the texture
 * @function texture:center
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */

/***
 * Flips a texture vertically
 * @function texture:vflip
 */

/***
 * Flips a texture horizontally
 * @function texture:hflip
 */

/***
 * Checks if the texture is flipped
 * @function texture:flip
 * @treturn boolean true if the texture is flipped vertically
 * @treturn boolean true if the texture if flipped horizontally
 */

/***
 * Blits the texture onto another texture
 * @function texture:blit
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 */
static const luaL_Reg lraspi_texture_object[] =
{
    {"reset",      lraspi_image_reset},
    {"tint",       lraspi_image_tint},
    {"alpha",      lraspi_image_alpha},
    {"rotate",     lraspi_image_rotate},
    {"center",     lraspi_image_center},
    {"vflip",      lraspi_image_v_flip},
    {"hflip",      lraspi_image_h_flip},
    {"flip",       lraspi_image_flip},
    {"width",      lraspi_image_width},
    {"height",     lraspi_image_height},
    {"realwidth",  lraspi_image_real_width},
    {"realheight", lraspi_image_real_height},
    {"resize",     lraspi_image_resize},
    {"blendmode",  lraspi_image_blend_mode},
    {"blit",       lraspi_image_blit},
    {"__gc",       lraspi_image__gc},
    {0, 0}
};

/***
 * This object represents a rendered text
 * @type text
 */

/***
 * Sets the quality to render text
 * @function text:textquality
 * @string quality A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */


/***
 * Gets the quality to render text
 * @function text:textquality
 * @treturn string A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */

/***
 * Replaces the content of the text with a new value
 * @function text:set
 * @string textstring The new content
 */

/***
 * Adds a new content to the rendered text
 * @function text:add
 * @string textstring The text to append
 */

/***
 * Clears the content of the rendered text
 * @function text:clear
 */
static const luaL_Reg lraspi_text_object[] =
{
    {"textquality", lraspi_image_text_quality},
    {"set",         lraspi_image_set_text},
    {"add",         lraspi_image_add_text},
    {"clear",       lraspi_image_clear_text},
    {"reset",       lraspi_image_reset},
    {"tint",        lraspi_image_tint},
    {"alpha",       lraspi_image_alpha},
    {"rotate",      lraspi_image_rotate},
    {"center",      lraspi_image_center},
    {"vflip",       lraspi_image_v_flip},
    {"hflip",       lraspi_image_h_flip},
    {"flip",        lraspi_image_flip},
    {"width",       lraspi_image_width},
    {"height",      lraspi_image_height},
    {"realwidth",   lraspi_image_real_width},
    {"realheight",  lraspi_image_real_height},
    {"resize",      lraspi_image_resize},
    {"blendmode",   lraspi_image_blend_mode},
    {"blit",        lraspi_image_blit},
    {"__gc",        lraspi_image__gc},
    {0, 0}
};

static const luaL_Reg lraspi_image[] =
{
    {"init",       lraspi_image_init},
    {"new",        lraspi_image_new},
    {"newtext",    lraspi_image_new_text},
    {"load",       lraspi_image_load},
    {"reset",      lraspi_image_reset},
    {"tint",       lraspi_image_tint},
    {"alpha",      lraspi_image_alpha},
    {"rotate",     lraspi_image_rotate},
    {"center",     lraspi_image_center},
    {"vflip",      lraspi_image_v_flip},
    {"hflip",      lraspi_image_h_flip},
    {"flip",       lraspi_image_flip},
    {"width",      lraspi_image_width},
    {"height",     lraspi_image_height},
    {"realwidth",  lraspi_image_real_width},
    {"realheight", lraspi_image_real_height},
    {"resize",     lraspi_image_resize},
    {"blendmode",  lraspi_image_blend_mode},
    {"blit",       lraspi_image_blit},
    {"free",       lraspi_image__gc},
    {"close",      lraspi_image_close},
    {0, 0}
};

int luaopen_image(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Texture::type, lraspi_texture_object);
    lraspi::lua::registerobject(L, lraspi::Image::type, lraspi_texture_object);
    lraspi::lua::registerobject(L, lraspi::Text::type, lraspi_text_object);
    luaL_newlib(L, lraspi_image);
    return 1;
}

}