//
// Created by xRockmetalx
//

#ifndef TO_STRING_H
#define TO_STRING_H

#include <string>
#include <Color.h>
#include <Position.h>
#include <Size.h>

class ToString {
public:

    ToString() = delete;
    ToString(const ToString &other) = delete;
    ToString(const ToString &&other) = delete;
    ToString& operator = (const ToString &other) = delete;
    ToString& operator = (const ToString &&other) = delete;

    static std::string color_to_string(Color color);
    static std::string position_to_string(const Position &position);
    static std::string size_to_string(const Size &size);
};

#endif // TO_STRING_H
