#include "Player.h"

Player::Player() {
	name = "";
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
}

Player::~Player(void) {
	delete dices;
	delete hand;
}

Player::Player(string n) {
	name = n;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
}

Player::Player(string n, vector<Country*> c) {
	name = n;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
	countries = c;
}

string Player::getName() {
	return name;
}

int Player::getArmies() {
	return unplaced_armies;
}

vector<Country*> Player::getCountries() {
	return countries;
}

void Player::addArmiesToCountry(int n, Country* c) {
	if (n <= unplaced_armies && c->getOwner() == this) {
		c->addArmies(n);
		unplaced_armies -= n;
	}
}

void Player::removeArmiesFromCountry(int n, Country* c) {
	if (n <= unplaced_armies && c->getOwner() == this) {
		c->removeArmies(n);
		unplaced_armies += n;
	}
}

void Player::addCountry(Country* c) {
	countries.push_back(c);
}

void Player::removeCountry(Country* c) {
	for (auto& country : countries) {
		if (country == c) {
			//TODO: update new country's owner
			countries.erase(
					countries.begin() + (&country - &*(countries.begin())));
			break;
		}
	}
}

void Player::reinforce() {
	unplaced_armies += (countries.size() / 3); // # countries bonus
	if (hand->SelectExchange()) {
		unplaced_armies++; // hardcoded for demo
	}
	this->addArmiesToCountry(unplaced_armies, countries[0]); // hardcoded for demo
}

void Player::attack() {
	dices->throwDie(3);
	dices->printDiceRollHistory();
}

void Player::fortify() {
	this->addArmiesToCountry(unplaced_armies, countries[0]);
}
