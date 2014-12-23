#include "Population.h"

class PathGenerator {
public:
	static Path generatePath(int nOfCities);

	
private:
	static bool used(int point, Points points);
};

class PopulationGenrator {
public:
	static Population generatePopulation(int size, int nOfCities);
	static Population generatePopulationFrom(Paths paths);
};