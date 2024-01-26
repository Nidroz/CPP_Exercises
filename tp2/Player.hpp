#pragma once
#include "Card.hpp"
#include <string>
#include <vector>

class Player {
    public:
        Player(const std::string& name);
        static void deal_all_cards(Player& p1, Player& p2);
        Card operator[](int index);
        static bool play(const Player& p1, const Player& p2);
        unsigned int getScore() const {
            return _score;
        };

    private:
        std::string _name;
        std::vector<Card> _cards;
        unsigned int _score = 0u;
        static inline unsigned int turn_number;
};

// Si vous ne précisez rien pour _cards, comment sera initialisé l'attribut ?
// => à null

// Pour _score, une valeur aléatoire si on ne précise rien, et qu'on utilise la variable
// avant son initialisation.
