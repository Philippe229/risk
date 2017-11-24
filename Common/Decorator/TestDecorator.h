/*
 * TestDecorator.h
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#ifndef COMMON_DECORATOR_TESTDECORATOR_H_
#define COMMON_DECORATOR_TESTDECORATOR_H_

#include "../Observer/Observer.h"
#include "ObserverDecorator.h"

class TestDecorator : public ObserverDecorator {

private:

public:
	TestDecorator(Observer* o);
	void update();

};

#endif /* COMMON_DECORATOR_TESTDECORATOR_H_ */
