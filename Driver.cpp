#include <iostream>
#include <vector>

#include "Player.h"
#include "Country.h"
#include "Border.h"
#include "Map.h"

using namespace std;

int main() {
	Player *roosevelt = new Player("Teddy Roosevelt");
	Player *gandhi = new Player("Gandhi");

	vector<Country> countries;
	countries.push_back(Country("USA", "America", *roosevelt, 10));
	countries.push_back(Country("India", "Asia", *gandhi, 20));
	countries.push_back(Country("England", "Europe", *roosevelt, 5));
	countries.push_back(Country("China", "Asia", *gandhi, 20));

	vector<Border> borders;
	borders.push_back(Border(countries[0], countries[1]));
	borders.push_back(Border(countries[1], countries[2]));
	borders.push_back(Border(countries[2], countries[3]));
	borders.push_back(Border(countries[3], countries[0]));

	Map *world = new Map(countries, borders);
	world->getBorders();
	world->getCountries();

	cout << "end";
	return 0;
}
