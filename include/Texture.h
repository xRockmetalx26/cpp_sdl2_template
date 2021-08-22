//
// Created by xRockmetalx
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <Size.h>

struct SDL_Texture;

class Texture {
public:

    void delete_texture();

    Size get_size_texture() const;

protected:

    SDL_Texture *texture{};
};

#endif // TEXTURE_H
