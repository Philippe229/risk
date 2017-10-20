#ifndef INITIALIZATION_H_
#define INITIALIZATION_H_

#include <vector>
#include "../Player/Player.h"
#include "../MapLoader/MapLoader.h"
#include "../CardComponents/Deck.h"

using namespace std;

class Initialization {
private:
    const string mapDirectory = "./Map/maps/";

    MapLoader* loadedMap;
    vector<Player*> gamePlayers;
    Deck* currentDeck;

    void clearScreen();
    int getUserInputInteger(string, int, int);
    vector<string> getAndDisplayMapOptions();

    void chooseMap();
    void createPlayers();
public:
    Initialization();
    Deck* getDeck();
    vector<Player*> getPlayers();
    Map* getMap();
};

#endif