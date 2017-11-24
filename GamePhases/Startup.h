#ifndef STARTUP_H_
#define STARTUP_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/Country.h"

class Startup {
private:
    vector<Player*> playerOrder;
    Map* currMap;

    void clearScreen();
    void displayPlayersCountriesAndArmies(Player*);
    int getUserInputInteger(string, int, int);
public:
    Startup(vector<Player*>, Map*);
    Startup(vector<Player*> players, Map* map, bool quickStart);
    void randomPlayerOrder();
    void assignCountries();
    void assignArmies();
    vector<Player*> getPlayerOrder();
};

#endif
