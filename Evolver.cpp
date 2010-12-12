/*
 *  Evolver.cpp
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Evolver.h"

void advanceGeneration(vector<Chromosome> &pool){
	
	//cout << "Top candidate: " << endl;// << pool[0].description() << endl;
	//printf("Value: %d\n", pool[0].parsedValue());
	printf("Fitness: %10d, value: %10d, length: %5d ", evaluateFitness(pool[0]), pool[0].parsedValue(), (int)pool[0].simpleDescription().length());
	cout << pool[0].simpleDescription() << endl;
	
	pool.resize(SURVIVORS_PER_GENERATION);
	
	//Mutate
	for (size_t i = 0; i < SURVIVORS_PER_GENERATION; i++){
		pool[i].mutate(MUTATION_RATE);
	}
	
	//Recombine and mate
	for (size_t i = 0; i < SURVIVORS_PER_GENERATION; i++){
		
		for (int j = 0; j < MATES_PER_ORGANISM; j++) {
			Chromosome newChromosome = pool[i].combination(pool[rand() % SURVIVORS_PER_GENERATION]);
			pool.push_back(newChromosome);
		}
	}
	
	sort(pool.begin(), pool.end(), Chromosome::compareChromosomes);
	
	//Intermate the surviors, MATES_PER_ORGANISM times per organism
}

void initializePool(vector<Chromosome> &pool){
	for(size_t i = 0; i < pool.size(); i++){
		pool[i] = Chromosome();
	}
}


//This function should be changed to evolve the desired attributes
int evaluateFitness(Chromosome &chrom){
	int value = abs(chrom.parsedValue() - TARGET_VALUE);
	value += SHORTNESS_IMPORTANCE * chrom.simpleDescription().length();
	value += LENGTH_IMPORTANCE * (CHROMOSOME_LENGTH - chrom.simpleDescription().length());
	return value;
}