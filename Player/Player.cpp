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
	double raw, fractpart, intpart;
	bool good = false;
	int input;
	cout << "Input Index\t| Country Name\t| Armies" << endl;
	cout << endl;

	for(int i = 0;i < attackBase.size();i++)
	{
		cout << i+1  << "\t| " << attackBase.at(i)->getName() << "\t| " << attackBase.at(i)->getArmies() << endl;
	}
	cout << "Select which country you would like to attack from" << endl;
	do
	{
		good = validateNumericInput(input, 1, attackBase.size());
	}
	while(!good);
	cout << "Attacking From " << attackBase.at(input-1)->getName() << endl;
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
bool Player::validateNumericInput(int& input,int lower, int upper)
{
	double raw, fractpart, intpart;
	cin >> raw;
	if(cin)
	{
		fractpart = modf (raw, &intpart);
		input = (int)intpart;
		if(fractpart != 0)
		{
			cout << "Invalid Input! Number not integer" << endl;
			return false;
		}
	}
	// or if(cin.fail())
	if(!cin)
	{
		cout << "Invalid Input! Number not numeric" << endl;
		// reset failbit
		cin.clear(); 
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		return false;
	}
	else if(input < lower || input > upper)
	{
		cout << "Invalid Input! Number out of range" << endl;
		return false;
	}
	else
	{
		return true;
	}
}