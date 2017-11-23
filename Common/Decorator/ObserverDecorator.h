/*
 * Decorator.h
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#ifndef COMMON_DECORATOR_OBSERVERDECORATOR_H_
#define COMMON_DECORATOR_OBSERVERDECORATOR_H_

#include "../Observer/Observer.h"

class ObserverDecorator : public Observer {

protected:
	Observer* observer;

public:
	ObserverDecorator(Observer* o);
	void update();

};

#endif /* COMMON_DECORATOR_OBSERVERDECORATOR_H_ */
