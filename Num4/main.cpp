#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    // Create objects
    Rectangle r1(0, 0, 10, 10);
    Triangle t1(0, 0, 5, 10, 10, 0);
    
    std::cout << "Creating files" << std::endl; 
    std::cout << r1.toString() << std::endl;
    std::cout << t1.toString() << std::endl;
    
    r1.saveToFile();
    t1.saveToFile();
    
    // Test copy constructor
    std::cout << "Test copy" << std::endl;
    Rectangle r2 = r1;
    std::cout << r2.toString() << std::endl;
    r2.saveToFile();
    
    // Test assignment operator
    std::cout << "Test assignment" << std::endl;
    Rectangle r3(100, 100, 200, 200);
    r3 = r1;
    std::cout << r3.toString() << std::endl;
    r3.saveToFile();
    
    std::cin.get();
    
    
    return 0;
}
