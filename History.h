#include <vector>

typedef std::vector<double> FitnessHistory;

class History {
public:
	int currentGenration;
	FitnessHistory history;
	void printHistory();
};