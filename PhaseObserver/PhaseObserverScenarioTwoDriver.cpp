#include <iostream>
#include <vector>
#include "../Player/Player.h"
#include "../Player/PlayerStrategies/AggressiveBot.h"
#include "../Player/PlayerStrategies/DefensiveBot.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"
#include "../Common/Common.h"
#include "../CardComponents/Deck.h"
#include "../GamePhases/MainLoop.h"

int main() {

	// Load map, create deck, create player, assign countries
	MapLoader loader("./Map/maps/World(small).map");
	Map* map = loader.getMap();

    Deck* deck = new Deck(map -> getCountries().size());

	Player* player1 = new AggressiveBot("Player 1");
	Player* player2 = new DefensiveBot("Player 2");
	vector<Player*> players;
	players.push_back(player1);
	players.push_back(player2);

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

	// Start game
    MainLoop mainLoop(players, map, deck);
    mainLoop.play();

	delete player1;
	delete player2;
	delete deck;

	return 0;
}


