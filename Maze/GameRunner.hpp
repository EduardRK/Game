#pragma once

#include "Runner.hpp"

class GameRunner final : public Runner
{
private:
    int _argc;
    char **_argv;

public:
    ~GameRunner();
    GameRunner(int argc, char **argv);

    void run() override;
};