#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;
using std::array;
using std::size_t;
using std::swap;

template <typename T, size_t N>
void heapify(array<T, N>& arr, size_t n, size_t i) 
{
	size_t largest = i; // initialize lasgest as root
	size_t left = 2 * i + 1; // left child
	size_t right = 2 * i + 2; // right child 

	// if left child is larger than root
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	// if right child is larger than largest so far
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	// if largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		
		heapify(arr, n, largest);	
	}
}

template <typename T, size_t N>
void heap_sort(array<T, N>& arr) 
{
	// Build heap (rearrange array))
	for (int i = N / 2 - 1; i >= 0; i--) {
		heapify(arr, N, i);
	}

	// One by one extract an element from heap
	for (int i = N - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// Call max heapify on the reduce heap
		heapify(arr, i, 0);
	} 
}


