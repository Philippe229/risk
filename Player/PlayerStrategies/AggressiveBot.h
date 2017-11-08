#ifndef AGGRESSIVE_BOT_H_
#define AGGRESSIVE_BOT_H_

#include "../PlayerActions.h"

class AggressiveBot : public PlayerActions {
public:
    AggressiveBot();
    AggressiveBot(string);
    void reinforce(Map*, Deck*);
	void attack(Map*, Deck*);
	void fortify(Map*, Deck*);
};

#endif