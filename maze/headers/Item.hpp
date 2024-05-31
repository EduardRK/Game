#pragma once

#include <memory>

#include "Drawable.hpp"
#include "BackpackDrawable.hpp"
#include "Point.hpp"
#include "ActivatingItem.hpp"
#include "Explosion.hpp"

class Item : public Drawable, public BackpackDrawable
{
public:
    virtual ~Item() = default;

    virtual void useItem() = 0;
    virtual std::shared_ptr<ActivatingItem<Explosion>> getActivatingItem() = 0;
    virtual Point currentPosition() = 0;
};