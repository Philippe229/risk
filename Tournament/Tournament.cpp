#include "Tournament.h"
#include "../GamePhases/Initialization.h"
#include "../Common/Common.h"
#include "../Player/PlayerStrategies/AggressiveBot.h"
#include "../Player/PlayerStrategies/DefensiveBot.h"
#include "../Player/PlayerStrategies/RandomBot.h"
#include "../Player/PlayerStrategies/CheaterBot.h"
#include <limits>

void Tournament::tournamentInitialization() {
	int numMaps = 0;
	int numComputers;
	numMaps = Common::getUserInputIntegerInRange(
			"Select Number of Maps for the Tournament (1 to 5): ", 1, 5);
	Initialization ini(numMaps);
	maps = ini.chooseSeveralMaps();
	numComputers = Common::getUserInputIntegerInRange(
			"Select Number of Computers(2 to 4):", 2, 4);
	setUpComputers(numComputers);
	gamesPerMap = Common::getUserInputIntegerInRange(
			"Select Number of Games per Map (1 to 5): ", 1, 5);
	turnsToDraw = Common::getUserInputIntegerInRange(
			"Select Number of Turns Before Draw (Min = 1): ", 1,
			std::numeric_limits<int>::max());
	for (auto& map : maps) {
		for(int i = 0; i < gamesPerMap; i++) {
			decks.push_back(new Deck(map->getCountries().size()));
		}
	}
}

void Tournament::setUpComputers(int numCpu) {
	int input;
	cout << "**Types of Computers**" << endl;
	cout << "1- Aggressive" << endl;
	cout << "2- Benevolant" << endl;
	cout << "3- Random" << endl;
	cout << "4- Cheater" << endl;
	for (int i = 0; i < numCpu; i++) {
		input = Common::getUserInputIntegerInRange(
				"Select Computer Type " + to_string(i + 1) + " (1 to 4):", 1,
				4);
		switch (input) {
		case 1:
			players.push_back(new AggressiveBot("Bot " + to_string(i + 1)));
			break;
		case 2:
			players.push_back(new DefensiveBot("Bot " + to_string(i + 1)));
			break;
		case 3:
			players.push_back(new RandomBot("Bot " + to_string(i + 1)));
			break;
		case 4:
			players.push_back(new CheaterBot("Bot " + to_string(i + 1)));
			break;
		default:
			cout << "Invalid computer choice" << endl;
		}
	}
}
void Tournament::startTournament() {
	Game* g;
	int gamesIterator = 0;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < gamesPerMap; j++) {
			g = new Game(cleanUpMap(maps.at(i)), players, (i + 1) * (j + 1), turnsToDraw,
					decks.at(gamesIterator));
			gamesIterator++;
			games.push_back(g);
			g->startGame();
			cout << g->getWinnerName() << endl;
		}
	}
	printReport();
}

void Tournament::printReport() {
	int gamesIterator = 0;
	cout << "TOURNAMENT RESULTS:" << endl << "      ";
	for (int j = 0; j < gamesPerMap; j++) {
		cout << "Game" + to_string(j+j);
	}
	cout << endl;
	for (int i = 0; i < maps.size(); i++) {
		cout << "Map " + to_string(i+1);
		for (int j = 0; j < gamesPerMap; j++) {
			cout << " " + games[gamesIterator]->getWinnerName() + " ";
			gamesIterator++;
		}
		cout << endl;
	}
}

Map* Tournament::cleanUpMap(Map* m) {
	for (int continentIndex = 0; continentIndex < m->getContinents().size(); continentIndex++) {
			Continent* currContinent =  m->getContinents()[continentIndex];
			vector<Country*> continentsCountries = currContinent->getCountries();

			for (int countryIndex = 0; countryIndex < continentsCountries.size(); countryIndex++) {
				Country* currCountry = continentsCountries[countryIndex];
				currCountry->setOwner(NULL);
				currCountry->setArmies(0);
			}
	}
	return m;
}
