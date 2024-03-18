#pragma once

#include <iostream>
#include "Entity.hpp"

class Character : public Entity {
    public:
        Character(int x, int y)
            : Entity(x, y)
        {}

        char get_representation() const override { return 'O'; }
};