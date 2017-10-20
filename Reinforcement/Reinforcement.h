#ifndef REINFORCEMENT_REINFORCEMENT_H_
#define REINFORCEMENT_REINFORCEMENT_H_

#include <iostream>
#include <vector>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/Continent.h"

using namespace std;

class Reinforcement {

private:
	static int getCountryBonus(Player* player);
	static int getContinentBonus(Player* player, vector<Continent*> continents);
	static int getCardBonus(Player* player);

public:
	static void reinforcement(Player* player, Map* map);

};

#endif /* REINFORCEMENT_REINFORCEMENT_H_ */
