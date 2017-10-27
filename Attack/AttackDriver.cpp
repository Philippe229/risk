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

		vector<Country*> c1 = one->getCountries();
		vector<Country*> c2 = two->getCountries();
		one->addArmies(10);
		one->addArmiesToCountry(3, c1.at(3));
		one->addArmiesToCountry(7, c1.at(9));
        int numToAdd = c2.size();
        two->addArmies(numToAdd*3);
        for(int i = 0; i < numToAdd;i++)
        {
            two->addArmiesToCountry(3, c2.at(i));
        }
		one->attack();


	} catch (invalid_argument e) {
		cout << e.what() << endl;
	 }

	return 0;
}

