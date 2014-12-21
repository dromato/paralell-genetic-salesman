// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Population.cpp"
#include "PopulationGenerator.cpp"
#include "Fitness.cpp"
#include "Selection.cpp"
#include "Crossover.cpp"
#include "History.cpp"

const int GENERATIONS = 2000;
const int POPULATION_SIZE = 10;
const int ELITES = 2;

History history;

int main() {
	FitnessHistory::iterator it;
	history.currentGenration = 0;
	history.history.reserve(GENERATIONS);
	it = history.history.begin();

	Population population = PopulationGenrator::generatePopulation();
	Population elders;
	while (history.currentGenration < GENERATIONS)
	{
		history.currentGenration++;
		Fitness::calculate(population);
		history.history.insert(it, Fitness::populationMeanFitness(population));
		TournamentSelection::performSelection(population);
		Crossover::preserveElites(population, Fitness::elitesFrom(population, ELITES));
		Crossover::populateExtincted(population, POPULATION_SIZE);
	}
	return 0;
}
