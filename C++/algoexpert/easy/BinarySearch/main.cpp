#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> array, int start, int end, int target)
{
	if (array.empty()) return -1; 	// empty array condition
	if (start > end) return -1; 		// not found condition

	int pos = start + (end - start) / 2;
	int candidate = array[pos];

	// found condition
	if (candidate == target) return pos;
	
	if (candidate > target) {
		// next candidate can be in left half
		end = pos - 1;
	} else {
		// next candidate can be in right half
		start = pos + 1;
	}

	return binarySearch(array, start, end, target);
}

int binarySearch(vector<int> array, int target) {
  return binarySearch(array, 0, array.size(), target);
}

int main()
{
	vector<int> array{0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
	cout << binarySearch(array, 33) << endl;	
	cout << binarySearch(array, 2) << endl;
	cout << binarySearch(array, 80) << endl;

	vector<int> empty{};
	cout << binarySearch(empty, 2) << endl;

	vector<int> single{10};
	cout << binarySearch(single, 10) << endl;
	cout << binarySearch(single, 2) << endl;

	return EXIT_SUCCESS;
}

