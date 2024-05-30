#include "Statuses.hpp"

Statuses::Statuses(bool fireStatus, bool torchStatus, bool keyStatus) : _fireStatus{fireStatus}, _torchStatus{torchStatus}, _keyStatus{keyStatus}
{
}

Statuses::Statuses() : Statuses(false, false, false)
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

bool Statuses::keyStatus() const
{
    return _keyStatus;
}

bool Statuses::keyStatus()
{
    return _keyStatus;
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

void Statuses::addKeyStatus()
{
    _keyStatus = true;
}

void Statuses::removeKeyStatus()
{
    _keyStatus = false;
}
