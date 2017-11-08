#include "../../GamePhases/Initialization.h"
#include "../PlayerContext.h"
#include "Human.h"
#include "AggressiveBot.h"

int main() {
    Player* human = new Human("Player 1");
    Player* aggressiveBot = new AggressiveBot("Player 2");

    Map* currMap;
    Deck* currDeck;

    Initialization ini;
    currMap = ini.getMap();
    currDeck = ini.getDeck();

    for (int i = 0; i < currMap->getCountries().size(); i++) {
        Country* currCountry = currMap->getCountries()[i];
        currCountry->addArmies(1);

        if (i % 2 == 0) {
            currCountry->setOwner(human);
            human->addCountry(currCountry);
        } else {
            currCountry->setOwner(aggressiveBot);
            aggressiveBot->addCountry(currCountry);
        }
    }

    PlayerContext playerContext(human);
    cout << "Human Player Reinforcing: " << endl;
    playerContext.reinforce(currMap, currDeck);

    cout << "Human Player Attacking: " << endl;
    playerContext.attack(currMap, currDeck);

    cout << "Human Player Fortifying: " << endl;
    playerContext.fortify(currMap, currDeck);

    return 0;
}