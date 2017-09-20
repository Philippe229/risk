#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include "MapLoader.h"

using namespace std;

MapLoader::MapLoader() {
}

MapLoader::MapLoader(string textFileName) {
    parseMap(textFileName);
}

// Helper function for getting whole lines without carriage returns
string MapLoader::readLine(ifstream &fileReader) {
    string line;
    if (getline(fileReader, line)) {
        if (line[line.length() - 1] == '\r') {
            line.pop_back();
        }

        return line;
    } else {
        return "";
    }
}

Map MapLoader::getMap() {
    return loadedMap;
}

void MapLoader::parseMap(string textFileName) {
    string line;
    ifstream fileReader(textFileName);

    // Verify that [Map] exists but skip over it
    if ((line = this->readLine(fileReader)) != "[Map]") {
        throw invalid_argument("Map file is invalid, missing [Map] section.");
    }

    while ((line = this->readLine(fileReader)) != "[Continents]" && !fileReader.eof()) {}

    // Parse the continents
    if (line != "[Continents]") {
        throw invalid_argument("Map file is invalid, missing [Continents] section.");
    }

    while ((line = this->readLine(fileReader)) != "[Territories]" && !fileReader.eof()) {
        cout << line << endl;
    }

    // Parse the territories
    if (line != "[Territories]") {
        throw invalid_argument("Map file is invalid, missing [Territories] section.");
    }

    while ((line = this->readLine(fileReader)) != "" && !fileReader.eof()) {
        cout << line << endl;
    }

    fileReader.close();
}