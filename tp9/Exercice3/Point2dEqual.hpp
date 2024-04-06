#pragma once

#include <iostream>
#include <cstddef>
#include "Point2d.hpp"

class Point2dEqual {
    public:
        std::size_t operator()(const Point2d& p1, const Point2d& p2) const {
            return p1._x == p2._x && p1._y == p2._y;
        }
};
