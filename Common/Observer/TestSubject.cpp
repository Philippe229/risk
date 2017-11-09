/*
 * TestSubject.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#include "TestSubject.h"

TestSubject::TestSubject() : someData(42) {

}

TestSubject::~TestSubject() {

}

void TestSubject::setData(int newData) {
	someData = newData;
	notifyAll();
}

int TestSubject::getData() {
	return someData;
}




