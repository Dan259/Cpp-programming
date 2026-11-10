#include "sphera.h"
#include "decart.h"
#include <math.h>
#include <iostream>
#define pi 3.141592653589793238462643383279

Sphera::Sphera(){
	
	lon = 0; lat = 0; R = 0;
}

Sphera::Sphera(double _lon, double _lat, double _R){
	
	lon = _lon; lat = _lat; R = _R;
}

Sphera::operator Decart(){
	
	Decart result;
	
	result.x = R * cos(lon) * cos(lat);
	result.y = R * cos(lat) * sin(lon);
	result.z = R * sin(lat);
	
	return result;
}

double Sphera::radians(double a){
	return a * (pi / 180);
}

double Sphera::BigCircleDistance(Sphera p1, Sphera p2){
	double rad;
	
	p1.lon = radians(p1.lon); p2.lon = radians(p2.lon); p1.lat = radians(p1.lat); p2.lat = radians(p2.lat); 
	
	rad = 2*asin(sqrt(pow(sin((p2.lat - p1.lat) / 2), 2) + (cos(p1.lat) * cos(p2.lat) * (pow(sin((p2.lon - p1.lon) / 2), 2)))));
	
	double res;
	res = rad * 6371000;
	
	return res;
}

std::ostream& operator<<(std::ostream& c, Sphera s){
	c << s.lon << " " << s.lat << " " << s.R << "\n";
	return c;
}
