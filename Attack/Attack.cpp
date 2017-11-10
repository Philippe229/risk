#include "Attack.h"

void Attack::attackInitalization(Player* player, Deck* d) {

	notify(player, "Attack", "");

	pl = player;
	deck = d;
	countries = pl->getCountries();
	id = pl->getID();
	int countriesOwnedBeforeAttackPhase = player->getCountries().size();
	char response;
	cout << "Do you wish to attack during this turn Player " << id
			<< " (Y/y to continue)?" << endl;
	cin >> response;
	if (toupper(response) == 'Y') {
		updateAttack();
		attackProcedure();
	}
	// draw a card if player conquered at least one country during attack phase
	if (player->getCountries().size() > countriesOwnedBeforeAttackPhase) {
		player->getHand()->getCard(deck->Draw());
	}
	cout << "End of the attack phase.";
}

void Attack::updateAttack() {
	//cout << "***********" << id << "***********"<<endl;
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
	vector<int> valid;
	pl->showCountries();
	cout << "Input Index|Country Name|Armies|Enemies Around" << endl;
	cout << endl;

	for (int i = 0; i < attackBase.size(); i++) {
		attackBase.at(i)->updateInfo();
		if (attackBase.at(i)->getCanAttack()) {
			cout << i + 1 << "\t|" << attackBase.at(i)->getName() << "|"
					<< attackBase.at(i)->getArmies() << "|"
					<< attackBase.at(i)->getNumEnemiesAround() << endl;
			valid.push_back(i + 1);
			numAttack++;
		}
	}

	if (numAttack < 1) {
		cout << "No valid country to attack from" << endl;
		return;
	}

	cout << "Select which country you would like to attack from" << endl;
	do {
		good = validateSpecNumericInput(input, valid);
	} while (!good);
	base = attackBase.at(input - 1);
	cout << "Attacking From " << base->getName() << endl;
	cout << "Input Index| Country Name|Armies|Owner" << endl;
	cout << endl;
	enemyCountries = base->getBorderingEnemies();
	valid.clear();
	for (int i = 0; i < enemyCountries.size(); i++) {
		cout << i + 1 << "\t| " << enemyCountries.at(i)->getName() << "| "
				<< enemyCountries.at(i)->getArmies() << "|"
				<< enemyCountries.at(i)->getOwner()->getID() << endl;
		valid.push_back(i + 1);
	}

	cout << "Select which country you would like to attack" << endl;
	good = false;
	do {
		good = validateSpecNumericInput(input, valid);
	} while (!good);

	target = enemyCountries.at(input - 1);
	att = base->getOwner();
	def = target->getOwner();

	if (userAttack(base, target)) {
		good = false;
		def->removeCountry(target);
		target->setOwner(att);
		att->addCountry(target);
		cout << "Select how many armies to move in your new country" << endl;
		cout << "Armies available: " << base->getArmies() - 1 << endl;
		do {
			good = validateNumericInput(input, 1, base->getArmies() - 1);
		} while (!good);
		base->removeArmies(input);
		target->addArmies(input);
	}

	att->showCountries();

	char response;
	cout << "Do you wish to attack again Player " << id << " (Y/y to continue)?"
			<< endl;
	cin >> response;
	if (toupper(response) == 'Y') {
		updateAttack();
		attackProcedure();
		return;
	}
}

bool Attack::userAttack(Country* base, Country* target) {
	Player* att = base->getOwner();
	Player* def = target->getOwner();
	int attDice = 0;
	int defDice = 0;
	int checks = 0;
	vector<int> attResults;
	vector<int> defResults;

	string message = "Attacking " + target -> getName() + "'s " +
			to_string(target -> getArmies()) + " armies (owned by " + def -> getName() + ") with " +
			base -> getName() + "'s " +to_string(base -> getArmies()) + " armies.";
	notify(att, "Attack", message);

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
		cout << "Attack select dice (1-" << attDice << "): " << endl;
		bool good = false;
		int input;
		do {
			good = validateNumericInput(input, 1, attDice);
		} while (!good);
		attDice = input;
		good = false;
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
		char response;
		cout << "Do you wish to attack again " << target->getName()
				<< " (Y/y to continue)?" << endl;
		cin >> response;
		if (toupper(response) != 'Y') {
			return false;
		}
	}

}

//could optimize, check if country is already in vector
bool Attack::isContained(Country* possibility, vector<Country*> c) {
	for (int i = 0; i < c.size(); i++) {
		if (possibility->getName() == c.at(i)->getName())
			return true;
	}
	return false;
}

bool Attack::validateSpecNumericInput(int& input, vector<int> poss) {
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
	} else if (!(std::find(poss.begin(), poss.end(), input) != poss.end())) {
		cout << "Invalid Input! Number not valid" << endl;
		cin.clear();
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} else
		return true;
}

bool Attack::validateNumericInput(int& input, int lower, int upper) {
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

void Attack::attack(Deck* currDeck, Player* player, Country* sourceCountry, Country* destinationCountry, int numDice, int numArmiesToMove) {
	if (numDice > 3 || numDice > min(3, sourceCountry->getArmies() - 1)) {
		cout << "Invalid amount of dice chosen." << endl;
		return;
	}

	if (player == NULL) {
		cout << "Player must be set." << endl;
		return;
	}

	if (sourceCountry->getOwner() != player) {
		cout << "You cannot attack with a country you do not own." << endl;
		return;
	}

	if (sourceCountry == NULL || destinationCountry == NULL) {
		cout << "Source and destination must be set when attacking." << endl;
		return;
	}

	cout << sourceCountry->getName() << " is attacking " << destinationCountry->getName() << endl;

	bool successfulTakeover = false;
	// Roll the dice
	vector<int> attackResults = sourceCountry->getOwner()->rollDie(numDice);
	vector<int> defenseResults = destinationCountry->getOwner()->rollDie(min(2, destinationCountry->getArmies()));

	// Remove the appropriate amount of armies
	for (int i = 0; i < min(attackResults.size(), defenseResults.size()); i++) {
		cout << "Attack dice: " << attackResults[attackResults.size() - 1 - i] << endl;
		cout << "Defense dice: " << defenseResults[defenseResults.size() - 1 -i] << endl;
		// Successful attack
		if (attackResults[attackResults.size() - 1 - i] > defenseResults[defenseResults.size() - 1 -i]) {
			cout << "Attacker wins removing one army from " << destinationCountry->getName() << endl;
			destinationCountry->removeArmies(1);

			if (destinationCountry->getArmies() == 0) {
				cout << player->getName() << " captured new country " << destinationCountry->getName() << endl;
				destinationCountry->getOwner()->removeCountry(destinationCountry);
				destinationCountry->setOwner(player);
				int numMoving = min(numArmiesToMove, sourceCountry->getArmies() - 1);
				destinationCountry->addArmies(numMoving);
				sourceCountry->removeArmies(numMoving);

				successfulTakeover = true;
			}
		} else {
			cout << "Defender wins removing one army from " << sourceCountry->getName() << endl;
			// Failed attack
			sourceCountry->removeArmies(1);
		}
	}

	sourceCountry->updateInfo();
	destinationCountry->updateInfo();

	// Get a card if a country was successfully attacked
	if (player->getHand()->getNumberOfCards() < 5 && successfulTakeover) {
		player->getHand()->getCard(currDeck->Draw());
	}
}
