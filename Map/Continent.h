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
    vector<shared_ptr<Country> > countries;
public:
    Continent(int);
    Continent(int, string);
    Continent(int, string, vector<shared_ptr<Country> >);

    void addCountry(shared_ptr<Country>);
    string getName();
    int getWorth();
};

#endif