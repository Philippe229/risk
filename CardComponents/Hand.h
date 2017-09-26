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

class Hand {
public:
	Hand(int);
	// virtual ~Hand();
	bool SelectExchange();
	int verifyInput(int,int[]);
	bool VerifyExchange(int, int, int);
	void PrintHand();
	void getCard(Card);
private:
	bool positionTaken(int, int[]);
	vector<Card> cards;
	int numCards;
	int maxCards;
	int exchange;
};

#endif /* HAND_H_ */
