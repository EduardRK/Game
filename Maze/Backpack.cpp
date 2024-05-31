#include <GL/glut.h>

#include "Backpack.hpp"
#include "EmptyItem.hpp"

Backpack::Backpack(int capacity) : _capacity{capacity}
{
    _backpack = new BackpackCell[capacity];
}

Backpack::Backpack() : Backpack(DEFAULT_CAPACITY)
{
}

Backpack::~Backpack()
{
    delete[] _backpack;
}

bool Backpack::saveItem(std::shared_ptr<Item> item)
{
    int index = findEmpty();

    if (index == -1)
    {
        return false;
    }

    _backpack[index].addItem(item);
    return true;
}

std::shared_ptr<Item> Backpack::getItem(int index)
{
    if (index < _capacity)
    {
        std::shared_ptr<Item> item = _backpack[index].getItem();
        return item;
    }

    return std::make_shared<EmptyItem>();
}

void Backpack::draw()
{
    float left = -0.9f;
    float top = -0.9f + GAP;

    glLineWidth(LINE_WIDTH);

    for (size_t i = 0; i < _capacity; ++i)
    {
        glColor3f(0.35f, 0.35f, 0.35f);

        glBegin(GL_LINE_LOOP);
        glVertex2f(left, top);
        glVertex2f(left, top - SIDE);
        glVertex2f(left + SIDE, top - SIDE);
        glVertex2f(left + SIDE, top);
        glVertex2f(left, top);
        glEnd();

        _backpack[i].backpackDraw(left, top, SIDE);

        left += (SIDE + GAP);
    }

    left = -1.f;
}

int Backpack::findEmpty()
{
    for (size_t i = 0; i < _capacity; ++i)
    {
        if (_backpack[i].empty())
        {
            return i;
        }
    }

    return -1;
}
