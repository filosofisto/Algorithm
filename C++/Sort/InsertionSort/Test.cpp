//
// Created by eduardo on 26.04.20.
//
#include <iostream>
#include "gtest/gtest.h"
#include "insertionsort.h"

TEST(INSERT_SORTING, Default)
{
	using std::array;

	array<int, 9> a{9,8,7,6,5,4,3,2,1};
	auto b = a;

	EXPECT_EQ(a, b);

	//array<int, 9> expected{1,2,3,4,5,6,7,8,9};

	insertion_sort(a);
	
	EXPECT_NE(a, b);
 	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(9, a[8]);
}

