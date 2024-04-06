#include <iostream>
#include "Point3d.hpp"
#include <string>
#include <set>
#include "Point3dCompare.hpp"

int main(int argc, char const *argv[])
{
    Point3d p1 = {1, 2, 4};
    Point3d p2 = {3, 4, 6};
    std::set<Point3d, Point3dCompare> coords;
    coords.insert(p1);
    coords.insert(p2);
    std::cout << "grid[" << p1._x << ", " << p1._y << ", " << p1._z << "] = " 
        << coords.count(p1) << std::endl;
    return 0;
}
