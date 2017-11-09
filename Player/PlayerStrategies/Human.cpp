#include "Human.h"
#include <queue>

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
    for(int j = 0; j < allCountries.size(); j++) {
        if(allCountries.at(j)->getArmies() > 1)
            base.push_back(allCountries.at(j));
    }
    if(base.size() < 1) {
        cout << "No Fortification Options." << endl;
        return;
    }
	for (int i = 0; i < base.size(); i++) {
		base.at(i)->updateInfo();
		cout << i + 1 << "\t|" << base.at(i)->getName() << "|" << base.at(i)->getArmies() << "|" << base.at(i)->getNumEnemiesAround() << endl;
		
    }
    cout << "Select a source country" << endl;
    do {
        good = Common::validateNumericInput(input, 1, base.size());
     } while (!good);
     Country* sourceCountry = getCountries()[input -1];
     good = false;
     cout << "Select number of armies to move (1 - " <<  sourceCountry->getArmies() -1 << ")" << endl;
     do {
        good = Common::validateNumericInput(input, 1, sourceCountry->getArmies() -1);
     } while (!good);
     armies = input;
     base.clear();
     for(int j = 0; j < allCountries.size(); j++) {
        if(verifyTargetCountry(sourceCountry, allCountries.at(j)) && sourceCountry != allCountries.at(j))
            base.push_back(allCountries.at(j));
    }
     for (int i = 0; i < base.size(); i++) {
		base.at(i)->updateInfo();
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
			if (!visitedCountries[borderingCountry])
				queue.push(borderingCountry);
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

