#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
<<<<<<< HEAD
#include "Potion.hpp"
=======
>>>>>>> refs/remotes/origin/tp7
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
<<<<<<< HEAD
                if (_times < 2) {
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
                    _times--;
                    if (_times == 1) {
                        _representation = 'o';
                    } else if (_times == 0) {
                        _representation = 'O';
=======
                if (entity.get_x() == trap->get_x() && entity.get_y() == trap->get_y()) {
                    std::cout << "You stepped on a trap!" << std::endl;
                    //times++;
                    if (times == 1) {
                        injured = true;
                        dead = false;
                    } else if (times == 2) {
                        injured = false;
                        dead = true;
>>>>>>> refs/remotes/origin/tp7
                    }
                }
            }
        }

        void update() override {
            if (dead) {
                return;
            }
        }
    
    private:
        int _times = 0;
        char _representation = 'O';
};