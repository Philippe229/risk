#include <iostream>
#include "Player.h"
#include "Map/Map.h"
#include "Map/Country.h"

using namespace std;

int main(int argc, char **argv) {

	Player *roosevelt = new Player("Teddy Roosevelt");
	Player *gandhi = new Player("Gandhi");

	vector<Country*> countries;
	countries.push_back(new Country("USA", "America", roosevelt, 10));
	countries.push_back(new Country("India", "Asia", gandhi, 20));
	countries.push_back(new Country("England", "Europe", roosevelt, 5));
	countries.push_back(new Country("China", "Asia", gandhi, 20));

	countries[0]->addBorderingCountry(countries[1]);
	countries[1]->addBorderingCountry(countries[0]);
	countries[1]->addBorderingCountry(countries[2]);
	countries[2]->addBorderingCountry(countries[1]);
	countries[2]->addBorderingCountry(countries[3]);
	countries[3]->addBorderingCountry(countries[2]);
	countries[3]->addBorderingCountry(countries[0]);
	countries[0]->addBorderingCountry(countries[3]);

	roosevelt->addCountry(countries[0]);
	roosevelt->addCountry(countries[2]);
	gandhi->addCountry(countries[1]);
	gandhi->addCountry(countries[3]);

	Map *world = new Map(countries);
	for(auto country: world->getCountries()) {
		cout << country->getOwner()->getName() << endl;
		country->getOwner()->reinforce();
		country->getOwner()->attack();
	}
	return 0;
}

