#include "AggressiveBot.h"

AggressiveBot::AggressiveBot() {
    Player();
}

AggressiveBot::AggressiveBot(string n) : Player(n) {

}

void AggressiveBot::reinforce(Map* currMap) {
    Reinforcement::staticBonusArmies = Reinforcement::getTotalBonusArmies(this, currMap->getContinents());

    vector<Country*> myCountries = Player::getCountries();
    Country* strongestCountry = NULL;

    for (int i = 0; i < myCountries.size(); i++) {
        if (strongestCountry == NULL || myCountries[i]->getArmies() > strongestCountry->getArmies()) {
            strongestCountry = myCountries[i];
        }
    }

    Reinforcement::reinforcement(this, strongestCountry, Reinforcement::staticBonusArmies);
}

void AggressiveBot::attack(Map*) {
    
}

void AggressiveBot::fortify(Map*) {
    vector<Country*> myCountries = Player::getCountries();
    Country* strongestCountry = NULL;

    for (int i = 0; i < myCountries.size(); i++) {
        if (strongestCountry == NULL || myCountries[i]->getArmies() > strongestCountry->getArmies()) {
            strongestCountry = myCountries[i];
        }
    }

    for (int i = 0; i < myCountries.size(); i++) {
        if (myCountries[i] != strongestCountry) {
            Fortification::fortify(this, myCountries[i], strongestCountry, myCountries[i]->getArmies() - 1);
        }
    }
}