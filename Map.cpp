#include "Map.h"
#include <time.h>
#include <stdlib.h>
#include <cmath>

Point::Point(int c_x, int c_y) {
	x = c_x;
	y = c_y;
}

Point::Point() { }

Point Point::randomPoint() {
	return Point(rand() % 100, rand() % 100);
}

Point Map::map[];

double Map::distanceBetween(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double Map::distanceBetween(int p1, int p2) {
	return Map::distanceBetween(map[p1], map[p2]);
}

void Map::generateMap() {
	srand(time(NULL));
	for(int i = 0; i < MAP_SIZE; i++) {
		map[i] = Point::randomPoint();
	}
}
