#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Card.hpp"
#include "Player.hpp"

int main(int argc, char const *argv[]) {
    Player p1 { "Julien" };
    Player p2 { "Gerald" };
    Player::deal_all_cards(p1, p2);

    bool playing = true;
    while (playing) {
        if ((Player::play(p1, p2) == 1)) {
            std::cout << "PARTIE FINISHED ! " << std::endl;
            playing = false;
        }
        std::cout << "Player 1 score : " << p1.getScore() <<
         " | Player 2 score : " << p2.getScore() << std::endl;
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
