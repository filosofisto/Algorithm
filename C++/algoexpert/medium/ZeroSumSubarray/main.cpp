#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int> array, size_t from, size_t to)
{
	int result = 0;

	for (size_t i{from}; i <= to; ++i) {
		result += array[i];
	}
	
	return result;
}

bool zeroSumSubarray(vector<int> array)
{
	for (size_t start{0}; start < array.size(); ++start) {
		for (size_t end{start}; end < array.size(); ++end) {
			if (sum(array, start, end) == 0) {
				return true;
			}	
		}
	}

	return false;
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	vector<int> array{-5, -5, 2, 3, 2};
	cout << boolalpha << zeroSumSubarray(array) << '\n';

	vector<int> b{0};
	cout << boolalpha << zeroSumSubarray(b) << '\n';

	vector<int> c{1};
	cout << boolalpha << zeroSumSubarray(c) << '\n';


	return EXIT_SUCCESS;
}
