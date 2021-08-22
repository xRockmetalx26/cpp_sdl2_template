//
// Created by xRockmetalx
//

#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
public:

    explicit Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255);

    void set_red(uint8_t red);
    void set_green(uint8_t green);
    void set_blue(uint8_t blue);
    void set_alpha(uint8_t alpha);

    uint8_t get_red() const;
    uint8_t get_green() const;
    uint8_t get_blue() const;
    uint8_t get_alpha() const;

protected:

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

#endif // COLOR_H
