#include <iostream>
#include <vector>
#include "Evolver.h"


using namespace std;

int main (int argc, char * const argv[]) {
	srand(time(0));
	
	vector<Chromosome> pool(GENERATION_SIZE);
	initializePool(pool);
	

	
	cout << "sorting" << endl;
	sort(pool.begin(), pool.end(), Chromosome::compareChromosomes);
	
	for (int i = 0; i < pool.size(); i++){
		printf("%10d %10d\n",pool[i].parsedValue(), evaluateFitness(pool[i]));
	}
	
	for(int generation = 0; generation < GENERATIONS; generation++){
		//sort(pool.begin(), pool.end(), Chromosome::compareChromosomes);
		
		//Find top SURVIVORS_PER_GENERATION survivors
		
		
		//Intermate the surviors, MATES_PER_ORGANISM times per organism
	}
	
	
    return 0;
}


/*	for (int i = 0; i < pool.size(); i++){
	printf("%10d %10d\n",pool[i].parsedValue(), evaluateFitness(pool[i]));
}*/