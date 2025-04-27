#include <iostream>
#include <vector>

using namespace std;

/*
	Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum.
	If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order.
	If no two numbers sum up to the target sum, the function should return an empty array.

	Note that the target sum has to be obtained by summing two different integers in the array; you can't add a single integer
  to itself in order to obtain the target sum.

	You can assume that there will be at most one pair of numbers summing up to the target sum.

	Sample input:

	array = [3, 5, -4, 8, 11, 1, -1, 6]
	targetSum = 10

	Sample Output
	[-1, 11] // the numbers could be in reverse order
*/

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
	int first;
	int second;

	for (int i = 0; i < array.size()-1; ++i) {
		first = array[i];
		for (int j = i+1; j < array.size(); ++j) {
			second = array[j];

			if (first+second == targetSum) {
				return vector<int>{first, second};
			}	
		}		
	}

	return vector<int>{};
}

template <typename T>
void printVector(const vector<T>& v) 
{
	cout << "[";
	for (const T& t : v) {
		cout << t << " ";
	}
	cout << "\b]\n";
}

int main()
{
	vector<int> array = {3,5,-4,8,11,1,-1,6};
	int targetSum = 10;

	auto result = twoNumberSum(array, targetSum);
	printVector(result);

	return EXIT_SUCCESS; 
}
