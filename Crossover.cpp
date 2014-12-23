#include "Crossover.h"
#include <utility>

Paths Crossover::nowKiss(const Path path1, const Path path2) {
	// Determine crossing points
	int length = path1.cities.size();
	int firstCrossPt, secondCrossPt;
	pick(firstCrossPt, secondCrossPt, length - 1);

	CrossingData crossingData = CrossingData::getInstance(length, firstCrossPt, secondCrossPt);

	Path child1 = Path();
	Path child2 = Path();
	child1.cities = Points(length, -1);
	child2.cities = Points(length, -1);

	for(int i = crossingData.firstCrossingPoint; i <= crossingData.secondCrossingPoint; i++) {
		child1.cities[i] = path2.cities[i];
		child2.cities[i] = path1.cities[i];
	}

	populateAroundCrossingPoints(path1, path2, child1, child2, crossingData);

	populateRemainingFromParent(child1, path1, crossingData.chromosomeLenght);
	populateRemainingFromParent(child2, path2, crossingData.chromosomeLenght);

	Paths result = Paths();
	result.push_back(child1);
	result.push_back(child2);

	return result;
}

CrossingData CrossingData::getInstance(int length, int firstCrossingPt, int secondCrossingPt) {
	CrossingData data = CrossingData();
	data.chromosomeLenght = length;
	data.firstCrossingPoint = firstCrossingPt;
	data.secondCrossingPoint = secondCrossingPt;

	return data;
}

void Crossover::populateAroundCrossingPoints(Path parent1, Path parent2, Path (&child1), Path (&child2), CrossingData crossingData) {
	for(int i = 0; i < crossingData.chromosomeLenght; i++) {
		if(i >= crossingData.firstCrossingPoint && i <= crossingData.secondCrossingPoint) {
			continue;
		}

		if(!pathContainsPoint(child1, parent1.cities[i])) {
			child1.cities[i] = parent1.cities[i];
		}
		if(!pathContainsPoint(child2, parent2.cities[i])) {
			child2.cities[i] = parent2.cities[i];
		}
	}
}

bool Crossover::pathContainsPoint(const Path path, const int point) {
	for(Points::size_type i = 0; i < path.cities.size(); i++) {
		if(path.cities[i] == point) {
			return true;
		}
	}

	return false;
}

void Crossover::populateRemainingFromParent(Path (&child), Path parent, int length) {
	for(int i = 0; i < length; i++) {
		if(child.cities[i] == -1) {
			fillOneGene(child, parent, i, length);
		}
	}
}

void Crossover::fillOneGene(Path (&child), Path parent, int currentPosition, int length) {
	for(int j = 0; j < length; j++) {
		if(!pathContainsPoint(child, parent.cities[j])) {
			child.cities[currentPosition] = parent.cities[j];
		}
	}
}

void Crossover::populateExtincted(Population (&population), const int size) {
	Paths childrens;
	int first, second;
	int initialSize = population.paths.size();
	Paths childs;
	for(int i = initialSize; i < size; i++) {
		pick(first, second, initialSize); // We need to pick from older part of generation.
		childs = nowKiss(population.paths[first], population.paths[second]);
		population.paths.push_back(childs[0]);
		if(population.paths.size() == size) break;
		population.paths.push_back(childs[1]);
		if(population.paths.size() == size) break;
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