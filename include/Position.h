//
// Created by xRockmetalx
//

#ifndef POSITION_H
#define POSITION_H

class Position {
public:

    explicit Position(int x = 0, int y = 0);

    void set_x(int x);
    void set_y(int y);

    int get_x() const;
    int get_y() const;

protected:

    int x;
    int y;
};

#endif // POSITION_H
