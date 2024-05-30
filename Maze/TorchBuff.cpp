#include "TorchBuff.hpp"

TorchBuff::TorchBuff(Player &player) : _player{player}
{
}

void TorchBuff::draw()
{
}

void TorchBuff::nextTurn()
{
    if (!_player.statuses().torchStatus())
    {
        _player.statuses().addTorchStatus();
        _player.statuses().addFireStatus();
        _player.stats().addBonusDamage(BUFF_BONUS_DAMAGE);
        _player.stats().addBonusRadiusView(BUFF_RADIUS_OF_VIEW);
    }

    --_turnsLeft;
}

void TorchBuff::attack()
{
    if (!_player.statuses().torchStatus())
    {
        _player.statuses().addTorchStatus();
        _player.statuses().addFireStatus();
        _player.stats().addBonusDamage(BUFF_BONUS_DAMAGE);
        _player.stats().addBonusRadiusView(BUFF_RADIUS_OF_VIEW);
    }

    _turnsLeft -= 5;
}

bool TorchBuff::complete()
{
    if (_turnsLeft <= 0 && _player.statuses().torchStatus())
    {
        _player.statuses().removeTorchStatus();
        _player.statuses().removeFireStatus();
        _player.stats().removeBonusDamage(BUFF_BONUS_DAMAGE);
        _player.stats().removeBonusRadiusView(BUFF_RADIUS_OF_VIEW);
    }

    return _turnsLeft <= 0;
}
