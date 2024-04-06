#pragma once

#include <iostream>
#include <cstddef>
#include "Point2d.hpp"

class Point2dHash {
    public:
        std::size_t operator()(const Point2d& p) const {
            std::size_t h1 = std::hash<int>()(p._x);
            std::size_t h2 = std::hash<int>()(p._y);
            return h1 ^ h2;
        }
};
