#include <iostream>

#include <vector>

using namespace std;

int getNextPos(vector<int> array, int toMove) 
{
  for (int i{array.size()-1}; i > -1; --i) {
    if (array[i] != toMove) {
      return i;
    }
  }

  return -1;
}

vector<int> moveElementToEnd(vector<int> array, int toMove) 
{
  int pos;
  
  for (int i{0}; i < array.size(); ++i) {
    if (array[i] == toMove) {
      pos = getNextPos(array, toMove);
      swap(array[i], array[pos])
    }
  }
  return array;
}

int main()
{
	return EXIT_SUCCESS;
}
