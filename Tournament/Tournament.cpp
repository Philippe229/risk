#include "Tournament.h"
#include "../GamePhases/Initialization.h"
#include "../Common/Common.h"
#include "../Player/PlayerStrategies/AggressiveBot.h"
#include "../Player/PlayerStrategies/DefensiveBot.h"
#include "../Player/PlayerStrategies/RandomBot.h"
#include "../Player/PlayerStrategies/CheaterBot.h"
#include <limits>

void Tournament::tournamentInitialization () {
    int numMaps = 0;
    int numComputers;
    numMaps = Common::getUserInputIntegerInRange("Select Number of Maps for the Tournament (1 to 5): ",1,5);
    Initialization ini(numMaps);
    maps = ini.chooseSeveralMaps();
    numComputers = Common::getUserInputIntegerInRange("Select Number of Computers(2 to 4):",2,4);
    setUpComputers(numComputers);
    gamesPerMap = Common::getUserInputIntegerInRange("Select Number of Games per Map (1 to 5): ",1,5);
    turnsToDraw = Common::getUserInputIntegerInRange("Select Number of Turns Before Draw (Min = 1): ",1,std::numeric_limits<int>::max());
}

void Tournament::setUpComputers(int numCpu) {
    int input;
    cout << "**Types of Computers**" << endl; 
    cout << "1- Aggressive" << endl; 
    cout << "2- Benevolant" << endl; 
    cout << "3- Random" << endl;
    cout << "4- Cheater" << endl;
    for(int i =0;i < numCpu;i++) {
        input = Common::getUserInputIntegerInRange("Select Computer Type " + to_string(i+1) + " (1 to 4):",1,4);
        switch(input) {
            case 1:
                players.push_back(new AggressiveBot());
                break;
            case 2:
                players.push_back(new DefensiveBot());
                break;
            case 3:
                players.push_back(new RandomBot());
                break;
            case 4:
                players.push_back(new CheaterBot());
                break;
            default:
                cout << "Invalid computer choice" << endl;
        }
    }
}
void Tournament::startTournament() {
    Game* g;
    for(int i = 0;i < maps.size();i++) {
        for(int j = 0;j < gamesPerMap;j++) {
            g = new Game(maps.at(i),players,(i+1)*(j+1),turnsToDraw);
            games.push_back(g);
            g->startGame();
            cout << g->getWinnerName() << endl;
        }
    }
}

void Tournament::printReport() {
    
}
