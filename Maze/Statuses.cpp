#include "Statuses.hpp"

Statuses::Statuses(bool fireStatus, bool torchStatus) : _fireStatus{fireStatus}, _torchStatus{torchStatus}
{
}

Statuses::Statuses() : Statuses(false, false)
{
}

bool Statuses::fireStatus() const
{
    return _fireStatus;
}

bool Statuses::fireStatus()
{
    return _fireStatus;
}

bool Statuses::torchStatus() const
{
    return _torchStatus;
}

bool Statuses::torchStatus()
{
    return _torchStatus;
}

void Statuses::addFireStatus()
{
    _fireStatus = true;
}

void Statuses::removeFireStatus()
{
    _fireStatus = false;
}

void Statuses::addTorchStatus()
{
    _torchStatus = true;
}

void Statuses::removeTorchStatus()
{
    _torchStatus = false;
}
