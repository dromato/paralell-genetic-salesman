#include "Population.h"

class Crossover {
	static Paths nowKiss(const Path path1, const Path path2);
	static void pick(int (&first), int (&second), int size);
public:
	static void populateExtincted(Population (&population), const int size);
	static void preserveElites(Population (&population), const Population elites);
};