#include "../Player/Player.h"
#include "../Reinforcement/Reinforcement.h"
#include "../Fortification/Fortification.h"
#include "../Attack/Attack.h"

int Player::nextID = 1;
Player::Player() {
	name = "";
	id = nextID;
	nextID++;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
	gameStatsObserver = NULL;
}

Player::~Player(void) {
	delete dices;
	delete hand;
}

Player::Player(string n) {
	name = n;
	id = nextID;
	nextID++;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
	gameStatsObserver = NULL;
}

Player::Player(string n, vector<Country*> c) {
	name = n;
	id = nextID;
	nextID++;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
	countries = c;
	gameStatsObserver = NULL;
}

string Player::getName() {
	return name;
}

int Player::getArmies() {
	return unplaced_armies;
}

int Player::getPlacedArmies() {
	int placedArmies = 0;
	for(int i = 0; i < countries.size();i++) {
		placedArmies += countries.at(i)->getArmies();
	}
	return placedArmies;
}
Hand* Player::getHand() {
	return hand;
}

DiceRollingFacility* Player::getDiceFacility() {
	return dices;
}

void Player::addArmies(int newArmies) {
	unplaced_armies = newArmies;
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
	for (size_t i = 0; i < countries.size(); i++) {
		if (countries[i] == c) {
			countries.erase(countries.begin() + i);
			break;
		}
	}
}

vector<int> Player::rollDie(int numDie) {
	vector<int> results = dices->throwDie(numDie);
	sort (results.begin(), results.begin()+results.size());
	return results;
}

void Player::showCountries() {
	cout << "**********Player " << id << " Countries**********" << endl;
	cout << "Country Name|Armies" << endl;
	for (int i = 0;i < countries.size();i++) {
		cout << countries.at(i)->getName() << "|" << countries.at(i)->getArmies() << endl;
	}
}

int Player::getID() {
	return id;
}

void Player::saveGameStats(GameStatsObserver* stats) {
	gameStatsObserver = stats;
}

GameStatsObserver* Player::getGameStats() {
	return gameStatsObserver;
}
