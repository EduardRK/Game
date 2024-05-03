#pragma once

#include <cstdlib>

class Window final
{
private:
    std::size_t _height;
    std::size_t _width;

public:
    Window(std::size_t height, std::size_t width);
    ~Window();

    void init(int argc, char **argv);
    void keyboardFunc(void (*keyboardFunc)(unsigned char, int, int));
    void displayFunc(void (*displayFunc)());
    void mainLoop();
};