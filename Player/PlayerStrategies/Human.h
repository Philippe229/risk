#ifndef HUMAN_H_
#define HUMAN_H_

#include <string>
#include "../Player.h"
#include "../PlayerActions.h"

class Human : public Player, public PlayerActions {
public:
    Human();
    Human(string);
    void reinforce(vector<Continent*> continents);
	void attack(Deck* deck);
	void fortify(Country* sourceCountry, Country* targetCountry, int numOfArmies);
};

#endif