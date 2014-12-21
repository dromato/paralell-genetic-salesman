#include "Population.h"

class PathGenerator {
	static Path generatePath();
};

class PopulationGenrator {
public:
	static Population generatePopulation();
	static Population generatePopulationFrom(Paths paths);
};