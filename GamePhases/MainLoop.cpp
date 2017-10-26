#include <iostream>
#include "MainLoop.h"

using namespace std;

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
}

void MainLoop::play() {
    Player* winner;
    Player* currPlayer;
    int playingIndex = 0;
    int numTurns = 0;

    while ((winner = getWinner()) == NULL) {
        currPlayer = playerOrder[playingIndex];

        currPlayer->reinforce(currMap->getContinents());
        currPlayer->attack();
        currPlayer->fortify(currPlayer->getCountries()[0]->getName(), currPlayer->getCountries()[1]->getName(), 1);

        playingIndex = (playingIndex + 1) % playerOrder.size();
        numTurns += 1;

        if (numTurns == 6) {
            for (int i = 0; i < currMap->getCountries().size(); i++) {
                currMap->getCountries()[i]->setOwner(currPlayer);
            }
        }
    }

    cout << "Winner: " << winner->getName() << endl;
}