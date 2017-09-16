#ifndef BORDER_H_
#define BORDER_H_

#include "Country.h"

class Border {

private:
	Country start;
	Country end;

public:
	Border();
	Border(Country, Country);

	Country getStart();
	Country getEnd();
};

#endif
