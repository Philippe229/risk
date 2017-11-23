#include "CheaterBot.h"

CheaterBot::CheaterBot() : Player() {

}

CheaterBot::~CheaterBot() {

}

CheaterBot::CheaterBot(string n) : Player(n) {

}

void CheaterBot::reinforce(Map* currMap, Deck* currDeck) {
    // Double all armies
    vector<Country*> myCountries = Player::getCountries();
   
    for (int i = 0; i < myCountries.size(); i++) {
        string message = "Reinforcing " + myCountries[i]->getName() + " with " + to_string(myCountries[i]->getArmies()) + " armies....";
        Reinforcement::notifyObserver(myCountries[i]->getOwner(), message);
        myCountries[i]->addArmies(myCountries[i]->getArmies());
    }
}

void CheaterBot::attack(Map* currMap, Deck* currDeck) {
    // Attack all neighbouring countries
    vector<Country*> myCountries = Player::getCountries();
    
    for (int j = 0; j < myCountries.size(); j++) {
        Country* currCountry = myCountries[j];

        // Attack all bordering enemies and win automatically
        vector<Country*> borderingEnemies = currCountry->getBorderingEnemies();
        for (int i = 0; i < borderingEnemies.size() && currCountry->getArmies() > 1; i++) {
            string message = "Attacking " + borderingEnemies[i]->getName() + "'s " +
                to_string(borderingEnemies[i]->getArmies()) + " armies (owned by " + borderingEnemies[i]->getOwner()->getName() + ") with " +
                currCountry->getName() + "'s " + to_string(currCountry->getArmies()) + " armies.";
            Attack::notifyObserver(currCountry->getOwner(), message);

            currCountry->removeArmies(1);
            borderingEnemies[i]->removeArmies(borderingEnemies[i]->getArmies() - 1);
            borderingEnemies[i]->getOwner()->removeCountry(borderingEnemies[i]);
            borderingEnemies[i]->setOwner(currCountry->getOwner());
            currCountry->getOwner()->addCountry(borderingEnemies[i]);
            cout << currCountry->getOwner()->getName() << " captured new country " << borderingEnemies[i]->getName() << endl;
        }
    }
}

void CheaterBot::fortify(Map* currMap, Deck* currDeck) {
    Fortification::startFortify(this);
    vector<Country*> myCountries = Player::getCountries();

    // Go through all countries and double the armies if they have surrounding enemies
    for (int i = 0; i < myCountries.size(); i++) {
        Country* currCountry = myCountries[i];

        // If we have bordering enemies then double the amount of armies
        vector<Country*> borderingEnemies = currCountry->getBorderingEnemies();
        if (borderingEnemies.size() > 0) {
            string message = "Fortifying " + currCountry->getName() + "'s " +
                to_string(currCountry->getArmies()) + " army/armies by doubling it.";
            Fortification::notifyObserver(currCountry->getOwner(), message);
            
            currCountry->addArmies(currCountry->getArmies());
        }
    }
}

int CheaterBot::defensiveDice(int max) {
    return max;
}
