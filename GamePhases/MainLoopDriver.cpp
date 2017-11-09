#include <ctime>
#include "Initialization.h"
#include "Startup.h"
#include "MainLoop.h"

int main() {
    srand(time(0));
    Initialization ini;
    Startup startup(ini.getPlayers(), ini.getMap());
    MainLoop mainLoop(ini.getPlayers(), ini.getMap(), ini.getDeck());
    mainLoop.play();
    return 0;
}
