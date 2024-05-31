#include <GL/glut.h>

#include "GlutCellRenderer.hpp"
#include "Cell.hpp"

GlutCellRenderer::GlutCellRenderer(float height, float width) : _height{height}, _width{width}
{
}

GlutCellRenderer::GlutCellRenderer(float width) : GlutCellRenderer(width, width)
{
}


void GlutCellRenderer::render(const Cell &cell)
{
    if (cell.isWall())
    {
        glColor3f(0.0f, 0.0f, 0.8f);
    }
    else if (cell.isPassage())
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    else if (cell.isCracked())
    {
        glColor3f(66.0f / 255.0f, 170.0f / 255.0f, 1.0f);
    }

    float left = static_cast<float>(cell.point().x()) / (_width / 2) - 1.f;
    float top = -static_cast<float>(cell.point().y()) / (_height / 2) + 1.f;

    glBegin(GL_QUADS);
    glVertex2f(left, top);
    glVertex2f(left, top - SIDE / (_height / 2));
    glVertex2f(left + SIDE / (_width / 2), top - SIDE / (_height / 2));
    glVertex2f(left + SIDE / (_width / 2), top);
    glEnd();
}