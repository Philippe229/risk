#ifndef HUMAN_H_
#define HUMAN_H_

#include <string>
#include "../Player.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"

class Human : public Player {
public:
    Human();
    Human(string);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
};

#endif