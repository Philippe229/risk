#ifndef MAP_H_
#define MAP_H_

#include <string>
#include <iostream>
#include <vector>
#include "Country.h"
#include "Continent.h"

using namespace std;

class Map {

private:
	vector<Country*> countries;
	vector<Continent*> continents;

public:
	Map();
	Map(vector<Country*>);
	Map(vector<Country*>, vector<Continent*>);
	~Map();

	vector<Country*> getCountries();
	vector<Continent*> getContinents();
	void addCountry(Country*);
	void addContinent(Continent*);
};

#endif
