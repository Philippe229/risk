#ifndef TOURNAMENT_TOURNAMENT_H_
#define TOURNAMENT_TOURNAMENT_H_

#include <string>
#include <iostream>
#include <vector>
#include "Game.h"
#include "../Player/PlayerContext.h"
#include "../Map/Map.h"
#include "../CardComponents/Deck.h"

class Map;
class Player;
class Tournament {

private:
	vector<Map*> maps;
	vector<Player*> players;
	int gamesPerMap;
	int turnsToDraw;
	vector<Game*> games;
	vector<Deck*> decks;
	void setUpComputers(int);
	Map* cleanUpMap(Map*);
	vector<Player*> cleanUpPlayers(vector<Player*>);

public:
	void tournamentInitialization();
	void startTournament();
	void printReport();
};

#endif
