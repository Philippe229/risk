/*
 * Card.h
 *
 *  Created on: Sep 17, 2017
 *      Author: dylanfernandes
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Card {
public:
	enum cardType {
		Infantry, Artillery, Cavalry
	};
	Card(cardType);
	Card(cardType, string);
	cardType getCardVal();
	string getTerritory();
private:
	cardType val;
	string territory;
	map<int, string> enumName;
};

#endif /* CARD_H_ */
