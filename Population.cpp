#include <vector>

const int POPULATION_SIZE = 10;

#ifndef POINT_H
#define POINT_H
struct Point {
	const int x, y;
};
#endif /* POINT_H */

typedef std::vector<Point> Points;

#ifndef PATH_H
#define PATH_H
struct Path {
	Points points;
	double fitness;
};
#endif /* PATH_H */

typedef std::vector<Path> Paths;

#ifndef POPULATION_H
#define POPULATION_H
class Population {
public:
	Paths paths;
};
#endif /* POPULATION_H */