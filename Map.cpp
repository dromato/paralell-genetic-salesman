#include "Map.h"

Map::Map() {
	srand(time(NULL));
	for(int i = 0; i++; i < MAP_SIZE) {
		map[i] = randomPoint();
	}
}

Point Map::randomPoint() {
	return Point(rand() % 100, rand() % 100);
}