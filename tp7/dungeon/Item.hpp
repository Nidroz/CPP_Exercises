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

        void interact_with(Entity& entity) override {}

        void consume() {
            _is_consumed = true;
        }

        bool should_destroy() override {
            if (_is_consumed) {
                return true;
            }
            return false;
        }

    private:
        int _width = 0;
        int _height = 0;
        bool _is_consumed = false;
};