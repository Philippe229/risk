#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "DiceRollingFacility.h"

int main() {
	srand(time(0));

	DiceRollingFacility diceRollingFacility1;
	DiceRollingFacility diceRollingFacility2;

	cout << "Throw 2 die:" << endl;

	for (int result : diceRollingFacility1.throwDie(2)) {
		cout << result << endl;
	}

	cout << "\nThrow 3 die:" << endl;

	for (int result : diceRollingFacility2.throwDie(3)) {
		cout << result << endl;
	}

	cout << "\ndiceRollingFacility1 history:" << endl;
	diceRollingFacility1.printDiceRollHistory();

	int loopCount = 1000;

	while (loopCount > 0) {
		diceRollingFacility2.throwDie(3);
		loopCount--;
	}

	cout << "\ndiceRollingFacility2 history after 3000 dice throws:" << endl;
	diceRollingFacility2.printDiceRollHistory();

	return 0;
}
