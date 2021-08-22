//
// Created by xRockmetalx
//

#include <Transformable.h>

Transformable::Transformable(const Position &position, const Size &size)
    : Position{position}, Size{size}, scale{1, 1}, rotation{} {}

void Transformable::move(const int dx, const int dy) { x += dx, y += dy; }

void Transformable::set_position(const Position &position) { Position::operator=(position); }
void Transformable::set_size(const Size &size) { Size::operator=(size); }
void Transformable::set_scale(const Size &scale) { this->scale = scale; }
void Transformable::set_rotation(const float rotation) { this->rotation = rotation; }

Position Transformable::get_position() const { return *this; }
Size Transformable::get_size() const { return *this; }
Size Transformable::get_scale() const { return scale; }
float Transformable::get_rotation() const { return rotation; }
