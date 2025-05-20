#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iterator>

using namespace std;

int distance(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0)) {
		// Same signal
		return abs(a-b);
	} else {
		// Diff signal
		return abs(a)+abs(b);
	}
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
	int sizeOne = arrayOne.size();
	int sizeTwo = arrayTwo.size();

	if (sizeOne == 0 || sizeTwo == 0) return {};

	int minDist = numeric_limits<int>::max();
	int tmpDist;
	int leftPos, rightPos = -1;

	for (int i{0}; i < sizeOne; ++i) {
		for (int j{0}; j < sizeTwo; ++j) {
			tmpDist = distance(arrayOne[i], arrayTwo[j]);
			if (tmpDist < minDist) {
				leftPos = i;
				rightPos = j;
				minDist = tmpDist;
			}
		}	
	}

	if (leftPos == -1 || rightPos == -1) return {};

	return {arrayOne[leftPos], arrayTwo[rightPos]};
}

int main()
{
	vector<int> arrayOne{-1, 5, 10, 20, 28, 3};
	vector<int> arrayTwo{26, 134, 135, 15, 17};
	vector<int> result{smallestDifference(arrayOne, arrayTwo)};
	copy(result.begin(), result.end(), ostream_iterator<int>{cout, " "});

	return EXIT_SUCCESS;
}
