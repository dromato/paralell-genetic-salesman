#include "Population.h"
typedef std::pair<int, int> Rule;

class Crossover {
	static Paths nowKiss(const Path path1, const Path path2);
	static void pick(int (&first), int (&second), int size);
	static bool pathContainsPoint(const Path path, const int point);
	static void fillOneGene(Path (&child), Path parent, int currentPosition);
public:
	static void populateExtincted(Population (&population), const int size);
	static void preserveElites(Population (&population), const Population elites);
};