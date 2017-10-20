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
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input" << endl;
        cout << "Must be greater than " << min - 1 << " and less than " << max + 1 << " and must be an integer" << endl;
        cout << "Try again: ";
        cin >> input;
    }

    return input;
}

vector<string> Initialization::getAndDisplayMapOptions() {
    DIR* directory;
    struct dirent* file;
    vector<string> mapFiles;

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
    int mapNumber = getUserInputInteger("Your choice: ", 1, mapFiles.size());
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
}

void Initialization::createPlayers() {

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