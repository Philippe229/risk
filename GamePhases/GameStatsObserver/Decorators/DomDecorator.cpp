#include "DomDecorator.h"
#include <iostream>
#include <cstdio>

DomDecorator::DomDecorator(GameStatsObserver* o) : StatsDecorator(o) {

}

void DomDecorator::update() {
	StatsDecorator::update();
	players = mainLoop -> getPlayers();
    display();
}

//Has player already been added to array
bool DomDecorator::sawPlayer(Player* player) {
    if(players.size() == 0)
        return false;
    for(int i = 0; i < players.size();i++) {
        if(players.at(i)->getID() == player->getID())
            return true;
    }
    return false;
}

void DomDecorator::display() {
    int totalCountries = 0;
    int totalArmies = 0;
    int numCountries= 0;
    int numArmies = 0; 
    double rPercentage = 0;
    Player* p;

    for(int j = 0;j < players.size();j++) {
        p = players.at(j);
        totalCountries += p->getCountries().size();
        totalArmies += p->getPlacedArmies();
    }

    cout << endl << "###DOMINATION STATISTICS###" << endl;
    cout << "--Dominance--" << endl;
    //Build bar graph
    for(int i = 0;i < players.size();i++) {
        p = players.at(i);
        numCountries = p->getCountries().size();
        rPercentage = ((double)numCountries / (double)totalCountries)*100;
        cout << "| Player " << p->getID() << ": ";
        buildGraph((rPercentage/10),10);
    }

    cout << "--Army Force--" << endl;
	for(int i = 0;i < players.size();i++) {
        p = players.at(i);
        numArmies = p->getPlacedArmies();
        rPercentage = ((double)numArmies / (double)totalArmies)*100;
        cout << "| Player " << p->getID() << ": ";
        buildGraph((rPercentage/10),10);
    }

    cout << "#####################" << endl;
}

void DomDecorator::buildGraph(double numPlus, int numTot) {
    for(int i = 0; i < numTot;i++)
        if(i < (int)numPlus)
            cout << "+";
        else
            cout << "-";
    printf("\t %.2f ", numPlus*10 );
    cout << "%"<< endl;
}
