// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Population.cpp"
#include "PopulationGenerator.cpp"
#include "Fitness.cpp"
#include "Selection.cpp"
#include "Crossover.cpp"


int main() {
	Population population = PopulationGenrator::generatePopulation();
	Fitness::calculate(population);
	TournamentSelection::performSelection(population);
	return 0;
}
