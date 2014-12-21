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

int main() {
	Map::generateMap();
	FitnessHistory::iterator it;
	history.currentGenration = 0;
	history.history.reserve(GENERATIONS);

	Population population = PopulationGenrator::generatePopulation(POPULATION_SIZE, MAP_SIZE);
	Population elites;
	while (history.currentGenration < GENERATIONS)
	{
		Fitness::calculate(population);
		history.history.push_back(Fitness::populationMeanFitness(population));
		elites = Fitness::elitesFrom(population, ELITES);
		TournamentSelection::performSelection(population);
		Crossover::preserveElites(population, elites);
		Crossover::populateExtincted(population, POPULATION_SIZE);
		history.currentGenration++;
	}
	return 0;
}
