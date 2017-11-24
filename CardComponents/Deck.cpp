/*
 * Deck.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: dylanfernandes
 */

#include "Deck.h"
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

Deck::Deck(int numCountries) {
	size = numCountries;
	// set the number of cards for each according to the number of countries
	numInfantry = numCountries / 3;
	numArtillery = numCountries / 3;
	numCavalry = numCountries / 3;
	size = numInfantry + numArtillery + numCavalry;
	int random;

	int maxInf = numInfantry;
	int maxArt = numArtillery;
	int maxCavalry = numCavalry;

	for (int i = 0; i < size; i++) {
		// set the type of card randomly
		random = rand() % 3;
		if (random == 0 && maxInf > 0) {
			cards.push_back(Card(Card::Infantry));
			maxInf--;
		} else if (random == 1 && maxArt > 0) {
			cards.push_back(Card(Card::Artillery));
			maxArt--;
		} else if (random == 2 && maxCavalry > 0) {
			cards.push_back(Card(Card::Cavalry));
			maxCavalry--;
		} else {
			i--;
		}
	}
}
Card Deck::Draw() {
	if (!cards.empty()) {
		Card draw = cards.back();
		cards.pop_back();
		Card::cardType type = draw.getCardVal();
		
		if (type == Card::Infantry) {
			numInfantry--;
		} else if (type == Card::Artillery) {
			numArtillery--;
		} else {
			numCavalry--;
		}

		return draw;
	} else {
		cout << "The deck is empty\n";
	}
	exit(EXIT_FAILURE);
}
void Deck::PrintStatistics() {
	cout << "Deck Statistics" << endl;
	cout << "***************" << endl;
	cout << "Number of Infantry: " << numInfantry << "\n";
	cout << "Number of Artillery: " << numArtillery << "\n";
	cout << "Number of Cavalry: " << numCavalry << "\n";
}

int Deck::getNumberCards() {
	return cards.size();
}
