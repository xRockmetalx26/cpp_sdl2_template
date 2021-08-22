//
// Created by xRockmetalx
//

#include <Size.h>

Size::Size(const int width, const int height) : width{width}, height{height} {}

void Size::set_width(const int width) { this->width = width; }
void Size::set_height(const int height) { this->height = height; }

int Size::get_width() const { return width; }
int Size::get_height() const { return height; }
