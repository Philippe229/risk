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
#include "Reinforcement.h"

using namespace std;

int main() {
	{
		cout << "case: PLAYER 1 OWNS ALL COUNTRIES" << endl;
		// Load map and assign countries
		MapLoader loader("./Map/maps/World(small).map");
		Map *map = loader.getMap();

		Player* player1 = new Player("Player 1");

		for (auto& country : map->getCountries()) {
			country->addArmies(1);
			country->setOwner(player1);
			player1->addCountry(country);
		}

		cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
		Reinforcement::reinforcement(player1, map);
		cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";

		cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
		Reinforcement::reinforcement(player1, map);
		cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";
	}

	{
		cout << "case: PLAYER 1 & PLAYER 2 OWN 50-50 COUNTRIES" << endl;
		// Load map and assign countries
		MapLoader loader("./Map/maps/World(small).map");
		Map *map = loader.getMap();

		Player* player1 = new Player("Player 1");
		Player* player2 = new Player("Player 2");

		for (auto& country : map->getCountries()) {
			country->addArmies(1); // each country start with one army
			if ((&country - &*(map->getCountries().begin())) % 2 == 0) {
				country->setOwner(player1);
				player1->addCountry(country);
			} else {
				country->setOwner(player2);
				player2->addCountry(country);
			}
		}

		cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
		Reinforcement::reinforcement(player1, map);
		cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";

		cout << "\nPlayer 2 REINFORCEMENT'S PHASE BEGINS\n";
		Reinforcement::reinforcement(player2, map);
		cout << "\nPlayer 2 REINFORCEMENT'S PHASE ENDED\n";
	}

	return 0;
}
