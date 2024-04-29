#pragma once

#include <functional>

#include "Point.hpp"

namespace std
{
    template <>
    struct hash<Point>
    {
        size_t operator()(const Point &p) const
        {
            size_t hashValue = 17;
            hashValue = hashValue * 31 + hash<int>()(p.x());
            hashValue = hashValue * 31 + hash<int>()(p.y());
            return hashValue;
        }
    };
}