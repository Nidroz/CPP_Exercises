#pragma once

#include "Point3d.hpp"
#include <tuple>

class Point3dCompare
{
public:
    bool operator()(const Point3d &p1, const Point3d &p2) const
    {
        return std::tie(p1._x, p1._y, p1._z) < std::tie(p2._x, p2._y, p2._z);
    }
};