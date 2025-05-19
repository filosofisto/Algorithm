#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> bubbleSort(vector<int> array) 
{
	vector<int> ret{array};
	size_t limitOut = ret.size()-1;
	size_t limitIn = ret.size();

	for (size_t i{0}; i != limitOut; ++i) {
		for (size_t j{i+1}; j < limitIn; ++j) {
			if (ret[j] < ret[i]) {
				swap(ret[j], ret[i]);
			}
		}
	}

  return ret;
}

int main()
{
	vector<int> array{9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> result = bubbleSort(array);
	copy(result.begin(), result.end(), ostream_iterator<int>{cout, " "});
	
	return EXIT_SUCCESS;
}

