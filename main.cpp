#include <memory>

#include "maze/Runner.hpp"
#include "maze/GameRunner.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<Runner> runner = std::make_unique<GameRunner>(argc, argv);
    runner->run();

    return 0;
}