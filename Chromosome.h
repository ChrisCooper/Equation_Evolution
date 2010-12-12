/*
 *  chromosome.h
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */ 
#include <iostream>
#include "Probablilty.h"

#ifndef _CHROMOSOME_
#define _CHROMOSOME_

#define CHROMOSOME_LENGTH 100
#define CROSSOVER_AVERAGE_LENGTH (CHROMOSOME_LENGTH / 10)
#define CROSSOVER_CHANCE (((float)CHROMOSOME_LENGTH) / CROSSOVER_AVERAGE_LENGTH/2 / CHROMOSOME_LENGTH)

using namespace std;

enum OperationType { ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULUS, NON_OPERATION};

class Chromosome {
public:
    Chromosome();								// constructor; initialize the chromosome to random genotypes
	Chromosome(string startingGenotype);
    Chromosome combination(Chromosome &mate);	//returns a Chromosome from mixing with another
	void mutate(float volatility);				//mutates genes with volatility as probabilty of each gene changing
	
	int parsedValue();
	string description();
	string simpleDescription();
	void addCrossover(Chromosome &source, size_t startIndex, size_t crossoverLength);
	static bool compareChromosomes(Chromosome c1, Chromosome c2);
	
private:

	string _genes;                      
    int _parsedValue;                  
	bool _scoreNeedsUpdate;
	
	void randomize();
	void mutate(size_t geneIndex);
	OperationType determineOperatorType(char operationChar);
	void applyOperation(OperationType operation, int number);
	void removeDivisionsByZero();
};

#endif