#include "Crossover.h"
#include <utility>
typedef std::pair<int, int> Rule;

Paths Crossover::nowKiss(const Path path1, const Path path2) {
	// Determine crossing points
	int length = path1.cities.size(); // There is 1 crossing point less than actual length
	int firstCrossPt, secontCrossPt;
	pick(firstCrossPt, secontCrossPt, length - 1);
	
	// Create rules for exchange
	int nOfRules = secontCrossPt - firstCrossPt + 1;
	Rule* rules = new Rule[nOfRules];
	for(int i = 0; i + firstCrossPt <= secontCrossPt; i++) {
		rules[i] = Rule(path1.cities[firstCrossPt + i], path2.cities[firstCrossPt + i]);
	}
	
	Path child1 = Path();
	Path child2 = Path();
	child1.cities.reserve(length);
	child2.cities.reserve(length);
	// Fill childrens genes between crosspoints
	for(int i = 0; i + firstCrossPt <= secontCrossPt; i++) {
		
	}

	delete[] rules;
	return Paths();
}

void Crossover::populateExtincted(Population (&population), const int size) {
	Paths childrens;
	int first, second;
	int initialSize = population.paths.size();
	for(int i = initialSize; i < size; i++) {
		pick(first, second, initialSize); // We need to pick from older part of generation.
		nowKiss(population.paths[first], population.paths[second]);
	}
}

void Crossover::preserveElites(Population (&population), const Population elites) {
	for(int i = 0; i < elites.paths.size(); i++) {
		population.paths.push_back(elites.paths[i]);
	}
}

void Crossover::pick(int (&first), int (&second), int size) {
	first = rand() % size;
	do {
		second = rand() % size;
	} while(first == second);

	int smallerCrossPt = (first < second) ? first : second;
	int largerCrossPt = (first > second) ? first : second;

	first = smallerCrossPt;
	second = largerCrossPt;
}