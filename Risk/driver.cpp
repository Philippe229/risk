/*
 * driver.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: dylanfernandes
 */
#include "Deck.h"
#include "Hand.h"
#include <iostream>
using namespace std;

const int COUNTRIES = 60;
const int HANDSIZE = 5;
int armies = 5;
int playerArmies = 0;
int main (int argc, char *argv[])
{
	cout << "Here" << endl;
	Deck myDeck = Deck(COUNTRIES);
	Hand myHand = Hand(HANDSIZE);
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	if(myHand.SelectExchange())
	{
		playerArmies = playerArmies + armies;
		cout << "Player now has " << playerArmies << " armies" << endl;
		armies++;

	}
	myDeck.PrintStatistics();
	myHand.PrintHand();
}
