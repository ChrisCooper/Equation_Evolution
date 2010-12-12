/*
 *  Evolver.h
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include "Chromosome.h"

#ifndef _EVOLVER_
#define _EVOLVER_

#define MUTATION_RATE 0.02f
#define SURVIVORS_PER_GENERATION 30
#define MATES_PER_ORGANISM 3
#define GENERATION_SIZE (SURVIVORS_PER_GENERATION * MATES_PER_ORGANISM)
#define GENERATIONS 200

#define TARGET_VALUE 725000

void advanceGeneration(vector<Chromosome> &pool);
void initializePool(vector<Chromosome> &pool);
int evaluateFitness(Chromosome &chrom);

#endif