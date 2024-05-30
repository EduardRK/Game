#pragma once

template <class T>
class Dealer
{
public:
    virtual ~Dealer() = default;

    virtual T deal() = 0;
};