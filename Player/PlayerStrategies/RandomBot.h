#ifndef RANDOM_BOT_H_
#define RANDOM_BOT_H_

#include <algorithm>
#include "../Player.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"

class RandomBot : public Player {
public:
    RandomBot();
    virtual ~RandomBot();
    RandomBot(string);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
    int defensiveDice(int);
};

#endif
