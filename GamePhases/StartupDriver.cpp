#include <iostream>
#include <ctime>
#include "Initialization.h"
#include "Startup.h"

using namespace std;

int main() {
    srand(time(0));
    Initialization ini;
    Startup startup(ini.getPlayers(), ini.getMap());

    cout << endl << "*FINISHED PLACING ARMIES*" << endl;
    cout << "Current Map: " << endl;

    printf("%20s | %25s | %6s\n", "Player Name", "Country Name", "Armies");
    for (int i = 0; i < ini.getPlayers().size(); i++) {
        Player* currPlayer = ini.getPlayers()[i];
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
