//
// Created by eduardo on 26.04.20.
//
#include <iostream>
#include <array>
#include "gtest/gtest.h"
#include "matrix.h"

using namespace std;

TEST(MATRIX_ADDITION, Default)
{
	Matrix<int, 3> mat1 = {{
		{
			{1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
		}
	}};

  Matrix<int, 3> mat2 = {{
		{
			{9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}}
 	}};

	Matrix<int, 3> addition = mat1 + mat2;
	Matrix<int, 3> addition_expected = {{
		{
			{10, 10, 10},
			{10, 10, 10},
			{10, 10, 10}
		}
	 }};
	 
	bool equals = addition == addition_expected;
	EXPECT_TRUE(equals); 	
}

TEST(MATRIX_SUBTRACTION, Default)
{
	Matrix<int, 3> mat1 = {{
		{
			{1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
		}
	}};

  Matrix<int, 3> mat2 = {{
		{
			{9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}}
 	}};

	Matrix<int, 3> subtraction = mat1 - mat2;
	Matrix<int, 3> subtraction_expected = {{
		{
			{-8, -6, -4},
			{-2, 0, 2},
			{4, 6, 8}
		}
	 }};
	 
	bool equals = subtraction == subtraction_expected;
	EXPECT_TRUE(equals); 	
}

TEST(MATRIX_MULTIPLICATION, Default)
{
	Matrix<int, 3> mat1 = {{
		{
			{1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
		}
	}};

  Matrix<int, 3> mat2 = {{
		{
			{9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}}
 	}};

	Matrix<int, 3> product = mat1 * mat2;
	Matrix<int, 3> product_expected = {{
		{
			{30, 24, 18},
			{84, 69, 54},
			{138, 114, 90}
		}
	 }};
	 
	bool equals = product == product_expected;
	EXPECT_TRUE(equals); 	
}

