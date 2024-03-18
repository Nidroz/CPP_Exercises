#pragma once

#include <iostream>
#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"

class Character : public Entity {
    public:
        Character(int x, int y)
            : Entity(x, y)
        {}

        char get_representation() const override { 
            if (_lives == 2) {
                return 'O'; 
            } else if (_lives == 1) {
                return 'o';
            } else {
                return ' ';
            }
            
        }

        void interact_with(Entity& other) override {
            const auto* trap = dynamic_cast<Trap*>(&other);
            if (trap != nullptr) {
                _lives == 0 ? _lives = 0 : _lives--;
            }

            const auto* potion = dynamic_cast<Potion*>(&other);
            if (trap != nullptr) {
                _lives == 2 ? _lives = 2 : _lives++;
            }
        }

    private:
        int _lives = 2;
};