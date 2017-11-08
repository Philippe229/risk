/*
 * Hand.h
 *
 *  Created on: Sep 20, 2017
 *      Author: dylanfernandes
 */

#ifndef HAND_H_
#define HAND_H_

#include "Card.h"
#include <vector>
#include <map>
#include <string>

class Hand {
public:
	Hand(int);
	int SelectExchange();
	int verifyInput(int, int[]);
	bool VerifyExchange(int, int, int);
	void PrintHand();
	void getCard(Card);
	int getNumberOfCards();
	int getAnyExchange();

private:
	bool positionTaken(int, int[]);
	vector<Card> cards;
	int numCards;
	int maxCards;
	int exchange;
	int exchangeMultiplier; // track number of exchanges done by player
};

#endif /* HAND_H_ */
