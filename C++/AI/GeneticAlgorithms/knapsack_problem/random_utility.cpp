#include "random_utility.h"

int zeroOrOne()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    return dis(gen);
}
