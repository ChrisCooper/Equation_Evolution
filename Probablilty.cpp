/*
 *  Probablilty Functions.cpp
 *  Evolution
 *
 *  Created by Chris Cooper on 10-12-12.
 *  Copyright 2010 Chris Cooper. All rights reserved.
 *
 */

#include "Probablilty.h"

int binomialRandomAroundTarget(int target){
	int trials = target * 2;
	float probability = 0.5;
	int total = 0;
	
	for (int i = 0; i < trials; i++){
		if (zeroToOneUniform()  < probability){
			total++;
		}
	}
	return total;
}

float zeroToOneUniform(){
	return (((float)rand()) / RAND_MAX);
}

bool eventHappenedWithProbability(float probability){
	return zeroToOneUniform() < probability;
}