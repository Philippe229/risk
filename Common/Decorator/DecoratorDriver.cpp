/*
 * DecoratorDriver.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include "../Observer/Observer.h"
#include "../Observer/TestObserver.h"
#include "../Observer/TestSubject.h"
#include "TestDecorator.h"

int main() {
	TestSubject* ts = new TestSubject();
	Observer* testObserver = new TestObserver(ts);

	testObserver -> update();

	Observer* testDecorator = new TestDecorator(testObserver);

	testDecorator -> update();

	return 0;
}
