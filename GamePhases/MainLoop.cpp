#include <iostream>
#include "MainLoop.h"
#include "GameStatsObserver/Decorators/DomDecorator.h"
#include "GameStatsObserver/Decorators/HandsDecorator.h"
#include "GameStatsObserver/Decorators/ContinentsDecorator.h"
#include "../Common/Common.h"

using namespace std;

// Get the winning player, return NULL if no one has won yet
Player* MainLoop::getWinner() {
	Player* currPlayer = currMap->getCountries()[0]->getOwner();
	int currIndex = 1;

	while (currIndex < currMap->getCountries().size()) {
		if (currPlayer != currMap->getCountries()[currIndex++]->getOwner()) {
			return NULL;
		}
	}

	return currPlayer;
}

MainLoop::MainLoop(vector<Player*> players, Map* theMap, Deck* theDeck) {
	playerOrder = players;
	currMap = theMap;
	currDeck = theDeck;
	gameStatsObserver = new GameStatsObserver(this);
	turn = 1;
}

MainLoop::MainLoop(vector<Player*> players, Map* theMap, Deck* theDeck,
		int max) {
	playerOrder = players;
	currMap = theMap;
	currDeck = theDeck;
	gameStatsObserver = new GameStatsObserver(this);
	turn = 1;
	maxTurns = max;
}

// Play the game
void MainLoop::play() {
    Player* winner;
    Player* currPlayer;
    size_t playingIndex = 0;

    for (Player* p : playerOrder)
    	p->saveGameStats(new GameStatsObserver(this));

    // While no one has won keep playing
    while ((winner = getWinner()) == NULL) {
        currPlayer = playerOrder[playingIndex];

        gameStatsObserver = currPlayer->getGameStats();
        notify();

        // Choose decorators for game stats
        if (!currPlayer->getGameStats()->getLock()) {
        	GameStatsObserver* playerGameStats = currPlayer->getGameStats();

        	cout << endl << "Choose decorators:" << endl;
        	cout << "0: default, 1: domination, 2: hands, 3: continents," << endl;
        	cout << "4: domination + hands, 5: domination + continents, 6: hands + continents," << endl;
        	cout << "7: domination + hands + continents" << endl;

        	int selection = Common::getUserInputIntegerInRange("", 0, 7);

        	switch(selection) {
        	case 0:
        		playerGameStats = new GameStatsObserver(this);
        		break;
        	case 1:
        		playerGameStats = new DomDecorator(new GameStatsObserver(this));
        		break;
        	case 2:
        		playerGameStats = new HandsDecorator(new GameStatsObserver(this));
        		break;
        	case 3:
        		playerGameStats = new ContinentsDecorator(new GameStatsObserver(this));
        		break;
        	case 4:
        		playerGameStats = new HandsDecorator(new DomDecorator(new GameStatsObserver(this)));
        		break;
        	case 5:
        		playerGameStats = new ContinentsDecorator(new DomDecorator(new GameStatsObserver(this)));
        		break;
        	case 6:
        		playerGameStats = new ContinentsDecorator(new HandsDecorator(new GameStatsObserver(this)));
        		break;
        	case 7:
        		playerGameStats = new ContinentsDecorator(new HandsDecorator(new DomDecorator(new GameStatsObserver(this))));
        		break;
        	}

        	currPlayer->saveGameStats(playerGameStats);

        	char doLock;
        	cout << "Do you wish to add/remove decorators in the future? (Y/N)" << endl;
        	cin >> doLock;

        	if (toupper(doLock) == 'N') {
        		cout << "Locking game stats" << endl;
        		currPlayer->getGameStats()->lock();
        	}
        }

        currPlayer->reinforce(currMap, currDeck);
        currPlayer->attack(currMap, currDeck);
        currPlayer->fortify(currMap, currDeck);

        if (playingIndex + 1 == playerOrder.size()) {
        	turn++;
        }

        playingIndex = (playingIndex + 1) % playerOrder.size();
    }

	cout << "Winner: " << winner->getName() << endl;
}

int MainLoop::playSeveral() {
	Player* winner;
	Player* currPlayer;
	int playingIndex = 0;
	turnsPerPlayer = 0;

	// While no one has won keep playing
	while ((winner = getWinner()) == NULL) {
		currPlayer = playerOrder[playingIndex];
		notifyAll();
		currPlayer->reinforce(currMap, currDeck);
		notifyAll();
		currPlayer->attack(currMap, currDeck);
		notifyAll();
		currPlayer->fortify(currMap, currDeck);
		//increase turns after last player has played
		if (playingIndex % playerOrder.size() == playerOrder.size() - 1) {
			turnsPerPlayer += 1;
		}
		if (turnsPerPlayer == maxTurns) {
			//draw
			return -1;
		}
		playingIndex = (playingIndex + 1) % playerOrder.size();
	}

	return winner->getID();
}

vector<Player*> MainLoop::getPlayers() {
    return playerOrder;
}

int MainLoop::getTurn() {
	return turn;
}

void MainLoop::notify() {
	gameStatsObserver -> update();
}

Map* MainLoop::getMap() {
	return currMap;
}
