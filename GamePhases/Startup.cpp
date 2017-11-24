#include "Startup.h"

using namespace std;

int Startup::getUserInputInteger(string output, int min, int max) {
    string inputString;
	int input;
	bool failFlag;
	
	cout << output;
	cin >> inputString;
	
	try {
		input = stoi(inputString);
		failFlag = false;
	} catch (invalid_argument e) {
		failFlag = true;
	}

	// While the input is invalid
	while (input < min || input > max || cin.fail() || failFlag || inputString.find(".") != string::npos) {
        if (input == -1) {
            cout << "Quitting..." << endl;
            exit(1);   
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;

        if (inputString.find(".") == string::npos) {
            cout << "Must be greater than " << min - 1 << " and less than " << max + 1 << " and must be an integer" << endl;
        } else {
            cout << "Must be an integer" << endl;
        }
        cout << "Try again (-1 to quit): ";
		cin >> inputString;
		
		try {
			input = stoi(inputString);
			failFlag = false;
		} catch (invalid_argument e) {
			failFlag = true;
		}
    }

    return input;
}

void Startup::clearScreen() {
    cout << string(100, '\n');
}

// Pretty print all the player's countries, their bordering countries, and the amount of armies in them
void Startup::displayPlayersCountriesAndArmies(Player* thePlayer) {
    printf("%3s | %25s | %6s | %25s | %6s\n", "Num", "Country Owned", "Armies", "Bordering Countries", "Armies");
    for (int i = 0; i < thePlayer->getCountries().size(); i++) {
        Country* currCountry = thePlayer->getCountries()[i];
        printf("%3i | %25s | %6i | ", i + 1, currCountry->getName().c_str(), currCountry->getArmies());

        for (int j = 0; j < currCountry->getBorderingCountries().size(); j++) {
            Country* bordering = currCountry->getBorderingCountries()[j];
            if (j == 0) {
                printf("%25s | %6i\n", bordering->getName().c_str(), bordering->getArmies());
            } else {
                printf("%3s | %25s | %6s | %25s | %6i\n", "", "", "", bordering->getName().c_str(), bordering->getArmies());
            }
        }
    }
}

Startup::Startup(vector<Player*> players, Map* map) {
        playerOrder = players;
        currMap = map;
        randomPlayerOrder();
        assignCountries();
        assignArmiesAI();
}

Startup::Startup(vector<Player*> players, Map* map, bool quickStart) {
	if (!quickStart) {
		Startup(players, map);
	} else {
		playerOrder = players;
		currMap = map;
		randomPlayerOrder();

		// Assign countries randomly
		size_t countriesAssigned = 0;
		int playerIndex = 0;

		while (countriesAssigned < currMap -> getCountries().size()) {
			int countryIndex = rand() % currMap -> getCountries().size();
			if (currMap -> getCountries()[countryIndex] -> getOwner() == NULL) {
				countriesAssigned += 1;
	            currMap -> getCountries()[countryIndex] -> setOwner(playerOrder[playerIndex]);
	            playerOrder[playerIndex] -> addCountry(currMap -> getCountries()[countryIndex]);
	            playerIndex = (playerIndex + 1) % playerOrder.size();
			}
		}

		// Spread player armies evenly
	    int numArmies[6] = {0, 40, 35, 30, 25, 20};

	    for (Player* player : playerOrder) {
	    	vector<Country*> playerCountries = player -> getCountries();
	    	size_t countryIndex = 0;
	    	int armiesToPlace = numArmies[playerOrder.size() - 1];

	    	while (armiesToPlace > 0) {
	    		playerCountries[countryIndex] -> addArmies(1);
	    		armiesToPlace--;
	    		if (countryIndex + 1 == playerCountries.size())
	    			countryIndex = 0;
	    		else
	    			countryIndex++;
	    	}
	    }
	}
}

// Choose a random player order
void Startup::randomPlayerOrder() {
    cout << endl << "*ASSIGNING RANDOM ORDER*" << endl;

    // Swap random player indexes 100 times
    for (int i = 0; i < 100; i++) {
        int swapIndexOne = rand() % playerOrder.size();
        int swapIndexTwo = rand() % playerOrder.size();

        Player* tempPlayer = playerOrder[swapIndexOne];
        playerOrder[swapIndexOne] = playerOrder[swapIndexTwo];
        playerOrder[swapIndexTwo] = tempPlayer;
    }

    cout << endl << "Current player order: " << endl;
    for (int i = 0; i < playerOrder.size(); i++) {
        cout << (i + 1) << ": " << playerOrder[i]->getID() << endl;
    }
}

// Give countries to players randomly in a round robin fashion
void Startup::assignCountries() {
    cout << endl << "*ASSIGNING RANDOM COUNTRIES TO PLAYERS*" << endl;
    int numCountriesAssigned = 0;
    int currPlayerIndex = 0;

    // Pick a random country, if it's not taken give it to the proper player
    while (numCountriesAssigned < currMap->getCountries().size()) {
        int countryIndexToAssign = rand() % currMap->getCountries().size();

        if (currMap->getCountries()[countryIndexToAssign]->getOwner() == NULL) {
            numCountriesAssigned += 1;

            currMap->getCountries()[countryIndexToAssign]->setOwner(playerOrder[currPlayerIndex]);
            playerOrder[currPlayerIndex]->addCountry(currMap->getCountries()[countryIndexToAssign]);
            currPlayerIndex = (currPlayerIndex + 1) % playerOrder.size();
        }
    }
    
    // Pretty print all the countries assigned
    cout << endl << "Current countries assigned: " << endl;
    for (int i = 0; i < playerOrder.size(); i++) {
        cout << endl << playerOrder[i]->getName() << "(" << playerOrder[i]->getCountries().size() << " countries): " << endl;
        for (int j = 0; j < playerOrder[i]->getCountries().size(); j++) {
            cout << playerOrder[i]->getCountries()[j]->getName() << endl;
        }
    }
}

// Get user input for assigning intial armies to countries
void Startup::assignArmies() {
    cout << endl << "*ASSIGNING ARMIES TO COUNTRIES*" << endl;
    int numArmies[6] = {0, 40, 35, 30, 25, 20};
    int totalTokens = numArmies[playerOrder.size() - 1] * playerOrder.size();
    int currPlayerIndex = 0;
    map<string, int> playerArmies;

    for (int i = 0; i < playerOrder.size(); i++) {
        playerArmies[playerOrder[i]->getName()] = numArmies[playerOrder.size() - 1];
    }

    // Assign one army to every country
    for (int i = 0; i < currMap->getCountries().size(); i++) {
        currMap->getCountries()[i]->addArmies(1);
        totalTokens -= 1;

        playerArmies[currMap->getCountries()[i]->getOwner()->getName()] -= 1;
    }

    // While players still have army tokens keep placing armies
    while (totalTokens > 0) {
        Player* currPlayersTurn = playerOrder[currPlayerIndex];

        // If the player still has armies to place
        if (playerArmies[currPlayersTurn->getName()] > 0) {
            cout << endl << "Current player to place an army unit (" << playerArmies[currPlayersTurn->getName()] << " left): " << currPlayersTurn->getName() << endl;
            displayPlayersCountriesAndArmies(currPlayersTurn);
            int countryNumber = getUserInputInteger("Your choice (-1 to quit): ", 1, currPlayersTurn->getCountries().size());
            currPlayersTurn->getCountries()[countryNumber - 1]->addArmies(1);
            totalTokens -= 1;
            playerArmies[currPlayersTurn->getName()] -= 1;
        }

        // Move to the next player in the order
        currPlayerIndex = (currPlayerIndex + 1) % playerOrder.size();
    }
}

void Startup::assignArmiesAI() {
    cout << endl << "*ASSIGNING ARMIES TO COUNTRIES*" << endl;
    int numArmies[6] = {0, 40, 35, 30, 25, 20};
    int totalTokens = numArmies[playerOrder.size() - 1] * playerOrder.size();
    int currPlayerIndex = 0;
    map<string, int> playerArmies;

    for (int i = 0; i < playerOrder.size(); i++) {
        playerArmies[playerOrder[i]->getName()] = numArmies[playerOrder.size() - 1];
    }

    // Assign one army to every country
    for (int i = 0; i < currMap->getCountries().size(); i++) {
        currMap->getCountries()[i]->addArmies(1);
        totalTokens -= 1;

        playerArmies[currMap->getCountries()[i]->getOwner()->getName()] -= 1;
    }
}

vector<Player*> Startup::getPlayerOrder() {
    return playerOrder;
}
