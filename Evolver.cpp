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
	
	sort(pool.begin(), pool.end(), Chromosome::compareChromosomes);
	
	//cout << "Top candidate: " << endl;// << pool[0].description() << endl;
	//printf("Value: %d\n", pool[0].parsedValue());
	printf("Fitness: %d\n", evaluateFitness(pool[0]));
	
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
	
	
	
	//Intermate the surviors, MATES_PER_ORGANISM times per organism
}

void initializePool(vector<Chromosome> &pool){
	for(size_t i = 0; i < pool.size(); i++){
		pool[i] = Chromosome();
	}
}


//This function should be changed to evolve the desired attributes
int evaluateFitness(Chromosome &chrom){
	return abs(chrom.parsedValue() - TARGET_VALUE);
}