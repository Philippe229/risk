/*
 * StatsDecorator.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Philippe
 */

#include "StatsDecorator.h"

StatsDecorator::StatsDecorator(GameStatsObserver* o) {
	this -> decoratedObserver = o;
}

void StatsDecorator::update() {
	decoratedObserver -> update();
}
