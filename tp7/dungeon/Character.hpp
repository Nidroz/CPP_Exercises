#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
#include <iostream>
#include "Potion.hpp"
#include <iostream>

class Character : public Entity {
    public:
        Character() = default;

        Character(int x, int y)
            : Entity(x, y)
        {}

        char get_representation() const override {
            return _representation;
        }

        void interact_with(Entity &entity) {
            const auto* trap = dynamic_cast<Trap*>(&entity);
            const auto* potion = dynamic_cast<Potion*>(&entity);
            if (trap != nullptr) {
                if (_times < 2) {
                    std::cout << "You stepped on a trap!" << std::endl;
                    //_times++;
                    if (_times == 1) {
                        _representation = 'o';
                    } else if (_times == 2) {
                        _representation = '.';
                    }
                }
            } 
            else if (potion != nullptr) {
                if (_times > 0) {
                    _times--;
                    if (_times == 1) {
                        _representation = 'o';
                    } else if (_times == 0) {
                        _representation = 'O';
                    }
                }
            }
        }
    
    private:
        int _times = 0;
        char _representation = 'O';
};