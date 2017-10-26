#include "Attack.h"
void Attack::attackInitalization(Player* player) {
    pl = player;
    countries = pl->getCountries();
    id = pl->getID();
	char response;
	cout << "Do you wish to attack during this turn Player " << id << " (Y/y to continue)?" << endl;
	cin >> response;
	if (toupper(response) == 'Y')
	{
		updateAttack();
		attackProcedure();
	}
	cout << "End of the attack phase.";
}

void Attack::updateAttack() {
    //cout << "***********" << id << "***********"<<endl;
	vector<Country*> borderingCountries;
	attackBase.clear();
	bool isAdded = false;
	for (int i = 0; i < countries.size();i++) {
		isAdded = false;
		borderingCountries = countries.at(i)->getBorderingCountries();
		for (int j = 0;j < borderingCountries.size();j++) {
			// add attack possibility if the player isn't the owner
			if (id != borderingCountries.at(j)->getOwner()->getID()) {
				//add attack base country 
				if (!isAdded) {
					attackBase.push_back(countries.at(i));
					isAdded = true;
				}
				//add country if it is unique
				if (!isContained(borderingCountries.at(j),attackPossibilities))
					attackPossibilities.push_back(borderingCountries.at(j));
				//cout << borderingCountries.at(j)->getName()<< " " << borderingCountries.at(j)->getOwner()->getName() << endl;
			}
		}
	}
}

void Attack::attackProcedure() {
	double raw, fractpart, intpart;
	bool good = false;
	int numAttack = 0;
	vector<Country*> enemyCountries;
	int input;
	Country* base;
	Country* target;
	Player* att;
	Player* def;
	cout << "Input Index|Country Name|Armies|Enemies Around" << endl;
	cout << endl;

	for (int i = 0;i < attackBase.size();i++) {
		attackBase.at(i)->updateInfo();
		if(attackBase.at(i)->getCanAttack()) {
			cout << i+1  << "\t|" << attackBase.at(i)->getName() << "|" << attackBase.at(i)->getArmies() <<  "|" << attackBase.at(i)->getNumEnemiesAround() << endl;
			numAttack++;
		}
	}
	if (numAttack < 1) {
		cout << "No valid country to attack from" << endl;
		return;
	}
	cout << "Select which country you would like to attack from" << endl;
	do {
		good = validateNumericInput(input, 1, attackBase.size());
	}
	while(!good);
	base = attackBase.at(input-1);
	cout << "Attacking From " << base->getName() << endl;
	cout << "Input Index| Country Name|Armies|Owner" << endl;
	cout << endl;
	enemyCountries = base->getBorderingEnemies();
	for (int i = 0;i < enemyCountries.size();i++) {
		cout << i+1  << "\t| " << enemyCountries.at(i)->getName() << "| " << enemyCountries.at(i)->getArmies() <<  "|" << enemyCountries.at(i)->getOwner()->getID() << endl;
	}
	cout << "Select which country you would like to attack" << endl;
	good = false;
	do {
		good = validateNumericInput(input, 1, enemyCountries.size());
	}
	while(!good);
	target = enemyCountries.at(input-1);
	att = base->getOwner();
	def = target->getOwner();
	if (attack(base, target)) {
			good = false;
			def->removeCountry(target);
			target->setOwner(att);
			att->addCountry(target);
			cout << "Select how many armies to move in your new country" << endl;
            cout << "Armies available: " << base->getArmies() - 1 <<endl;
			do {
				good = validateNumericInput(input, 0, base->getArmies() - 1);
			}
			while(!good);
			base->removeArmies(input);
			target->addArmies(input);
		}
		att->showCountries();
		char response;
		cout << "Do you wish to attack again Player " << id << " (Y/y to continue)?" << endl;
		cin >> response;
		if (toupper(response) == 'Y') {
			updateAttack();
			attackProcedure();
			return;
		}
}
bool Attack::attack(Country* base, Country* target) {
	Player* att = base->getOwner();
	Player* def = target->getOwner();
	int attDice = 0;
	int defDice = 0;
	int checks = 0;
	vector<int> attResults;
	vector<int> defResults;
	cout <<  "***** " <<base->getName() << " is attacking " << target->getName() << " *****" << endl;
	while (true) {
		if(base->getArmies() > 3)
			attDice = 3;
		else if (base->getArmies() == 1)
			attDice = 1;
		else
			attDice = base->getArmies() - 1;

		if(target->getArmies() > 2)
			defDice = 2;
		else
			defDice = target->getArmies();

		attResults= att->rollDie(attDice);
		defResults= def->rollDie(defDice);
		if (attResults.size() > defResults.size())
			checks = defResults.size();
		else	
			checks = attResults.size();
		cout << "*****Dice Roll*****" << endl;
		cout << "Attack Dice: " << attDice << endl;
		cout << "Defense Dice: " << defDice << endl;
		for (int i = 0; i < checks;i++) {
			cout << "Dice Comparison " << endl;
			cout << "Attack Dice: " << attResults.at(attResults.size()-1- i) << endl;
			cout << "Defense Dice: " << defResults.at(defResults.size()-1-i) << endl;
			if (attResults.at(attResults.size()-1- i) <= defResults.at(defResults.size()-1-i)) {
				base->removeArmies(1);
				if (base->getArmies() <= 1) {
					cout << "Defender wins" <<endl;
					return false;
					break;
				}
			}
			else {
				target->removeArmies(1);
				if (target->getArmies() == 0) {
					cout << "Attacker wins" <<endl;
					return true;
					break;
				}
			}

		}
	}

}
//could optimize, check if country is already in vector
bool Attack::isContained(Country* possibility, vector<Country*> c) {
	for (int i = 0; i < c.size();i++) {
		if(possibility->getName() == c.at(i)->getName())
			return true;
	}
	return false;
}
bool Attack::validateNumericInput(int& input,int lower, int upper) {
	double raw, fractpart, intpart;
	cin >> raw;
	if (cin) {
		fractpart = modf (raw, &intpart);
		input = (int)intpart;
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
	}
	else if (input < lower || input > upper) {
		cout << "Invalid Input! Number out of range" << endl;
		return false;
	}
	else
		return true;
}