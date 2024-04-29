#include <GL/glut.h>
#include <cstdlib>

#include "Window.hpp"

Window::Window(std::size_t height, std::size_t width) : _height{height}, _width{width}
{
}

Window::~Window()
{
}

void Window::init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_height, _width);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Maze game");
}