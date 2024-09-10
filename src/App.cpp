#include "Game.h"
#include "UI.h"

int main() {
    Game game(UI::getNumberOfPlayers());

    game.StartGame();
}