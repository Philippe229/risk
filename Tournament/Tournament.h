#ifndef TOURNAMENT_TOURNAMENT_H_
#define TOURNAMENT_TOURNAMENT_H_

#include <string>
#include <iostream>
#include <vector>
#include "Game.h"
#include "../Player/PlayerContext.h"
#include "../Map/Map.h"

class Tournament {

private:
	vector<Map*> maps;
	vector<Player*> players;
	int gamesPerMap;
	int gamesToDraw;
	vector<Game*> games;

public:
	void tournamentInitialization();
	void startTournament();
	void printReport();
};

#endif
