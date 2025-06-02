#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  return {};
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	vector<int> array{2, 1, 2, 2, 2, 3, 4, 2};
	print(moveElementToEnd(array, 2));

	return EXIT_SUCCESS;
}
