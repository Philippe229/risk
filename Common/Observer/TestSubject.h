/*
 * TestSubject.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#ifndef COMMON_OBSERVER_TESTSUBJECT_H_
#define COMMON_OBSERVER_TESTSUBJECT_H_

#include "Subject.h"

class TestSubject : public Subject {

private:
	int someData;

public:
	TestSubject();
	~TestSubject();
	int getData();
	void setData(int newData);

};



#endif /* COMMON_OBSERVER_TESTSUBJECT_H_ */
