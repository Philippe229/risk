#include "PlayerContext.h"

PlayerContext::PlayerContext(Player* strategy) {
    playerStrategy = strategy;
}

void PlayerContext::setPlayerStrategy(Player* strategy) {
    playerStrategy = strategy;
}

void PlayerContext::reinforce(Map* currMap, Deck* currDeck) {
    playerStrategy->reinforce(currMap, currDeck);
}

void PlayerContext::attack(Map* currMap, Deck* currDeck) {
    playerStrategy->attack(currMap, currDeck);
}

void PlayerContext::fortify(Map* currMap, Deck* currDeck) {
    playerStrategy->fortify(currMap, currDeck);
}