/*
 *  chromosome.h
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */
#import <iostream>

#define CHROMOSOME_LENGTH 101

using namespace std;

enum OperationType { ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULUS, NON_OPERATION};

class Chromosome {
public:
    Chromosome();								// constructor; initialize the chromosome to random genotypes
	Chromosome(string startingGenotype);
    Chromosome combination(Chromosome mate);	//returns a Chromosome from mixing with another
	void mutate(float volatility);				//mutates genes with volatility as probabilty of each gene changing
	
	int fitnessScore();
	string description();
	string simpleDescription();
	
private:

	string _genes;                      
    int _fitnessScore;                  
	bool _scoreNeedsUpdate;
	
	void randomize();
	void mutate(size_t geneIndex);
	OperationType determineOperatorType(char operationChar);
	void applyOperation(OperationType operation, int number);
	void removeDivisionsByZero();
};