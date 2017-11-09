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
	// Edge cases
	// cout << "Invalid arguments:" << endl;
	// player1 -> fortify(player1 ->  getCountries()[3], player1 ->  getCountries()[3], 0);
	// player1 -> fortify(player1 ->  getCountries()[3], player2 -> getCountries()[14], 0);
	// player1 -> fortify(player1 ->  getCountries()[3], player2 -> getCountries()[14], 3);
	// player1 -> fortify(player1 ->  getCountries()[3], player1 ->  getCountries()[5], 3);
	// player1 -> fortify(player1 ->  getCountries()[3], player1 -> getCountries()[15], 3);

	// cout << endl << "-----------------------------------------------------------" << endl;

	// // Player 1: Western United States - Alberta - Alaska - Kamchatka - Mongolia - Siberia
	// Country* player1SourceCountry = player1 ->  getCountries()[3];
	// Country* player1TargetCountry = player1 -> getCountries()[15];

	// // Player 2: China - India
	// Country* player2SourceCountry = player2 -> getCountries()[15];
	// Country* player2TargetCountry = player2 -> getCountries()[14];

	// // Give unplaced armies to players
	// player1 -> addArmies(1);
	// player2 -> addArmies(8);

	// // Add unplaced armies to countries
	// player1 -> addArmiesToCountry(1, player1SourceCountry);
	// player2 -> addArmiesToCountry(8, player2SourceCountry);

	// // Test Player 1
	// cout << endl << "Player 1:" << endl;
	// Common::displayPlayersCountriesAndArmies(player1);

	// player1 -> fortify(player1SourceCountry, player1TargetCountry, 1);

	// cout << endl << "Player 1:" << endl;
	// Common::displayPlayersCountriesAndArmies(player1);

	// cout << endl << "-----------------------------------------------------------" << endl;

	// // Test Player 2
	// cout << endl << "Player 2:" << endl;
	// Common::displayPlayersCountriesAndArmies(player2);

	// player2 -> fortify(player2SourceCountry, player2TargetCountry, 5);

	// cout << endl << "Player 2:" << endl;
	// Common::displayPlayersCountriesAndArmies(player2);

	return 0;
}

