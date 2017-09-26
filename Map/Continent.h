#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <vector>
#include <string>
#include "Country.h"

using namespace std;

class Continent {
private:
    int worth;
    string name;
    vector<Country*> countries;
public:
    Continent(int);
    Continent(int, string);
    Continent(int, string, vector<Country*>);

    void addCountry(Country*);
    string getName();
    int getWorth();
};

#endif