#ifndef ATTACKAI_H_
#define ATTACKAI_H_

#include "../Player/Player.h"
#include "../CardComponents/Deck.h"

using namespace std;

class AttackAI {

private:
	void updateAttack();
	// int numberOfCountriesConquered;
	// void attackProcedure();
	bool isContained(Country*,vector<Country*>);
	bool validateNumericInput(int&,int,int);
	// bool validateSpecNumericInput(int&,vector<int>);
    bool attack(Country*, Country*);
    int id;
    Player* pl;
    Deck* deck; // get gameloop's deck
    vector<Country*> countries;
    vector<Country*> attackBase;
	vector<Country*> attackPossibilities;

public:
	void attackInitalization(Player*, Deck* deck);

};

#endif /* ATTACKAI_H_ */