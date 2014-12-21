// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Population.h"
#include "PopulationGenerator.h"
#include "Fitness.h"
#include "Selection.h"
#include "Crossover.h"
#include "History.h"
#include "Map.h"

const int GENERATIONS = 2000;
const int POPULATION_SIZE = 10;
const int ELITES = 2;

History history;
Map map = Map();

int main() {
	FitnessHistory::iterator it;
	history.currentGenration = 0;
	history.history.reserve(GENERATIONS);
	it = history.history.begin();

	Population population = PopulationGenrator::generatePopulation(POPULATION_SIZE, MAP_SIZE);

	while (history.currentGenration < GENERATIONS)
	{
		history.currentGenration++;
		Fitness::calculate(population);
		history.history.insert(it++, Fitness::populationMeanFitness(population));
		TournamentSelection::performSelection(population);
		Crossover::preserveElites(population, Fitness::elitesFrom(population, ELITES));
		Crossover::populateExtincted(population, POPULATION_SIZE);
	}
	return 0;
}
