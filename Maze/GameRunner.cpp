#include "GameRunner.hpp"
#include "GlutFunctions.hpp"

GameRunner::GameRunner(int argc, char **argv) : _argc{argc}, _argv{argv}
{
}

void GameRunner::run()
{
    window->init(_argc, _argv);
    window->keyboardFunc(keyboardFunc);
    window->displayFunc(displayFunc);
    window->mainLoop();
}