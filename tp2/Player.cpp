#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "Player.hpp"

Player::Player(const std::string& name)
    : _name { name }
    {}

void Player::deal_all_cards(Player& p1, Player& p2) {
    std::vector<Card> all_cards;
    std::vector<unsigned int> values = {7, 8, 9, 10, 11, 12, 13, 14};
    std::vector<std::string> colors = {"Trefle", "Carreau", "Pique", "Coeur"};

    for (auto value : values) {
        for (auto color : colors) {
            all_cards.emplace_back(Card {value, color});
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    for (int index = 0; index < all_cards.size() / 2; index++) {
        p1._cards.emplace_back(all_cards.at(index));
    }

    for (int index = all_cards.size() / 2; index < all_cards.size(); index++) {
        p2._cards.emplace_back(all_cards.at(index));
    }
}

Card Player::operator[](int index) {
    return _cards.at(index);
}

bool play(const Player& p1, const Player& p2) {
    
}
