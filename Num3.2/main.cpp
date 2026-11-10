#include <iostream>
#include <sstream>
#include <fstream>
#include "decart.h"
#include "sphera.h"

int main(){
	Sphera s1, s2;
	Decart d1, d2;
	double max_distance_s = 0, max_distance_d = 0;
	
	
	std::ifstream file("num3.txt");
	std::string line1, line2;
	
	while(getline(file, line1) && getline(file,line2)){
		std::stringstream ss1(line1);
		ss1 >> s1.lon >> s1.lat;
		d1.x = s1.lon; d1.y = s1.lat; d1.z = 6371000;
		std::stringstream ss2(line2);
		ss2 >> s2.lon >> s2.lat;
		d2.x = s2.lon; d2.y = s2.lat; d2.z = 6371000;
		
		double res1 = Sphera::BigCircleDistance(s1, s2);
		double res2 = Decart::euclidianDistance(d1, d2);
		
		if(max_distance_s < res1){
			max_distance_s = res1;
		}
		if(max_distance_d < res2){
			max_distance_d = res2;
		}
		
	
		std::cout << res1 << " " << res2 << std::endl;
	}
	//std::cout << max_distance_s << " " << max_distance_d << "\n";
	return 0;
}
