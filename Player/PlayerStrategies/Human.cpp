#include "Human.h"

Human::Human() {
    Player();
}

Human::Human(string n) : Player(n) {

}

void Human::reinforce(vector<Continent*> continents) {
    Player::reinforce(continents);
}

void Human::fortify(Country* sourceCountry, Country* targetCountry, int numOfArmies) {
    Player::fortify(sourceCountry, targetCountry, numOfArmies);
}

void Human::attack(Deck* deck) {
    Player::attack(deck);
}