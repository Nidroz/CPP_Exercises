#pragma once
#include <iostream>
#include <functional>

struct Point3d
{
    int x = 0;
    int y = 0;
    int z = 0;
    
    bool operator<(const Point3d& otherP3d) const {
        return x < otherP3d.x && y < otherP3d.y;
    }
};

class Point3dCompare {
    public:
        bool operator()(const Point3d& point3d_1, const Point3d& point3d_2) const {
            return std::tie(point3d_1.x, point3d_1.y, point3d_1.z) < std::tie(point3d_2.x, point3d_2.y, point3d_2.z);
        }
};