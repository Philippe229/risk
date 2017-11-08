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
		cout << "The map is completely connected, and the continents are subgraphs." << endl;
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	// Not all countries are connected
	try {
		MapLoader loader("./Map/maps/countries-unconnected.map");
		Map* currentMap = loader.getMap();
		cout << "The map is completely connected, and the continents are subgraphs." << endl;
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	// Not all continents are connected
	try {
		MapLoader loader("./Map/maps/continents-unconnected.map");
		Map* currentMap = loader.getMap();
		cout << "The map is completely connected, and the continents are subgraphs." << endl;
	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

    return 0;
}
