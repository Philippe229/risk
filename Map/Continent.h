#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <vector>
#include <string>
#include "Country.h"

using namespace std;

//forward declaration (circular dependency)
class Country;

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
    vector<Country*> getCountries();
    string getName();
    int getWorth();
    string getOwner();
};

#endif
