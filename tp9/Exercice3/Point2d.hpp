#pragma once
#include <iostream>
#include <functional>

struct Point2d
{
    int x = 0;
    int y = 0;

    
    bool operator==(const Point2d& otherP2d) const {
        return x == otherP2d.x && y == otherP2d.y;
    }
};

enum class Content {
    Empty,
    Red,
    Yellow
};

class Point2dHash {
    public:
        std::size_t operator()(const Point2d& point2d) const {
            std::size_t h1 = std::hash<int>{} (point2d.x);
            std::size_t h2 = std::hash<int>{} (point2d.y);
            return h1 ^ (h2 << 1);
        }
};

class Point2dEqual {
    public:
        bool operator()(const Point2d& point2d_1, const Point2d& point2d_2) const {
            return point2d_1.x == point2d_2.x && point2d_1.y == point2d_2.y;
        }
};

namespace std {

template <>
struct hash<Point2d>
{
    std::size_t operator()(const Point2d& point2d) const {
        std::size_t h1 = std::hash<int>{} (point2d.x);
        std::size_t h2 = std::hash<int>{} (point2d.y);
        return h1 ^ (h2 << 1);
    }
};

}