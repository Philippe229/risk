/*
 * driver.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: dylanfernandes
 */
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int COUNTRIES = 60;
const int HANDSIZE = 5;
int armies = 5;
int playerArmies = 0;
int main(int argc, char *argv[]) {
	srand(time(0));

	cout << "Deck content" << endl;
	cout << "++++++++++++" << endl;
	Deck myDeck = Deck(COUNTRIES);
	Hand myHand = Hand(COUNTRIES);
	for (int i = 0; i < COUNTRIES; i++) {
		myHand.getCard(myDeck.Draw());
	}
	myDeck.PrintStatistics();
	cout << "Hand demo" << endl;
	cout << "+++++++++" << endl;
	myDeck = Deck(COUNTRIES);
	myHand = Hand(HANDSIZE);
	for (int i = 0; i < HANDSIZE; i++) {
		myHand.getCard(myDeck.Draw());
	}
	if (myHand.SelectExchange()) {
		playerArmies = playerArmies + armies;
		cout << "Player now has " << playerArmies << " armies" << endl;
		armies++;

	}
	myHand.PrintHand();
}
