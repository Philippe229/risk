#include <iostream>
#include <vector>

#include "../Player/Player.h"
#include "../MapLoader/MapLoader.h"

using namespace std;

int main() {
	// Proper Map format
	try {
		MapLoader loader("./Map/maps/World(small).map");
		Map* currentMap = loader.getMap();

		if (currentMap->isMapValid()) {
			cout << "The map is completely connected, and the continents are subgraphs." << endl;
		} else {
			if (!currentMap->verifyContinentsAreConnected()) {
				cout << "Some of the continents are not subgraphs, verify that every continent is connected." << endl;
			} else if(!currentMap->verifyCountriesBelongToOneContinent()) {
				cout << "Some continents owns a country which does not belong to it" << endl;
			} else {
				cout << "Some of the countries are not connected, this means the map is disjoint when it should not be." << endl;
			}
		}
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	// Not all countries are connected
	try {
		MapLoader loader("./Map/maps/countries-unconnected.map");
		Map* currentMap = loader.getMap();
		
		if (currentMap->isMapValid()) {
			cout << "The map is completely connected, and the continents are subgraphs." << endl;
		} else {
			if (!currentMap->verifyContinentsAreConnected()) {
				cout << "Some of the continents are not subgraphs, verify that every continent is connected." << endl;
			} else if(!currentMap->verifyCountriesBelongToOneContinent()) {
				cout << "Some continents owns a country which does not belong to it" << endl;
			} else {
				cout << "Some of the countries are not connected, this means the map is disjoint when it should not be." << endl;
			}
		}
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	// Not all continents are connected
	try {
		MapLoader loader("./Map/maps/continents-unconnected.map");
		Map* currentMap = loader.getMap();
		
		if (currentMap->isMapValid()) {
			cout << "The map is completely connected, and the continents are subgraphs." << endl;
		} else {
			if (!currentMap->verifyContinentsAreConnected()) {
				cout << "Some of the continents are not subgraphs, verify that every continent is connected." << endl;
			} else if(!currentMap->verifyCountriesBelongToOneContinent()) {
				cout << "Some continents owns a country which does not belong to it" << endl;
			} else {
				cout << "Some of the countries are not connected, this means the map is disjoint when it should not be." << endl;
			}
		}
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	
    return 0;
}
