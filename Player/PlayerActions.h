#ifndef PLAYER_ACTIONS_H_
#define PLAYER_ACTIONS_H_

#include "../Map/Country.h"
#include "../Map/Continent.h"
#include "../CardComponents/Deck.h"

// forward declaration (circular dependency)
class Country;
class Continent;
class Deck;
class Map;

class PlayerActions {
public:
	virtual void reinforce(Map*) = 0;
	virtual void reinforce(vector<Continent*>) = 0;
	virtual void attack(Map*) = 0;
	virtual void attack(Deck* deck) = 0;
	virtual void fortify(Map*) = 0;
	virtual void fortify(Country*, Country*, int) = 0;
};

#endif