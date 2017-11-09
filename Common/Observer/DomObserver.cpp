#include <iostream>
#include "DomObserver.h"

DomObserver::DomObserver() {
	// Creates an observer with no subject to observe
	m = NULL;
}

DomObserver::DomObserver(Map* pMap) {
	m = pMap;
	m -> addObserver(this);
}

DomObserver::~DomObserver() {
	if (m != NULL)
		m -> removeObserver(this);
}

void DomObserver::update() {
    vector<Country*> countries = m->getCountries();
    players.clear();
    Player* player;
    for(int i = 0; i < countries.size();i++) {
        player = countries.at(i)->getOwner();
        if (!sawPlayer(player))
            players.push_back(player);
    }
}

//Has player already been added to array
bool DomObserver::sawPlayer(Player* player) {
    if(players.size() == 0)
        return false;
    for(int i = 0; i < players.size();i++) {
        if(players.at(i)->getID() == player->getID())
            return true;
    }
    return false;
}

void DomObserver::display() {
    int totalCountries = m->getCountries().size();
    Player* p;
    for(int i = 0;i < players.size();i++) {
        p = players.at(i);
        cout << "| " << p->getID() << " Dominance: " << p->getCountries().size() << "/" << totalCountries << endl;
    }
	//cout << testSubject -> getData() << endl;
}