/*
 * Decorator.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include "ObserverDecorator.h"

ObserverDecorator::ObserverDecorator(Observer* o) {
	this -> observer = o;
}

void ObserverDecorator::update() {
	observer -> update();
}
