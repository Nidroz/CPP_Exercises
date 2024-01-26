#pragma once
#include "Card.hpp"
#include <string>
#include <vector>

class Player {
    public:
        Player(const std::string& name);
        static void deal_all_cards(Player& p1, Player& p2);
        Card operator[](int index);

        static inline unsigned int turn_number;
        static bool play(Player& p1, Player& p2);
        unsigned int getScore() const {
            return _score;
        };

    private:
        std::string _name;
        std::vector<Card> _cards;
        unsigned int _score = 0u;
};

// Si vous ne précisez rien pour _cards, comment sera initialisé l'attribut ?
// => à null (vector vide)

// Pour _score, une valeur aléatoire si on ne précise rien, et qu'on utilise la variable
// avant son initialisation.

// A quoi sert la fonction std::this_thread::sleep_for ?
// Elle sert à mettre en pause le programme pendant un certain temps (donné).