#pragma once

#include <memory>

#include "Drawable.hpp"
#include "Point.hpp"
#include "ActivatingItem.hpp"
#include "Explosion.hpp"

class Item : public Drawable
{
public:
    virtual ~Item() = default;

    virtual void useItem() = 0;
    virtual std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() = 0;
    virtual Point currentPosition() = 0;
};