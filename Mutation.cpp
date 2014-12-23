#include "Mutation.h"

void Mutation::mutate(Population (&population), int rate) {
	int dice;
	for(int i = 0; i < population.paths.size(); i++) {
		dice = rand() % 100;
		if(dice < rate) {
			singleMutataion(population.paths[i]);
		}
	}
}

void Mutation::singleMutataion(Path &path) {
	int firstPt, secondPt;
	pick(firstPt, secondPt, path.cities.size() - 1);
	Points temp;
	for(int i = firstPt; i <= secondPt; i++) {
		temp.push_back(path.cities[i]);
	}

	for(int i = firstPt; i <= secondPt; i++) {
		path.cities[i] = temp[secondPt - i];
	}
}

void Mutation::pick(int &firstPt, int &secondPt, int length) {
	int x1 = rand() % length;
	int x2;
	do {
		x2 = rand() % length;
	} while(x1 == x2);

	firstPt = (x1 < x2) ? x1 : x2;
	secondPt = (x1 > x2) ? x1 : x2;
}