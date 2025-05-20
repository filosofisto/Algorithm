#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSum(int target, int a, int b, int c)
{
	return target == (a+b+c);
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) 
{
	size_t size{array.size()};
	if (size < 3) return {};

	vector<vector<int>> result{};  
	int a, b, c;

	for (int i{0}; i < size-2; ++i) {
		a = array[i];

		for (int j{i+1}; j < size-1; ++j) {
			b = array[j];

			for (int k{j+1}; k < size; ++k) {
				c = array[k];

				if (isSum(targetSum, a, b, c)) {
					vector<int> vec{a, b, c};
					sort(vec.begin(), vec.end());
					result.push_back(vec);
				}
			}
		}
	}

	sort(result.begin(), result.end(), [](const vector<int>& x, const vector<int>& y) {
		return x < y;
	});

	return result;
}

void print(const vector<vector<int>>& vec)
{
	cout << "[";

	for (const auto& v : vec) {
		cout << "[";

		for (const auto& i : v) {
			cout << i << " ";
		}

		cout << "]";
	}

	cout << "]\n";
}

int main()
{
	vector<int> array{12, 3, 1, 2, -6, 5, -8, 6};
	print(threeNumberSum(array, 0));

	return EXIT_SUCCESS;
}
