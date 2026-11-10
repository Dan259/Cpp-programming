#ifndef SPHERA_H
#define SPHERA_H
#include <iostream>
#include "decart.h"

class Decart;

class Sphera{
public:
	double lon, lat, R;
	Sphera();
	Sphera(double _lon, double _lat, double _R);
	static double radians(double a);
	
	static double BigCircleDistance(Sphera p1, Sphera p2);
	
	friend std::ostream& operator<<(std::ostream& c, const Sphera s);
	
	operator Decart();
};

#endif
