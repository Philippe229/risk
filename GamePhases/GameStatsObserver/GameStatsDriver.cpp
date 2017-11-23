/*
 * GameStatsDriver.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include <ctime>
#include "../Initialization.h"
#include "../Startup.h"
#include "../MainLoop.h"

int main() {
	srand(time(0));
	Initialization init;
	Startup startup(init.getPlayers(), init.getMap(), true);
	MainLoop game(startup.getPlayerOrder(), init.getMap(), init.getDeck());
	game.play();

    return 0;
}

