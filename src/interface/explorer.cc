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
#include <ctime>
#include <cstring>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

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

Image* _bg[4];
Image* _logo;
Text*  _title;
Color* _color_title;

std::vector<std::string> _file_list;

int _current_bg = 0;
int _current_file = 0;

std::string gettime()
{
    time_t rawtime;
    struct tm* tminfo;
    char buffer[64];

    // Gets the time
    time(&rawtime);
    tminfo = localtime(&rawtime);

    std:strftime(buffer, sizeof(buffer), "%a, %b %0e %b, %R", tminfo);

    return std::string(buffer);
}

void loadbg()
{
    for (int i = 0; i < 4; i++)
    {
        // Loads the background
        try
        {
            _bg[i] = image::loadImage(std::string("res/bg" + std::to_string(i+1) + ".jpg").c_str());
        }
        catch(lraspi::Exception e)
        {
            std::cerr << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        // Calculates the ratio
        double x_ratio = (double) screen::getWidth() / (double) _bg[i]->getRealWidth();
        double y_ratio = (double) screen::getHeight() / (double) _bg[i]->getRealHeight();

        // Checks the size of the image to resize proportionaly
        if (x_ratio*_bg[i]->getRealHeight() > screen::getHeight())
        {
            _bg[i]->setWidth((int) screen::getWidth());
            _bg[i]->setHeight(x_ratio*_bg[i]->getRealHeight());
        }
        else
        {
            _bg[i]->setWidth(y_ratio*_bg[i]->getRealWidth());
            _bg[i]->setHeight((int) screen::getHeight());
        }
    }

}

void loadlogo()
{
    // Loads the logo
    try
    {
        _logo = image::loadImage("res/logo.png");
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
    // Render title
    try
    {
        _title = image::createText(screen::getFont(), "Lua Raspi");
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
    DIR* _pdir;
    struct dirent* _sdir;

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
                std::cerr << "Could not open file" << _sdir->d_name << strerror(errno) << std::endl;
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

    loadbg();
    loadlogo();
    rendertitle();
    listdir();
}

void update()
{

}

void drawbg()
{
    int x = ((double) (screen::getWidth()-_bg[_current_bg]->getWidth()))/2;
    int y = ((double) (screen::getHeight()-_bg[_current_bg]->getHeight()))/2;
    screen::blit(_bg[_current_bg], x, y);
}

void drawhub()
{
    // Draw title
    for (int i = 0; i < 20; i++)
    {
        Uint8 color = 255-i*55/20;
        SDL_SetRenderDrawColor(screen::getRenderer(), color, color, color, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(screen::getRenderer(), 0, i, screen::getWidth(), i);
    }

    std::string _str_time = gettime();
    int _time_x = screen::getWidth()-screen::getFont()->getWidth(_str_time.c_str())-3;

    SDL_SetRenderDrawColor(screen::getRenderer(), 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(screen::getRenderer(), 0, 20, screen::getWidth(), 20);
    SDL_RenderDrawLine(screen::getRenderer(), _time_x-4, 0, _time_x-4, 19);
    SDL_SetRenderDrawColor(screen::getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);

    screen::blit(_title, 3, 3);
    screen::print(_time_x, 3, _str_time.c_str(), _color_title);
}

void drawexplorer()
{
    SDL_SetRenderDrawColor(screen::getRenderer(), 255, 255, 255, 128);
    SDL_SetRenderDrawBlendMode(screen::getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_Rect r = {40, 60, screen::getWidth() - 80, screen::getHeight() - 100};
    SDL_RenderFillRect(screen::getRenderer(), &r);
    SDL_SetRenderDrawColor(screen::getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_SetRenderDrawBlendMode(screen::getRenderer(), SDL_BLENDMODE_NONE);

    int x = ((double) (screen::getWidth()-_logo->getWidth()))/2;
    int y = ((double) (screen::getHeight()-_logo->getHeight()))/2;
    screen::blit(_logo, x, y);

    int pos = 0;
    int width = screen::getFont()->getWidth(">");
    int height = screen::getFont()->getHeight();

    for (auto it = _file_list.begin(); it != _file_list.end(); it++)
    {
        if (pos == _current_file)
        {
            SDL_Rect r = {40, 80+pos*(height+2), screen::getWidth()-80, height};
            SDL_RenderFillRect(screen::getRenderer(), &r);
            screen::print(60, 80+pos*(height+2), ">", _color_title);
        }
        screen::print(60+width+5, 80+pos*(height+2), (*it).c_str(), _color_title);
        pos++;
    }
}

void draw()
{
    drawbg();
    drawhub();
    drawexplorer();
}

void close()
{
    for (int i = 0; i < 4; i++)
    {
        delete _bg[i];
    }
    delete _logo;
    delete _title;
    delete _color_title;
}

} // namespace explorer

} // namespace lraspi

#endif // LRAPI_INTERFACE_EXPLORER_H