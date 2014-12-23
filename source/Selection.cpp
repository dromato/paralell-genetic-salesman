#include "Selection.h"

Population TournamentSelection::performSelection(Population population) {
	int initialSize = population.paths.size();
	Population newGeneration;
	Points entries;
	for(int i = 0; i < initialSize / 2; i++) {
		entries = pick(population.paths.size());
		select(population, newGeneration, entries);
	}

	return newGeneration;
}

Points TournamentSelection::pick(int size) {
	int candidate;
	Points entries;
	do {
		candidate = rand() % size;
		if(notContain(entries, candidate)) {
			entries.push_back(candidate);
		}
	} while(entries.size() < 10);

	return entries;
}

bool TournamentSelection::notContain(Points (&points), int point) {
	for(int i = 0; i < points.size(); i++) {
		if(points[i] == point) {
			return false;
		}
	}
	return true;
}

void TournamentSelection::select(Population (&population), Population (&newGeneration), Points candidates) {
	int best = candidates[0];
	for(int i = 1; i < candidates.size(); i++) {
		if(population.paths[candidates[i]].fitness < population.paths[best].fitness) {
			best = candidates[i];
		}
	}

	newGeneration.paths.push_back(population.paths[best]);
}