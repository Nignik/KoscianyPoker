#pragma once

#include "Player.h"

class Game {
public:
    Game(unsigned int numberOfPlayers);

    void StartGame();
    void StartRound();
    void EndRound();
    unsigned int ComputeResults();


private:
    std::vector<Player> m_players;

};