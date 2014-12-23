#include "Population.h"

class Mutation {
public:
	static void mutate(Population (&population), int rate);

private:
	static void singleMutataion(Path &path);
	static void pick(int &firstPt, int &secondPt, int length);
};