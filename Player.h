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
	string name;
	int unplaced_armies;
	vector<Country*> countries;
	DiceRollingFacility* dices;
	Hand* hand;

public:
	Player();
	~Player();
	Player(string);
	Player(string, vector<Country*>);

	string getName();
	int getArmies();
	vector<Country*> getCountries();

	void addArmies(int); // armies to be placed
	void addCountry(Country*);
	void removeCountry(Country*);
	void addArmiesToCountry(int, Country*);
	void removeArmiesFromCountry(int, Country*);

	void reinforce();
	void attack();
	void fortify();
};

#endif
