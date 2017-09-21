#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "DiceRollingFacility.h"

int main() {
	srand(time(0));

	int seed1 = rand();
	int seed2 = rand();

	while (seed2 == seed1)
		seed2 = rand();

	DiceRollingFacility diceRollingFacility1(seed1);
	DiceRollingFacility diceRollingFacility2(seed2);

	cout << "Throw 2 die:" << endl;

	for (int result : diceRollingFacility1.throwDie(2)) {
		cout << result << endl;
	}

	cout << "Throw 3 die:" << endl;

	for (int result : diceRollingFacility2.throwDie(3)) {
		cout << result << endl;
	}

	cout << "diceRollingFacility1 history:" << endl;
	diceRollingFacility1.printDiceRollHistory();

	cout << "diceRollingFacility2 history:" << endl;
	diceRollingFacility2.printDiceRollHistory();

	return 0;
}

// attacker has at least 2 die and at most 3 die
// defender has at least 1 die and at most 2 die
// best roll vs best roll then second best roll vs second best roll
// each player has its own dice rolling facility
