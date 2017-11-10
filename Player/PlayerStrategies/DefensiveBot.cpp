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
    cout << "Bonus armies:" << Reinforcement::staticBonusArmies << endl;
    int incrementBy;

    // Sort countries in ascending according to the number of armies
    vector<Country*> myCountries = Player::getCountries();
    std::sort( myCountries.begin(), myCountries.end(), [ ](Country*& lhs, Country*& rhs)
    {
       return lhs->getArmies() < rhs->getArmies();
    });

    // take the difference between the (i+1)th country armies and the (i)th country armies
    // and assign that difference to every country that is less or equal to (i)
    for (int i = 0; i < myCountries.size() - 1; i++) {
        incrementBy = myCountries[i+1]->getArmies() - myCountries[i]->getArmies();

        if (incrementBy == 0) {
        	break;
        }

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

    // all countries have the same number of armies
    // or there is a remainder of bonus armies
    // assign 1 army to each country
    if (Reinforcement::staticBonusArmies != 0) {
    	do {
    		for(int j = 0; j < myCountries.size(); j++) {
    			if (Reinforcement::staticBonusArmies == 0) {
    				break;
    			}
    			Reinforcement::reinforcement(this, myCountries[j], 1);
    		}
    	} while (Reinforcement::staticBonusArmies != 0);
    }
    cout << "remaining armies: " << Reinforcement::staticBonusArmies << endl;
}

void DefensiveBot::attack(Map* currMap, Deck* currDeck) {
	// Never attack
}

void DefensiveBot::fortify(Map* currMap, Deck* currDeck) {
    vector<Country*> myCountries = Player::getCountries();
    Country* weakestCountry = NULL;

    // Get the weakest country (least armies)
    for (int i = 0; i < myCountries.size(); i++) {
        if (weakestCountry == NULL || myCountries[i]->getArmies() < weakestCountry->getArmies()) {
        	weakestCountry = myCountries[i];
        }
    }

    // Sort countries by number of armies
    sort(myCountries.begin(), myCountries.end(), [](Country* lhs,Country* rhs) {
        return lhs->getArmies() < rhs->getArmies();
    });

    // Try to fortify the country with the most armies with the weakest country
    for (int i = myCountries.size() - 1; i >= 0; i--) {
        if (weakestCountry != myCountries[i] && Fortification::verifyTargetCountry(this, weakestCountry, myCountries[i])) {
            Fortification::fortify(this, myCountries[i], weakestCountry, myCountries[i]->getArmies() - 1);
            break;
        }
    }
}
