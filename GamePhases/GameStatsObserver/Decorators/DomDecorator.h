#ifndef GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_DOMDECORATOR_H_
#define GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_DOMDECORATOR_H_

#include "StatsDecorator.h"
#include "../../../Player/Player.h"


class DomDecorator : public StatsDecorator {

private:
    vector<Player*> players;
    bool sawPlayer(Player*);
    void buildGraph(double, int);

public:
    DomDecorator(GameStatsObserver* o);
	void update();
	void display();

};

#endif
