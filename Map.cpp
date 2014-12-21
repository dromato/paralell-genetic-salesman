#include "Population.cpp"

const int MAP_SIZE = 20;

class Map
{
	Point map[MAP_SIZE];
	Point randomPoint();

public:
	Map() {
		for(int i = 0; i++; i < MAP_SIZE) {
			map[i] = randomPoint();
		}
	}
};