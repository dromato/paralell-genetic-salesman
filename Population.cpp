#include <vector>

struct Point {
	int x, y;
};

typedef std::vector<Point> Points;

struct Path {
	Points points;
};

typedef std::vector<Path> Paths;

class Population {
public:
	Paths paths;
};