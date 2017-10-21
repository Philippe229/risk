#include <iostream>
#include <map>
#include "Reinforcement.h"

using namespace std;

void Reinforcement::reinforcement(Player* player, vector<Continent*> continents) {

	int bonusArmies = 0;

	// calculate # of reinforcements
	bonusArmies += getCountryBonus(player);
	bonusArmies += getContinentBonus(player, continents);
	bonusArmies += getCardBonus(player);

	// place reinforcements
	do {
		for (auto& country : player->getCountries()) {
			int choice;
			if (bonusArmies == 0)
				break;

			cout << "You have " << bonusArmies << " armies to place" << endl;
			cout << "How many armies do you want to place in: "
					<< country->getName() << " (which " << country->getArmies()
					<< " armies)" << endl;

			do {
				cin >> choice;
				if (choice < 0 || bonusArmies < choice) {
					cout << "Please enter a number between 0 and "
							<< bonusArmies << endl;
				}
			} while (choice < 0 || bonusArmies < choice);

			country->addArmies(choice);
			bonusArmies -= choice;

			cout << country->getName() << " now has " << country->getArmies()
					<< " armies" << endl;
		}
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
	if(numberOfCards < 3) {
		return 0;
	}
	if(numberOfCards == 5) {
		cout << "You have " << numberOfCards << " cards you need to exchange them" << endl;
		return player->getHand()->SelectExchange();
	} else {
		cout << "You have " << numberOfCards << " cards would you like to view them? (y/n)";
		string answer;
		cin >> answer;
		if(answer == "y" || answer == "Y") {
			return player->getHand()->SelectExchange();
		} else {
			return 0;
		}
	}
	return 0;
}
