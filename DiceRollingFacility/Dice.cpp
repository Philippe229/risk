/*
 * Dice.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Dice.h"

Dice::Dice() {
	cout << "Dice constructed" << endl;
	srand(time(0)); // seed a random number with time
	best = -1;
}

Dice::~Dice() {
	cout << "Dice destroyed" << endl;
}

int Dice::roll() {
	return rand() % 6 + 1; // biased?
}


int Dice::getBest() {
	return best;
}
