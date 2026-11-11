#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
private:
    int x1, y1, x2, y2, x3, y3;

public:
    Triangle();
    Triangle(int a, int b, int c, int d, int e, int f);
    Triangle(const Triangle& other);
    ~Triangle();
    Triangle& operator=(const Triangle& other);
    void loadFromFile() override;
    void saveToFile() override;
    std::string toString() override;
};

#endif //TRIANGLE_H

