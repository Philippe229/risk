#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Country {

private:
	int armies;
	string country_name;
	string continent_name;
	Player owner;

public:
	Country();
	Country(string);
	Country(string, string);
	Country(string, string, Player);
	Country(string, string, Player, int);

	int getArmies();
	string getName();
	string getContinent();
	Player getOwner();

	// can only change number of armies and owner
	void addArmies(int);
	void removeArmies(int);
	void setOwner(Player);
};

#endif
