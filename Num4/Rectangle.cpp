#include "Rectangle.h"
#include <fstream>

Rectangle::Rectangle(){
    x1 = 0; y1 = 0; x2 = 1; y2 = 1;
    fileName += ".txt";
}

Rectangle::Rectangle(int a, int b, int c, int d){
    x1 = a; y1 = b; x2 = c; y2 = d;
    fileName += ".txt";
}

Rectangle::Rectangle(const Rectangle& other):x1(other.x1),y1(other.y1),x2(other.x2),y2(other.y2) {
	fileName += ".txt";
}

Rectangle::~Rectangle(){
    remove(fileName.c_str());
}

Rectangle& Rectangle::operator=(const Rectangle& other){
    if(this!=&other){
        x1=other.x1;
        y1=other.y1;
        x2=other.x2;
        y2=other.y2;
    }
    return *this;
}

void Rectangle::loadFromFile(){
    std::ifstream file(fileName);
    if(file.is_open()){
        file >> x1 >> y1 >> x2 >> y2;
        file.close();
    }
}

void Rectangle::saveToFile(){
    std::ofstream file(fileName);
    if(file.is_open()){
        file << x1 << " " << y1 << " " << x2 << " " << y2;
        file.close();
    }
}

std::string Rectangle::toString(){
    return fileName + ": (" + std::to_string(x1) + ", " + std::to_string(y1) + "), (" + std::to_string(x2) + ", " + std::to_string(y2) + ")";
}

