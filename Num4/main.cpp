#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    // Create objects
    Rectangle r1(0, 0, 10, 10);
    Triangle t1(0, 0, 5, 10, 10, 0);
    
    std::cout << r1.toString() << std::endl;
    std::cout << t1.toString() << std::endl;
    
    // Save to files
    r1.saveToFile();
    t1.saveToFile();
    
    // Test copy constructor
    Rectangle r2 = r1;
    std::cout << r2.toString() << std::endl;
    r2.saveToFile();
    
    // Test assignment operator
    Rectangle r3(100, 100, 200, 200);
    r3 = r1;
    std::cout << r3.toString() << std::endl;
    r3.saveToFile();
    
    // Test destructor
    {
        Rectangle r_temp(1, 1, 2, 2);
        r_temp.saveToFile();
    }
    
//    // Test polymorphic array
//    std::vector<Figure*> figures;
//    figures.push_back(new Rectangle(0, 0, 5, 5));
//    figures.push_back(new Triangle(0, 0, 3, 4, 4, 3));
//    figures.push_back(new Rectangle(10, 10, 50, 50));
//    
//    for (auto fig : figures) {
//        std::cout << fig->toString() << std::endl;
//        fig->saveToFile();
//    }
//    
//    for (auto fig : figures) {
//        delete fig;
//    }
    
    return 0;
}
