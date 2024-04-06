#include <iostream>
#include "Point2d.hpp"
#include "Point2dHash.hpp"
#include "Point2dEqual.hpp"
#include <unordered_map>
#include <string>
#include "Content.hpp"

int main(int argc, char const *argv[])
{
    Point2d p1 = {1, 2};
    Point2d p2 = {3, 4};
    Content c1 = Content::Red;
    Content c2 = Content::Yellow;
    std::unordered_map<Point2d, Content> grid = {
        {p1, c1},
        {p2, c2}
    };
    std::cout << "grid[" << p1._x << ", " << p1._y << "] = " << static_cast<int>(grid[p1]) << std::endl;
    return 0;
}
