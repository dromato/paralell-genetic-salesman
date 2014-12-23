#include "Population.h"
typedef std::pair<int, int> Rule;

struct CrossingData {
	int firstCrossingPoint, secondCrossingPoint, chromosomeLenght;

	static CrossingData getInstance(int chromosomeLenght, int firstCrossingPt, int secontCrossingPt);
};

class Crossover {
	static Paths nowKiss(const Path path1, const Path path2);
	static CrossingData generateCrossingData(int chromosomeLength);
	static void pick(int (&first), int (&second), int size);
	static bool pathContainsPoint(const Path path, const int point);
	static void fillOneGene(Path (&child), Path parent, int currentPosition, int length);
	static void populateRemainingFromParent(Path (&child), Path parent, int length);
	static void populateAroundCrossingPoints(Path parent1, Path parent2, Path (&child1), Path (&child2), CrossingData crossingData);
public:
	static void populateExtincted(Population (&population), const int size);
	static void preserveElites(Population (&population), const Population elites);
};