#include "Human.h"

Human::Human() : Player() {

}

Human::Human(string n) : Player(n) {

}

void Human::reinforce(Map* currMap, Deck* currDeck) {
    Reinforcement::playerReinforcement(this, currMap->getContinents());
}

void Human::attack(Map* currMap, Deck* currDeck) {
    Attack a;
	a.attackInitalization(this, currDeck);
}

void Human::fortify(Map* currMap, Deck* currDeck) {
    bool good = false;
    int input;
    int armies = 0;
    
    cout << "Input Index|Country Name|Armies|Enemies Around" << endl;
	cout << endl;
    vector<Country*> allCountries = getCountries();
    vector<Country*> base;

    // Get all countries that can be fortified
    for (int j = 0; j < allCountries.size(); j++) {
        if (allCountries[j]->getArmies() > 1) {
            for (int i = 0; i < allCountries.size(); i++) {
                if (allCountries[i] != allCountries[j] && verifyTargetCountry(allCountries[j], allCountries[i])) {
                    base.push_back(allCountries.at(j));
                    break;
                }
            }
        }
    }

    if (base.size() == 0) {
        cout << "No Fortification Options." << endl;
        return;
    }

    // Update all the surrounding enemies of fortifiable countries
	for (int i = 0; i < base.size(); i++) {
		base[i]->updateInfo();
		cout << i + 1 << "\t|" << base.at(i)->getName() << "|" << base.at(i)->getArmies() << "|" << base.at(i)->getNumEnemiesAround() << endl;
    }

    char doFortify;
    cout << "Do you wish to fortify (y/n)? " << endl;
    cin >> doFortify;

    if (toupper(doFortify) == 'N') {
        return;
    }

    // Select the source
    cout << "Select a source country" << endl;
    do {
        good = Common::validateNumericInput(input, 1, base.size());
    } while (!good);

    // Select the amount of armies
    Country* sourceCountry = getCountries()[input -1];
    good = false;
    cout << "Select number of armies to move (1 - " <<  sourceCountry->getArmies() - 1 << ")" << endl;
    do {
        good = Common::validateNumericInput(input, 1, sourceCountry->getArmies() -1);
    } while (!good);

    armies = input;
    base.clear();

    // Get all the connected countries
    for (int j = 0; j < allCountries.size(); j++) {
        if (verifyTargetCountry(sourceCountry, allCountries[j]) && sourceCountry != allCountries[j]) {
            base.push_back(allCountries[j]);
        }
    }

    // Update all connected countries information
    for (int i = 0; i < base.size(); i++) {
        base[i]->updateInfo();
        cout << i + 1 << "\t|" << base.at(i)->getName() << "|" << base.at(i)->getArmies() << "|" << base.at(i)->getNumEnemiesAround() << endl;
    }

    cout << "Select a target country" << endl;
    good = false;
    do {
        good = Common::validateNumericInput(input, 1, base.size());
    } while (!good);

    Country* targetCountry = getCountries()[input -1];
    cout << sourceCountry->getName() << endl;
    cout << targetCountry->getName() << endl;
    Fortification::fortify(this, sourceCountry, targetCountry, 1);
}

bool Human::verifyTargetCountry(Country* sourceCountry, Country* targetCountry) {
	vector<Country*> playerCountries = getCountries();

	// verify link between countries with BFS
	queue<Country*> queue;
	vector<Country*> borderingCountries;
	map<Country*, bool> visitedCountries;

	for (Country* playerCountry : playerCountries) {
		visitedCountries.insert({playerCountry, false});
	}

	queue.push(sourceCountry);

	while (!queue.empty()) {
		Country* currentCountry = queue.front();
		queue.pop();
		visitedCountries[currentCountry] = true;

		if (currentCountry == targetCountry)
			return true;

		borderingCountries = currentCountry -> getBorderingCountries();

		for (Country* borderingCountry : borderingCountries) {
			if (borderingCountry->getOwner() == this && !visitedCountries[borderingCountry]) {
                queue.push(borderingCountry);
            }
		}
	}

	return false;
}

int Human::defensiveDice(int max) {
    bool good = false;
    int input;

    cout << "Defender select dice(1-" << max << "): " << endl;
    do {
        good = Common::validateNumericInput(input, 1, max);
    } while (!good);

    return input;
}

