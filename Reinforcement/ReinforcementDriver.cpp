#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Player/Player.h"
#include "../CardComponents/Deck.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"
#include "Reinforcement.h"

using namespace std;

int main() {
	cout << "case: PLAYER 1 OWNS ALL COUNTRIES" << endl;

	// Load map and assign countries
	MapLoader loader("./Map/maps/World(small).map");
	Map *map = loader.getMap();

	Player* player1 = new Player("Player 1");

	// Assign countries to player
	for (auto& country : map->getCountries()) {
		country->setOwner(player1);
		player1->addCountry(country);
	}

	// Assign cards to player
	Deck deck = Deck(42);
	for (int i = 0; i < 5; i++) {
		player1->getHand()->getCard(deck.Draw());
	}

	cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
	Reinforcement::reinforcement(player1, map->getContinents());
	cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";

	cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
	Reinforcement::reinforcement(player1, map->getContinents());
	cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";

	return 0;
}
