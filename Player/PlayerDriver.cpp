#include <iostream>
#include "Player.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"
#include "../Map/Country.h"

using namespace std;

int main(int argc, char **argv) {

	try {
		cout << "loading map using map loader..." << endl;
		MapLoader loader("./Map/maps/World(small).map");
		Map *map = loader.getMap();

		cout << "creating two players..." << endl;
		Player* one = new Player("one");
		Player* two = new Player("two");

		cout << "assigning countries to players..." << endl;
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

		cout << "\n1. each player owns a collection of countries;" << endl;
		cout
				<< "player one has: " + to_string(one->getCountries().size())
						+ " countries" << endl;
		cout
				<< "player two has: " + to_string(two->getCountries().size())
						+ " countries" << endl;

		cout << "\n2. each player owns a collection of Risk cards;" << endl;
		one->showCards();
		two->showCards();

		cout << "\n3. each player has their own dice facility;" << endl;
		one->rollDie();
		two->rollDie();

	} catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	return 0;
}

