#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <iostream>
#include <vector>
#include "Country.h"

using namespace std;

class Map {

private:
	vector<Country> countries;

public:
	Map();
	Map(vector<Country>);

	vector<Country> getCountries();
	void addCountry(Country);
};

#endif
