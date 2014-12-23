#include "History.h"
#include <iostream>

void History::printHistory(int size) {
	std::cout << std::endl;
	for(int i = 0; i += 50; i < size) {
		if(i < historyBest.size())
			std::cout << "Generation: " << i << ". Mean  :  " << historyMean[i] << ",  best:  " << historyBest[i] << std::endl;
	}
}