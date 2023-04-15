#include "purePursuit.h"
#include <vector>
#include <math.h>
#include <cmath>

#define SQD(n) std::pow(n,2)

int sign(double x) {
  if (x > 0.0) return 1;
  if (x < 0.0) return -1;
  return 0;
}

double get_dis(std::vector<double> p1, std::vector<double> p2) {
  return std::sqrt(SQD(p1[0] - p2[0]) + SQD(p1[1] - p2[1]));
}
std::vector<double> get_intersection(std::vector<double> start, std::vector<double> end, std::vector<double> cur, double radius) {
      std::vector<double> p1 {start[0] - cur[0], start[1] - cur[1]};
      std::vector<double> p2 {end[0] - cur[0], end[1] - cur[1]};

      double dx = p2[0] - p1[0];
      double dy = p2[1] - p1[1];
      float d = sqrt(SQD(dx) + SQD(dy));
      float D = p1[0] * p2[1] - p2[0] * p1[1];
      float discriminant = SQD(radius) * SQD(d) - SQD(D);// took off std::abs here
//    printf("dis: %f\n", discriminant);
//    printf("hello?: %f\n", sqrt(discriminant));
    if(discriminant<0) return {-99, -99};

      float x1 = (D * dy + sign(dy) * dx * sqrt(discriminant)) / SQD(d);
      float y1 = (-D * dx + std::abs(dy) * sqrt(discriminant)) / SQD(d);
      float x2 = (D * dy - sign(dy) * dx * sqrt(discriminant)) / SQD(d);
      float y2 = (-D * dx - std::abs(dy) * sqrt(discriminant)) / SQD(d);
      /* Above calculations can be explained and proven here: https://mathworld.wolfram.com/Circle-LineIntersection.html */

      std::vector<double> intersection1 {x1, y1};
      std::vector<double> intersection2 {x2, y2};

      float distance1 = get_dis(p2, intersection1);
      float distance2 = get_dis(p2, intersection2);

      std::vector<double> calc1 {(x1 + cur[0]), (y1 + cur[1])};
      std::vector<double> calc2 {(x2 + cur[0]), (y2 + cur[1])};

      if (distance1 < distance2) return calc1;
      if (distance1 > distance2) return calc2;
      return calc1;
}