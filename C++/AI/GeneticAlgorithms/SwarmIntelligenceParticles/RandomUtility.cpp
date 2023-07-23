#include "RandomUtility.h"

std::random_device RandomUtility::rd;
std::mt19937 RandomUtility::gen(rd());

double RandomUtility::randomProbability() {
    return randomBetween(0.0f, 1.0f);
}

double RandomUtility::randomBetween(double start, double end)
{
    std::uniform_real_distribution<double> dis(start, end);
    return dis(gen);
}
