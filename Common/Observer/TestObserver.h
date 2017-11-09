/*
 * TestObserver.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#ifndef COMMON_OBSERVER_TESTOBSERVER_H_
#define COMMON_OBSERVER_TESTOBSERVER_H_

#include "Observer.h"
#include "TestSubject.h"

class TestObserver : public Observer {

private:
	TestSubject* testSubject;

public:
	TestObserver();
	TestObserver(TestSubject* ts);
	~TestObserver();
	void update();
	void display();
};



#endif /* COMMON_OBSERVER_TESTOBSERVER_H_ */
