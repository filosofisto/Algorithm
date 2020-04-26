//
// Created by eduardo on 26.04.20.
//

#ifndef MAXIMUMSUBARRAY_MAXIMUMSUBARRAY_H
#define MAXIMUMSUBARRAY_MAXIMUMSUBARRAY_H

#include <iostream>
#include <climits>

using namespace std;

typedef struct
{
    int maxLeft;
    int maxRight;
    int sum;
} MaximumSubarrayResult;

class MaximumSubarray {
public:
    MaximumSubarray(bool enablePrint = false);
    ~MaximumSubarray();

    MaximumSubarrayResult calculate(int* array, int low, int high) const;
private:
    MaximumSubarrayResult calculateCrossingSubarray(int* array, int low, int mid, int high) const;
    void print(int* array, int low, int high) const;
    bool enablePrint;
};


#endif //MAXIMUMSUBARRAY_MAXIMUMSUBARRAY_H
