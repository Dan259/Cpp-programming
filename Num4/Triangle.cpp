#include "Triangle.h"
#include <fstream>

Triangle::Triangle(){
    x1 = 0; y1 = 0; x2 = 1; y2 = 1; x3 = 2; y3 = 2;
    fileName += ".txt";
}

Triangle::Triangle(int a, int b, int c, int d, int e, int f){
    x1 = a; y1 = b; x2 = c; y2 = d; x3 = e; y3 = f;
    fileName += ".txt";
}

Triangle::Triangle(const Triangle& other):x1(other.x1),y1(other.y1),x2(other.x2),y2(other.y2),x3(other.x3),y3(other.y3) {
	fileName += ".txt";
}

Triangle::~Triangle(){
    remove(fileName.c_str());
}

Triangle& Triangle::operator=(const Triangle& other){
    if(this!=&other){
        x1=other.x1;
        y1=other.y1;
        x2=other.x2;
        y2=other.y2;
        x3=other.x3;
        y3=other.y3;
    }
    return *this;
}

void Triangle::loadFromFile(){
    std::ifstream file(fileName);
    if(file.is_open()){
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        file.close();
    }
}

void Triangle::saveToFile(){
    std::ofstream file(fileName);
    if(file.is_open()){
        file << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
        file.close();
    }
}

std::string Triangle::toString(){
    return fileName + ": (" + std::to_string(x1) + ", " + std::to_string(y1) + "), (" + std::to_string(x2) + ", " + std::to_string(y2) + "), (" + std::to_string(x3) + ", " + std::to_string(y3) + ")";
}

