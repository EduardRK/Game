#pragma once

#include "Buff.hpp"
#include "Player.hpp"

class TorchBuff final : public Buff
{
private:
    static constexpr float GAP = 0.02f;
    static constexpr float COLOR_GAP = (255.f / 30.f) / 255.f;

    static constexpr int BUFF_BONUS_DAMAGE = 2;
    static constexpr int BUFF_RADIUS_OF_VIEW = 3;

    Player &_player;

    int _turnsLeft = 30;
    float _redColor = 1.f;

public:
    TorchBuff(Player &player);
    ~TorchBuff() = default;

    void draw(int buffIndex, float side) override;
    void nextTurn() override;
    void attack() override;
    bool complete() override;
};