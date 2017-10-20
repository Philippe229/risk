/*
 * Hand.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: dylanfernandes
 */

#include "Hand.h"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

Hand::Hand(int max) {
	maxCards = max;
	numCards = 0;
	// 3 cards needed to get armies
	exchange = 3;

}

void Hand::getCard(Card c) {
	cards.push_back(c);
	numCards++;
}

void Hand::PrintHand() {
	cout << "Current Hand" << endl;
	cout << "************" << endl;
	for (int i = 0; i < maxCards; i++) {
		if (!cards.empty() && i < cards.size()) {
			Card::cardType t;
			t = cards.at(i).getCardVal();
			string type;
			if (t == Card::Infantry)
				type = "Infantry";
			if (t == Card::Artillery)
				type = "Artillary";
			if (t == Card::Cavalry)
				type = "Cavalry";
			cout << "Card Slot " << i + 1 << ": " << type << endl;
		} else {
			cout << "Card Slot " << i + 1 << ": Empty Slot" << endl;
		}
	}
}

bool Hand::positionTaken(int position, int exchanges[]) {
	for (int i = 0; i < exchange; i++) {
		if (exchanges[i] == position)
			return false;
	}
	return true;
}
// if true, units will be given to player in the main driver
int Hand::verifyInput(int numIteration, int exchanges[]) {
	bool notGood = true;
	double raw, fractpart, intpart;
	int input;
	do {
		cout << "Select Card " << numIteration << ": ";
		cin >> raw;
		// handle decimal input
		if (cin) {
			fractpart = modf(raw, &intpart);
			input = (int) intpart;
			if (fractpart != 0) {
				cout << "Invalid Input! Number not integer" << endl;
				continue;
			}
		}
		// or if(cin.fail())
		if (!cin) {
			cout << "Invalid Input! Number not numeric" << endl;
			// reset failbit
			cin.clear();
			// skip bad input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else if (input < 1 || input > maxCards) {
			cout << "Invalid Input! Number out of range" << endl;
		} else if (!positionTaken(input, exchanges)) {
			cout << "Invalid Input! Number already selected" << endl;
		} else {
			for (int i = 0; i < exchange; ++i) {
				if (exchanges[i] == -1) {
					exchanges[i] = input;
					break;
				}
			}
			notGood = false;
		}
	} while (notGood);
	return input;
}
bool Hand::SelectExchange() {
	// set exchange as not assigned
	int exchanges[3] = { -1, -1, -1 };
	int card1;
	int card2;
	int card3;
	PrintHand();
	if (numCards >= 3) {
		cout << "Select the three cards you wish to exchange" << endl;
		card1 = verifyInput(1, exchanges);
		card2 = verifyInput(2, exchanges);
		card3 = verifyInput(3, exchanges);
		if (VerifyExchange(card1, card2, card3)) {
			// to erase latter elements first
			if (card2 < card3)
				swap(card2, card3);
			if (card1 < card2)
				swap(card1, card2);
			if (card2 < card3)
				swap(card2, card3);
			cards.erase(cards.begin() + card1 - 1);
			cards.erase(cards.begin() + card2 - 1);
			cards.erase(cards.begin() + card3 - 1);
			cout << "Successful exchange." << endl;
			return true;
		} else {
			cout << "Invalid exchange." << endl;
		}
	} else
		cout << "Not enough cards in hand to exchange" << endl;
	return false;
}

bool Hand::VerifyExchange(int c1, int c2, int c3) {
	// index starts at 0
	Card::cardType type1 = cards.at(c1 - 1).getCardVal();
	Card::cardType type2 = cards.at(c2 - 1).getCardVal();
	Card::cardType type3 = cards.at(c3 - 1).getCardVal();

	// same card type
	if (type1 == type2 && type2 == type3) {
		return true;
	}
	// unique card type
	if (type1 != type2 && type1 != type3 && type2 != type3) {
		return true;
	}
	return false;
}

