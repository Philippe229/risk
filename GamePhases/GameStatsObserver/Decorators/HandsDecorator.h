/*
 * HandsDecorator.h
 *
 *  Created on: Nov 23, 2017
 *      Author: Philippe
 */

#ifndef GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_HANDSDECORATOR_H_
#define GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_HANDSDECORATOR_H_

#include "StatsDecorator.h"

class HandsDecorator : public StatsDecorator {

private:

public:
	HandsDecorator(GameStatsObserver* o);
	void update();

};

#endif /* GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_HANDSDECORATOR_H_ */
