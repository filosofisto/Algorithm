#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::size_t;

template <typename T, size_t N>
void merge(array<T, N>& arr, size_t left, size_t mid, size_t right) 
{
	size_t n1 = mid - left + 1;
  size_t n2 = right - mid;

  // Create temporary arrays
  array<T, N> leftArr, rightArr;

  // Copy data to temporary arrays leftArr[] and rightArr[]
  for (size_t i = 0; i < n1; i++) {
  	leftArr[i] = arr[left + i];
	}
  for (size_t j = 0; j < n2; j++) {
  	rightArr[j] = arr[mid + 1 + j];
	}
    
	// Merge the temporary arrays back into arr[left..right]
  size_t i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
 		if (leftArr[i] <= rightArr[j]) {
    	arr[k] = leftArr[i];
      i++;
    } else {
    	arr[k] = rightArr[j];
      j++;
   	}
        
		k++;
  }

  // Copy the remaining elements of leftArr[], if there are any
  while (i < n1) {
  	arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr[], if there are any
  while (j < n2) {
 		arr[k] = rightArr[j];
    j++;
    k++;
  }
}

template <typename T, size_t N>
void merge_sort(array<T, N>& arr, size_t left, size_t right) 
{
	if (left < right) {
  	// Find the middle point
    size_t mid = left + (right - left) / 2;

    // Sort first and second halves
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
	}
}

template <typename T, size_t N>
void merge_sort(array<T, N>& arr) 
{
	merge_sort(arr, 0, arr.size() - 1);
}	
