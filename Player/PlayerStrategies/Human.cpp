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
    cout << "Input Index|Country Name|Armies|Enemies Around" << endl;
	cout << endl;
    vector<Country*> base = getCountries();

	for (int i = 0; i < base.size(); i++) {
		base.at(i)->updateInfo();
		cout << i + 1 << "\t|" << base.at(i)->getName() << "|" << base.at(i)->getArmies() << "|" << base.at(i)->getNumEnemiesAround() << endl;
		
    }
    cout << "Select a source contry" << endl;
    do {
        good = Common::validateNumericInput(input, 1, base.size());
     } while (!good);
     Country* sourceCountry = getCountries()[input -1];
     cout << "Select a target contry" << endl;
     do {
         good = Common::validateNumericInput(input, 1, base.size());
      } while (!good);
    Country* targetCountry = getCountries()[input -1];
    cout << sourceCountry->getName() << endl;
    cout << targetCountry->getName() << endl;
    Fortification::fortify(this, sourceCountry, targetCountry, 1);
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

