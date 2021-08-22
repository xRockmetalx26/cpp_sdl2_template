//
// Created by xRockmetalx
//

#include <Color.h>

Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha)
    : red{red}, green{green}, blue{blue}, alpha{alpha} {}

void Color::set_red(const uint8_t red) { this->red = red; }
void Color::set_green(const uint8_t green) { this->green = green; }
void Color::set_blue(const uint8_t blue) { this->blue = blue; }
void Color::set_alpha(const uint8_t alpha) { this->alpha = alpha; }

uint8_t Color::get_red() const { return red; }
uint8_t Color::get_green() const { return green; }
uint8_t Color::get_blue() const { return blue; }
uint8_t Color::get_alpha() const { return alpha; }
