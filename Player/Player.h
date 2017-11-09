#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "../Map/Country.h"
#include "../Map/Continent.h"
#include "../Map/Map.h"
#include "../CardComponents/Hand.h"
#include "../CardComponents/Card.h"
#include "../CardComponents/Deck.h"
#include "../DiceRollingFacility/DiceRollingFacility.h"

using namespace std;

// forward declaration (circular dependency)
class Country;
class Continent;
class Deck;
class Map;

class Player {

private:
	string name;
	int unplaced_armies;
	static int nextID;
	int id;
	vector<Country*> countries;
	vector<Country*> attackBase;
	vector<Country*> attackPossibilities;
	DiceRollingFacility* dices;
	Hand* hand;

public:
	Player();
	~Player();
	Player(string);
	Player(string, vector<Country*>);

	string getName();
	int getArmies();
	int getID();
	Hand* getHand();
	DiceRollingFacility* getDiceFacility();
	vector<Country*> getCountries();
	void addArmies(int newArmies);
	void addCountry(Country* c);
	void removeCountry(Country* c);
	void addArmiesToCountry(int, Country*);
	void removeArmiesFromCountry(int, Country*);
	void showCountries();
	vector<int> rollDie(int);

	virtual void reinforce(Map*, Deck*) = 0;
	virtual void attack(Map*, Deck*) = 0;
	virtual void fortify(Map*, Deck*) = 0;
	virtual int defensiveDice(int) = 0;
};

#endif
