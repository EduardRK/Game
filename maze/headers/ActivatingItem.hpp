#pragma once

#include "Drawable.hpp"
#include "Turnable.hpp"
#include "Point.hpp"

template <class T>
class ActivatingItem : public Drawable, public Turnable
{
public:
    virtual ~ActivatingItem() = default;

    virtual void activate() = 0;
    virtual bool complete() = 0;
    virtual T result() = 0;
    virtual Point currentPosition() = 0;
};