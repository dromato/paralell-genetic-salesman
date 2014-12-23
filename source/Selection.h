#include "Population.h"

class TournamentSelection {
private:
	static void select(Population (&population), Population (&newGeneration), Points candidates);
	static Points pick(int size);
	static bool notContain(Points (&points), int point);
public:
	static Population performSelection(Population population);
};
