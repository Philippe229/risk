/*
 * PhaseObserver.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Philippe
 */

#include <iostream>
#include "PhaseObserver.h"

void PhaseObserver::update(Player* newPlayer, string newPhase, string action) {
	if (newPlayer == NULL) {
		cout << "Error: player is null" << endl;
		return;
	}

	currentPlayer = newPlayer;
	currentPhase = newPhase;
	phaseAction = action;

	display();
}

void PhaseObserver::display() {
	cout << endl << "__________________________________________________" << endl;
	cout << currentPlayer -> getName() + ": " + currentPhase + " phase" << endl;
	cout << phaseAction << endl;
	cout << "__________________________________________________" << endl << endl;
}

void PhaseObserver::update() {

}




