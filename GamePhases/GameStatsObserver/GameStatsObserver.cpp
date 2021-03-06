/*
 * GameStatsObserver.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include "GameStatsObserver.h"
#include <iostream>

using namespace std;

GameStatsObserver::GameStatsObserver(MainLoop* m) {
	mainLoop = m;
	mainLoop -> addObserver(this);
	locked = false;
}

GameStatsObserver::~GameStatsObserver() {
	if (mainLoop != NULL)
		mainLoop -> removeObserver(this);
}

void GameStatsObserver::update() {
    cout << endl << "###GAME STATISTICS###" << endl;
	cout << "Turn: " + to_string(mainLoop -> getTurn()) << endl;
    cout << "#####################" << endl;

}

MainLoop* GameStatsObserver::getMainLoop() {
	return mainLoop;
}

void GameStatsObserver::lock() {
	locked = true;
}

bool GameStatsObserver::getLock() {
	return locked;
}
