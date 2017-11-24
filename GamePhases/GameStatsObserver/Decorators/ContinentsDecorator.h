/*
 * ContinentsDecorator.h
 *
 *  Created on: Nov 23, 2017
 *      Author: Philippe
 */

#ifndef GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_CONTINENTSDECORATOR_H_
#define GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_CONTINENTSDECORATOR_H_

#include "StatsDecorator.h"

class ContinentsDecorator : public StatsDecorator {

private:

public:
    ContinentsDecorator(GameStatsObserver* o);
	void update();

};

#endif /* GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_CONTINENTSDECORATOR_H_ */
