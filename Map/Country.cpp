#include <string>
#include <vector>
#include <iostream>
#include "Country.h"

using namespace std;

Country::Country() {
	armies = 0;
	owner = NULL;
	canAttack = false;
}

Country::Country(string country) {
	armies = 0;
	country_name = country;
	owner = NULL;
	canAttack = false;
}

Country::Country(string country, string continent) {
	armies = 0;
	country_name = country;
	continent_name = continent;
	owner = NULL;
	canAttack = false;
}

Country::Country(string country, string continent, Player* player) {
	armies = 0;
	country_name = country;
	continent_name = continent;
	owner = player;
	canAttack = false;
}

Country::Country(string country, string continent, Player* player, int army) {
	armies = army;
	country_name = country;
	continent_name = continent;
	owner = player;
	canAttack = false;
}

Country::Country(string country, string continent, Player* player, int army, vector<Country*> countries) {
	armies = army;
	country_name = country;
	continent_name = continent;
	owner = player;
	borderingCountries = countries;
	canAttack = false;
}

int Country::getArmies() {
	return armies;
}

string Country::getName() {
	return country_name;
}

string Country::getContinent() {
	return continent_name;
}

Player* Country::getOwner() {
	return owner;
}

void Country::addArmies(int army) {
	armies += army;
}

void Country::removeArmies(int army) {
	armies -= army;
}

void Country::setOwner(Player* player) {
	owner = player;
}

void Country::addBorderingCountry(Country* country) {
	borderingCountries.push_back(country);
}

vector<Country*> Country::getBorderingCountries() {
	return borderingCountries;
}

vector<Country*> Country::getBorderingEnemies() {
	return borderingEnemies;
}

void Country::updateInfo() {
	numEnemiesAround = 0;
	borderingEnemies.clear();
	for(int i = 0;i < borderingCountries.size();i++) {
		if(owner->getID() != borderingCountries.at(i)->getOwner()->getID()) {
			numEnemiesAround++;
			borderingEnemies.push_back(borderingCountries.at(i));
		}
	}
	if(numEnemiesAround > 0 && armies > 1)
		canAttack = true;
	else
		canAttack = false;
}
//always called before getBorderingEnemies
int Country::getNumEnemiesAround() {
	return numEnemiesAround;
}

bool Country::getCanAttack() {
	return canAttack;
}