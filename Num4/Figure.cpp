#include "Figure.h"
#include <iostream>
int Figure::counter=0;

Figure::Figure(){
    counter++;
    fileName = std::to_string(counter);
}

void Figure::loadFromFile(){}
void Figure::saveToFile(){}
std::string Figure::toString(){}
Figure::~Figure(){}
