#pragma once

#include "Entity.hpp"

class Item : public Entity
{
    public:
        Item(int width, int height)
            : _width { width }
            , _height { height }
            , Entity { random_value(0, width), random_value(0, height) }
        {}

    private:
        int _width = 0;
        int _height = 0;
};