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
	vector<shared_ptr<Country> > countries;
	vector<shared_ptr<Continent> > continents;

public:
	Map();
	Map(vector<shared_ptr<Country> >);
	Map(vector<shared_ptr<Country> >, vector<shared_ptr<Continent> >);

	vector<shared_ptr<Country> > getCountries();
	vector<shared_ptr<Continent> > getContinents();
	void addCountry(shared_ptr<Country>);
	void addContinent(shared_ptr<Continent>);
};

#endif
