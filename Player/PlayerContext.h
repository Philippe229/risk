#ifndef PLAYER_CONTEXT_H_
#define PLAYER_CONTEXT_H_

#include "Player.h"

class PlayerContext {
private:
    Player* playerStrategy;
public:
    PlayerContext(Player*);
    void setPlayerStrategy(Player*);

    void reinforce(Map*, Deck*);
    void attack(Map*, Deck*);
    void fortify(Map*, Deck*);
};

#endif