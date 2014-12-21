#include "Fitness.h"
#include "Map.h"

void Fitness::calculate(Population (&population)) {
	for(Paths::size_type i = 0; i < population.paths.size(); i++) {
		population.paths[i].fitness = calculate(population.paths[i]);
	}
}

double Fitness::calculate(const Path path) {
	double fit = 0;
	for(Points::size_type i = 0; i < path.cities.size() - 1; i++) {
		fit += Map::distanceBetween(path.cities[i], path.cities[i + 1]);
	}
	fit += Map::distanceBetween(path.cities[0], path.cities[path.cities.size() - 1]);

	return fit;
}

const double Fitness::populationMeanFitness(const Population population) {
	int n = population.paths.size();
	double sum = 0;
	for(int i = 0; i < n; i++) {
		sum += population.paths[i].fitness;
	}

	return sum / n;
}

void Fitness::sortByFitness(Population (&population)) {
}

Population Fitness::elitesFrom(const Population population, int numberOfElites) {
	return Population();
}