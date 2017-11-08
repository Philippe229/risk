#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include "../Player/Player.h"
#include "../Map/Country.h"

class Common {
public:
    static void displayPlayersCountriesAndArmies(Player* thePlayer);
    static int getUserInputInteger(string output, int min, int max);
    static string getUserInputString(string output, string choice1, string choice2);
    static void clearScreen();
};

#endif