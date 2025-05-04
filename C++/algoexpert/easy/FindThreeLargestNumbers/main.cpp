#include <iostream>
#include <vector>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) 
{
	size_t size = array.size();
	if (size <= 3) return array;

	int firstLargestPos{0};
	int secondLargestPos{-1};
	int thirdLargestPos{-1};
	
	// First largest
	for (int i{0}; i < size; ++i) {
		if (array[i] > array[firstLargestPos]) {
			firstLargestPos = i;
		}
	}

	// Second largest
	for (int i{0}; i < size; ++i) {
		if (i != firstLargestPos && (secondLargestPos == -1 || array[i] > array[secondLargestPos])) {
			secondLargestPos = i;
		}
	}

	// Third largest
	for (int i{0}; i < size; ++i) {
		if (i != firstLargestPos && i != secondLargestPos && (thirdLargestPos == -1 || array[i] > array[thirdLargestPos])) {
			thirdLargestPos = i;
		}
	}

  return {array[thirdLargestPos], array[secondLargestPos], array[firstLargestPos]};
}

void show(const vector<int>& v)
{
	cout << '[';

	for (const auto& item : v) {
		cout << item << " ";
	}

	cout << '\b' << ']' << endl;
}

int main()
{
	vector<int> array{10, 5, 9, 10, 12};
	show(findThreeLargestNumbers(array));

	return EXIT_SUCCESS;
}
