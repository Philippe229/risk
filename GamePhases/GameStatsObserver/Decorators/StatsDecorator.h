#ifndef GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_STATSDECORATOR_H_
#define GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_STATSDECORATOR_H_

#include "../GameStatsObserver.h"

class StatsDecorator : public GameStatsObserver {

protected:
	GameStatsObserver* decoratedObserver;

public:
	StatsDecorator(GameStatsObserver* o);
	void update();

};

#endif /* GAMEPHASES_GAMESTATSOBSERVER_DECORATORS_STATSDECORATOR_H_ */
