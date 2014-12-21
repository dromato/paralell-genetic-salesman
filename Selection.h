#include "Population.h"

class TournamentSelection {
private:
	static void kill(Population (&population), int first, int second);
	static void pick(int (&first), int (&second), int size);
public:
	static void performSelection(Population (&population));
};
