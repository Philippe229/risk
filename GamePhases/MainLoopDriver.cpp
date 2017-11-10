#include <ctime>
#include "Initialization.h"
#include "Startup.h"
#include "MainLoop.h"

int main() {
    Player* human = new Human("Player 1");
    Player* h2 = new Human("Player 2");
    vector<Player*> players;
    players.push_back(human);
    players.push_back(h2);
    Map* currMap;
    Deck* currDeck;

    Initialization ini(false);
    currMap = ini.getMap();
    currDeck = ini.getDeck();

    for (int i = 0; i < currMap->getCountries().size(); i++) {
        Country* currCountry = currMap->getCountries()[i];
        currCountry->addArmies(1);

        if (i % 2 == 0) {
            currCountry->setOwner(human);
            human->addCountry(currCountry);
        } else {
            currCountry->setOwner(h2);
            h2->addCountry(currCountry);
        }
    }
    MainLoop mainLoop(players, currMap , currDeck);
    mainLoop.play();
    return 0;
}
