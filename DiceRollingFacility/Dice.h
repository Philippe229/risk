/*
 * Dice.h
 *
 *  Created on: Sep 18, 2017
 *      Author: Philippe
 */

#ifndef DICE_H_
#define DICE_H_

#include <iostream>
#include <vector>
using namespace std;

class Dice {

private:
	vector<int> results; // list or array instead?
	int best;

public:
	Dice();
	~Dice();
	int roll();
	int getResults();
	int getBest();

};

#endif /* DICE_H_ */
