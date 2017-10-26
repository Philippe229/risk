/*
 * Attack.h
 *
 *  Created on: Oct 25, 2017
 *      Author: Dylan Fernandes
 */

#ifndef ATTACK_H_
#define ATTACK_H_

#include "../Player/Player.h"

using namespace std;

class Attack {

private:
	void updateAttack();
	void attackProcedure();
	bool isContained(Country*,vector<Country*>);
	bool validateNumericInput(int&,int,int);
    bool attack(Country*, Country*);
    int id;
    Player* pl;
    vector<Country*> countries;
    vector<Country*> attackBase;
	vector<Country*> attackPossibilities;

public:
	void attackInitalization(Player*);

};

#endif /* ATTACK_H_ */