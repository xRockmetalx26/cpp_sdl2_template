//
// Created by xRockmetalx
//

#include <ToString.h>

std::string ToString::color_to_string(const Color color) {
    return "red: " + std::to_string(color.get_red()) + ", green: " + std::to_string(color.get_green()) +
           ", blue: " + std::to_string(color.get_blue()) + ", alpha: " + std::to_string(color.get_alpha());
}

std::string ToString::position_to_string(const Position &position) {
    return "x: " + std::to_string(position.get_x()) + ", y: " + std::to_string(position.get_y());
}

std::string ToString::size_to_string(const Size &size) {
    return "width: " + std::to_string(size.get_width()) + ", height: " + std::to_string(size.get_height());
}
