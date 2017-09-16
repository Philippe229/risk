#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <iostream>
#include <vector>
#include "Country.h"
#include "Border.h"

using namespace std;

class Map {

private:
	vector<Border> borders;
	vector<Country> countries;

public:
	Map();
	Map(vector<Country>, vector<Border>);

	vector<Country> getCountries();
	vector<Border> getBorders();
};

#endif
