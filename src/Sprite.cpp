//
// Created by xRockmetalx
//

#include <Sprite.h>
#include <RenderWindow.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(const std::string &filename, const Position &position, const Size &size)
    : Transformable{position, size} {
    load_image(filename);
}

void Sprite::load_image(const std::string &filename) {
    delete_texture();

    SDL_Surface* surface_image = IMG_Load(filename.c_str());
    texture = SDL_CreateTextureFromSurface(RenderWindow::get_instance().get_renderer(), surface_image);
    SDL_FreeSurface(surface_image);

    Size size_texture{get_size_texture()};
    rectangle_texture.w = size_texture.get_width();
    rectangle_texture.h = size_texture.get_height();
}

void Sprite::draw() const {
    const SDL_Point center{width / 2, height / 2};
    const SDL_Rect dest_rect{x, y, width * scale.get_width(), height * scale.get_height()};

    SDL_RenderCopyEx(RenderWindow::get_instance().get_renderer(), texture, &rectangle_texture, &dest_rect, get_rotation(), &center, SDL_FLIP_NONE);
}

void Sprite::set_rectangle_texture(const Position &position, const Size &size) {
    rectangle_texture.x = position.get_x();
    rectangle_texture.y = position.get_y();
    rectangle_texture.w = size.get_width();
    rectangle_texture.h = size.get_height();
}
