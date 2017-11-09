#ifndef PLAYER_PLAYERSTRATEGIES_DEFENSIVEBOT_H_
#define PLAYER_PLAYERSTRATEGIES_DEFENSIVEBOT_H_

#include "../Player.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"
#include <algorithm>

class DefensiveBot : public Player {
public:
	DefensiveBot();
	virtual ~DefensiveBot();
	DefensiveBot(string);
    int defensiveDice(int);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
};

#endif
