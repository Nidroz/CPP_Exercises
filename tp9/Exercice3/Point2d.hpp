#pragma once

struct Point2d {
    public:
        int _x;
        int _y;

        bool operator==(const Point2d& p) const {
            return _x == p._x && _y == p._y;
        }
};

namespace std {
    template <>
    struct hash<Point2d> {
        std::size_t operator()(const Point2d& p) const {
            std::size_t h1 = std::hash<int>()(p._x);
            std::size_t h2 = std::hash<int>()(p._y);
            return h1 ^ h2;
        }
    };
}