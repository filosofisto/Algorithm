//
// Created by eduardo on 26.04.20.
//

#include "MaximumSubarray.h"

MaximumSubarray::MaximumSubarray(bool enablePrint): enablePrint(enablePrint)
{

}

MaximumSubarray::~MaximumSubarray() = default;

MaximumSubarrayResult MaximumSubarray::calculate(int *array, int low, int high) const {
    print(array, low, high);

    if (high == low) {
        return MaximumSubarrayResult{low, high, array[low]};
    }

    int mid = (low + high) / 2;
    MaximumSubarrayResult resultLeft = calculate(array, low, mid);
    MaximumSubarrayResult resultRight = calculate(array, mid+1, high);
    MaximumSubarrayResult resultCross = calculateCrossingSubarray(array, low, mid, high);

    if (resultLeft.sum >= resultRight.sum && resultLeft.sum >= resultCross.sum) {
        return resultLeft;
    } else if (resultRight.sum >= resultLeft.sum && resultRight.sum >= resultCross.sum) {
        return resultRight;
    } else {
        return resultCross;
    }

}

MaximumSubarrayResult MaximumSubarray::calculateCrossingSubarray(int *array, int low, int mid, int high) const {
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = -1;

    for (int i = mid; i >= low; i--) {
        sum += array[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = -1;

    for (int j = mid+1; j <= high; j++) {
        sum += array[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    return MaximumSubarrayResult{maxLeft, maxRight, leftSum+rightSum};
}

void MaximumSubarray::print(int *array, int low, int high) const {
    if (!enablePrint) {
        return;
    }

    cout << endl;

    for (int i = low; i <= high; i++) {
        cout << array[i] << " ";
    }
}

