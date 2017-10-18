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

void Fortification::fortify(Player* player, string sourceCountry, string targetCountry, int numOfArmies) {
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
			verifyNumOfArmies(player, sourceCountry, numOfArmies)) {
		Country* playerSourceCountry = player -> getCountry(sourceCountry);
		Country* playerTargetCountry = player -> getCountry(targetCountry);

		cout << player -> getName() + " is fortifying " + targetCountry + "'s " +
				to_string(playerTargetCountry -> getArmies()) + " army/armies with " +
				to_string(numOfArmies) + " of " + sourceCountry + "'s " +
				to_string(playerSourceCountry -> getArmies()) + " armies." << endl;

		playerSourceCountry -> removeArmies(numOfArmies);
		playerTargetCountry -> addArmies(numOfArmies);
	}
}

bool Fortification::verifyTargetCountry(Player* player, string sourceCountry, string targetCountry) {
	Country* playerSourceCountry = player -> getCountry(sourceCountry);
	Country* playerTargetCountry = player -> getCountry(targetCountry);

	// verify ownership
	if (playerSourceCountry == NULL || playerTargetCountry == NULL) {
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

	queue.push(playerSourceCountry);

	while (!queue.empty()) {
		Country* currentCountry = queue.front();
		queue.pop();
		visitedCountries[currentCountry] = true;

		if (currentCountry == playerTargetCountry)
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

bool Fortification::verifyNumOfArmies(Player* player, string sourceCountry, int numOfArmies) {
	int sourceCountryNumOfArmies = player -> getCountry(sourceCountry) -> getArmies();

	if (sourceCountryNumOfArmies - numOfArmies < 1) {
		cout << "Not enough armies to move." << endl;
		return false;
	}

	return true;
}

