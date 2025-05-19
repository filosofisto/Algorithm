#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> insertionSort(vector<int> array) 
{
	vector<int> result{array};
	size_t limit{array.size()};
	int key;
	int j;

	for (size_t i{1}; i < limit; ++i) {
		key = result[i];
		j = i - 1;

		while (j >= 0 && result[j] > key) {
			result[j+1] = result[j];
			--j;
		}

		result[j+1] = key;	
	}

  return result;
}

int main()
{
	vector<int> array{9, 8, 7};
	vector<int> result{insertionSort(array)};

	copy(result.begin(), result.end(), ostream_iterator<int>{cout, " "});

	return EXIT_SUCCESS;
}

