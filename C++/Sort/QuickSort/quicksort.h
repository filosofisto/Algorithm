#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;
using std::array;
using std::size_t;
using std::swap;

template<typename T, size_t N>
void print(array<T,N>& a)
{
	for (auto element : a) {
		cout << element << " ";
	}

	cout << endl;
}

template <typename T, size_t N>
void quick_sort(array<T, N>& arr, int low, int high) 
{
  if (low < high) {
  	// Partition the array and get the pivot index
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
    	if (arr[j] < pivot) {
      	++i;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[high]);
    int pivotIndex = i + 1;

    // Recursively sort the sub-arrays
    quick_sort(arr, low, pivotIndex - 1);
    quick_sort(arr, pivotIndex + 1, high);
  }
}

template <typename T, size_t N>
void quick_sort(array<T, N>& arr) 
{
	quick_sort(arr, 0, arr.size() - 1);
}
