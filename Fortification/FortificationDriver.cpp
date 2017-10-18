/*
 * FortificationDriver.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"
#include "Fortification.h"

using namespace std;

int main() {
	// Load map and assign countries
	MapLoader loader("./Map/maps/World(small).map");
	Map *map = loader.getMap();

	Player* player1 = new Player("Player 1");
	Player* player2 = new Player("Player 2");

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

	cout << "Invalid arguments:" << endl;
	Fortification::fortify(NULL, "", "", 0);
	Fortification::fortify(player1, "Western United States", "Western United States", 0);
	Fortification::fortify(player1, "Western United States", "India", 0);
	Fortification::fortify(player1, "Western United States", "India", 3);
	Fortification::fortify(player1, "Western United States", "Peru", 3);
	Fortification::fortify(player1, "Western United States", "Siberia", 3);

	// Give unplaced armies to players
	player1 -> addArmies(1);
	player2 -> addArmies(8);

	// Add unplaced armies to countries
	player1 -> addArmiesToCountry(1, player1 -> getCountry("Western United States"));
	player2 -> addArmiesToCountry(8, player2 -> getCountry("China"));

	// Player 1: Western United States - Alberta - Alaska - Kamchatka - Mongolia - Siberia
	// Player 2: China - India
	Country* player1SourceCountry = player1 -> getCountry("Western United States");
	Country* player1TargetCountry = player1 -> getCountry("Siberia");
	Country* player2SourceCountry = player2 -> getCountry("China");
	Country* player2TargetCountry = player2 -> getCountry("India");

	// Test Player 1
	cout << "\nPlayer 1:" << endl;
	cout << "\tSource Country: " + player1SourceCountry -> getName() +
			" - Troops: " + to_string(player1SourceCountry -> getArmies()) << endl;
	cout << "\tTarget Country: " + player1TargetCountry -> getName() +
			" - Troops: " + to_string(player1TargetCountry -> getArmies()) << endl << endl;

	Fortification::fortify(player1, "Western United States", "Siberia", 1);

	cout << "\nPlayer 1:" << endl;
	cout << "\tSource Country: " + player1SourceCountry -> getName() +
			" - Troops: " + to_string(player1SourceCountry -> getArmies()) << endl;
	cout << "\tTarget Country: " + player1TargetCountry -> getName() +
			" - Troops: " + to_string(player1TargetCountry -> getArmies()) << endl;

	cout << endl << "-----------------------------------------------------------" << endl;

	// Test Player 2
	cout << "\nPlayer 2:" << endl;
	cout << "\tSource Country: " + player2SourceCountry -> getName() +
			" - Troops: " + to_string(player2SourceCountry -> getArmies()) << endl;
	cout << "\tTarget Country: " + player2TargetCountry -> getName() +
			" - Troops: " + to_string(player2TargetCountry -> getArmies()) << endl << endl;

	Fortification::fortify(player2, "China", "India", 5);

	cout << "\nPlayer 2:" << endl;
	cout << "\tSource Country: " + player2SourceCountry -> getName() +
			" - Troops: " + to_string(player2SourceCountry -> getArmies()) << endl;
	cout << "\tTarget Country: " + player2TargetCountry -> getName() +
			" - Troops: " + to_string(player2TargetCountry -> getArmies()) << endl;

	return 0;
}

