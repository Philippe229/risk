#include "Map.h"

Map::Map() {
}

Map::Map(vector<shared_ptr<Country> > c) {
	countries = c;
}

Map::Map(vector<shared_ptr<Country> > co, vector<shared_ptr<Continent> > con) {
	countries = co;
	continents = con;
}

vector<shared_ptr<Country> > Map::getCountries() {
	return countries;
}

vector<shared_ptr<Continent> > Map::getContinents() {
	return continents;
}

void Map::addCountry(shared_ptr<Country> c) {
	countries.push_back(c);
}

void Map::addContinent(shared_ptr<Continent> c) {
	continents.push_back(c);
}