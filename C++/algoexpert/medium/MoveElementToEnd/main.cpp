#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int getNextPos(vector<int> array, int toMove, int limit) 
{
	int pos{-1};

  for (int i{static_cast<int>(array.size())-1}; i > -1 && i > limit; --i) {
    if (array[i] != toMove) {
      pos = i;
			break;
    }
  }

  return pos;
}

vector<int> moveElementToEnd(vector<int> array, int toMove) 
{
  int pos;
  
  for (int i{0}; i < array.size(); ++i) {
    if (array[i] == toMove) {
      pos = getNextPos(array, toMove, i);

			if (pos == -1) {
				break;
			}

      swap(array[i], array[pos]);
    }
  }
  return array;
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
