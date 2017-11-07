//#include <iostream>
//#include <stdexcept>
//#include "MapLoader.h"
//
//using namespace std;
//
//int main() {
//    // Proper Map format
//    try {
//        MapLoader loader("./Map/maps/World(small).map");
//        cout << "Map was successfully parsed." << endl;
//    } catch (invalid_argument e) {
//        cout << e.what() << endl;
//    }
//
//    // Typo given in one or more of the bordering country names
//    try {
//        MapLoader loader("./Map/maps/misnamed-bordering-country.map");
//        cout << "Map was successfully parsed." << endl;
//    } catch (invalid_argument e) {
//        cout << e.what() << endl;
//    }
//
//    // Typo given in one of the country names
//    try {
//        MapLoader loader("./Map/maps/misnamed-country.map");
//        cout << "Map was successfully parsed." << endl;
//    } catch (invalid_argument e) {
//        cout << e.what() << endl;
//    }
//
//    // [Map] tag given but nothing else
//    try {
//        MapLoader loader("./Map/maps/semi-valid-format-1.map");
//        cout << "Map was successfully parsed." << endl;
//    } catch (invalid_argument e) {
//        cout << e.what() << endl;
//    }
//
//    // Empty file
//    try {
//        MapLoader loader("./Map/maps/incorrect-format.map");
//        cout << "Map was successfully parsed." << endl;
//    } catch (invalid_argument e) {
//        cout << e.what() << endl;
//    }
//
//    return 0;
//}
