const int MAP_SIZE = 20;

struct Point {
	int x, y;
	Point();
	Point(int c_x, int c_y);
};

class Map
{
	Point map[MAP_SIZE];
	Point randomPoint();

public:
	Map();
};