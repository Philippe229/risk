#include <iostream>
#include "Player.h"
#include "Map/Map.h"
#include "MapLoader/MapLoader.h"
#include "Map/Country.h"

using namespace std;

int main(int argc, char **argv) {

	MapLoader loader("./Map/maps/World(small).map");
	Map *map =  loader.getMap();

	Player* one = new Player("one");
	Player* two = new Player("two");

	for(auto& country: map->getCountries()) {
		country->addArmies(1);
		if ((&country-&*(map->getCountries().begin())) % 2 == 0) {
			country->setOwner(one);
			one->addCountry(country);
		} else {
			country->setOwner(two);
			two->addCountry(country);
		}
	}

	one->reinforce();
	one->attack();
	one->fortify();

	two->reinforce();
	two->attack();
	two->fortify();

	return 0;
}

