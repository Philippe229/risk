#include "Map.h"

Map::Map() {
}

Map::Map(vector<Country*> c) {
	countries = c;
}

Map::Map(vector<Country*> co, vector<Continent*> con) {
	countries = co;
	continents = con;
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