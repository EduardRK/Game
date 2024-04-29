#pragma once

#include "Runner.hpp"

class GameRunner final : public Runner
{
public:
    GameRunner();
    ~GameRunner();

    void run() override;
}