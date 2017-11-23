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
    int turnsPerPlayer;
    Player* getWinner();
    bool isMaxTurns;
    int maxTurns;

public:
    MainLoop(vector<Player*>, Map*, Deck*);
    MainLoop(vector<Player*>, Map*, Deck*, int);
    vector<Player*> getPlayers();
    void play();
    int getTurn();
    int playSeveral();
};

#endif
