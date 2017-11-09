#include "../../GamePhases/Initialization.h"
#include "../PlayerContext.h"
#include "Human.h"
#include "AggressiveBot.h"
#include "DefensiveBot.h"

int main() {
	Player* aggressiveBot = new AggressiveBot("Agressive Bot");
    Player* defensiveBot = new AggressiveBot("Defensive Bot");
    Player* human = new Human("Human");

    Map* currMap;
    Deck* currDeck;

    Initialization ini;
    currMap = ini.getMap();
    currDeck = ini.getDeck();

    for (int i = 0; i < currMap->getCountries().size(); i++) {
        Country* currCountry = currMap->getCountries()[i];
        currCountry->addArmies(1);

        if (i % 3 == 0) {
            currCountry->setOwner(aggressiveBot);
            aggressiveBot->addCountry(currCountry);
        } else if(i % 3 == 1){
            currCountry->setOwner(defensiveBot);
            defensiveBot->addCountry(currCountry);
        } else {
            currCountry->setOwner(human);
            human->addCountry(currCountry);
        }
    }

    // DEMO: two turns each player
    // TURN 1

    PlayerContext agressive(aggressiveBot);
    cout << "Agressive Bot Reinforcing: " << endl;
    agressive.reinforce(currMap, currDeck);

    cout << "Agressive Bot Attacking: " << endl;
    agressive.attack(currMap, currDeck);

    cout << "Agressive Bot Fortifying: " << endl;
    agressive.fortify(currMap, currDeck);

    PlayerContext defensive(defensiveBot);
    cout << "Defensive Bot Reinforcing: " << endl;
    defensive.reinforce(currMap, currDeck);

    cout << "Defensive Bot Attacking: " << endl;
    defensive.attack(currMap, currDeck);

    cout << "Defensive Bot Fortifying: " << endl;
    defensive.fortify(currMap, currDeck);

    PlayerContext player(human);
    cout << "Human Reinforcing: " << endl;
    player.reinforce(currMap, currDeck);

    cout << "Human Attacking: " << endl;
    player.attack(currMap, currDeck);

    cout << "Human Fortifying: " << endl;
    player.fortify(currMap, currDeck);

    // TURN 2

    cout << "Agressive Bot Reinforcing: " << endl;
    agressive.reinforce(currMap, currDeck);

    cout << "Agressive Bot Attacking: " << endl;
    agressive.attack(currMap, currDeck);

    cout << "Agressive Bot Fortifying: " << endl;
    agressive.fortify(currMap, currDeck);

    cout << "Defensive Bot Reinforcing: " << endl;
    defensive.reinforce(currMap, currDeck);

    cout << "Defensive Bot Attacking: " << endl;
    defensive.attack(currMap, currDeck);

    cout << "Defensive Bot Fortifying: " << endl;
    defensive.fortify(currMap, currDeck);

    cout << "Human Reinforcing: " << endl;
    player.reinforce(currMap, currDeck);

    cout << "Human Attacking: " << endl;
    player.attack(currMap, currDeck);

    cout << "Human Fortifying: " << endl;
    player.fortify(currMap, currDeck);

    cout << "END OF DEMO" << endl;
    return 0;
}
