#include "MazeGameRunner.hpp"
#include "GlutFunctions.hpp"

MazeGameRunner::MazeGameRunner(int argc, char **argv) : _argc{argc}, _argv{argv}
{
}

void MazeGameRunner::run()
{
    _window->init(_argc, _argv);
    _window->keyboardFunc(keyboardFunc);
    _window->displayFunc(displayFunc);
    _window->mainLoop();
}