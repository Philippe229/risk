#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <string>
#include <vector>
#include "../Player/Player.h"

using namespace std;

//forward declaration (circular dependency)
class Player;

class Country {

private:
	int armies;
	int numEnemiesAround;
	bool canAttack;
	string country_name;
	string continent_name;
	Player* owner;
	vector<Country*> borderingCountries;
	vector<Country*> borderingEnemies;

public:
	Country();
	Country(string);
	Country(string, string);
	Country(string, string, Player*);
	Country(string, string, Player*, int);
	Country(string, string, Player*, int, vector<Country*>);

	int getArmies();
	int getNumEnemiesAround();
	void updateInfo();
	bool getCanAttack();
	string getName();
	string getContinent();
	Player* getOwner();

	// can only change number of armies and owner
	void addArmies(int);
	void removeArmies(int);
	void setOwner(Player*);
	void addBorderingCountry(Country*);
	vector<Country*> getBorderingCountries();
	vector<Country*> getBorderingEnemies();
};

#endif
