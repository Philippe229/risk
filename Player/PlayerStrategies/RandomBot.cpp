#include "RandomBot.h"

RandomBot::RandomBot() : Player() {

}

RandomBot::~RandomBot() {

}

RandomBot::RandomBot(string n) : Player(n) {

}

void RandomBot::reinforce(Map* currMap, Deck* currDeck) {
    Reinforcement::staticBonusArmies = Reinforcement::getTotalBonusArmies(this, currMap->getContinents());
    // Get a random country
    vector<Country*> myCountries = Player::getCountries();

    if (myCountries.size() > 0) {
        Country* randomCountry = myCountries[rand() % myCountries.size()];

        // Reinforce the random with all bonus armies
        Reinforcement::reinforcement(this, randomCountry, Reinforcement::staticBonusArmies);
    }
}

void RandomBot::attack(Map* currMap, Deck* currDeck) {
    int timesToAttack = rand() % 20;
    // Get a random country
    vector<Country*> myCountries = Player::getCountries();

    if (myCountries.size() > 0) {
        Country* randomCountry = myCountries[rand() % myCountries.size()];
        // Attack all bordering countries randomly and assign 1 army if take over is successful
        vector<Country*> borderingEnemies = randomCountry->getBorderingEnemies();

        while (borderingEnemies.size() > 0 && randomCountry != NULL && timesToAttack-- > 0 && randomCountry->getArmies() > 1) {
            Country* countryToAttack = borderingEnemies[rand() % borderingEnemies.size()];
            Attack::attack(currDeck, this, randomCountry, countryToAttack, min(3, randomCountry->getArmies() - 1), 1);
        }
    }
}

void RandomBot::fortify(Map* currMap, Deck* currDeck) {
    Fortification::startFortify(this);
    vector<Country*> myCountries = Player::getCountries();

    if (myCountries.size() > 0) {
        Country* randomSourceCountry = myCountries[rand() % myCountries.size()];
        Country* randomDestinationCountry = myCountries[rand() % myCountries.size()];

        int amountToMove;
        if (randomSourceCountry->getArmies() > 1) {
            amountToMove = rand() % (randomSourceCountry->getArmies() - 1);
        } else {
            amountToMove = 0;
        }

        Fortification::fortify(this, randomSourceCountry, randomDestinationCountry, amountToMove);
    }
}

int RandomBot::defensiveDice(int max) {
    return max;
}
