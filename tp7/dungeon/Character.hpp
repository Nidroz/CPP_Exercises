#pragma once

#include "Entity.hpp"
#include "Trap.hpp"

class Character : public Entity {
    public:
        Character() = default;

        Character(int x, int y)
            : Entity(x, y)
        {}

        char get_representation() const override { 
            if (injured) {
                return 'o';
            } else if (dead) {
                return '.';
            }
        
            return 'O'; 
        }

        void interact_with(Entity &entity) {
            const auto* trap = dynamic_cast<Trap*>(&entity);
            if (trap != nullptr) {
                if (entity.get_x() == trap->get_x() && entity.get_y() == trap->get_y()) {
                    times++;
                    if (times == 1) {
                        injured = true;
                    } else if (times == 2) {
                        injured = false;
                        dead = true;
                    }
                    
                }
            }
        }
    
    private:
        bool injured = false;
        bool dead = false;
        int times = 0;
};