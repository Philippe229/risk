/*
 * Fortification.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Philippe
 */

#include <iostream>
#include <queue>
#include "Fortification.h"

using namespace std;

void Fortification::startFortify(Player* player) {
	notify(player, "Fortification", "");
}

void Fortification::fortify(Player* player, Country* sourceCountry, Country* targetCountry, int numOfArmies) {
	if (player == NULL) {
		cout << "Invalid player." << endl;
		return;
	}

	if (sourceCountry == targetCountry) {
		cout << "Target country is the same as source country. No need to move armies." << endl;
		return;
	}

	if (numOfArmies < 1) {
		cout <<"Need one or more armies to move." << endl;
		return;
	}

	if (verifyTargetCountry(player, sourceCountry, targetCountry) &&
			verifyNumOfArmies(sourceCountry, numOfArmies)) {

		string message = "Fortifying " + targetCountry -> getName() + "'s " +
				to_string(targetCountry -> getArmies()) + " army/armies with " +
				to_string(numOfArmies) + " of " + sourceCountry -> getName() + "'s " +
				to_string(sourceCountry -> getArmies()) + " armies.";

		notify(player, "Fortification", message);

		sourceCountry -> removeArmies(numOfArmies);
		targetCountry -> addArmies(numOfArmies);
	}
}

bool Fortification::verifyTargetCountry(Player* player, Country* sourceCountry, Country* targetCountry) {
	vector<Country*> playerCountries = player -> getCountries();
	// verify ownership
	if(find(playerCountries.begin(), playerCountries.end(), sourceCountry) == playerCountries.end() ||
			find(playerCountries.begin(), playerCountries.end(), targetCountry) == playerCountries.end()) {
		cout << "One of the countries does not belong to the player." << endl;
		return false;
	}

	// verify link between countries with BFS
	queue<Country*> queue;
	vector<Country*> borderingCountries;
	map<Country*, bool> visitedCountries;

	for (Country* playerCountry : player -> getCountries()) {
		visitedCountries.insert({playerCountry, false});
	}

	queue.push(sourceCountry);

	while (!queue.empty()) {
		Country* currentCountry = queue.front();
		queue.pop();
		visitedCountries[currentCountry] = true;

		if (currentCountry == targetCountry)
			return true;

		borderingCountries = currentCountry -> getBorderingCountries();

		for (Country* borderingCountry : borderingCountries) {
			if (borderingCountry -> getOwner() == player && !visitedCountries[borderingCountry])
				queue.push(borderingCountry);
		}
	}

	cout << "No path found between countries." << endl;

	return false;
}

bool Fortification::verifyNumOfArmies(Country* sourceCountry, int numOfArmies) {
	int sourceCountryNumOfArmies = sourceCountry -> getArmies();

	if (sourceCountryNumOfArmies - numOfArmies < 1) {
		cout << "Not enough armies to move." << endl;
		return false;
	}

	return true;
}

