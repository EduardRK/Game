#pragma once

class MazeRenderer
{
public:
    virtual ~MazeRenderer() = default;

    virtual void render() = 0;
};
