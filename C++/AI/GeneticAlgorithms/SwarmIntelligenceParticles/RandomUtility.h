#ifndef RANDOM_UTILITY_H
#define RANDOM_UTILITY_H

#include <random>

class RandomUtility {
public:
    static double randomProbability();
    static double randomBetween(double start, double end);

private:
    static std::random_device rd;
    static std::mt19937 gen;
};

#endif
