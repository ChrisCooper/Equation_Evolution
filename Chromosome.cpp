/*
 *  chromosome.cpp
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "chromosome.h"
#include "Evolver.h"

//string genes;                      
//int fitnessScore;                  
//bool scoreNeedsUpdate;

string genotpyeSet = string("0123456789+-*/%");

string operationCharacters = string("+-*/%");

Chromosome::Chromosome(){
	_genes = string(CHROMOSOME_LENGTH, '0');
	randomize();
	_scoreNeedsUpdate = true;
}

Chromosome::Chromosome(string startingGenotype){
	if (startingGenotype.length() != CHROMOSOME_LENGTH){
		randomize();
	} else {
		_genes = startingGenotype.substr(0);
	}
	removeDivisionsByZero();
	_scoreNeedsUpdate = true;
}

Chromosome Chromosome::combination(Chromosome &mate){
	Chromosome newChromosome = Chromosome(_genes.substr(0));
	
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++) {
		if (eventHappenedWithProbability(CROSSOVER_CHANCE)){
			int crossoverLength = binomialRandomAroundTarget(CROSSOVER_AVERAGE_LENGTH);
			newChromosome.addCrossover(mate, i, crossoverLength);
		}
	}
	
	return newChromosome;
}

void Chromosome::addCrossover(Chromosome &source, size_t startIndex, size_t crossoverLength){
	for (size_t i = startIndex; i < CHROMOSOME_LENGTH && i < startIndex + crossoverLength; i++) {
		_genes[i] = source._genes[i];
	}
	removeDivisionsByZero();
}

void Chromosome::mutate(float volatility){
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++){
		if (eventHappenedWithProbability(volatility)){
			mutate(i);
		}
	}
}

	
int Chromosome::parsedValue(){
	if (!_scoreNeedsUpdate){
		return _parsedValue;
	}
	
	bool expectsOperator = false;
	_parsedValue = 0;
	OperationType operation = ADD;
	
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++){
		if (expectsOperator){
			
			operation = determineOperatorType(_genes[i]);
			
			if (operation != NON_OPERATION){
				expectsOperator = false;
			}
			
		} else {
			int number = _genes[i] - '0';
			
			if (number < 0 || number > 9){
				continue;
			}
			
			applyOperation(operation, number);

			expectsOperator = true;
		}
	}
	
	return _parsedValue;
}

void Chromosome::applyOperation(OperationType operation, int number){
	switch (operation) {
		case ADD:
			_parsedValue += number;
			break;
		case SUBTRACT:
			_parsedValue -= number;
			break;
		case MULTIPLY:
			_parsedValue *= number;
			break;
		case DIVIDE:
			_parsedValue /= number;
			break;
		case MODULUS:
			_parsedValue %= number;
			break;
		default:
			cout << "Non operation not expected while calculation fitness.\n";
			break;
	}
}

OperationType Chromosome::determineOperatorType(char operationChar){
	size_t operatorIndex = operationCharacters.find(operationChar);
	bool operatorFound = operatorIndex != string::npos;
	
	if (!operatorFound){
		return NON_OPERATION;
	}
	
	return (OperationType) operatorIndex;
}

void Chromosome::randomize(){
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++){
		mutate(i);
	}
}

void Chromosome::mutate(size_t geneIndex){
	size_t genotypeIndex = (size_t)rand() % genotpyeSet.length();
	_genes[geneIndex] = genotpyeSet[genotypeIndex];
	removeDivisionsByZero();
	_scoreNeedsUpdate = true;

}

void Chromosome::removeDivisionsByZero(){
	bool foundDivision = false;
	
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++) {
		if (foundDivision){
			if (_genes[i] == '0'){
				_genes[i] = ((rand() % 9) + 1) + '0';
				foundDivision = false;
			}
			
			
		} else {
			OperationType type = determineOperatorType(_genes[i]);
			if (type == DIVIDE || type == MODULUS){
				foundDivision = true;
			}
		}
	}
}

string Chromosome::description(){
	return string("Chromosome: ") + _genes.substr(0);
}

string Chromosome::simpleDescription(){
	string theDescription = string("");
	bool operatorExpected = false;
	
	for (size_t i = 0; i < CHROMOSOME_LENGTH; i++) {
		if (operatorExpected){
			if (operationCharacters.find(_genes[i]) != string::npos){
				theDescription += _genes[i];
				operatorExpected = false;
			}
			
		} else {
			int number = _genes[i] - '0';
			if (number < 0 || number > 9){
				continue;
			}
			theDescription += _genes[i];
			operatorExpected = true;
		}
	}
	
	if (!operatorExpected){
		theDescription.erase(theDescription.length()-1, 1);
	}
	return string("Simple Chromosome: ") + theDescription;
}

bool Chromosome::compareChromosomes(Chromosome c1, Chromosome c2){
	return (evaluateFitness(c1) < evaluateFitness(c2));
}