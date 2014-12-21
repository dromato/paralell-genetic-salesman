#include "Population.cpp"

class PathGenerator {
	static Path generatePath();
};

class PopulationGenrator {
public:
	static Population generatePopulation();
	static Population generatePopulationFrom(Paths paths);
};

Path PathGenerator::generatePath() {
	return Path();
}

Population PopulationGenrator::generatePopulation() {
	return Population();
}