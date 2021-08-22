//
// Created by xRockmetalx
//

#ifndef SIZE_H
#define SIZE_H

class Size {
public:

    explicit Size(int width = 0, int height = 0);

    void set_width(int width);
    void set_height(int height);

    int get_width() const;
    int get_height() const;

protected:

    int width;
    int height;
};

#endif // SIZE_H
