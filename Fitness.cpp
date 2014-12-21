#include "Population.cpp"

class Fitness {
	double calculate(const Path path);

public:
	static void calculate(Population (&population));
	static const double populationMeanFitness(const Population population);
	static void sortByFitness(Population (&population));
	static Population elitesFrom(const Population population, int numberOfElites);
};

void Fitness::calculate(Population (&population)) {
	
}

const double Fitness::populationMeanFitness(const Population population) {
	return 0;
}