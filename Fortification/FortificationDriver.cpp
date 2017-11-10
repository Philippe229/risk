/*
 * FortificationDriver.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Player/PlayerStrategies/Human.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"
#include "../Common/Common.h"

using namespace std;

int main() {
	// Load map and assign countries
	MapLoader loader("./Map/maps/World(small).map");
	Map *map = loader.getMap();

	Player* player1 = new Human();
	Player* player2 = new Human("Player 2");
    Deck* currDeck;

	for (auto& country : map -> getCountries()) {

		country -> addArmies(1);

		if ((&country - &*(map -> getCountries().begin())) % 2 == 0) {
			country -> setOwner(player1);
			player1 -> addCountry(country);
		} else {
			country -> setOwner(player2);
			player2 -> addCountry(country);
		}
	}
	player1 ->fortify(map, currDeck);

	return 0;
}

