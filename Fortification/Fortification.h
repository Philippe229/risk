/*
 * Fortification.h
 *
 *  Created on: Oct 6, 2017
 *      Author: Philippe
 */

#ifndef FORTIFICATION_H_
#define FORTIFICATION_H_

#include "../Player/Player.h"

using namespace std;

class Fortification {

private:
	static bool verifyTargetCountry(Player* player, string sourceCountry, string targetCountry);
	static bool verifyNumOfArmies(Player* player, string sourceCountry, int numOfArmies);

public:
	static void fortify(Player* player, string sourceCountry, string targetCountry, int numOfArmies);

};

#endif /* FORTIFICATION_H_ */
