/*
 * driver.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: dylanfernandes
 */
#include "Deck.h"
#include "Hand.h"
const int COUNTRIES = 60;
const int HANDSIZE = 5;
int main ()
{
	Deck myDeck = Deck(COUNTRIES);
	Hand myHand = Hand(HANDSIZE);
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	myHand.getCard(myDeck.Draw());
	myHand.PrintHand();
}
