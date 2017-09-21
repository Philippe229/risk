/*
 * DiceRollingFacility.h
 *
 *  Created on: Sep 19, 2017
 *      Author: Philippe
 */

#ifndef DICEROLLINGFACILITY_H_
#define DICEROLLINGFACILITY_H_

#include <iostream>
#include <vector>
using namespace std;

class DiceRollingFacility {
	private:
		int diceRollHistory[6] = {0,0,0,0,0,0};
		void registerResult(int result);

	public:
		vector<int> throwDie(int numOfDie);
		void printDiceRollHistory();
};

#endif /* DICEROLLINGFACILITY_H_ */
