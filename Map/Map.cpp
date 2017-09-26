#include "Map.h"
#include <iostream>
using namespace std;

Map::Map() {
}

Map::Map(vector<Country*> c) {
	countries = c;
}

Map::Map(vector<Country*> co, vector<Continent*> con) {
	countries = co;
	continents = con;
}

Map::~Map() {
	while (countries.size() > 0) {
		delete countries.back();
		countries.pop_back();
	}

	while (continents.size() > 0) {
		delete continents.back();
		continents.pop_back();
	}
}

vector<Country*> Map::getCountries() {
	return countries;
}

vector<Continent*> Map::getContinents() {
	return continents;
}

void Map::addCountry(Country* c) {
	countries.push_back(c);
}

void Map::addContinent(Continent* c) {
	continents.push_back(c);
}