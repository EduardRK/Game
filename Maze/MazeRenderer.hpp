#pragma once

class MazeRenderer
{
public:
    virtual ~MazeRenderer();

    virtual void render() = 0;
};
