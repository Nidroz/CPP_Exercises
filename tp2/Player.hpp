#pragma once

#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(const std::string& name);
    static void deal_all_cards(Player& p1, Player& p2);
    Card operator[](int index);
    static bool play(Player& p1, Player& p2);
    unsigned int getScore() const;
    static void whoWinned(const Player& p1, const Player& p2);

private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score = 0u;
    static inline unsigned int turn_number;
};