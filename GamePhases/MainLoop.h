#ifndef MAIN_H_
#define MAIN_H_

#include <vector>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../CardComponents/Deck.h"
#include "../Common/Observer/Subject.h"
#include "GameStatsObserver/GameStatsObserver.h"

class Subject;
class Player;
class GameStatsObserver;

class MainLoop : public Subject {

private:
    GameStatsObserver* observer;
    vector<Player*> playerOrder;
    Map* currMap;
    Deck* currDeck;
    int turn;

    Player* getWinner();

public:
    MainLoop(vector<Player*>, Map*, Deck*);
    vector<Player*> getPlayers();
    void play();
    int getTurn();

};

#endif
