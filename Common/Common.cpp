#include "Common.h"

void Common::displayPlayersCountriesAndArmies(Player* thePlayer) {
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

int Common::getUserInputIntegerInRange(string output, int min, int max) {
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

string Common::getUserInputStringTwoChoices(string output, string choice1, string choice2) {
    string input;

    cout << output;
    cin >> input;

    // While the input is invalid
    while ((input != choice1 && input != choice2) || cin.fail() || input == "q" || input == "Q") {
        if (input == "q" || input == "Q") {
            cout << "Quitting..." << endl;
            exit(1);   
        }

        // Clear the stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        cout << "Must be " << choice1 << " or " << choice2 << " and must be a string" << endl;
        cout << "Try again ('q' to quit): ";
        cin >> input;
    }

    return input;
}

void Common::clearScreen() {
    cout << string(100, '\n');
}

bool Common::validateNumericInput(int& input, int lower, int upper) {
	double raw, fractpart, intpart;
	cin >> raw;
	if (cin) {
		fractpart = modf(raw, &intpart);
		input = (int) intpart;
		if (fractpart != 0) {
			cout << "Invalid Input! Number not integer" << endl;
			return false;
		}
	}
	// or if(cin.fail())
	if (!cin) {
		cout << "Invalid Input! Number not numeric" << endl;
		// reset failbit
		cin.clear();
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} else if (input < lower || input > upper) {
		cout << "Invalid Input! Number out of range" << endl;
		cin.clear();
		// skip bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} else
		return true;
}