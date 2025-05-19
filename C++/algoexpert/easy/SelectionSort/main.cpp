#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> selectionSort(vector<int> array) 
{
	vector<int> result{array};
	size_t limitOut{array.size()-1};
	size_t limitInner{array.size()};
	size_t minPos;

	for (size_t i{0}; i < limitOut; ++i) {
		minPos = i;

		for (size_t j{i+1}; j < limitInner; ++j) {
			if (result[j] < result[minPos]) {
				minPos = j;
			}
		}

		swap(result[i], result[minPos]);
	}

  return result;
}

int main()
{
	vector<int> array{9, 8, 7};
	vector<int> result{selectionSort(array)};

	copy(result.begin(), result.end(), ostream_iterator<int>{cout, " "});

	return EXIT_SUCCESS;
}

