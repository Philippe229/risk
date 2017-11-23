#include <iostream>
#include "MainLoop.h"

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
	gameStatsObserver = new GameStatsObserver(this);

	// give player option to decorate observer
	gameStatsObserver = new DomDecorator(gameStatsObserver);

    playerOrder = players;
    currMap = theMap;
    currDeck = theDeck;
    turn = 1;
    isMaxTurns = false;
}

MainLoop::MainLoop(vector<Player*> players, Map* theMap, Deck* theDeck, int max) {
	gameStatsObserver = new GameStatsObserver(this);

	// TODO

    playerOrder = players;
    currMap = theMap;
    currDeck = theDeck;
    turn = 1;

    if (max > 0)
        isMaxTurns = true;
    else
        isMaxTurns = false;
}

// Play the game
void MainLoop::play() {
    Player* winner;
    Player* currPlayer;
    size_t playingIndex = 0;
    notifyAll();

    // While no one has won keep playing
    while ((winner = getWinner()) == NULL) {
        currPlayer = playerOrder[playingIndex];
//        notifyAll();
        currPlayer->reinforce(currMap, currDeck);
//        notifyAll();
        currPlayer->attack(currMap, currDeck);
//        notifyAll();
        currPlayer->fortify(currMap, currDeck);

        if (playingIndex + 1 == playerOrder.size()) {
        	turn++;
        	notifyAll();
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
        if (playingIndex % playerOrder.size() == playerOrder.size() - 1)
            turnsPerPlayer += 1;
        if (isMaxTurns) {
            if (turnsPerPlayer == maxTurns) {
                //draw
                return -1;
            }
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
