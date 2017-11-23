/*
 * GameStatsObserver.h
 *
 *  Created on: Nov 17, 2017
 *      Author: Philippe
 */

#ifndef GAMEPHASES_GAMESTATSOBSERVER_GAMESTATSOBSERVER_H_
#define GAMEPHASES_GAMESTATSOBSERVER_GAMESTATSOBSERVER_H_

#include "../../Common/Observer/Observer.h"
#include "../MainLoop.h"

class MainLoop;

class GameStatsObserver : public Observer {

protected:
	MainLoop* mainLoop;

public:
	GameStatsObserver();
	GameStatsObserver(MainLoop* m);
	~GameStatsObserver();
	void update();

};

#endif /* GAMEPHASES_GAMESTATSOBSERVER_GAMESTATSOBSERVER_H_ */
