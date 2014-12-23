const int MAP_SIZE = 100;

class Point {
public:
	int x, y;
	Point();
	Point(int c_x, int c_y);

	static Point randomPoint();
};

class Map {
	static Point map[MAP_SIZE];
	static double distanceBetween(const Point p1, const Point p2);

public:
	static void generateMap();
	static double distanceBetween(int p1, int p2);
};