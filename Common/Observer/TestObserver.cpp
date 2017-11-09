/*
 * TestObserver.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#include <iostream>
#include "TestObserver.h"

TestObserver::TestObserver() {
	// Creates an observer with no subject to observe
	testSubject = NULL;
}

TestObserver::TestObserver(TestSubject* ts) {
	testSubject = ts;
	testSubject -> addObserver(this);
}

TestObserver::~TestObserver() {
	if (testSubject != NULL)
		testSubject -> removeObserver(this);
}

void TestObserver::update() {
	display();
}

void TestObserver::display() {
	cout << testSubject -> getData() << endl;
}

