#pragma once

#include <vector>
#include <random>
#include <algorithm>

struct Player {
    std::vector<int> dices;
    std::string name;
    std::string dicesFormation;
    unsigned int score = 0;

    Player(std::string name) 
        : name(name),
        dices(std::vector<int>(5))
    {
        ThrowDices();
    }

    void ThrowDices() {
        for (auto& dice : dices) {
            dice = rand() % 6 + 1;
        }
        std::sort(dices.rbegin(), dices.rend());
        ComputeDicesFormation();
    }

    void ComputeDicesFormation() {
        int triples = 0, pairs = 0, cnt = 0;

        std::vector<int> dicesCount(7);
        for(auto& dice : dices){
            dicesCount[dice]++;
        }

        for(auto& count : dicesCount){
            if(count == 1){
                cnt++;
            }
        }

        if(cnt == 5 && dicesCount[0] == 1 && dicesCount.back() != 1){
            dicesFormation = "Maly Street";
            score = 4;
        }
        else if(cnt == 5 && dicesCount.back() == 1 && dicesCount[0] != 1){
            dicesFormation = "Duzy Street";
            score = 5;
        }

        for(auto& count : dicesCount){
            if(count == 5){
                dicesFormation = "POKER";
                score = 8;
            }
            else if(count == 4){
                dicesFormation = "Kareta";
                score = 7;
            }
            else if(count == 3){
                triples++;
            }
            else if(count == 2){
                pairs++;
            }
        }
            
        if(pairs == 2){
            dicesFormation = "Dwie pary";
            score = 2;
        }
        else if(pairs == 1 && triples == 1){
            dicesFormation = "Full";
            score = 6;
        }
        else if(triples == 1){
            dicesFormation = "Trojka";
            score = 3;
        }
        else if(pairs == 1){
            dicesFormation = "Para";
            score = 1;
        }
    }
};

inline bool compareByName(const Player& a, const Player& b) {
    return a.name < b.name;
}

inline bool compareByScore(const Player& a, const Player& b) {
    if (a.score != b.score)
        return a.score < b.score;
    return a.dices < b.dices;
}