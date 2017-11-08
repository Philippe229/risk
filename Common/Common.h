#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <stdexcept>
#include "../Player/Player.h"
#include "../Map/Country.h"

class Common {
public:
    static void displayPlayersCountriesAndArmies(Player* thePlayer);
    static int getUserInputIntegerInRange(string output, int min, int max);
    static string getUserInputStringTwoChoices(string output, string choice1, string choice2);
    static void clearScreen();
};

#endif