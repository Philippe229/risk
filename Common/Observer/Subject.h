/*
 * Subject.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#ifndef COMMON_OBSERVER_SUBJECT_H_
#define COMMON_OBSERVER_SUBJECT_H_

#include <list>

using namespace std;

class Observer;

class Subject {

private:
	list<Observer*>* observers;

public:
	virtual void addObserver(Observer* o);
	virtual void removeObserver(Observer* o);
	virtual void notify(Observer* o);
	virtual void notifyAll();
	Subject();
	~Subject();

};

#endif /* COMMON_OBSERVER_SUBJECT_H_ */
