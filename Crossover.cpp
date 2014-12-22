#include "Crossover.h"
#include <utility>

Paths Crossover::nowKiss(const Path path1, const Path path2) {
	// Determine crossing points
	int length = path1.cities.size(); // There is 1 crossing point less than actual length
	int firstCrossPt, secondCrossPt;
	pick(firstCrossPt, secondCrossPt, length - 1);

	Path child1 = Path();
	Path child2 = Path();
	child1.cities = Points(length, -1);
	child2.cities = Points(length, -1);

	int nOfRules = secondCrossPt - firstCrossPt;
	Rule* rules = new Rule[nOfRules * 2];
	for(int i = 0; i < nOfRules; i++) {
		rules[i] = Rule(path1.cities[firstCrossPt + i], path2.cities[firstCrossPt + i]);
	}
	for(int i = nOfRules; i < nOfRules * 2; i++) {
		rules[i] = Rule(path2.cities[firstCrossPt + (i - nOfRules)], path1.cities[firstCrossPt + (i - nOfRules)]);
	}

	for(int i = 0; i < length; i++) {
		
	}

	for(int i = 0; i < length; i++) {
		fillOneGene(child1, path2, i);
		fillOneGene(child2, path1, i);
	}

	return Paths();
}

bool Crossover::pathContainsPoint(const Path path, const int point) {
	for(Points::size_type i = 0; i < path.cities.size(); i++) {
		if(path.cities[i] == point) {
			return true;
		}
	}

	return false;
}

void Crossover::fillOneGene(Path (&child), Path parent, int currentPosition) {
	if(child.cities[currentPosition] == -1) {
		for(int j = 0; j < child.cities.size(); j++) {
			if(!pathContainsPoint(child, parent.cities[j])) {
				child.cities[currentPosition] = parent.cities[j];
				break;
			}
		}
	}
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