#include "AttackAI.h"


bool AttackAI::attack(Country* base, Country* target, int attDice) {
	Player* att = base->getOwner();
	Player* def = target->getOwner();
	int defDice = 0;
	int checks = 0;
	vector<int> attResults;
	vector<int> defResults;
	while (true) {
		if (target->getArmies() > 2)
			defDice = 2;
		else
			defDice = target->getArmies();
		bool good = false;
		int input;

        good = false;
        //check if player human or AI
		defDice = 1; //replace with call to select dice for defender
		attResults = att->rollDie(attDice);
		defResults = def->rollDie(defDice);
		if (attResults.size() > defResults.size())
			checks = defResults.size();
		else
			checks = attResults.size();
		for (int i = 0; i < checks; i++) {
			if (attResults.at(attResults.size() - 1 - i)
					<= defResults.at(defResults.size() - 1 - i)) {
				base->removeArmies(1);
				if (base->getArmies() <= 1) {
					cout << "Defender wins" << endl;
					return false;
				}
			} else {
				target->removeArmies(1);
				if (target->getArmies() == 0) {
					cout << "Attacker wins" << endl;
					return true;
				}
			}

		}
			return false;
	}

}

