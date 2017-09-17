/*
 * Card.h
 *
 *  Created on: Sep 17, 2017
 *      Author: dylanfernandes
 */

#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

class Card {
public:
	enum cardType {Infantry, Artillery, Cavalry};
	Card();
	Card(cardType, string);
	cardType getCardVal();
	string getTerritory();
	virtual ~Card();
private:
	cardType val;
	string territory;
};

#endif /* CARD_H_ */
