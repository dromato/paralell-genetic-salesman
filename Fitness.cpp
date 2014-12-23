#include <algorithm>
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

const double Fitness::populationBestFitness(const Population population) {
	int n = population.paths.size();
	double best = population.paths[0].fitness;
	for(int i = 0; i < n; i++) {
		if(best > population.paths[i].fitness) {
			best = population.paths[i].fitness;
		}
	}

	return best;
}

void Fitness::sortByFitness(Population (&population)) {
	std::sort(population.paths.begin(), population.paths.end(), sortMethod);
}

bool Fitness::sortMethod(Path path1, Path path2) {
	return path1.fitness < path2.fitness;
}

Population Fitness::elitesFrom(Population (&population), int numberOfElites) {
	sortByFitness(population);
	Population elites = Population();
	for(int i = 0; i < numberOfElites; i++) {
		elites.paths.push_back(population.paths[i]);
	}
	return elites;
}