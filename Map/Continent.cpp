#include "Continent.h"

Continent::Continent(int w) {
    worth = w;
}

Continent::Continent(int w, string n) {
    worth = w;
    name = n;
}

Continent::Continent(int w, string n, vector<Country*> cs) {
    worth = w;
    name = n;
    countries = cs;
}

void Continent::addCountry(Country* c) {
    countries.push_back(c);
}

vector<Country*> Continent::getCountries() {
    return countries;
}

string Continent::getName() {
    return name;
}

int Continent::getWorth() {
    return worth;
}

string Continent::getOwner() {
	vector<Player*> countryOwners;

	for (Country* c : countries)
		countryOwners.push_back(c->getOwner());

	if (equal(countryOwners.begin() + 1, countryOwners.end(), countryOwners.begin()))
		return countryOwners.front() -> getName();
	else
		return "Contested";
}
