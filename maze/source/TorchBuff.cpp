#include <GL/glut.h>

#include "TorchBuff.hpp"

TorchBuff::TorchBuff(Player &player) : _player{player}
{
}

void TorchBuff::draw(int buffIndex, float side)
{
    float left = 1.f - (side + GAP) * (buffIndex + 1);
    float top = 1.f - GAP;

    glColor3f(_redColor, 0.f, 0.f);

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - side);
    glVertex2f(left + side, top - side);
    glVertex2f(left + side, top);
    glEnd();
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
    _redColor -= COLOR_GAP;
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
    _redColor -= (COLOR_GAP * 5);
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
