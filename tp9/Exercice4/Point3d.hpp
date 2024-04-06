#pragma once

#include <tuple>

struct Point3d
{
public:
    int _x;
    int _y;
    int _z;

    bool operator<(const Point3d &p) const
    {
        return std::tie(_x, _y, _z) < std::tie(p._x, p._y, p._z);
    }
};