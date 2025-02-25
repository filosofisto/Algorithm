#include <iostream>
#include <print>
#include <random>
#include <chrono>
#include <functional>
#include <string>

#include "printarray.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

using std::size_t;
using std::array;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::string;

template <size_t N>
void fill(array<int, N>& arr) 
{
    random_device rd;
    mt19937 gen(rd());  // Mersenne Twister generator
    uniform_int_distribution<> dis(0, 1000);  // Distribution from 0 to 1000

    for (auto& val : arr) {
        val = dis(gen);  // Fill each element with a random value
    }
}

template <typename Func, size_t N>
void measure_time(const string& label, array<int, N>& arr, Func&& func) 
{
	auto start = high_resolution_clock::now();
  func(arr);
  auto end = high_resolution_clock::now();

  duration<double> duration = end - start;
	auto duration_nanos = duration_cast<nanoseconds>(end - start);

  cout << label << " - Execution time: " << duration_nanos.count() << " nanoseconds" << endl;
}

int main()
{
	array<int, 10> small;
	fill(small);

	auto small_copy = small;
	measure_time("Size 10 Insertion Sort", small_copy, [](auto& arr) { insertion_sort(arr); });

	small_copy = small;
	measure_time("Size 10 Merge Sort    ", small_copy, [](auto& arr) { merge_sort(arr); });

	small_copy = small;
	measure_time("Size 10 Heap Sort     ", small_copy, [](auto& arr) { heap_sort(arr); });

	small_copy = small;
	measure_time("Size 10 Quick Sort    ", small_copy, [](auto& arr) { quick_sort(arr); });

	cout << endl;

	array<int, 100> not_so_small;
	fill(not_so_small);

	auto not_so_small_copy = not_so_small;
	measure_time("Size 100 Insertion Sort", not_so_small_copy, [](auto& arr) { insertion_sort(arr); });

	not_so_small_copy = not_so_small;
	measure_time("Size 100 Merge Sort    ", not_so_small_copy, [](auto& arr) { merge_sort(arr); });

	not_so_small_copy = not_so_small;
	measure_time("Size 100 Heap Sort     ", not_so_small_copy, [](auto& arr) { heap_sort(arr); });

	not_so_small_copy = not_so_small;
	measure_time("Size 100 Quick Sort    ", not_so_small_copy, [](auto& arr) { quick_sort(arr); });

	cout << endl;

	array<int, 1000> thousand;
	fill(thousand);

	auto thousand_copy = thousand;
	measure_time("Size 1000 Insertion Sort", thousand_copy, [](auto& arr) { insertion_sort(arr); });

	thousand_copy = thousand;
	measure_time("Size 1000 Merge Sort    ", thousand_copy, [](auto& arr) { merge_sort(arr); });

	thousand_copy = thousand;
	measure_time("Size 1000 Heap Sort     ", thousand_copy, [](auto& arr) { heap_sort(arr); });

	thousand_copy = thousand;
	measure_time("Size 1000 Quick Sort    ", thousand_copy, [](auto& arr) { quick_sort(arr); });


	return 0;
}

