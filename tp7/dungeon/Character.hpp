#pragma once

#include <iostream>
#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Logger.hpp"

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
            auto* trap = dynamic_cast<Trap*>(&other);
            if (trap != nullptr) {
                //trap->consume();
                _lives == 0 ? _lives = 0 : _lives--;
            }

            auto* potion = dynamic_cast<Potion*>(&other);
            if (trap != nullptr) {
                //potion->consume();
                _lives == 2 ? _lives = 2 : _lives++;
            }
        }

        bool should_destroy() const override {
            return _lives == 0;
        }

        ~Character() {
            logger << "A character died at position (" << get_x() << ", " << get_y() << ")";
        }

    private:
        int _lives = 2;
};