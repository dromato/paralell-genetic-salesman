#include "Population.cpp"

class Crossover {
	static Paths nowKiss(const Path path1, const Path path2);
public:
	static void populateExtincted(Population (&population), const int size);
	static void populateWithElite(Population (&toBePopulated), const Population oldGeneration);
	static void preserveElites(Population (&population), const Population elites);
};