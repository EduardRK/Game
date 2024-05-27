#pragma once

#include <memory>

template <class T>
class Selector
{
public:
    virtual ~Selector() = default;

    virtual std::shared_ptr<T> seedSelect(int seed) = 0;
    virtual std::shared_ptr<T> randomSelect() = 0;
};