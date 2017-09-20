#include <iostream>
#include <stdexcept>
#include "MapLoader.h"

using namespace std;

int main() {
    try {
        MapLoader loader("../Map/maps/World(small).map");
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try {
        MapLoader loader("../Map/maps/semi-valid-format-1.map");
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    try {
        MapLoader loader("../Map/maps/incorrect-format.map");
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    
    return 0;
}