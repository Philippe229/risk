/*
 * ContinentsDecorator.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Philippe
 */

#include "ContinentsDecorator.h"

ContinentsDecorator::ContinentsDecorator(GameStatsObserver* o) : StatsDecorator(o) {

}

void ContinentsDecorator::update() {
	StatsDecorator::update();

	Map* map = mainLoop -> getMap();

    cout << endl << "###CONTINENTS STATISTICS###" << endl;

    for (Continent* c : map -> getContinents())
    	cout << c -> getName() + " ownership: " + c -> getOwner() << endl;

    cout << "#####################" << endl;

}

