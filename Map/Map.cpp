#include "Map.h"
#include <iostream>
#include <deque>
#include <map>
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

bool Map::verifyCountriesAreConnected() {
	// Use BFS on the first node to verify that all countries are connected
	vector<Country*> connectedCountries;
	deque<Country*> countriesToLookAt;
	map<Country*, bool> visited;
	vector<Country*> allCountries = getCountries();

	for (int i = 0; i < allCountries.size(); i++) {
		visited.insert(pair<Country*, bool>(allCountries[i], false));
	}

	Country* firstCountry = allCountries[0];
	connectedCountries.push_back(firstCountry);
	countriesToLookAt.push_back(firstCountry);
	visited[firstCountry] = true;

	while (countriesToLookAt.size() > 0) {
		Country* currentCountry = countriesToLookAt.front();
		countriesToLookAt.pop_front();
		vector<Country*> currentBorderingCountries = currentCountry->getBorderingCountries();

		// Check if the bordering countries contain the current country, essentially check if it's bidirectional
		for (int i = 0; i < currentBorderingCountries.size(); i++) {
			Country* bordering = currentBorderingCountries[i];

			if (!visited[bordering]) {
				bool isConnected = false;
				vector<Country*> innerBorderingCountries = bordering->getBorderingCountries();

				for (int j = 0; j < innerBorderingCountries.size(); j++) {
					Country* innerBordering = innerBorderingCountries[j];
					if (innerBordering == currentCountry) {
						isConnected = true;
						break;
					}
				}

				if (!isConnected) {
					return false;
				} else {
					connectedCountries.push_back(bordering);
					countriesToLookAt.push_back(bordering);
					visited[bordering] = true;
				}
			}
		}
	}

	if (connectedCountries.size() != allCountries.size()) {
		return false;
	}

	return true;
}

bool Map::verifyContinentsAreConnected() {
	// Use BFS on every continent and make sure that every continent is a connected subgraph
	for (int continentIndex = 0; continentIndex < getContinents().size(); continentIndex++) {
		Continent* currContinent = getContinents()[continentIndex];

		vector<Country*> connectedCountries;
		deque<Country*> countriesToLookAt;
		map<Country*, bool> visited;
		vector<Country*> continentsCountries = currContinent->getCountries();

		for (int visitedIndex = 0; visitedIndex < continentsCountries.size(); visitedIndex++) {
			visited.insert(pair<Country*, bool>(continentsCountries[visitedIndex], false));
		}

		Country* firstCountry = continentsCountries[0];
		connectedCountries.push_back(firstCountry);
		countriesToLookAt.push_back(firstCountry);
		visited[firstCountry] = true;

		while (countriesToLookAt.size() > 0) {
			Country* currentCountry = countriesToLookAt.front();
			countriesToLookAt.pop_front();
			vector<Country*> currentBorderingCountries = currentCountry->getBorderingCountries();

			// For every bordering country which is a part of the continent check if it also points back to the current one
			for (int i = 0; i < currentBorderingCountries.size(); i++) {
				Country* bordering = currentBorderingCountries[i];
	
				if (!visited[bordering] && bordering->getContinent() == currentCountry->getContinent()) {
					bool isConnected = false;
					vector<Country*> innerBorderingCountries = bordering->getBorderingCountries();
	
					for (int j = 0; j < innerBorderingCountries.size(); j++) {
						Country* innerBordering = innerBorderingCountries[j];
						if (innerBordering == currentCountry) {
							isConnected = true;
							break;
						}
					}
	
					if (!isConnected) {
						return false;
					} else {
						connectedCountries.push_back(bordering);
						countriesToLookAt.push_back(bordering);
						visited[bordering] = true;
					}
				}
			}
		}

		if (connectedCountries.size() != continentsCountries.size()) {
			return false;
		}
	}

	return true;
}

bool Map::verifyCountriesBelongToOneContinent() {
	map<string, string> countryNames;

	for (int continentIndex = 0; continentIndex < getContinents().size(); continentIndex++) {
		Continent* currContinent = getContinents()[continentIndex];
		vector<Country*> continentsCountries = currContinent->getCountries();

		for (int countryIndex = 0; countryIndex < continentsCountries.size(); countryIndex++) {
			Country* currCountry = continentsCountries[countryIndex];

			if (countryNames.count(currCountry->getName()) > 0) {
				return false;
			} else {
				countryNames[currCountry->getName()] = currCountry->getContinent();
			}
		}
	}

	return true;
}

bool Map::isMapValid() {
	return verifyCountriesBelongToOneContinent() && verifyCountriesAreConnected() && verifyContinentsAreConnected();
}
