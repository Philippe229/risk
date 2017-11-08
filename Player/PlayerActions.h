#ifndef PLAYER_ACTIONS_H_
#define PLAYER_ACTIONS_H_

#include "../Map/Country.h"
#include "../Map/Continent.h"
#include "../CardComponents/Deck.h"

// forward declaration (circular dependency)
class Country;
class Continent;
class Deck;

class PlayerActions {
public:
    virtual void reinforce(vector<Continent*> continents) = 0;
	virtual void attack(Deck* deck) = 0;
	virtual void fortify(Country* sourceCountry, Country* targetCountry, int numOfArmies) = 0;
};

#endif