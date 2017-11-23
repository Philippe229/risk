#ifndef REINFORCEMENT_REINFORCEMENT_H_
#define REINFORCEMENT_REINFORCEMENT_H_

#include <iostream>
#include <vector>
#include <map>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/Continent.h"
#include "../PhaseObserver/Phase.h"

using namespace std;

class Reinforcement : public Phase {
private:
	static int getCountryBonus(Player*);
	static int getContinentBonus(Player*, vector<Continent*>);
	static int getCardBonus(Player*);
	static int getMaxCardBonus(Player*);
public:
	static int staticBonusArmies;
	static void startReinforcement(Player* p);
	static void playerReinforcement(Player*, vector<Continent*>);
	static void reinforcement(Player*, Country*, int);
	static int getTotalBonusArmies(Player*, vector<Continent*>);
	static void notifyObserver(Player*, string);
};

#endif /* REINFORCEMENT_REINFORCEMENT_H_ */
