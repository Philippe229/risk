/*
 * HandsDecorator.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Philippe
 */

#include "HandsDecorator.h"

HandsDecorator::HandsDecorator(GameStatsObserver* o) : StatsDecorator(o) {

}

void HandsDecorator::update() {
	StatsDecorator::update();
    vector<Player*> players = mainLoop -> getPlayers();

    cout << endl << "###HANDS STATISTICS###" << endl;

    for(Player* p : players) {
    	cout << "* " + p -> getName() + " hand:";
    	p-> getHand() ->PrintHand();
    }

    cout << "#####################" << endl;

}
