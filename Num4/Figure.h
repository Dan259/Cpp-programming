#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
protected:
    std::string fileName;
    static int counter;

public:
    Figure();
    virtual void loadFromFile();
    virtual void saveToFile();
    virtual std::string toString();
    virtual ~Figure();
};

#endif //FIGURE_H

