#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
#include <iostream>
#include "Potion.hpp"
#include <iostream>
#include "Logger.hpp"

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
            auto* trap = dynamic_cast<Trap*>(&entity);
            auto* potion = dynamic_cast<Potion*>(&entity);
            if (trap != nullptr) {
                if (_times < 2) {
                    trap->consume();
                    _times++;
                    if (_times == 1) {
                        _representation = 'o';
                    } else if (_times == 2) {
                        _representation = '.';
                    }
                }
            } 
            else if (potion != nullptr) {
                if (_times > 0) {
                    potion->consume();
                    _times--;
                    if (_times == 1) {
                        _representation = 'o';
                    } else if (_times == 0) {
                        _representation = 'O';
                    }
                }
            }
        }

        bool should_destroy() override {
            if (_times == 2 || _representation == '.') {
                return true;
            }
            return false;
        }

        ~Character() {
            logger << "A character died at position";
        }
    
    private:
        int _times = 0;
        char _representation = 'O';
};