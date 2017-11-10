#ifndef MAIN_H_
#define MAIN_H_

#include <vector>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../CardComponents/Deck.h"
#include "../Common/Observer/Subject.h"
#include "../Common/Observer/DomObserver.h"
class Subject;
class Player;
class DomObserver;

class MainLoop : public Subject { 
private:
    vector<Player*> playerOrder;
    Map* currMap;
    Deck* currDeck;
    DomObserver* d;

    Player* getWinner();
public:
    MainLoop(vector<Player*>, Map*, Deck*);
    vector<Player*> getPlayers();
    void play();
};

#endif