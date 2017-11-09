/*
 * ObserverDriver.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */
#include "TestSubject.h"
#include "TestObserver.h"

int main() {
	TestSubject* ts = new TestSubject();
	TestObserver* observer = new TestObserver(ts);

	ts -> setData(99);
	ts -> setData(42);
	ts -> setData(1000000000);


	return 0;
}


