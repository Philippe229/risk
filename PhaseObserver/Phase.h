/*
 * Phase.h
 *
 *  Created on: Nov 9, 2017
 *      Author: Philippe
 */

#ifndef PHASE_H_
#define PHASE_H_

#include "../Common/Observer/Subject.h"
#include "PhaseObserver.h"
#include "../Player/Player.h"

class Phase : public Subject {

private:
	static PhaseObserver observer;

public:
	static void notify(Player* p, string phaseName, string message); // push the subject data to the observer

};

#endif /* PHASE_H_ */
