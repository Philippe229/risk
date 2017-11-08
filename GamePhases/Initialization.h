#ifndef INITIALIZATION_H_
#define INITIALIZATION_H_

#include <iostream>
#include <limits>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <stdexcept>
#include "../Player/Player.h"
#include "../Player/PlayerStrategies/Human.h"
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
    string getUserInputString(string, string, string);
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
