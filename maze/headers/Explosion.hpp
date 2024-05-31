#pragma once

#include "Point.hpp"
#include "Damage.hpp"

class Explosion final
{
private:
    Point _center;
    int _radius;
    Damage _damage;

public:
    Explosion(Point center, int radius, Damage damage);
    Explosion(Point center, int radius, int damage);
    Explosion();
    ~Explosion() = default;

    int radius() const;
    int radius();

    Point center();
    const Point &center() const;

    Damage &damage();
    const Damage &damage() const;
};