#include "Player.h"

Player::Player() {
	player_name = "John F. Kennedy";
	dices = new DiceRollingFacility();
	hand = new Hand(0);
}

Player::~Player(void) {
	delete dices;
}

Player::Player(string n) {
	player_name = n;
	dices = new DiceRollingFacility();
	hand = new Hand(0);
}

Player::Player(string n, vector<Country*> c) {
	player_name = n;
	dices = new DiceRollingFacility();
	hand = new Hand(0);
	countries = c;
}

string Player::getName() {
	return player_name;
}

vector<Country*> Player::getCountries() {
	return countries;
}

Hand* Player::getHand() {
	return hand;
}

void Player::addCountry(Country* c) {
	countries.push_back(c);
}

void Player::setHand(Hand* h) {
	hand = h;
}

void Player::reinforce() {
	cout << to_string(countries.size() / 3) << endl;

}

void Player::attack() {
	dices->throwDie(2);
	dices->printDiceRollHistory();
}

void Player::fortify() {

}
