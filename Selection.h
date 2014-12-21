#include "Population.h"

class TournamentSelection {
	Path fightToDeath(const Path path1, const Path path2);
public:
	static void performSelection(Population (&population));
};
