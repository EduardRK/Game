#include <random>

#include "RandomFunctions.hpp"

int nextRandomInt(int min, int max)
{
    if (min == max)
    {
        return min;
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max - 1);
    return dist6(rng);
}

int nextRandomInt(int max)
{
    return nextRandomInt(0, max);
}

float nextRandomFloat(float min, float max)
{
    if (min == max)
    {
        return min;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);

    return dis(gen);
}

float nextRandomFloat(float max)
{
    return nextRandomFloat(0, max);
}
