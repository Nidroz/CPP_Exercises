#include <iostream>
#include <set>
#include "Point3d.hpp"

int main(int argc, char const *argv[])
{
    Point3d p1 = {1, 3, 5};
    Point3d p2 = {2, 7, 0};
    std::set<Point3d> coords;
    coords.emplace(Point3d { 2, 7, 0});
    coords.emplace(Point3d { 6, 9, 0});
    coords.emplace(Point3d { 1, 2, 3});

    std::cout << "Coords Size: " << coords.size() << std::endl;
    for (const auto& coord : coords) {
        std::cout << coord.x << ", " << coord.y << ", " << coord.z << std::endl;
    }
    return 0;
}
