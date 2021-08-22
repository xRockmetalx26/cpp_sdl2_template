//
// Created by xRockmetalx
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Transformable.h>
#include <Texture.h>
#include <Drawable.h>
#include <Position.h>
#include <Size.h>
#include <Color.h>

struct SDL_Renderer;

class Rectangle : public Transformable, public Texture, public Drawable {
public:

    explicit Rectangle(const Position &position = Position{}, const Size &size = Size{});

    void draw() const override;

    void load_rgba();

    void set_color(Color color);
    void set_color_border(Color color);
    void set_border_size(int size);

    Color get_color() const;
    Color get_color_border() const;
    int get_border_size() const;

private:

    Color color{};
    Color color_border{};
    int border_size{};
};

#endif // RECTANGLE_H
