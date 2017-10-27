#include <vector>
#include <ctime>
#include "Initialization.h"

int main() {
    srand(time(0));
    Initialization ini;

    cout << endl << "Current Game State:" << endl;
    ini.getDeck()->PrintStatistics();
    vector<Player*> players = ini.getPlayers();

    for (int i = 0; i < players.size(); i++) {
        cout << endl << "Displaying " << players[i]->getName() << "'s information:" << endl;
        players[i]->getHand()->PrintHand();
        players[i]->getDiceFacility()->printDiceRollHistory();
    }

    return 0;
}
