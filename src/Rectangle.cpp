//
// Created by xRockmetalx
//

#include <Rectangle.h>
#include <RenderWindow.h>
#include <SDL2/SDL_render.h>

Rectangle::Rectangle(const Position &position, const Size &size)
    : Transformable{position, size} {
    load_rgba();
}

void Rectangle::load_rgba() {
    delete_texture();

    texture = SDL_CreateTexture(RenderWindow::get_instance().get_renderer(), SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, width, height);

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawBlendMode(RenderWindow::get_instance().get_renderer(), SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(RenderWindow::get_instance().get_renderer(), texture);

    SDL_SetRenderDrawColor(RenderWindow::get_instance().get_renderer(), color_border.get_red(), color_border.get_green(), color_border.get_blue(), color_border.get_alpha());
    SDL_RenderFillRect(RenderWindow::get_instance().get_renderer(), nullptr);

    SDL_Rect rect_border{};
    rect_border.x = border_size;
    rect_border.y = border_size;
    rect_border.w = get_size_texture().get_width() - border_size * 2;
    rect_border.h = get_size_texture().get_height() - border_size * 2;

    SDL_SetRenderDrawColor(RenderWindow::get_instance().get_renderer(), color.get_red(), color.get_green(), color.get_blue(), color.get_alpha());
    SDL_RenderFillRect(RenderWindow::get_instance().get_renderer(), &rect_border);

    SDL_SetRenderTarget(RenderWindow::get_instance().get_renderer(), nullptr);
}

void Rectangle::draw() const {
    SDL_Point center{width / 2, height / 2};
    SDL_Rect dest_rect{x, y, width * scale.get_width(), height * scale.get_height()};

    SDL_RenderCopyEx(RenderWindow::get_instance().get_renderer(), texture, nullptr, &dest_rect, rotation, &center, SDL_FLIP_NONE);
}

void Rectangle::set_color(Color color) {
    this->color = color;
    load_rgba();
}

void Rectangle::set_color_border(const Color color) {
    this->color_border = color;
    load_rgba();
}

void Rectangle::set_border_size(const int size) {
    border_size = size;
    load_rgba();
}

Color Rectangle::get_color() const { return color; }
Color Rectangle::get_color_border() const { return color_border; }
int Rectangle::get_border_size() const { return border_size; }
