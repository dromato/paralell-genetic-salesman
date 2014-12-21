// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Population.cpp"
#include "PopulationGenerator.cpp"
#include "Fitness.cpp"
#include "Selection.cpp"
#include "Crossover.cpp"
#include "History.cpp"

History history;

int main() {
	history.currentGenration = 0;
	history.history.reserve(2000);
	Population population = PopulationGenrator::generatePopulation();

	Fitness::calculate(population);
	TournamentSelection::performSelection(population);
	Crossover::populateExtincted(population, POPULATION_SIZE);
	return 0;
}
