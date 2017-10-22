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
	{
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

		cout << "Player 1 REINFORCEMENT'S PHASE BEGINS\n";
		player1->reinforce(map->getContinents());
		cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";

		cout << "\nPlayer 1 REINFORCEMENT'S PHASE BEGINS\n";
		player1->reinforce(map->getContinents());
		cout << "\nPlayer 1 REINFORCEMENT'S PHASE ENDED\n";
	}
	cout << "\n\n\n\n\nGAME 2" << endl;

	{
		// Load map and assign countries
		MapLoader loader2("./Map/maps/Mediterranean.map");
		Map *map2 = loader2.getMap();

		Player* player2 = new Player("Player 2");
		Player* player3 = new Player("Player 3");

		// Assign countries to playerS
		for (auto& country : map2->getCountries()) {
			if ((&country - &*(map2->getCountries().begin())) % 2 == 0) {
				country->setOwner(player2);
				player2->addCountry(country);
			} else {
				country->setOwner(player3);
				player3->addCountry(country);
			}
		}

		// Assign cards to player
		Deck deck = Deck(42);
		for (int i = 0; i < 5; i++) {
			player2->getHand()->getCard(deck.Draw());
			player3->getHand()->getCard(deck.Draw());
		}

		cout << "\nPlayer 2 REINFORCEMENT'S PHASE BEGINS\n";
		player2->reinforce(map2->getContinents());
		cout << "\nPlayer 2 REINFORCEMENT'S PHASE ENDED\n";

		cout << "Player 3 REINFORCEMENT'S PHASE BEGINS\n";
		player3->reinforce(map2->getContinents());
		cout << "\nPlayer 3 REINFORCEMENT'S PHASE ENDED\n";

		cout << "DRAWING 2 CARDS" << endl;
		for (int i = 0; i < 2; i++) {
			player2->getHand()->getCard(deck.Draw());
			player3->getHand()->getCard(deck.Draw());
		}

		cout << "\nPlayer 2 REINFORCEMENT'S PHASE BEGINS\n";
		player2->reinforce(map2->getContinents());
		cout << "\nPlayer 2 REINFORCEMENT'S PHASE ENDED\n";

		cout << "Player 3 REINFORCEMENT'S PHASE BEGINS\n";
		player3->reinforce(map2->getContinents());
		cout << "\nPlayer 3 REINFORCEMENT'S PHASE ENDED\n";
	}
	return 0;
}
