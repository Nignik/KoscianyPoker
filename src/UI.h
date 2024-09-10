#pragma once

#include <vector>
#include <iostream>
#include <string>

namespace UI {
    inline unsigned int getNumberOfPlayers() {
        unsigned int numberOfPlayers;

        std::cout << "Please input how many players will participate: ";
        std::cin >> numberOfPlayers;
        std::cout << std::endl;

        return numberOfPlayers;
    }

    template<typename T>
    inline void printVector(std::vector<T>& vec) {
        for (auto& x : vec) {
            std::cout << x << ' ';
        }
    }

    inline std::string getName() {
        std::string name;

        std::cout << "Please input your name: ";
        std::cin >> name;
        std::cout << std::endl;

        return name;
    }

    inline void printPlayersDices(std::vector<Player>& players) {
        for (auto& player : players) {
            std::cout << player.name << ": ";
            printVector(player.dices);
            std::cout << " -> " << player.dicesFormation;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    inline void printScore(std::vector<Player>& players) {
        for (auto& player : players) {
            std::cout << player.name << ": " << player.score << std::endl;
        }
        std::cout << std::endl;
    }

    inline void awaitConfirmation() {
        std::cout << "If you are ready to continue press enter twice" << std::endl;
        std::cout << std::endl;
        
        // fuck this ->
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
};