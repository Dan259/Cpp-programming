#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    int x1, y1, x2, y2;

public:
    Rectangle();
    Rectangle(int a, int b, int c, int d);
    Rectangle(const Rectangle& other);
    ~Rectangle();
    Rectangle& operator=(const Rectangle& other);
    void loadFromFile() override;
    void saveToFile() override;
    std::string toString() override;
};

#endif //RECTANGLE_H

