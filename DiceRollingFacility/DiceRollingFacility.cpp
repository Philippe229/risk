/*
 * DiceRollingFacility.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "DiceRollingFacility.h"
#include "Dice.h"

DiceRollingFacility::DiceRollingFacility(int seed) {
	srand(seed);
}

vector<int> DiceRollingFacility::throwDie(int numOfDie) {
	vector<int> results;

	if (numOfDie < 1 || numOfDie > 3) {
		cout << "Invalid number of die" << endl;
		return results;
	}

	while (numOfDie > 0) {
		Dice dice(rand());
		int result = dice.roll();
		this -> registerResult(result);
		results.push_back(result);
		numOfDie--;
	}

	return results;
}

void DiceRollingFacility::registerResult(int result) {
	diceRollHistory[result - 1]++;
}

void DiceRollingFacility::printDiceRollHistory() {
	double sum = 0;

	for (int count : diceRollHistory)
		sum += count;

	for (int index = 0; index < 6; index++)
			cout << "Percentage of times dice rolled " + to_string(index + 1) + ": " +
					to_string(diceRollHistory[index] / sum * 100) + "%" << endl;
}
