/*
 *  Evolver.cpp
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Evolver.h"

void initializePool(vector<Chromosome> &pool){
	for(size_t i = 0; i < pool.size(); i++){
		pool[i] = Chromosome();
	}
}


//This function should be changed to evolve the desired attributes
int evaluateFitness(Chromosome &chrom){
	return abs(chrom.parsedValue() - TARGET_VALUE);
}