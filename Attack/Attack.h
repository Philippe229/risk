/*
 * Attack.h
 *
 *  Created on: Oct 25, 2017
 *      Author: Dylan Fernandes
 */

#ifndef ATTACK_H_
#define ATTACK_H_

#include "../Player/Player.h"
#include "../CardComponents/Deck.h"
#include "../PhaseObserver/Phase.h"

using namespace std;

class Attack : public Phase {

private:
	void updateAttack();
	int numberOfCountriesConquered;
	void attackProcedure();
	bool isContained(Country*,vector<Country*>);
	bool validateNumericInput(int&,int,int);
	bool validateSpecNumericInput(int&,vector<int>);
    bool userAttack(Country*, Country*);
	int id;
	
    Player* pl;
    Deck* deck;
    vector<Country*> countries;
    vector<Country*> attackBase;
	vector<Country*> attackPossibilities;

public:
	void attackInitalization(Player*, Deck* deck);
	static void attack(Deck*, Player*, Country*, Country*, int, int);
	static void notifyObserver(Player*, string);
};

#endif /* ATTACK_H_ */
