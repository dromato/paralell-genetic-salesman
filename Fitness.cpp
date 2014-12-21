#include "Population.cpp"

class Fitness {
	double calculate(const Path path);

public:
	static void calculate(Population (&population));
	static double populationMeanFitness(const Population population);
};

void Fitness::calculate(Population (&population)) {
	
}

double Fitness::populationMeanFitness(const Population population) {
	return 0;
}