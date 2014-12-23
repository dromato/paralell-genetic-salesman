#include <vector>

typedef std::vector<double> FitnessHistory;

class History {
public:
	int currentGenration;
	FitnessHistory historyMean;
	FitnessHistory historyBest;
	void printHistory(int size);
};