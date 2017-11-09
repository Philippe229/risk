#include "DefensiveBot.h"

DefensiveBot::DefensiveBot() : Player() {

}

DefensiveBot::~DefensiveBot() {

}

DefensiveBot::DefensiveBot(string n) : Player(n) {

}

int DefensiveBot::defensiveDice(int max) {
    return max;
}

void DefensiveBot::reinforce(Map* currMap, Deck* currDeck) {
    Reinforcement::staticBonusArmies = Reinforcement::getTotalBonusArmies(this, currMap->getContinents());
    int incrementBy;

    // Sort the player's countries in ascending according to the number of armies
    vector<Country*> myCountries = Player::getCountries();
    std::sort( myCountries.begin(), myCountries.end(), [ ](Country*& lhs, Country*& rhs)
    {
       return lhs->getArmies() < rhs->getArmies();
    });


    // take the difference between the (i+1)th country armies and the (i)th country armies
    // and assign that difference to every country that is less or equal to (i)
    for (int i = 0; i < myCountries.size(); i++) {

        incrementBy = myCountries[i+1]->getArmies() - myCountries[i]->getArmies();

        if ((incrementBy*(i+1)) <= Reinforcement::staticBonusArmies) {
        	for (int j = 0; j <= i; j++) {
        		Reinforcement::reinforcement(this, myCountries[j], incrementBy);
        	}
        } else {
        	for (int j = 0; j <= i; j++) {
        		Reinforcement::reinforcement(this, myCountries[j], (Reinforcement::staticBonusArmies / (i+1)));
        	}
        	break; // all the bonus armies allocated
        }
    }
}

void DefensiveBot::attack(Map* currMap, Deck* currDeck) {
	// Never attack
}

void DefensiveBot::fortify(Map* currMap, Deck* currDeck) {
	int incrementBy;

	// Sort the player's countries in ascending of number of armies
    vector<Country*> myCountries = Player::getCountries();
    std::sort( myCountries.begin(), myCountries.end(), [ ](Country*& lhs, Country*& rhs)
    {
       return lhs->getArmies() < rhs->getArmies();
    });

    int size = myCountries.size();

    incrementBy = (myCountries[size - 1]->getArmies() - myCountries[0]->getArmies()) / 2;
    Fortification::fortify(this, myCountries[size - 1], myCountries[0], incrementBy);

}
