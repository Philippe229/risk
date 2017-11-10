#ifndef HUMAN_H_
#define HUMAN_H_

#include <queue>
#include <locale>
#include <string>
#include "../Player.h"
#include "../../Common/Common.h"
#include "../../Fortification/Fortification.h"
#include "../../Reinforcement/Reinforcement.h"
#include "../../Attack/Attack.h"\

using namespace std;

class Human : public Player {
private:
    bool verifyTargetCountry(Country*, Country*);
public:
    Human();
    Human(string);
    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
    int defensiveDice(int);
};

#endif