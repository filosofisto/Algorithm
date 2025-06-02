#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


void print(const vector<int> array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>{cout, " "});
}

int main()
{

	return EXIT_SUCCESS;
}
