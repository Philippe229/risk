#include "AggressiveBot.h"

AggressiveBot::AggressiveBot() : Player() {

}

AggressiveBot::AggressiveBot(string n) : Player(n) {

}

void AggressiveBot::reinforce(Map* currMap, Deck* currDeck) {
    Reinforcement::staticBonusArmies = Reinforcement::getTotalBonusArmies(this, currMap->getContinents());

    // Get the strongest country (most armies)
    vector<Country*> myCountries = Player::getCountries();
    Country* strongestCountry = NULL;

    for (int i = 0; i < myCountries.size(); i++) {
        if (strongestCountry == NULL || myCountries[i]->getArmies() > strongestCountry->getArmies()) {
            strongestCountry = myCountries[i];
        }
    }

    // Reinforce the strongest country with all bonus armies
    Reinforcement::reinforcement(this, strongestCountry, Reinforcement::staticBonusArmies);
}

void AggressiveBot::attack(Map* currMap, Deck* currDeck) {
    // Get the strongest country (most armies)
    vector<Country*> myCountries = Player::getCountries();
    Country* strongestCountry = NULL;

    for (int i = 0; i < myCountries.size(); i++) {
        if (strongestCountry == NULL || myCountries[i]->getArmies() > strongestCountry->getArmies()) {
            strongestCountry = myCountries[i];
        }
    }

    // Attack all bordering enemies and assign 1 army if take over is successful
    vector<Country*> borderingEnemies = strongestCountry->getBorderingEnemies();
    for (int i = 0; i < borderingEnemies.size() && strongestCountry->getArmies() > 1; i++) {
        while (strongestCountry->getArmies() > 1 && borderingEnemies[i]->getOwner() != this) {
            Attack::attack(currDeck, this, strongestCountry, borderingEnemies[i], min(3, strongestCountry->getArmies() - 1), 1);
        }
    }
}

void AggressiveBot::fortify(Map* currMap, Deck* currDeck) {
    // Get the country with the most bordering enemies
    vector<Country*> myCountries = Player::getCountries();
    Country* mostSurroundedCountry = NULL;

    for (int i = 0; i < myCountries.size(); i++) {
        if (mostSurroundedCountry == NULL || myCountries[i]->getNumEnemiesAround() > mostSurroundedCountry->getNumEnemiesAround()) {
            mostSurroundedCountry = myCountries[i];
        }
    }

    // Try to fortify the country with the most bordering enemies with every other country
    for (int i = 0; i < myCountries.size(); i++) {
        if (myCountries[i] != mostSurroundedCountry) {
            Fortification::fortify(this, myCountries[i], mostSurroundedCountry, myCountries[i]->getArmies() - 1);
        }
    }
}

int AggressiveBot::defensiveDice(int max) {
    return max;
}