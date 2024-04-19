#include <iostream>
#include <map>
#include <unordered_map>
#include "Point2d.hpp"

int main(int argc, char const *argv[])
{
    Point2d p1 = {1, 3};
    Point2d p2 = {2, 7};
    std::unordered_map<Point2d, Content> grid {
        {p1, Content::Yellow},
        {p2, Content::Red}
    };

    std::cout << "Grid Size: " << grid.size() << std::endl;
    return 0;
}
