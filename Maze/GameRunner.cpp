#include "GameRunner.hpp"
#include "GlutFunctions.hpp"

GameRunner::GameRunner(int argc, char **argv) : _argc{argc}, _argv{argv}
{
}

void GameRunner::run()
{
    _window->init(_argc, _argv);
    _window->keyboardFunc(keyboardFunc);
    _window->displayFunc(displayFunc);
    _window->mainLoop();
}