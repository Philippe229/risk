#include "Player.h"

Player::Player() {
	player_name = "John F. Kennedy";
}

Player::~Player(void) {

}

Player::Player(string n) {
	player_name = n;
}

string Player::getName() {
	return player_name;
}
