#include "Player.h"

int Player::nextID = 1;
Player::Player() {
	name = "";
	id = nextID;
	nextID++;
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
	id = nextID;
	nextID++;
	unplaced_armies = 0;
	hand = new Hand(5);
	dices = new DiceRollingFacility();
}

Player::Player(string n, vector<Country*> c) {
	name = n;
	id = nextID;
	nextID++;
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

void Player::addArmies(int newArmies) {
	unplaced_armies = newArmies;
}

vector<Country*> Player::getCountries() {
	return countries;
}

Country* Player::getCountry(string name) {
	for (Country* country : countries) {
		if (country -> getName() == name) {
			return country;
		}
	}
	return NULL;
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
			//TODO: update new country's owner
			countries.erase(countries.begin() + i);
			break;
		}
	}
}

// for demo purposes
void Player::rollDie() {
	dices->throwDie(3);
	dices->printDiceRollHistory();
}

void Player::showCards() {
	hand->PrintHand();
}

int Player::getID()
{
	return id;
}

void Player::attack()
{
	char response;
	cout << "Do you wish to attack during this turn Player " << id << " (Y/y to continue)?" << endl;
	cin >> response;
	if(toupper(response) == 'Y')
	{
		updateAttack();
		attackProcedure();
	}
	cout << "End of the attack phase.";
}

void Player::updateAttack()
{
	//cout << "***********" << id << "***********"<<endl;
	vector<Country*> borderingCountries;
	bool isAdded = false;
	for(int i = 0; i < countries.size();i++)
	{
		isAdded = false;
		borderingCountries = countries.at(i)->getBorderingCountries();
		for(int j = 0;j < borderingCountries.size();j++)
		{
			// add attack possibility if the player isn't the owner
			if(id != borderingCountries.at(j)->getOwner()->getID())
			{
				//add attack base country 
				if(!isAdded)
				{
					attackBase.push_back(countries.at(i));
					isAdded = true;
				}
				//add country if it is unique
				if(!isContained(borderingCountries.at(j),attackPossibilities))
					attackPossibilities.push_back(borderingCountries.at(j));
				//cout << borderingCountries.at(j)->getName()<< " " << borderingCountries.at(j)->getOwner()->getName() << endl;
			}
		}
	}
}

void Player::attackProcedure()
{
	cout << "Select which country you would like to attack" << endl;
	cout << "Input Index | Country Name | Owner" << endl;
	cout << endl;

	for(int i = 0;i < attackPossibilities.size();i++)
	{
		cout << i+1  << " | " << attackPossibilities.at(i)->getName() << " | " << attackPossibilities.at(i)->getOwner()->getID() << endl;
	}
}
bool Player::isContained(Country* possibility, vector<Country*> countries)
{
	for(int i = 0; i < countries.size();i++)
	{
		if(possibility->getName() == countries.at(i)->getName())
			return true;
	}
	return false;
}