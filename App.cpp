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

const int GENERATIONS = 200;
const int POPULATION_SIZE = 30;
const int ELITES = 2;

History history;

int main() {
	Map::generateMap();
	history.currentGenration = 0;
	history.historyBest.reserve(GENERATIONS);
	history.historyMean.reserve(GENERATIONS);

	Population population = PopulationGenrator::generatePopulation(POPULATION_SIZE, MAP_SIZE);
	Population elites;
	while (history.currentGenration < GENERATIONS)
	{
		system("cls");
		std::cout << history.currentGenration;
		
		Fitness::calculate(population);
		history.historyMean.push_back(Fitness::populationMeanFitness(population));
		history.historyBest.push_back(Fitness::populationBestFitness(population));
		elites = Fitness::elitesFrom(population, ELITES);
		TournamentSelection::performSelection(population);
		Crossover::preserveElites(population, elites);
		Crossover::populateExtincted(population, POPULATION_SIZE);
		history.currentGenration++;
	}

	history.printHistory(GENERATIONS);
	getchar();
	return 0;
}
