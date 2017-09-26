#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>

using namespace std;

class Player {

private:
	string player_name;

public:
	Player();
	~Player();
	Player(string name);
	string getName();
};

#endif
