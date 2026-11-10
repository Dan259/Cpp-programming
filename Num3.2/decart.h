#ifndef DECART_H
#define DECART_H
#include <math.h>
#include <iostream>

class Sphera;

class Decart{
	public:
		double x,y,z;
		Decart();
		
		Decart(double _x, double _y, double _z);
		
		static double euclidianDistance(Decart p1, Decart p2);
		
		friend std::ostream& operator<<(std::ostream& c, Decart d);
		
		operator Sphera();
		
};

#endif
