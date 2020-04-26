//
// Created by eduardo on 26.04.20.
//
#include <iostream>
#include "gtest/gtest.h"
#include "MaximumSubarray.h"

using namespace std;

TEST(MAXIMUM_SUBARRAY, Default)
{
    MaximumSubarray maximumSubarray(true);
    int array[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };

    MaximumSubarrayResult result = maximumSubarray.calculate(array, 0, size(array)-1);

    EXPECT_EQ(7, result.maxLeft);
    EXPECT_EQ(10, result.maxRight);
    EXPECT_EQ(43, result.sum);

    cout << endl << "Maximum Subarray" << endl;

    for (int i = result.maxLeft; i <= result.maxRight; i++) {
        cout << array[i] << "  ";
    }

    cout << endl;
    cout << "Sum: " << result.sum << endl;
}

