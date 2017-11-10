/*
 * Phase.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Philippe
 */

#include "Phase.h"
#include "PhaseObserver.h"

PhaseObserver Phase::observer;

void Phase::notify(Player* player, string phaseName, string message) {
	observer.update(player, phaseName, message);
}
