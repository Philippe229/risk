#include "Initialization.h"

void Initialization::clearScreen() {
    cout << string(100, '\n');
}

// Helper function for getting user integer input
int Initialization::getUserInputInteger(string output, int min, int max) {
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

// Helper function for getting user string input
string Initialization::getUserInputString(string output, string choice1, string choice2) {
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

// Displays all the available maps
vector<string> Initialization::getAndDisplayMapOptions() {
    vector<string> mapFiles;
    DIR* directory;
    struct dirent* file;

    // Code for iterating through directories, works for Unix Operating Systems
    if ((directory = opendir(mapDirectory.c_str())) == NULL) {
        cout << "Could not open directory of maps, exiting." << endl;
        exit(1);
    } else {
        int counter = 1;
        cout << "Select a map: " << endl;
        while ((file = readdir(directory)) != NULL) {
            struct stat pathStat;
            stat((mapDirectory + file->d_name).c_str(), &pathStat);
            int is_dir = S_ISDIR(pathStat.st_mode);
            if (!is_dir) {
                cout << counter++ << ": " << file->d_name << endl;
                mapFiles.push_back(file->d_name);
            }
        }
    }

    closedir(directory);

    return mapFiles;
}

// Gets user input for choosing an available map
void Initialization::chooseMap() {
    cout << endl << "*CHOOSING MAP*" << endl;
    vector<string> mapFiles = getAndDisplayMapOptions();
    int mapNumber = getUserInputInteger("Your choice (-1 to quit): ", 1, mapFiles.size());
    MapLoader* map = new MapLoader();

    bool validMap = false;
    string error;

    // Check if it's a valid map
    try {
        map->parseMap(mapDirectory + mapFiles[mapNumber - 1]);
        validMap = true;
    } catch (invalid_argument e) {
        error = e.what();
    }

    // While it's not a valid map keep asking for the user to choose another map
    while (!validMap) {
        clearScreen();
        cout << error;
        cout << "Invalid map, choose another map: " << endl;
        getAndDisplayMapOptions();
        mapNumber = getUserInputInteger("Your choice: ", 1, mapFiles.size());

        try {
            map->parseMap(mapDirectory + mapFiles[mapNumber - 1]);
            validMap = true;
        } catch (invalid_argument e) {
            error = e.what();
        }
    }

    loadedMap = map;
}

// Gets input from the user for the amount of players that should be created
void Initialization::createPlayers() {
    cout << endl << "*CHOOSING AMOUNT OF PLAYERS*" << endl;
    cout << "Select amount of players (2 - 6): " << endl;
    int numPlayers = getUserInputInteger("Your choice (-1 to quit): ", 2, 6);
    cout << "Creating players..." << endl;

    // Create a new deck and the players
    currentDeck = new Deck(loadedMap->getMap()->getCountries().size());
    for (int i = 0; i < numPlayers; i++) {
        cout << "Created Player " << (i + 1) << "..." << endl;
        Player* currPlayer = new Human("Player " + to_string(i + 1));
        gamePlayers.push_back(currPlayer);
    }
}

Initialization::Initialization() {
    chooseMap();
    cout << endl << "Successfully chose a map, creating the game state..." << endl;
    createPlayers();
}

Initialization::Initialization(bool cPlayer) {
    chooseMap();
    cout << endl << "Successfully chose a map, creating the game state..." << endl;
    if(cPlayer)
        createPlayers();
    else
        currentDeck = new Deck(loadedMap->getMap()->getCountries().size());
}

Deck* Initialization::getDeck() {
    return currentDeck;
}

vector<Player*> Initialization::getPlayers() {
    return gamePlayers;
}

Map* Initialization::getMap() {
    return loadedMap->getMap();
}
