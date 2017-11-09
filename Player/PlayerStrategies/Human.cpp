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
    Country* sourceCountry = getCountries()[0];
    Country* targetCountry = sourceCountry->getBorderingEnemies()[0];
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

