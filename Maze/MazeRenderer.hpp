#include <GL/glut.h>
#include <vector>

#include <iostream>


std::vector<std::vector<int>> maze = { {0,0,1,0,1,0},
                             {1,0,1,0,1,0},
                             {1,0,0,0,0,0},
                             {1,1,1,1,0,1},
                             {0,1,1,1,0,1},
                             {0,0,0,0,0,0} };

const float delta = 1.0f / 3.0f;

class MazeRenderer
{
private:
    
public:
    void renderer(std::vector<std::vector<int>>);
};
void MazeRenderer::renderer(std::vector<std::vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (maze[i][j] == 0)
            {
                glBegin(GL_QUADS);
                glColor3f(1, 1, 1);
                glVertex3f(j * delta, -i * delta, 0);
                glVertex3f(j * delta, -(i + 1) * delta, 0);
                glVertex3f((j + 1) * delta, -(i + 1) * delta, 0);
                glVertex3f((j + 1) * delta, -i * delta, 0);
                glEnd();
            }
            else
            {
                glBegin(GL_QUADS);
                glColor3f(0, 0, 0);
                glVertex3f(j * delta, -i * delta, 0);
                glVertex3f(j * delta, -(i + 1) * delta, 0);
                glVertex3f((j + 1) * delta, -(i + 1) * delta, 0);
                glVertex3f((j + 1) * delta, -i * delta, 0);
                glEnd();
            }
        }
    }
}