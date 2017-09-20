#ifndef MAP_LOADER_H_
#define MAP_LOADER_H_

#include <string>
#include <fstream>
#include "../Map/Map.h"

class MapLoader {
private:
    Map loadedMap;
    string readLine(ifstream&);

public:
    MapLoader();
    MapLoader(string);

    Map getMap();
    void parseMap(string);
};

#endif