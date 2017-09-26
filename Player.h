#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Map/Country.h"
#include "CardComponents/Hand.h"
#include "DiceRollingFacility/DiceRollingFacility.h"

using namespace std;

//forward declaration (circular dependency)
class Country;

class Player {

private:
	string player_name;
	vector<Country*> countries;
	DiceRollingFacility* dices;
	Hand* hand;

public:
	Player();
	~Player();
	Player(string);
	Player(string, vector<Country*>);

	string getName();
	vector<Country*> getCountries();
	Hand* getHand();
	void addCountry(Country*);
	void setHand(Hand*);

	void reinforce();
	void attack();
	void fortify();

};

#endif
