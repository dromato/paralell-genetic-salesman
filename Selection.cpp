#include "Selection.h"

void TournamentSelection::performSelection(Population (&population)) {
	int initialSize = population.paths.size();
	int first, second;
	for(int i = 0; i < initialSize / 2; i++) {
		pick(first, second, population.paths.size());
		kill(population, first, second);
	}
}

void TournamentSelection::pick(int (&first), int (&second), int size) {
	first = rand() % size;
	do {
		second = rand() % size;
	}while(first == second);
}

void TournamentSelection::kill(Population (&population), int first, int second) {
	if(population.paths[first].fitness < population.paths[second].fitness) {
		population.paths.erase(population.paths.begin() + first);
	} else {
		population.paths.erase(population.paths.begin() + second);
	}
}