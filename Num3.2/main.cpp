#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "decart.h"
#include "sphera.h"

int main() {
    std::ifstream file("num3.txt");
    
    std::vector<Sphera> sphera_points;
    std::string line;

    while (getline(file, line)) {
        Sphera point;
        std::stringstream ss(line);
        ss >> point.lon >> point.lat;
        sphera_points.push_back(point);
    }

    file.close();

    double max_distance_s = 0, max_distance_d = 0;
    Sphera max_s1, max_s2;

    for (size_t i = 0; i < sphera_points.size(); i++) {
        for (size_t j = i + 1; j < sphera_points.size(); j++) {
            Sphera s1 = sphera_points[i];
            Sphera s2 = sphera_points[j];

            Decart d1(s1.lon, s1.lat, 6371000);
            Decart d2(s2.lon, s2.lat, 6371000);

            double res2 = Decart::euclidianDistance(d1, d2);
            double res1 = Sphera::BigCircleDistance(s1, s2);

            if (max_distance_s < res1) {
                max_distance_s = res1;
                max_s1 = s1; 
                max_s2 = s2;
            }
            if (max_distance_d < res2) {
                max_distance_d = res2;
            }
        }
    }

    std::cout << "Max Spherical Distance: " << max_distance_s << " m\n";
    std::cout << "Points: (" << max_s1.lon << ", " << max_s1.lat << ") and (" << max_s2.lon << ", " << max_s2.lat << ")\n";

    std::cout << "Max Euclidean Distance: " << max_distance_d << " m\n";

    return 0;
}

