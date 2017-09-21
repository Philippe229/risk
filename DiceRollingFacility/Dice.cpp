/*
 * Dice.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Dice.h"

Dice::Dice(int seed) {
	srand(seed);
}

int Dice::roll() {
	return rand() % 6 + 1;
}
