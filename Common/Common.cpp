#include "../Player/Player.h"
#include "../Map/Country.h"

class Common {

public:

	static void displayPlayersCountriesAndArmies(Player* thePlayer) {
		printf("%3s | %25s | %6s | %25s | %6s\n", "Num", "Country Owned", "Armies", "Bordering Countries", "Armies");
		for (int i = 0; i < thePlayer->getCountries().size(); i++) {
			Country* currCountry = thePlayer->getCountries()[i];
			printf("%3i | %25s | %6i | ", i + 1, currCountry->getName().c_str(), currCountry->getArmies());

			for (int j = 0; j < currCountry->getBorderingCountries().size(); j++) {
				Country* bordering = currCountry->getBorderingCountries()[j];
				if (j == 0) {
					printf("%25s | %6i\n", bordering->getName().c_str(), bordering->getArmies());
				} else {
					printf("%3s | %25s | %6s | %25s | %6i\n", "", "", "", bordering->getName().c_str(), bordering->getArmies());
				}
			}
		}
	}

private:

};
