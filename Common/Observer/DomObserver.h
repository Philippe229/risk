#ifndef COMMON_OBSERVER_DOMOBSERVER_H_
#define COMMON_OBSERVER_DOMOBSERVER_H_

#include "Observer.h"
#include "../../Map/Map.h"
#include "../../Player/Player.h"

class Map;
class Player;
class Observer;

using namespace std;
class DomObserver : public Observer {

private:
    Map* m;
    vector<Player*> players;
    bool sawPlayer(Player*);
public:
	DomObserver();
	DomObserver(Map* m);
	~DomObserver();
	void update();
	void display();
};

#endif