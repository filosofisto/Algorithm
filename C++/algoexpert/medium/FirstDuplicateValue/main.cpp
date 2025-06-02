#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int firstDuplicateValue(vector<int> array)
{
	unordered_map<int, int> map{};

	for (const auto& value : array) {
		map[value]++;

		if (map[value] > 1) {
			return value;
		}
	}

	return -1;
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	vector<int> array{2, 1, 5, 2, 3, 3, 4};
	cout << firstDuplicateValue(array) << '\n';

	return EXIT_SUCCESS;
}
