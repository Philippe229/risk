#ifndef CHEATER_BOT_H_
#define CHEATER_BOT_H_

#include <algorithm>
#include <limits.h>
#include "../Player.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"

class CheaterBot : public Player {
public:
    CheaterBot();
    virtual ~CheaterBot();
    CheaterBot(string);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
    int defensiveDice(int);
};

#endif
