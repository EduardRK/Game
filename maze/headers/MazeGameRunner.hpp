#pragma once

#include <memory>
#include <cstdlib>

#include "GameRunner.hpp"
#include "Window.hpp"

class MazeGameRunner final : public GameRunner
{
private:
    static constexpr std::size_t HEIGHT = 1000;
    static constexpr std::size_t WIDTH = 1000;

    int _argc;
    char **_argv;
    std::unique_ptr<Window> _window = std::make_unique<Window>(HEIGHT, WIDTH);

public:
    MazeGameRunner(int argc, char **argv);
    ~MazeGameRunner() = default;

    void run() override;
};