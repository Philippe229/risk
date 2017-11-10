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
#include "../PhaseObserver/Phase.h"

using namespace std;

class Fortification : public Phase {

private:
	static bool verifyNumOfArmies(Country* sourceCountry, int numOfArmies);

public:
	static void startFortify(Player* player);
	static void fortify(Player* player, Country* sourceCountry, Country* targetCountry, int numOfArmies);
	static bool verifyTargetCountry(Player* player, Country* sourceCountry, Country* targetCountry);
};

#endif /* FORTIFICATION_H_ */
