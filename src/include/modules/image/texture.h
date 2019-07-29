/**
 * include/modules/image/texture.h - NEKERAFA - 28th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_WRAPPER_TEXTURE_H
#define LRASPI_WRAPPER_TEXTURE_H

#include <string>

#include <SDL2/SDL.h>

namespace lraspi
{
namespace image
{

class texture {
private:
    SDL_Texture* _sdl_texture;
    SDL_Renderer* _sdl_context;
    int _width, _height;
    int _tex_width, _tex_height;
    double _tex_angle;
    SDL_Point _tex_center;
    SDL_RendererFlip _tex_flip;

public:
    texture(SDL_Renderer* context);
    ~texture();
    bool load(std::string path);
    int getWidth();
    int getHeight();
    int getRealWidth() const;
    int getRealHeight() const;
    void blit(int x = 0, int y = 0);
};

} // namespace image
} // namespace lraspi

#endif // LRASPI_WRAPPER_TEXTURE_H