/*
 * Dice.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: Philippe
 */

#include <iostream>
using namespace std;
#include "Dice.h"

int Dice::roll() {
	return rand() % 6 + 1;
}
