/*
 * TestDecorator.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include "TestDecorator.h"
#include <iostream>

using namespace std;

TestDecorator::TestDecorator(Observer* o) : ObserverDecorator(o) {

}

/* Override Decorator method to add functionality */
void TestDecorator::update() {
	observer -> update();
	cout << "TestDecorator overriding Decorator update()" << endl;
}
