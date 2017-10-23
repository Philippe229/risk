/*
 * Card.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: dylanfernandes
 */

#include "Card.h"

Card::Card(cardType c) {
	this->val = c;
}

Card::Card(cardType c, string t) {
	this->val = c;
	this->territory = t;
}

string Card::getTerritory() {
	return this->territory;
}

Card::cardType Card::getCardVal() {
	return this->val;
}

