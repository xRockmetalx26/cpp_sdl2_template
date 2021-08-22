//
// Created by xRockmetalx
//

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <Transformable.h>
#include <Texture.h>
#include <Drawable.h>
#include <Position.h>
#include <Size.h>
#include <SDL2/SDL_rect.h>

class Sprite : public Transformable, public Texture, public Drawable {
public:

    explicit Sprite(const std::string &filename, const Position &position = Position{}, const Size &size = Size{});

    void draw() const override;

    void load_image(const std::string &filename);

    void set_rectangle_texture(const Position &position, const Size &size);

private:

    SDL_Rect rectangle_texture{};
};

#endif // SPRITE_H
