#include "decart.h"
#include "sphera.h"
#include <math.h>
#include <iostream>

Decart::Decart(){
	x = 0; y = 0; z = 0;
}

Decart::Decart(double _x, double _y, double _z){
	x = _x; y = _y; z = _z;
}

Decart::operator Sphera(){
	
	Sphera result;
	
	result.R = sqrt(x*x + y*y + z*z);
	result.lon = atan2(y, x);
	result.lat = asin(z / result.R);
	
	return result;
}

double Decart::euclidianDistance(Decart p1, Decart p2){
	double result;
	result = sqrt(pow(p2.x - p1.x, 2.) + pow(p2.y - p1.y, 2.) + pow(p2.z - p1.z, 2.));
			
	return result;
}

std::ostream& operator<<(std::ostream& c, Decart d){
	c << d.x << " " << d.y << " " << d.z << "\n";
	return c;
}
