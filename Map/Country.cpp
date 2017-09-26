#include <string>
#include <vector>
#include <iostream>
#include "Country.h"

using namespace std;

Country::Country() {
	armies = 0;
}

Country::Country(string country) {
	armies = 0;
	country_name = country;
}

Country::Country(string country, string continent) {
	armies = 0;
	country_name = country;
	continent_name = continent;
}

Country::Country(string country, string continent, Player* player) {
	armies = 0;
	country_name = country;
	continent_name = continent;
	owner = player;
}

Country::Country(string country, string continent, Player* player, int army) {
	armies = army;
	country_name = country;
	continent_name = continent;
	owner = player;
}

Country::Country(string country, string continent, Player* player, int army, vector<Country*> countries) {
	armies = army;
	country_name = country;
	continent_name = continent;
	owner = player;
	borderingCountries = countries;
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
