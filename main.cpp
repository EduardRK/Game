#include <memory>

#include "maze/headers/GameRunner.hpp"
#include "maze/headers/MazeGameRunner.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<GameRunner> gameRunner = std::make_unique<MazeGameRunner>(argc, argv);
    gameRunner->run();

    return 0;
}