#include "GameRunner.hpp"

GameRunner::GameRunner(int argc, char **argv) : _argc{argc}, _argv{argv}
{
}

GameRunner::~GameRunner()
{
}

void GameRunner::run()
{
    window->init(_argc, _argv);
}