#ifndef COMMON_OBSERVER_DOMOBSERVER_H_
#define COMMON_OBSERVER_DOMOBSERVER_H_

#include "Observer.h"
#include "../../Map/Map.h"
#include "../../Player/Player.h"
#include "../../GamePhases/MainLoop.h"

class Map;
class Player;
class Observer;
class MainLoop;

using namespace std;
class DomObserver : public Observer {

private:
    MainLoop* m;
    vector<Player*> players;
    bool sawPlayer(Player*);
    void buildGraph(int, int);
public:
	DomObserver();
	DomObserver(MainLoop*);
	~DomObserver();
	void update();
	void display();
};

#endif