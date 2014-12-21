#include "Population.h"

class Fitness {
	static double calculate(const Path path);
	static bool sortMethod(Path path1, Path path2);

public:
	static void calculate(Population (&population));
	static const double populationMeanFitness(const Population population);
	static void sortByFitness(Population (&population));
	static Population elitesFrom(Population (&population), int numberOfElites);
};
