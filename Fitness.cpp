#include "Population.cpp"

class Fitness {
	double calculate(Path path);

public:
	static void calculate(Population (&population));
};