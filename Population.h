#include <vector>

typedef std::vector<int> Points;

#ifndef PATH_H
#define PATH_H
struct Path {
	Points cities;
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