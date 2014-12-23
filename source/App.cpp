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
#include <chrono>
#include "Mutation.h"

const int GENERATIONS = 15500;
const int POPULATION_SIZE = 40;
const int ELITES = 2;
const int MUTATION_RATE = 5;

History history;

int main() {
	Map::generateMap();
	history.currentGenration = 0;
	history.historyBest.reserve(GENERATIONS);
	history.historyMean.reserve(GENERATIONS);

	Population population = PopulationGenrator::generatePopulation(POPULATION_SIZE, MAP_SIZE);
	Population elites;
	auto start_time = std::chrono::high_resolution_clock::now();
	while (history.currentGenration < GENERATIONS)
	{
		Fitness::calculate(population);
		history.historyMean.push_back(Fitness::populationMeanFitness(population));
		history.historyBest.push_back(Fitness::populationBestFitness(population));
		elites = Fitness::elitesFrom(population, ELITES);
		population = TournamentSelection::performSelection(population);
		Crossover::preserveElites(population, elites);
		Crossover::populateExtincted(population, POPULATION_SIZE);
		Mutation::mutate(population, MUTATION_RATE);
		history.currentGenration++;
	}
	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	std::cout << "| " << "Generation" << " | " << "Mean of gen." << " | " << "Best of gen." << " | " << std::endl;
	
	for(int i = 0; i < 500; i += 50 ) {
		if(i < GENERATIONS)
			std::cout << "| " << i << " | " << history.historyMean[i] << " | " << history.historyBest[i] << " | " << std::endl;
		else {
			break;
		}
	}
	for(int i = 500; i < 7000; i += 500 ) {
		if(i < GENERATIONS)
			std::cout << "| " << i << " | " << history.historyMean[i] << " | " << history.historyBest[i] << " | " << std::endl;
		else {
			break;
		}
	}
	for(int i = 7000; i <= GENERATIONS; i+= 1000) {
		if(i < GENERATIONS)
			std::cout << "| " << i << " | " << history.historyMean[i] << " | " << history.historyBest[i] << " | " << std::endl;
		else {
			break;
		}
	}
	std::cout << std::endl << "Took  :  " << time.count();
	getchar();
	return 0;
}
