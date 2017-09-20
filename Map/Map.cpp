#include "Map.h"

Map::Map() {
}

Map::Map(vector<Country> c) {
	countries = c;
}

vector<Country> Map::getCountries() {
	return countries;
}

void Map::addCountry(Country c) {
	countries.push_back(c);
}
