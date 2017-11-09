#ifndef AGGRESSIVE_BOT_H_
#define AGGRESSIVE_BOT_H_

#include <algorithm>
#include "../Player.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"

class AggressiveBot : public Player {
public:
    AggressiveBot();
    virtual ~AggressiveBot();
    AggressiveBot(string);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
    int defensiveDice(int);
};

#endif
