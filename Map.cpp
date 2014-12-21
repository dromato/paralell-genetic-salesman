#include "Map.h"
#include <time.h>
#include <stdlib.h>

Point::Point(int c_x, int c_y) {
	x = c_x;
	y = c_y;
}

Point::Point() { }

Map::Map() {
	srand(time(NULL));
	for(int i = 0; i < MAP_SIZE; i++) {
		map[i] = randomPoint();
	}
}

Point Map::randomPoint() {
	return Point(rand() % 100, rand() % 100);
}