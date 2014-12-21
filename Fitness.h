#include "Population.h"

class Fitness {
	static double calculate(const Path path);

public:
	static void calculate(Population (&population));
	static const double populationMeanFitness(const Population population);
	static void sortByFitness(Population (&population));
	static Population elitesFrom(const Population population, int numberOfElites);
};
