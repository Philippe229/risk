/*
 * Observer.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Philippe
 */

#ifndef COMMON_OBSERVER_OBSERVER_H_
#define COMMON_OBSERVER_OBSERVER_H_

class Observer {

private:

public:
	Observer();
	~Observer();
	virtual void update() = 0;
};



#endif /* COMMON_OBSERVER_OBSERVER_H_ */
