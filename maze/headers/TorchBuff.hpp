#pragma once

#include "Buff.hpp"
#include "Player.hpp"

class TorchBuff final : public Buff
{
private:
    static constexpr int BUFF_BONUS_DAMAGE = 2;
    static constexpr int BUFF_RADIUS_OF_VIEW = 3;

    Player &_player;

    int _turnsLeft = 30;

public:
    TorchBuff(Player &player);
    ~TorchBuff() = default;

    void draw() override;
    void nextTurn() override;
    void attack() override;
    bool complete() override;
};