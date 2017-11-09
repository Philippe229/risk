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

    // Sort the player's country in ascending number of armies
    vector<Country*> myCountries = Player::getCountries();
    std::sort( myCountries.begin(), myCountries.end(), [ ]( const auto& lhs, const auto& rhs )
    {
       return lhs->getArmies() < rhs->getArmies();
    });


    for (int i = 0; i < myCountries.size(); i++) {

        incrementBy = myCountries[i+1]->getArmies() - myCountries[i]->getArmies();

        if ((incrementBy*i) <= Reinforcement::staticBonusArmies) {
        	for (int j = 0; j < i; j++) {
        		Reinforcement::reinforcement(this, myCountries[j], incrementBy);
        	}
        } else {
        	for (int j = 0; j < i; j++) {
        		Reinforcement::reinforcement(this, myCountries[j], (Reinforcement::staticBonusArmies / i));
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

	// Sort the player's countries in ascending number of armies
    vector<Country*> myCountries = Player::getCountries();
    std::sort( myCountries.begin(), myCountries.end(), [ ]( const auto& lhs, const auto& rhs )
    {
       return lhs->getArmies() < rhs->getArmies();
    });

    int size = myCountries.size();

    incrementBy = (myCountries[size - 1]->getArmies() - myCountries[0]->getArmies()) / 2;
    Fortification::fortify(this, myCountries[size - 1], myCountries[0], incrementBy);

}
