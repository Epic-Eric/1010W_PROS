#ifndef PurePursuit_h
#define PurePursuit_h

#include <stdio.h>
#include <vector>

int sign(double x);
float point_line_distance(std::vector<double> p1, std::vector<double> p2, std::vector<double> p3);
double get_dis(std::vector<double> p1, std::vector<double> p2);
std::vector<double> get_intersection(std::vector<double> start, std::vector<double> end, std::vector<double> cur, double radius);

#endif /* PurePursuit_hpp */