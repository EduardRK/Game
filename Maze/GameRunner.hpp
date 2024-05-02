#pragma once

#include <memory>
#include <cstdlib>

#include "Runner.hpp"
#include "Window.hpp"

class GameRunner final : public Runner
{
private:
    static constexpr std::size_t HEIGHT = 1000;
    static constexpr std::size_t WIDTH = 1000;

    int _argc;
    char **_argv;
    std::unique_ptr<Window> window = std::make_unique<Window>(HEIGHT, WIDTH);

public:
    ~GameRunner();
    GameRunner(int argc, char **argv);

    void run() override;
};