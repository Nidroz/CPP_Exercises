#include <iostream>
#include <string>
#include "Card.hpp"
#include "Player.hpp"

int main(int argc, char const *argv[]) {
    const Card c1 { 8, "Pique" };
    c1.print();

    const Card c2 { 8, "Carreau" };
    std::cout << (c2 == c1) << std::endl; // -> 1
    const Card c3 { 10, "Carreau" };
    std::cout << (c2 == c3) << std::endl; // -> 0 

    std::cout << (c1 < c2) << std::endl; // -> 0
    std::cout << (c1 < c3) << std::endl; // -> 1
    std::cout << (c3 < c1) << std::endl; // -> 0

    Player p1 { "Gerald" };
    Player p2 { "Julien" };
    Player::deal_all_cards(p1, p2);

    
    for (auto i = 0; i < 16; ++i)
    {
        std::cout << p1[i] << std::endl;
        std::cout << p2[i] << std::endl;
    }

    bool playing = true;
    while (playing) {
        if ((Player::play(p1, p2) == 1)) {
            std::cout << "PARTIE FINISHED ! " << std::endl;
            playing = false;
        }
    }
    
    return 0;
}
