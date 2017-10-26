#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Attack.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"

using namespace std;

int main(int argc, char **argv) {

	srand(time(0));

	try {
		MapLoader loader("./Map/maps/World(small).map");
		Map *map = loader.getMap();
		Player* one = new Player("one");
		Player* two = new Player("two");

		for (auto& country : map->getCountries()) {
			country->addArmies(1); // each country start with one army
			if ((&country - &*(map->getCountries().begin())) % 2 == 0) {
				country->setOwner(one);
				one->addCountry(country);
			} else {
				country->setOwner(two);
				two->addCountry(country);
			}
		}

		vector<Country*> c = one->getCountries();
		one->addArmies(3);
		one->addArmiesToCountry(3, c.at(3));
		one->attack();


	} catch (invalid_argument e) {
		cout << e.what() << endl;
	 }

	return 0;
}

