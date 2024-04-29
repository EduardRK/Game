#include <GL/glut.h>

#include "GlutCellRenderer.hpp"
#include "Cell.hpp"

GlutCellRenderer::GlutCellRenderer(float height, float width) : _height{height}, _width{width}
{
}

GlutCellRenderer::GlutCellRenderer(float width) : GlutCellRenderer(width, width)
{
}

GlutCellRenderer::GlutCellRenderer() : GlutCellRenderer(BASE_WIDTH)
{
}

GlutCellRenderer::~GlutCellRenderer()
{
}

void GlutCellRenderer::render(const Cell &cell)
{
    if (cell.isWall())
    {
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    else if (cell.isPassage())
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    else if (cell.isCracked())
    {
        glColor3f(66.0f / 255.0f, 170.0f / 255.0f, 1.0f);
    }

    glBegin(GL_QUADS);
    glVertex2f((float)cell.point().x() - _width / 2, (float)cell.point().y() - _height / 2);
    glVertex2f((float)cell.point().x() - _width / 2, (float)cell.point().y() + _height / 2);
    glVertex2f((float)cell.point().x() + _width / 2, (float)cell.point().y() + _height / 2);
    glVertex2f((float)cell.point().x() + _width / 2, (float)cell.point().y() - _height / 2);
    glEnd();
}