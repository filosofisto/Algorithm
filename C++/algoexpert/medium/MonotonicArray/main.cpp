#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

bool isIncreaseMonotonic(vector<int> array)
{
	int limit{static_cast<int>(array.size())-1};

	for (int i{0}; i < limit; ++i) {
		if (array[i] > array[i+1]) return false;
	}

	return true;
}

bool isDecreaseMonotonic(vector<int> array)
{
	int limit{static_cast<int>(array.size())-1};

	for (int i{0}; i < limit; ++i) {
		if (array[i] < array[i+1]) return false;
	}

	return true;
}

bool isMonotonic(vector<int> array)
{
	if (array.size() < 2) return true;

	return isIncreaseMonotonic(array) || isDecreaseMonotonic(array);
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	vector<int> array{-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
	cout << boolalpha << isMonotonic(array) << '\n';

	vector<int> b{};
	cout << isMonotonic(b) << '\n';

	vector<int> c{1};
	cout << isMonotonic(c) << '\n';

	vector<int> d{1, 1, 1};
	cout << isMonotonic(d) << '\n';

	vector<int> e{1, 5, 10, 1100, 1101, 1102, 9001};
	cout << isMonotonic(e) << '\n';

	vector<int> f{1, 5, 2, 10, 1100, 1101, 1102, 9001};
	cout << isMonotonic(f) << '\n';
	
	return EXIT_SUCCESS;
}
