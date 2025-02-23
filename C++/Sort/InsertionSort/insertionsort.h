#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

template<typename T, size_t N>
void print(array<T,N>& a)
{
	for (auto element : a) {
		cout << element << " ";
	}

	cout << endl;
}

template<typename T, size_t N>
void insertion_sort(array<T,N>& a)
{
	for (auto j = 1; j < N; ++j) {
		print(a);

		auto key = a[j];
		auto i = j - 1;

		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i = i - 1;
		}

		a[i+1] = key;
	}
}
