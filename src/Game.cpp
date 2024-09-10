#include "Game.h"
#include "UI.h"

#include <memory>

Game::Game(unsigned int numberOfPlayers) 
{
    for (int i = 0; i < numberOfPlayers; i++) {
        Player newPlayer(UI::getName());
        m_players.emplace_back(std::move(newPlayer));
    }
}

void Game::StartGame() {
    while (true) {
        StartRound();
        ComputeResults();
        EndRound();
    }
}

void Game::StartRound()
{
    std::sort(m_players.begin(), m_players.end(), compareByName);
    for (auto& player : m_players) {
        player.ThrowDices();
    }

    UI::printPlayersDices(m_players);
}

void Game::EndRound()
{
    //UI::awaitConfirmation();
}

unsigned int Game::ComputeResults()
{
    std::sort(m_players.rbegin(), m_players.rend(), compareByScore);
    UI::printScore(m_players);
    return 0;
}
