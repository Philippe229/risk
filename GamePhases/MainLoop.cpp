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
    playerOrder = players;
    currMap = theMap;
    currDeck = theDeck;
    observer = new GameStatsObserver(this);
    turn = 1;
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

vector<Player*> MainLoop::getPlayers() {
    return playerOrder;
}

int MainLoop::getTurn() {
	return turn;
}
