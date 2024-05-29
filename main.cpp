#include <memory>

#include "maze/GameRunner.hpp"
#include "maze/MazeGameRunner.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<GameRunner> runner = std::make_unique<MazeGameRunner>(argc, argv);
    runner->run();

    return 0;
}