// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
//
//int const AMOUNT_OF_CITIES = 5;
//int const POPULATION_SIZE = 20;
//
//double locations[AMOUNT_OF_CITIES][2] = {
//		{1, 4},
//		{2, 3},
//		{0, 9},
//		{12, 2},
//		{4, 7}
//	};
//
//double distanceBetweenPoints(int p1, int p2);
//void populateWithRandomPath(int (&path)[AMOUNT_OF_CITIES]);
//bool doesArrayContainCity(int arr[AMOUNT_OF_CITIES], int number);
//void populateWithRandomPaths(int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES]);
//void calculateFitness(const int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE]);
//double calculateFitnessForSinglePath(const int path[AMOUNT_OF_CITIES]);

int main() {
//	if(AMOUNT_OF_CITIES % 2 == 1) {
//		throw std::invalid_argument("Population size should be even.");
//	}
//	int population[POPULATION_SIZE][AMOUNT_OF_CITIES];
//	double fitness[POPULATION_SIZE];
//	populateWithRandomPaths(population);
//	calculateFitness(population, fitness);
////	performSelection(population, fitness);
//	
	return 0;
}
//
////void performSelection(int (&population)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE]) {
////	int newPopulation[POPULATION_SIZE][AMOUNT_OF_CITIES];
////	for(int i = 0; i < AMOUNT_OF_CITIES / 2; i++) {
//////		fightToDeath(population, newPopulation, fitness, i);
////	}
////}
//
//void fightToDeath(int (&population)[POPULATION_SIZE][AMOUNT_OF_CITIES], int (&newPopulation)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE], int which) {
//	int const tournamentSize = POPULATION_SIZE / 4;
//	int theChoosenOne;
//	int alreadyChoosed[tournamentSize];
//	double bestFitness = 9999;
//	int winner;
//	for(int i = 0; i < tournamentSize; i++) {
//		do {
//			theChoosenOne = rand() % POPULATION_SIZE;
//		} while(doesArrayContainCity(alreadyChoosed, theChoosenOne));
//		if(bestFitness > fitness[theChoosenOne]) {
//			bestFitness = fitness[theChoosenOne];
//			fitness[theChoosenOne] = 9999;
//			winner = theChoosenOne;
//		}
//	}
//
////	newPopulation[which] = population[theChoosenOne];
//}
//
//double distanceBetweenPoints(int p1, int p2) {
//	return sqrt((locations[p1][0] - locations[p2][0]) * 
//				(locations[p1][0] - locations[p2][0])
//				+ 
//				(locations[p1][1] - locations[p2][1]) * 
//				(locations[p1][1] - locations[p2][1]));
//}
//
//void populateWithRandomPaths(int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES]) {
//	for(int i = 0; i < POPULATION_SIZE; i++) {
//		populateWithRandomPath(paths[i]);
//	}
//}
//
//void populateWithRandomPath(int (&path)[AMOUNT_OF_CITIES]) {
//	int nextCity;
//	for(int i = 0; i < AMOUNT_OF_CITIES; i++) {
//		do {
//			nextCity = rand() % AMOUNT_OF_CITIES;
//		} while(doesArrayContainCity(path, nextCity));
//
//		path[i] = nextCity;
//	}
//}
//
//bool doesArrayContainCity(const int arr[AMOUNT_OF_CITIES], const int number) {
//	for(int i = 0; i < AMOUNT_OF_CITIES; i++) { 
//		if(arr[i] == number) {
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void calculateFitness(const int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE]) {
//	for(int i = 0; i < POPULATION_SIZE; i++) {
//		fitness[i] = calculateFitnessForSinglePath(paths[i]);
//	}
//}
//
//double calculateFitnessForSinglePath(const int path[AMOUNT_OF_CITIES]) {
//	double fitness = 0;
//	for(int i = 0; i < AMOUNT_OF_CITIES - 1; i++) {
//		fitness += distanceBetweenPoints(path[i], path[i + 1]);
//	}
//	fitness += distanceBetweenPoints(path[AMOUNT_OF_CITIES - 1], path[0]);
//
//	return fitness;
//}