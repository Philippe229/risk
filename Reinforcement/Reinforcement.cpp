#include "Reinforcement.h"

int Reinforcement::staticBonusArmies = 0;

int Reinforcement::getTotalBonusArmies(Player* player, vector<Continent*> continents) {
	int bonusArmies = 0;
	
	// calculate # of reinforcements
	bonusArmies += getCountryBonus(player);
	bonusArmies += getContinentBonus(player, continents);
	bonusArmies += getMaxCardBonus(player);

	return bonusArmies;
}

void Reinforcement::reinforcement(Player* player, Country* country, int numArmies) {
	notify(player, "Reinforcement", "");

	if (numArmies <= staticBonusArmies) {
		if (player == NULL) {
			cout << "Invalid player." << endl;
			return;
		}

		if (country == NULL) {
			cout << "Invalid country." << endl;
			return;
		}
	
		if (numArmies < 1) {
			cout <<"Need one or more armies to move." << endl;
			return;
		}

		country->addArmies(numArmies);
		staticBonusArmies -= numArmies;

		cout << player->getName() << " reinforced " << country->getName()
				<< " with " << numArmies << " armies.... " << staticBonusArmies << " remaining bonus armies to place." << endl;
	} else {
		cout << "Not enough armies to place." << endl;
	}
}

void Reinforcement::playerReinforcement(Player* player, vector<Continent*> continents) {

	notify(player, "Reinforcement", "");

	int bonusArmies = 0;

	// calculate # of reinforcements
	bonusArmies += getCountryBonus(player);
	cout << "Bonus armies;\nCountry Bonus: +" << bonusArmies << endl;
	int temp = bonusArmies;
	bonusArmies += getContinentBonus(player, continents);
	cout << "Continent Bonus: +" << bonusArmies - temp << endl;
	temp = bonusArmies;
	bonusArmies += getCardBonus(player);
	cout << "Card Bonus: +" << bonusArmies - temp << endl;

	// place reinforcements
	do {
		int numberOfCountries = player->getCountries().size();
		cout << "Selection"  << "\t| " << "Country name" << "\t| " << "Number of armies" << endl;
		for(int i=0; i < numberOfCountries; i++) {
			cout << i+1  << "\t| " << player->getCountries().at(i)->getName() << "\t| " << player->getCountries().at(i)->getArmies() << endl;
		}

		cout << "Select which country you would like to reinforce" << endl;
		int country;
		do {
			cin >> country;
			if(country < 0 || numberOfCountries < country) {
				cout << "Select valid number" << endl;
			}
		} while (country < 0 || numberOfCountries < country);

		cout << "You have " << bonusArmies << " unplaced armies" << endl;
		cout << "How many armies would you like to add to: " << player->getCountries().at(country-1)->getName() << endl;

		int number;
		do {
			cin >> number;
			if(number < 0 || bonusArmies < number) {
				cout << "Select valid number" << endl;
			}
		} while (number < 0 || bonusArmies < number);

		Country* targetCountry = player -> getCountries().at(country - 1);
		string message = "Reinforcing " + targetCountry -> getName() + "'s " +
				to_string(targetCountry -> getArmies()) + " armies with " +  to_string(number) + " armies.";
		notify(player, "Reinforcement", message);

		bonusArmies -= number;
		player->getCountries().at(country-1)->addArmies(number);

	} while (bonusArmies > 0);
}

int Reinforcement::getCountryBonus(Player* player) {
	return player->getCountries().size() / 3;
}

int Reinforcement::getContinentBonus(Player* player, vector<Continent*> continents) {
	int bonusPoints = 0;
	// iterate array of continents
	for (size_t continentIndex = 0; continentIndex < continents.size(); continentIndex++) {
		size_t check = 0; // used to check if player owns a country
		Continent* currContinent = continents[continentIndex];
		vector<Country*> continentsCountries = currContinent->getCountries();
		// iterate countries of current continent
		for (size_t countryIndex = 0; countryIndex < continentsCountries.size(); countryIndex++) {
			Country* currCountry = continentsCountries[countryIndex];

			if (currCountry->getOwner() == player) {
				check++; // player owns the country
			} else {
				break; // someone else owns a country in continent: no bonus
			}
		}
		// check if player owns all countries of continent
		if (check == currContinent->getCountries().size()) {
			bonusPoints += currContinent->getWorth();
		}
	}

	return bonusPoints;
}

int Reinforcement::getCardBonus(Player* player) {
	int numberOfCards = player->getHand()->getNumberOfCards();
	
	if (numberOfCards < 3) {
		return 0;
	}

	if (numberOfCards == 5) {
		cout << "You have " << numberOfCards << " cards you need to exchange them" << endl;
		return player->getHand()->SelectExchange();
	} else {
		cout << "You have " << numberOfCards << " cards would you like to view them? (y/n)";
		string answer;
		cin >> answer;
		if (answer == "y" || answer == "Y") {
			return player->getHand()->SelectExchange();
		} else {
			return 0;
		}
	}

	return 0;
}

int Reinforcement::getMaxCardBonus(Player* player) {
	return player->getHand()->getAnyExchange();
}
