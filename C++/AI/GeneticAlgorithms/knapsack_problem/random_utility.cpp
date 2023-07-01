#include "random_utility.h"

int zeroOrOne()
{
    return between(0, 1);
}

int between(int start, int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(start, end - 1);
    
    return dist(gen);
}
