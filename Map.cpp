#include "Map.h"

Map::Map() {

}

Map::Map(vector<Country> c, vector<Border> b) {
	countries = c;
	borders = b;
}

vector<Country> Map::getCountries() {
	return countries;
}

vector<Border> Map::getBorders() {
	return borders;
}
