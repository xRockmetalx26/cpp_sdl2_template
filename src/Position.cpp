//
// Created by xRockmetalx
//

#include <Position.h>

Position::Position(const int x, const int y) : x{x}, y{y} {}

void Position::set_x(const int x) { this->x = x; }
void Position::set_y(const int y) { this->y = y; }

int Position::get_x() const { return x; }
int Position::get_y() const { return y; }
