//
// Created by xRockmetalx
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <Position.h>
#include <Size.h>

class Transformable : public Position, public Size {
public:

    explicit Transformable(const Position &position = Position{}, const Size &size = Size{});

    void move(int dx, int dy);

    void set_position(const Position &position);
    void set_size(const Size &size);
    void set_scale(const Size &scale);
    void set_rotation(float rotation);

    Position get_position() const;
    Size get_size() const;
    Size get_scale() const;
    float get_rotation() const;

protected:

    Size scale;
    float rotation;
};

#endif // TRANSFORMABLE_H
