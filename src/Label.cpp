//
// Created by xRockmetalx
//

#include <Label.h>
#include <RenderWindow.h>
#include <SDL2/SDL_ttf.h>

Label::Label(const std::string &font_filename, const std::string &text, const Position &position, const Size &size)
    : Transformable{position, size}, font_filename{font_filename}, text{text} {
    load_text(font_filename, text);
}

void Label::draw() const {
    const SDL_Point center{width / 2, height / 2};
    const SDL_Rect dest_rect{x, y, width * scale.get_width(), height * scale.get_height()};

    SDL_RenderCopyEx(RenderWindow::get_instance().get_renderer(), texture, nullptr, &dest_rect, rotation, &center, SDL_FLIP_NONE);
}

void Label::load_text(const std::string &font_filename, const std::string &text) {
    delete_texture();

    auto font{TTF_OpenFont(font_filename.c_str(), point_size)};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(),
        SDL_Color{color.get_red(), color.get_green(), color.get_blue(), color.get_alpha()});
    texture = SDL_CreateTextureFromSurface(RenderWindow::get_instance().get_renderer(), surface);
    
    SDL_FreeSurface(surface);
}

void Label::set_font(const std::string &filename) {
    font_filename = filename;
    load_text(font_filename, text);
}

void Label::set_text(const std::string &text) {
    this->text = text;
    load_text(font_filename, text);
}

void Label::set_color(Color color) {
    this->color = color;
    load_text(font_filename, text);
}

void Label::set_point_size(int size) {
    point_size = size;
    load_text(font_filename, text);
}

std::string Label::get_text() const { return text; }
Color Label::get_color() const { return color; }
int Label::get_point_size() const { return point_size; }
