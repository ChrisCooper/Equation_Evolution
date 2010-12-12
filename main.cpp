#include <iostream>
#include "Chromosome.h"

using namespace std;

int main (int argc, char * const argv[]) {
	srand(time(0));
	
	Chromosome testChromosome = Chromosome();
	
	cout << testChromosome.description() << endl;
	cout << testChromosome.simpleDescription() << endl;
	cout << testChromosome.fitnessScore() << endl;
	
	for (int i =0; i < 100; i++){
		testChromosome.mutate(0.01f);
		cout << testChromosome.fitnessScore() << endl;
	}
	
	cout << testChromosome.description() << endl;
	cout << testChromosome.simpleDescription() << endl;
	cout << testChromosome.fitnessScore() << endl;
	
    return 0;
}

