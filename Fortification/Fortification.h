/*
 * Fortification.h
 *
 *  Created on: Oct 6, 2017
 *      Author: Philippe
 */

#ifndef FORTIFICATION_H_
#define FORTIFICATION_H_

#include "../Player/Player.h"
#include "../Map/Country.h"

using namespace std;

class Fortification {

private:
	static bool verifyTargetCountry(Player* player, Country* sourceCountry, Country* targetCountry);
	static bool verifyNumOfArmies(Country* sourceCountry, int numOfArmies);

public:
	static void fortify(Player* player, Country* sourceCountry, Country* targetCountry, int numOfArmies);

};

#endif /* FORTIFICATION_H_ */
