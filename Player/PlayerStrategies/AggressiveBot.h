#ifndef AGGRESSIVE_BOT_H_
#define AGGRESSIVE_BOT_H_

#include "../PlayerActions.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"

class AggressiveBot : public Player, public PlayerActions {
public:
    AggressiveBot();
    AggressiveBot(string);
    void reinforce(Map*);
	void attack(Map*);
	void fortify(Map*);
};

#endif