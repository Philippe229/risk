#include "Map.h"

Map::Map() {
}

Map::Map(vector<Country> c) {
	countries = c;
}

vector<Country> Map::getCountries() {
	return countries;
}
