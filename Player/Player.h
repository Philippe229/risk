#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "../Map/Country.h"
#include "../Map/Continent.h"
#include "../CardComponents/Hand.h"
#include "../CardComponents/Card.h"
#include "../DiceRollingFacility/DiceRollingFacility.h"

using namespace std;

//forward declaration (circular dependency)
class Country;
class Continent;

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
	Hand* getHand();
	vector<Country*> getCountries();
	Country* getCountry(string name);
	void addArmies(int newArmies);
	void addCountry(Country* c);
	void removeCountry(Country* c);
	void addArmiesToCountry(int, Country*);
	void removeArmiesFromCountry(int, Country*);

	// Each player has: reinforce(), attack(), fortify() interface
	void reinforce(vector<Continent*> continents);
	void attack();
	void fortify(string sourceCountry, string targetCountry, int numOfArmies);
};

#endif
