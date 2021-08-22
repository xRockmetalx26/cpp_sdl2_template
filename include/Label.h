//
// Created by xRockmetalx
//

#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <Transformable.h>
#include <Texture.h>
#include <Drawable.h>
#include <Size.h>
#include <Color.h>

class Label : public Transformable, public Texture, public Drawable {
public:

    explicit Label(const std::string &font_filename, const std::string &text, const Position &position = Position{}, const Size &size = Size{});

    void draw() const override;
    void load_text(const std::string &font_filename, const std::string &text);

    void set_font(const std::string &filename);
    void set_text(const std::string &text);
    void set_color(Color color);
    void set_point_size(int size);

    std::string get_text() const;
    Color get_color() const;
    int get_point_size() const;

private:

    std::string font_filename;
    std::string text;
    Color color{};
    int point_size{22};
};

#endif // LABEL_H
