#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
	
vector<int> spiralTraverse(vector<vector<int>> array) 
{
	vector<int> ret{};
	if (array.size() == 0) return ret;

	int startRow{0};
	int endRow{static_cast<int>(array.size())-1};
	int startCol{0};
	int endCol{static_cast<int>(array[0].size())-1};

	while (startRow <= endRow && startCol <= endCol) {
		// Left to Right Row
		for (int c{startCol}; c <= endCol; ++c) {
			ret.push_back(array[startRow][c]);
		}

		// Up to Down Col
		for (int r{startRow+1}; r <= endRow; ++r) {
			ret.push_back(array[r][endCol]);
		}

		// Right to Left Row
		for (int c{endCol-1}; c >= startCol; --c) {
			ret.push_back(array[endRow][c]);
		}

		// Down to Up Col
		for (int r{endRow-1}; r > startRow; --r) {
			ret.push_back(array[r][startCol]);
		}

		startRow++;
		endRow--;
		startCol++;
		endCol--;
	}

  return ret;
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	/*vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{12, 13, 14, 5},
		{11, 16, 15, 6},
		{10, 9, 8, 7}
	};*/

	/*vector<vector<int>> matrix = {
		{1}
	};*/

	{
  		"array": [
    				[1, 2, 3, 4],
    				[10, 11, 12, 5],
    				[9, 8, 7, 6]
  			]
	}

	print(spiralTraverse(matrix));

	return EXIT_SUCCESS;
}
