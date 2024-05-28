#pragma once

#include <memory>

#include "Point.hpp"

template <class T>
class Selector
{
public:
    virtual ~Selector() = default;

    virtual std::shared_ptr<T> seedSelect(int seed, Point point) = 0;
    virtual std::shared_ptr<T> randomSelect(const Point& point) = 0;
};