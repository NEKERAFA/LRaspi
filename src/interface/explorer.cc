/**
 * interface/explorer.cc - NEKERAFA - 28th aug 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRAPI_INTERFACE_EXPLORER_H
#define LRAPI_INTERFACE_EXPLORER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cinttypes>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "lraspi.h"
#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/color/color_mod.h"
#include "modules/image/image.h"
#include "modules/image/image_mod.h"
#include "modules/screen/screen_mod.h"

#include "explorer.h"

namespace lraspi
{

namespace explorer
{

Image*   _logo = nullptr;
Text*    _title = nullptr;
Color*   _color_title = nullptr;
Font*    _default_font = nullptr;

SDL_Renderer* _sdl_renderer = nullptr;

SDL_Rect _explorer_bg;

char _str_time[32] = "";

std::vector<std::string> _file_list;

int _current_file = 0;

int _logo_x = 0;
int _logo_y = 0;

uint16_t _page_max = 0;
uint16_t _item_per_page = 0;

uint16_t _screen_width = 0;
uint16_t _screen_height = 0;

uint16_t _selector_width = 0;

bool _old_up = false;
bool _old_down = false;

void loadlogo()
{
    // Loads the logo
    try
    {
        _logo = image::loadImage((std::string(LRASPI_RES_FOLDER) + std::string("/logo.png")).c_str());
    }
    catch(lraspi::Exception e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    _logo->setSdlBlendMode(SDL_BLENDMODE_BLEND);
    _logo->setAlpha(100);
    _logo->setWidth(256);
    _logo->setHeight(256);
}

void rendertitle()
{
    try
    {
        // Render title text
        _title = image::createText(_default_font, "Lua Raspi");
        _title->setQuality(TextQuality::NORMAL);
        _title->tint(_color_title);
    }
    catch(lraspi::Exception e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void listdir()
{
    DIR* _pdir = nullptr;
    struct dirent* _sdir = nullptr;

    // Checks the directory
    if (!(_pdir = opendir(".")))
    {
        std::cerr << "Could not open directory" << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        // Iterate directory
        while((_sdir = readdir(_pdir)) != NULL)
        {
            struct stat _file_info;

            // Checks the file
            if (lstat(_sdir->d_name, &_file_info) == -1)
            {
                std::cerr << "Could not open file '" << _sdir->d_name << "' (" << strerror(errno) << ")" << std::endl;
                exit(EXIT_FAILURE);
            }
            // Checks the extension
            else if (S_ISREG(_file_info.st_mode))
            {
                // Checks the extension
                char* find_ext = std::strrchr(_sdir->d_name, '.');
                if (find_ext && strcmp(find_ext+1, "lua") == 0)
                    _file_list.push_back(std::string(_sdir->d_name));
            }
        }
    }
}

void load()
{
    _color_title = new Color(32, 32, 32);
    _sdl_renderer = screen::getRenderer();
    _screen_width = screen::getWidth();
    _screen_height = screen::getHeight();
    _default_font = screen::getFont();
    _selector_width = _default_font->getWidth(">");
    _explorer_bg = {40, 60, _screen_width - 80, _screen_height - 100};

    loadlogo();
    rendertitle();

    _logo_x = ((double) (_screen_width-_logo->getWidth()))/2;
    _logo_y = ((double) (_screen_height-_logo->getHeight()))/2;

    listdir();

    _page_max = (_file_list.size()*(_default_font->getHeight()+2)) / (_explorer_bg.h-40);
    _item_per_page = (_explorer_bg.h-40) / (_default_font->getHeight()+2);
}

void gettime()
{
    time_t rawtime;
    struct tm* tminfo = nullptr;

    // Gets the time info
    time(&rawtime);
    tminfo = localtime(&rawtime);

    // Gets the time string
    std::strftime(_str_time, sizeof(_str_time), "%a, %b %0e %Y, %R", tminfo);
}

const char* changefile()
{
    const Uint8* _current_keystates = SDL_GetKeyboardState(nullptr);

    // Checks the enter button
    if (_current_keystates[SDL_SCANCODE_RETURN])
        return _file_list[_current_file].c_str();

    // Checks the up arrow button
    if ((_current_keystates[SDL_SCANCODE_UP]) && (_current_keystates[SDL_SCANCODE_UP] != _old_up))
        if (_current_file > 0)
            _current_file--;

    // Checks the down arrow button
    if ((_current_keystates[SDL_SCANCODE_DOWN]) && (_current_keystates[SDL_SCANCODE_DOWN] != _old_down))
        if (_current_file < _file_list.size()-1)
            _current_file++;

    _old_up = _current_keystates[SDL_SCANCODE_UP];
    _old_down = _current_keystates[SDL_SCANCODE_DOWN];

    return nullptr;
}

const char* update()
{
    gettime();
    return changefile();
}

void drawtitle()
{
    int _time_x = _screen_width-_default_font->getWidth(_str_time)-3;
    Uint8 r, g, b, a;

    SDL_GetRenderDrawColor(_sdl_renderer, &r, &g, &b, &a);

    // Draw title bg
    for (int i = 0; i < 20; i++)
    {
        Uint8 color = 255-i*55/20;
        SDL_SetRenderDrawColor(_sdl_renderer, color, color, color, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(_sdl_renderer, 0, i, _screen_width, i);
    }

    SDL_SetRenderDrawColor(_sdl_renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(_sdl_renderer, 0, 20, _screen_width, 20);
    SDL_RenderDrawLine(_sdl_renderer, _time_x-4, 0, _time_x-4, 19);
    SDL_SetRenderDrawColor(_sdl_renderer, r, g, b, a);

    // Draw title
    screen::blit(_title, 3, 3);

    // Draw hour
    if (std::strlen(_str_time) > 0)
        screen::print(_time_x, 3, _str_time, _color_title);
}

void drawexplorer()
{
    int pos = 0;
    Uint8 r, g, b, a;
    SDL_BlendMode mode;

    SDL_GetRenderDrawColor(_sdl_renderer, &r, &g, &b, &a);
    SDL_GetRenderDrawBlendMode(_sdl_renderer, &mode);

    // Draw background
    SDL_SetRenderDrawColor(_sdl_renderer, 128, 128, 128, 128);
    SDL_SetRenderDrawBlendMode(_sdl_renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(_sdl_renderer, &_explorer_bg);
    SDL_SetRenderDrawColor(_sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    // Draw logo
    screen::blit(_logo, _logo_x, _logo_y);

    uint16_t _current_page = (_current_file*(_default_font->getHeight()+2)) / (_explorer_bg.h-40);

    for (int i = _current_page*_item_per_page; i < std::min((_current_page+1)*_item_per_page, (int) _file_list.size()); i++)
    {
        uint16_t pos = i - _current_page*_item_per_page;

        // Draw selector
        if (i == _current_file)
        {
            SDL_Rect selector = {50, 80+pos*(_default_font->getHeight()+2), _screen_width-100, _default_font->getHeight()};
            SDL_RenderFillRect(_sdl_renderer, &selector);
            screen::print(60, 80+pos*(_default_font->getHeight()+2), ">", _color_title);
        }

        // Draw file
        screen::print(60+_selector_width+5, 80+pos*(_default_font->getHeight()+2), _file_list[i].c_str(), _color_title);
    }

    SDL_SetRenderDrawColor(_sdl_renderer, r, g, b, a);
    SDL_SetRenderDrawBlendMode(_sdl_renderer, mode);
}

void draw()
{
    screen::clear(color::white);
    drawtitle();
    drawexplorer();
}

void close()
{
    delete _logo;
    delete _title;
    delete _color_title;
}

} // namespace explorer

} // namespace lraspi

#endif // LRAPI_INTERFACE_EXPLORER_H
