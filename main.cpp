#include <iostream>
#include <vector>
#include "Evolver.h"


using namespace std;

int main (int argc, char * const argv[]) {
	srand(time(0));
	
	vector<Chromosome> pool(GENERATION_SIZE);
	initializePool(pool);

	sort(pool.begin(), pool.end(), Chromosome::compareChromosomes);
	
	for(int generation = 0; generation < GENERATIONS; generation++){
		printf("%5d ", generation);
		advanceGeneration(pool);
	}
	
	
	cout << "Top candidate: " << pool[0].simpleDescription() << endl;
	cout << pool[0].description() << endl;
	printf("Value: %d\n", pool[0].parsedValue());
	printf("Fitness: %d\n", evaluateFitness(pool[0]));
	
    return 0;
}


/*	for (int i = 0; i < pool.size(); i++){
	printf("%10d %10d\n",pool[i].parsedValue(), evaluateFitness(pool[i]));
}*/