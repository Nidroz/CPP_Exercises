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

bool Player::play(Player& p1, Player& p2) {
    std::cout << "Current turn of the game : " << turn_number << std::endl;
    
    std::cout << "Player 1 have the card [" << p1._cards[turn_number] << "]" << " at turn " << turn_number << std::endl;
    std::cout << "Player 2 have the card [" << p2._cards[turn_number] << "]" << " at turn " << turn_number << std::endl;

    if (p1._cards[turn_number] < p2._cards[turn_number]) {
        std::cout << "Player 2 winned the turn " << turn_number << std::endl;
        p2._score++;
    } else if (p2._cards[turn_number] < p1._cards[turn_number]) {
        std::cout << "Player 1 winned the turn " << turn_number << std::endl;
        p1._score++;
    }
    
    turn_number++;
    if (turn_number == 15) {
        return 1;
    }
    return 0;
}
