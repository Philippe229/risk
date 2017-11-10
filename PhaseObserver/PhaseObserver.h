/*
 * PhaseObserver.h
 *
 *  Created on: Nov 9, 2017
 *      Author: Philippe
 */

#ifndef PHASEOBSERVER_H_
#define PHASEOBSERVER_H_

#include <iostream>
#include "../Common/Observer/Observer.h"
#include "../Player/Player.h"

class PhaseObserver : public Observer {

private:
	// Subject (phase) data:
	Player* currentPlayer;
	string currentPhase;
	string phaseAction;

public:
	void update();
	void update(Player* p, string currentPhase, string action);
	void display();

};

#endif /* PHASEOBSERVER_H_ */
