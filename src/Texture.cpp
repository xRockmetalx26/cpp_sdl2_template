//
// Created by xRockmetalx
//

#include <Texture.h>
#include <SDL2/SDL_render.h>

void Texture::delete_texture() { if(texture) SDL_DestroyTexture(texture); }

Size Texture::get_size_texture() const {
    int width{};
    int height{};

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    return Size{width, height};
}
