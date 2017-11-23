#ifndef STARTUP_H_
#define STARTUP_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "../Player/Player.h"
#include "../Map/Map.h"

class Startup {
private:
    vector<Player*> playerOrder;
    Map* currMap;

    void clearScreen();
    void displayPlayersCountriesAndArmies(Player*);
    int getUserInputInteger(string, int, int);
public:
    Startup(vector<Player*>, Map*);

    void randomPlayerOrder();
    void assignCountries();
    void assignArmies();
    void assignArmiesAI();
    vector<Player*> getPlayerOrder();
};

#endif
