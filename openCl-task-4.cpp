// openCl-task-4.cpp : Defines the entry point for the console application.
//

#include <iostream>

int const AMOUNT_OF_CITIES = 5;
int const POPULATION_SIZE = 20;

double locations[AMOUNT_OF_CITIES][2] = {
		{1, 4},
		{2, 3},
		{0, 9},
		{12, 2},
		{4, 7}
	};

double distanceBetweenPoints(int p1, int p2);
void populateWithRandomPath(int (&path)[AMOUNT_OF_CITIES]);
bool doesArrayContainCity(int arr[AMOUNT_OF_CITIES], int number);
void populateWithRandomPaths(int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES]);
void calculateFitness(const int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE]);
double calculateFitnessForSinglePath(const int path[AMOUNT_OF_CITIES]);
void createNewPopulation(int (&population)[POPULATION_SIZE][AMOUNT_OF_CITIES], const double (&fitness)[POPULATION_SIZE]);

int main() {
	int population[POPULATION_SIZE][AMOUNT_OF_CITIES];
	double fitness[POPULATION_SIZE];
	populateWithRandomPaths(population);
	calculateFitness(population, fitness);
	createNewPopulation(population, fitness);

	return 0;
}

double distanceBetweenPoints(int p1, int p2) {
	return sqrt((locations[p1][0] - locations[p2][0]) * 
				(locations[p1][0] - locations[p2][0])
				+ 
				(locations[p1][1] - locations[p2][1]) * 
				(locations[p1][1] - locations[p2][1]));
}

void populateWithRandomPaths(int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES]) {
	for(int i = 0; i < POPULATION_SIZE; i++) {
		populateWithRandomPath(paths[i]);
	}
}

void populateWithRandomPath(int (&path)[AMOUNT_OF_CITIES]) {
	int nextCity;
	for(int i = 0; i < AMOUNT_OF_CITIES; i++) {
		do {
			nextCity = rand() % AMOUNT_OF_CITIES;
		} while(doesArrayContainCity(path, nextCity));

		path[i] = nextCity;
	}
}

bool doesArrayContainCity(const int arr[AMOUNT_OF_CITIES], const int number) {
	for(int i = 0; i < AMOUNT_OF_CITIES; i++) { 
		if(arr[i] == number) {
			return true;
		}
	}

	return false;
}

void calculateFitness(const int (&paths)[POPULATION_SIZE][AMOUNT_OF_CITIES], double (&fitness)[POPULATION_SIZE]) {
	for(int i = 0; i < POPULATION_SIZE; i++) {
		fitness[i] = calculateFitnessForSinglePath(paths[i]);
	}
}

double calculateFitnessForSinglePath(const int path[AMOUNT_OF_CITIES]) {
	double fitness = 0;
	for(int i = 0; i < AMOUNT_OF_CITIES - 1; i++) {
		fitness += distanceBetweenPoints(path[i], path[i + 1]);
	}
	fitness += distanceBetweenPoints(path[AMOUNT_OF_CITIES - 1], path[0]);

	return fitness;
}

void createNewPopulation(int (&population)[POPULATION_SIZE][AMOUNT_OF_CITIES], const double (&fitness)[POPULATION_SIZE]) {

}