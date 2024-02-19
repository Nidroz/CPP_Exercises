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
    std::vector<std::string> colors = {"Pique", "Dame", "Coeur", "Carreau"};
    for (const auto& color : colors) {
        for (unsigned int value = 7; value <= 14; value++) {
            all_cards.emplace_back(Card {value, color});
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    for (int index = 0; index < all_cards.size() / 2; index++) {
        p1._cards.emplace_back(all_cards[index]);
    }

    for (int index = all_cards.size() / 2; index < all_cards.size(); index++) {
        p2._cards.emplace_back(all_cards[index]);
    }
}

Card Player::operator[](int index) {
    return _cards[index];
}

unsigned int Player::getScore() const {
    return _score;
}

bool Player::play(Player& p1, Player& p2) {
    unsigned int turn = Player::turn_number;
    // cas de fin de game
    if (turn >= p1._cards.size() || turn >= p2._cards.size()) {
        return true;
    }

    std::cout << "Current turn of the game : " << turn << std::endl;
    std::cout << "Player 1 have the card [" << p1._cards[turn] << "]" << " at turn " << turn << std::endl;
    std::cout << "Player 2 have the card [" << p2._cards[turn] << "]" << " at turn " << turn << std::endl;

    if (p1._cards[turn] < p2._cards[turn]) {
        std::cout << "Player 2 winned the turn " << turn << std::endl;
        p2._score++;
    } else if (p2._cards[turn] < p1._cards[turn]) {
        std::cout << "Player 1 winned the turn " << turn << std::endl;
        p1._score++;
    }

    Player::turn_number++;
    return false;
}

void Player::whoWinned(const Player& p1, const Player& p2) {
    if (p1.getScore() < p2.getScore()) {
        std::cout << "PLAYER 2 WINNED !" << std::endl;
    } else if (p2.getScore() < p1.getScore()) {
        std::cout << "PLAYER 1 WINNED !" << std::endl;
    } else {
        std::cout << "DRAW !" << std::endl;
    }
}