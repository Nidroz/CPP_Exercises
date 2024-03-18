#pragma once

#include "Random.hpp"

class Entity
{
public:
    Entity() = default;

    Entity(int x, int y)
        : _x { x }
        , _y { y }
    {}

    int get_x() const { return _x; }
    int get_y() const { return _y; }

    virtual char get_representation() const = 0; // virtuelle pure

    virtual void update() { random_move(_x, _y); }

private:
    int _x = 0;
    int _y = 0;
};
