#include <GL/glut.h>
#include <vector>

class MainHero
{
private:
    int currentPosition;
    std::vector<float> heights;
    float dx;

public:
    MainHero(int currentPosition, std::vector<float> &heights, float dx);
    ~MainHero();

    void run();
    void jump();

    void currentPositionIncrement();
    void currentPositionDecrement();
};

MainHero::MainHero(int currentPosition, std::vector<float> &heights, float dx) : currentPosition(currentPosition), heights(heights), dx(dx)
{
}

MainHero::~MainHero()
{
}

// void MainHero::show()
// {
//     glColor3f(1.0, 0.0, 0.0);

//     glBegin(GL_QUADS);
//     glVertex3f(currentPosition * dx - 1, -1 + dx * std::abs(heights.at(currentPosition)), 0.0);
//     glVertex3f((currentPosition + 1) * dx - 1, -1 + dx * std::abs(heights.at(currentPosition)), 0.0);
//     glVertex3f((currentPosition + 1) * dx - 1, -1 + dx * std::abs(heights.at(currentPosition)) + dx, 0.0);
//     glVertex3f(currentPosition * dx - 1, -1 + dx * std::abs(heights.at(currentPosition)) + dx, 0.0);
//     glEnd();
// }

void MainHero::jump()
{
}

inline void MainHero::currentPositionIncrement()
{
    currentPosition = currentPosition >= heights.size() - 1 ? currentPosition : ++currentPosition;
}

inline void MainHero::currentPositionDecrement()
{
    currentPosition = currentPosition <= 0 ? currentPosition : --currentPosition;
}
