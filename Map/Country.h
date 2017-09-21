#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <string>
#include <vector>
#include "../Player.h"

using namespace std;

class Country {

private:
	int armies;
	string country_name;
	string continent_name;
	Player owner;
	vector<shared_ptr<Country> > borderingCountries;

public:
	Country();
	Country(string);
	Country(string, string);
	Country(string, string, Player);
	Country(string, string, Player, int);
	Country(string, string, Player, int, vector<shared_ptr<Country> >);

	int getArmies();
	string getName();
	string getContinent();
	Player getOwner();

	// can only change number of armies and owner
	void addArmies(int);
	void removeArmies(int);
	void setOwner(Player);
	void addBorderingCountry(shared_ptr<Country>);
};

#endif
