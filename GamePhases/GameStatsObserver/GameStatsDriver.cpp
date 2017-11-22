/*
 * GameStatsDriver.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: Philippe
 */

#include <ctime>
#include "../Initialization.h"
#include "../Startup.h"


int main() {
	srand(time(0));
	Initialization init;
	Startup startup(init.getPlayers(), init.getMap(), true);
	Deck* deck = init.getDeck();

    cout << endl << "*FINISHED PLACING ARMIES*" << endl;
    cout << "Current Map: " << endl;

    printf("%20s | %25s | %6s\n", "Player Name", "Country Name", "Armies");
    for (int i = 0; i < init.getPlayers().size(); i++) {
        Player* currPlayer = init.getPlayers()[i];
        printf("%20s | ", currPlayer->getName().c_str());

        for (int j = 0; j < currPlayer->getCountries().size(); j++) {
            Country* currCountry = currPlayer->getCountries()[j];

            if (j == 0) {
                printf("%25s | %6i\n", currCountry->getName().c_str(), currCountry->getArmies());
            } else {
                printf("%20s | %25s | %6i\n", "", currCountry->getName().c_str(), currCountry->getArmies());
            }
        }
    }

    return 0;
}

