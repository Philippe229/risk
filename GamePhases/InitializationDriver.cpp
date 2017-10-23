#include <vector>
#include "Initialization.h"

int main() {
    Initialization ini;

    cout << endl << "Current Game State:" << endl;
    ini.getDeck()->PrintStatistics();
    vector<Player*> players = ini.getPlayers();

    for (int i = 0; i < players.size(); i++) {
        cout << endl << "Displaying " << players[i]->getName() << "'s information:" << endl;
        players[i]->showCards();
    }

    return 0;
}