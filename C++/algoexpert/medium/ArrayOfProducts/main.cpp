#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int prod(vector<int> array, int pos) 
{
	int p{1};

	for (int i{0}; i < array.size(); ++i) {
		if (i != pos) {
			p *= array[i];
		}
	}

	return p;
}

vector<int> arrayOfProducts(vector<int> array) 
{
	vector<int> ret{};

	for (int i{0}; i < array.size(); ++i) {
		ret.push_back(prod(array, i));
	}  

	return ret;
}

void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{
	vector<int> array{5, 1, 4, 2};
	print(arrayOfProducts(array));

	return EXIT_SUCCESS;
}
