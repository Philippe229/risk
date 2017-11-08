#include "AttackAI.h"

void AttackAI::attackInitalization(Player* player, Deck* d) {
    pl = player;
	deck = d;
    countries = pl->getCountries();
    int countriesOwnedBeforeAttackPhase = pl->getCountries().size();
    id = pl->getID();
    bool proceed = false;
    int move;
    Player* att;
	Player* def;
    Country* base;
    Country* target;
    while(true) {
        updateAttack();
        //AI method to send attack possibilities return true if attack
        proceed = true;
        if(proceed) {
            //ask AI for attack base
            base = pl->getCountries().at(0); // replace with get base from AI 
            //ask AI for ennemy country
            target = base->getBorderingCountries().at(0); // replace with get enemy from AI 
            att = base->getOwner();
            def = target->getOwner();
            if (attack(base, target)) {
                def->removeCountry(target);
                target->setOwner(att);
                att->addCountry(target);
                 //send armies AI can move base->getArmies() - 1 
                move = 1; // replace with AI choice
                base->removeArmies(move);
                target->addArmies(move);
            }
        }
        else {
            break;
        }

        
    }
    if (player->getCountries().size() > countriesOwnedBeforeAttackPhase) {
		player->getHand()->getCard(deck->Draw());
	}
}
bool AttackAI::isContained(Country* possibility, vector<Country*> c) {
	for (int i = 0; i < c.size(); i++) {
		if (possibility->getName() == c.at(i)->getName())
			return true;
	}
	return false;
}

void AttackAI::updateAttack() {
	vector<Country*> borderingCountries;
	attackBase.clear();
	bool isAdded = false;
	for (int i = 0; i < countries.size(); i++) {
		isAdded = false;
		borderingCountries = countries.at(i)->getBorderingCountries();
		for (int j = 0; j < borderingCountries.size(); j++) {
			// add attack possibility if the player isn't the owner
			if (id != borderingCountries.at(j)->getOwner()->getID()) {
				//add attack base country 
				if (!isAdded) {
					attackBase.push_back(countries.at(i));
					isAdded = true;
				}
				//add country if it is unique
				if (!isContained(borderingCountries.at(j), attackPossibilities))
					attackPossibilities.push_back(borderingCountries.at(j));
			}
		}
	}
}

bool AttackAI::attack(Country* base, Country* target) {
	Player* att = base->getOwner();
	Player* def = target->getOwner();
	int attDice = 0;
	int defDice = 0;
	int checks = 0;
	vector<int> attResults;
	vector<int> defResults;
	cout << "***** " << base->getName() << " is attacking " << target->getName()
			<< " *****" << endl;
	while (true) {
		if (base->getArmies() > 3)
			attDice = 3;
		else if (base->getArmies() == 1)
			attDice = 1;
		else
			attDice = base->getArmies() - 1;

		if (target->getArmies() > 2)
			defDice = 2;
		else
			defDice = target->getArmies();
		bool good = false;
		int input;
        //ask AI for # of dice he wants
        input = 1; // replace with AI choice
		attDice = input;
        good = false;
        //check if player human or AI
		cout << "Defender select dice(1-" << defDice << "): " << endl;
		do {
			good = validateNumericInput(input, 1, defDice);
		} while (!good);
		defDice = input;
		attResults = att->rollDie(attDice);
		defResults = def->rollDie(defDice);
		if (attResults.size() > defResults.size())
			checks = defResults.size();
		else
			checks = attResults.size();
		cout << "*****Dice Roll*****" << endl;
		cout << "Dice A/D: " << attDice << "/" << defDice << endl;
		cout << "Armies A/D: " << base->getArmies() << "/"
				<< target->getArmies() << endl;
		for (int i = 0; i < checks; i++) {
			cout << "Dice Comparison " << endl;
			cout << "Attack Dice: " << attResults.at(attResults.size() - 1 - i)
					<< endl;
			cout << "Defense Dice: " << defResults.at(defResults.size() - 1 - i)
					<< endl;
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
		bool stop;
        //send AI target + base, AI return false if he wants to continue
        stop = true; // replace with call to AI method
		if (!stop) {
			return false;
		}
	}

}

bool AttackAI::validateNumericInput(int& input, int lower, int upper) {
	double raw, fractpart, intpart;
	cin >> raw;
	if (cin) {
		fractpart = modf(raw, &intpart);
		input = (int) intpart;
		if (fractpart != 0) {
			cout << "Invalid Input! Number not integer" << endl;
			return false;
		}
	}
	// or if(cin.fail())
	if (!cin) {
		cout << "Invalid Input! Number not numeric" << endl;
		// reset failbit
		cin.clear();
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} else if (input < lower || input > upper) {
		cout << "Invalid Input! Number out of range" << endl;
		cin.clear();
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} else
		return true;
}