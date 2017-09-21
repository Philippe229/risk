#include "Continent.h"

Continent::Continent(int w) {
    worth = w;
}

Continent::Continent(int w, string n) {
    worth = w;
    name = n;
}

Continent::Continent(int w, string n, vector<shared_ptr<Country> > cs) {
    worth = w;
    name = n;
    countries = cs;
}

void Continent::addCountry(shared_ptr<Country> c) {
    countries.push_back(c);
}

string Continent::getName() {
    return name;
}

int Continent::getWorth() {
    return worth;
}