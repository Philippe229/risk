#ifndef MAIN_H_
#define MAIN_H_

#include <vector>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../CardComponents/Deck.h"

class MainLoop { 
private:
    vector<Player*> playerOrder;
    Map* currMap;
    Deck* currDeck;

    Player* getWinner();
public:
    MainLoop(vector<Player*>, Map*, Deck*);
    void play();
};

#endif