#include "Game.h"
#include "../GamePhases/MainLoop.h"
#include "../GamePhases/Startup.h"
#include "../CardComponents/Deck.h"

Game::Game(Map* m, vector<Player*> p, int n, int max, Deck* d) {
	map = m;
	deck = d;
	players = p;
	gameNumber = n;
	maxTurns = max;
}

void Game::startGame() {
	Startup startup(players, map);
	MainLoop mainLoop(players, map, deck, maxTurns);
	int results = mainLoop.playSeveral();
	if (results == -1) {
		win = NULL;
	} else {
		for (auto& player : players) {
			if (player->getID() == results) {
				win = player;
			}
		}
	}

}

string Game::getWinnerName() {
	if(win == NULL)
		return "DRAW";
	else	
		return win->getName();
}
