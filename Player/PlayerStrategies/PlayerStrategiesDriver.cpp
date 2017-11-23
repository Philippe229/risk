#include <ctime>
#include "../../GamePhases/Initialization.h"
#include "../PlayerContext.h"
#include "AggressiveBot.h"
#include "DefensiveBot.h"
#include "RandomBot.h"
#include "CheaterBot.h"
#include "../../Common/Common.h"

int main() {
    srand(time(0));

    Player* bots[4];
    for (int i = 0; i < 4; i++) {
        if (i % 4 == 0 ){
            bots[i] = new AggressiveBot("Agressive Bot");
        } else if (i % 4 == 1) {
            bots[i] = new DefensiveBot("Defensive Bot");
        } else if (i % 4 == 2) {
            bots[i] = new RandomBot("Random Bot");
        } else {
            bots[i] = new CheaterBot("Cheater Bot");
        }
    }

    Map* currMap;
    Deck* currDeck;

    Initialization ini;
    currMap = ini.getMap();
    currDeck = ini.getDeck();

    for (int i = 0; i < currMap->getCountries().size(); i++) {
        Country* currCountry = currMap->getCountries()[i];
        currCountry->addArmies(1);

        if (i % 4 == 0) {
            currCountry->setOwner(bots[0]);
            bots[0]->addCountry(currCountry);
        } else if (i % 4 == 1) {
            currCountry->setOwner(bots[1]);
            bots[1]->addCountry(currCountry);
        } else if (i % 4 == 2) {
            currCountry->setOwner(bots[2]);
            bots[2]->addCountry(currCountry);
        } else if (i % 4 == 3) {
            currCountry->setOwner(bots[3]);
            bots[3]->addCountry(currCountry);
        }
    }

    // DEMO: two turns each player
    for (int i = 0; i < 4 * 4; i++) {
        cout << bots[i % 4]->getName() << " Countries and Armies: " << endl;
        Common::displayPlayersCountriesAndArmies(bots[i % 4]);

        cout << endl;
        PlayerContext currBot(bots[i % 4]);

        cout << bots[i % 4]->getName() << " Reinforcing: " << endl;
        currBot.reinforce(currMap, currDeck);
    
        cout << bots[i % 4]->getName() << " Attacking: " << endl;
        currBot.attack(currMap, currDeck);
    
        cout << bots[i % 4]->getName() << " Fortifying: " << endl;
        currBot.fortify(currMap, currDeck);
    }

    cout << "END OF DEMO" << endl;
    return 0;
}
