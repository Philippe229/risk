#include <iostream>
#include "DomObserver.h"

DomObserver::DomObserver() {
	// Creates an observer with no subject to observe
	m = NULL;
}

DomObserver::DomObserver(MainLoop* mLoop) {
	m = mLoop;
	m -> addObserver(this);
}

DomObserver::~DomObserver() {
	if (m != NULL)
		m -> removeObserver(this);
}

void DomObserver::update() {
    players = m->getPlayers();
    display();
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
    int totalCountries = 0;
    int numCountries= 0;
    double rPercentage = 0;
    Player* p;
    for(int j = 0;j < players.size();j++) {
        p = players.at(j);
        totalCountries += p->getCountries().size();
    }
    cout << "###GAME STATISTICS###" << endl;
    //Build bar graph
    for(int i = 0;i < players.size();i++) {
        p = players.at(i);
        numCountries = p->getCountries().size();
        rPercentage = ((double)numCountries / (double)totalCountries)*100;
        cout << "| Player " << p->getID() << " Dominance: ";
        for(int i = 0; i < 10;i++)
            if(i < (rPercentage/10))
                cout << "+";
            else
                cout << "-";
        cout << endl;
    }
	//cout << testSubject -> getData() << endl;
}