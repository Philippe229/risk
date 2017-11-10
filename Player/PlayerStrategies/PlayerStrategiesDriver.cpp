#include <ctime>
#include "../../GamePhases/Initialization.h"
#include "../PlayerContext.h"
#include "Human.h"
#include "AggressiveBot.h"
#include "DefensiveBot.h"
#include "../../Common/Common.h"

int main() {
    srand(time(0));

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

    cout << "Aggressive Bot Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(aggressiveBot);

    cout << endl;
    PlayerContext agressive(aggressiveBot);
    cout << "Agressive Bot Reinforcing: " << endl;
    agressive.reinforce(currMap, currDeck);

    cout << "Agressive Bot Attacking: " << endl;
    agressive.attack(currMap, currDeck);

    cout << "Agressive Bot Fortifying: " << endl;
    agressive.fortify(currMap, currDeck);

    cout << "Defensive Bot Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(defensiveBot);

    cout << endl;
    PlayerContext defensive(defensiveBot);
    cout << "Defensive Bot Reinforcing: " << endl;
    defensive.reinforce(currMap, currDeck);

    cout << "Defensive Bot Attacking: " << endl;
    defensive.attack(currMap, currDeck);

    cout << "Defensive Bot Fortifying: " << endl;
    defensive.fortify(currMap, currDeck);

    cout << "Human Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(human);

    cout << endl;
    PlayerContext player(human);
    cout << "Human Reinforcing: " << endl;
    player.reinforce(currMap, currDeck);

    cout << "Human Attacking: " << endl;
    player.attack(currMap, currDeck);

    cout << "Human Fortifying: " << endl;
    player.fortify(currMap, currDeck);

    // TURN 2

    cout << "Aggressive Bot Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(aggressiveBot);
    
    cout << endl;
    cout << "Agressive Bot Reinforcing: " << endl;
    agressive.reinforce(currMap, currDeck);

    cout << "Agressive Bot Attacking: " << endl;
    agressive.attack(currMap, currDeck);

    cout << "Agressive Bot Fortifying: " << endl;
    agressive.fortify(currMap, currDeck);

    cout << "Defensive Bot Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(defensiveBot);
    
    cout << endl;
    cout << "Defensive Bot Reinforcing: " << endl;
    defensive.reinforce(currMap, currDeck);

    cout << "Defensive Bot Attacking: " << endl;
    defensive.attack(currMap, currDeck);

    cout << "Defensive Bot Fortifying: " << endl;
    defensive.fortify(currMap, currDeck);

    cout << "Human Countries and Armies: " << endl;
    Common::displayPlayersCountriesAndArmies(human);
    
    cout << endl;
    cout << "Human Reinforcing: " << endl;
    player.reinforce(currMap, currDeck);

    cout << "Human Attacking: " << endl;
    player.attack(currMap, currDeck);

    cout << "Human Fortifying: " << endl;
    player.fortify(currMap, currDeck);

    cout << "END OF DEMO" << endl;
    return 0;
}
