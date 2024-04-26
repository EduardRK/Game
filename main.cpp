#include <GL/glut.h>
#include <vector>
#include <math.h>

#include "MainHero.hpp"
#include "maze/Maze.hpp"
#include "maze/Cell.hpp"
#include "maze/MazeTypeCell.hpp"
#include "maze/PrimMazeGenerator.hpp"
#include "maze/DfsMazeSolver.hpp"
#include "maze/Point.hpp"

// std::vector<float> heights = {6, 6, 4, 4, 4, 5, -1, -1, -1, -1, 5, 6};
// float dx = 2.0f / 12.0f;
// MainHero mainHero(0, heights, dx);

void myDisp()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // for (int i = 0; i < heights.size(); ++i)
    // {
    //     if (heights.at(i) >= 0)
    //     {
    //         glColor3f(0.0, 1.0, 0.0);
    //     }
    //     else
    //     {
    //         glColor3f(0.0, 0.0, 1.0);
    //     }

    //     glBegin(GL_QUADS);
    //     glVertex3f(i * dx - 1, -1, 0.0);
    //     glVertex3f((i + 1) * dx - 1, -1, 0.0);
    //     glVertex3f((i + 1) * dx - 1, -1 + dx * std::abs(heights.at(i)), 0.0);
    //     glVertex3f(i * dx - 1, -1 + dx * std::abs(heights.at(i)), 0.0);
    //     glEnd();
    // }

    // mainHero.show();

    glutSwapBuffers();
}

void myKeyboard(int key, int x, int y)
{
    // switch (key)
    // {
    // case GLUT_KEY_RIGHT:
    //     mainHero.currentPositionIncrement();
    //     break;
    // case GLUT_KEY_LEFT:
    //     mainHero.currentPositionDecrement();
    //     break;
    // default:
    //     break;
    // }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 1000);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutCreateWindow("Window");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(myDisp);
    glutSpecialFunc(myKeyboard);
    glutMainLoop();

    return 0;
}
