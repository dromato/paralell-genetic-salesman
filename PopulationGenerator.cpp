#include "PopulationGenerator.h"

Path PathGenerator::generatePath(int nOfCities) {
	Path path = Path();
	path.cities.reserve(nOfCities);
	int point;
	for(int i = 0; i < nOfCities; i++) {
		do {
			point = rand() % nOfCities;
		} while(used(point, path.cities));
		path.cities.push_back(point);
	}

	return path;
}

bool PathGenerator::used(int point, Points points) {
	for(Points::size_type i = 0; i != points.size(); i++) {
		if(points[i] == point) {
			return true;
		}
	}

	return false;
}

Population PopulationGenrator::generatePopulation(int size, int nOfCities) {
	Population population = Population();
	population.paths.reserve(size);

	for(int i = 0; i < size; i++) {
		population.paths.push_back(PathGenerator::generatePath(nOfCities));
	}

	return population;
}

Population PopulationGenrator::generatePopulationFrom(Paths paths) {
	return Population();
}