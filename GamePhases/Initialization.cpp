#include "Initialization.h"
#include <iostream>
#include <limits>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
using namespace std;

void Initialization::clearScreen() {
    cout << string(100, '\n');
}

int Initialization::getUserInputInteger(string output, int min, int max) {
    int input;

    cout << output;
    cin >> input;

    while (input < min || input > max || cin.fail()) {
        if (input == -1) {
            cout << "Quitting..." << endl;
            exit(1);   
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        cout << "Must be greater than " << min - 1 << " and less than " << max + 1 << " and must be an integer" << endl;
        cout << "Try again (-1 to quit): ";
        cin >> input;
    }

    return input;
}

string Initialization::getUserInputString(string output, string choice1, string choice2) {
    string input;

    cout << output;
    cin >> input;

    while ((input != choice1 && input != choice2) || cin.fail() || input == "q" || input == "Q") {
        if (input == "q" || input == "Q") {
            cout << "Quitting..." << endl;
            exit(1);   
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        cout << "Must be " << choice1 << " or " << choice2 << " and must be a string" << endl;
        cout << "Try again ('q' to quit): ";
        cin >> input;
    }

    return input;
}

vector<string> Initialization::getAndDisplayMapOptions() {
    vector<string> mapFiles;
    DIR* directory;
    struct dirent* file;

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

void Initialization::chooseMap() {
    vector<string> mapFiles = getAndDisplayMapOptions();
    int mapNumber = getUserInputInteger("Your choice (-1 to quit): ", 1, mapFiles.size());
    MapLoader* map = new MapLoader();

    bool validMap = false;
    string error;

    try {
        map->parseMap(mapDirectory + mapFiles[mapNumber - 1]);
        validMap = true;
    } catch (invalid_argument e) {
        error = e.what();
    }

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

void Initialization::createPlayers() {
    cout  << "Select amount of players (2 - 6): " << endl;
    int numPlayers = getUserInputInteger("Your choice (-1 to quit): ", 2, 6);
    cout << "Creating players..." << endl;

    currentDeck = new Deck(5 * numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        cout << "Created Player " << (i + 1) << "..." << endl;
        Player* currPlayer = new Player("Player " + to_string(i + 1));
        gamePlayers.push_back(currPlayer);
    }
}

Initialization::Initialization() {
    chooseMap();
    cout << "Successfully chose a map, creating the game state..." << endl;
    createPlayers();
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