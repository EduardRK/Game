#include "Explosion.hpp"

Explosion::Explosion(Point center, int radius, Damage damage) : _center{center}, _radius{radius}, _damage{damage}
{
}

Explosion::Explosion(Point center, int radius, int damage) : Explosion(center, radius, Damage(damage))
{
}

Explosion::Explosion() : Explosion(Point(), 0, 0)
{
}

int Explosion::radius() const
{
    return _radius;
}

int Explosion::radius()
{
    return _radius;
}

Point Explosion::center()
{
    return _center;
}

const Point &Explosion::center() const
{
    return _center;
}

Damage &Explosion::damage()
{
    return _damage;
}

const Damage &Explosion::damage() const
{
    return _damage;
}
