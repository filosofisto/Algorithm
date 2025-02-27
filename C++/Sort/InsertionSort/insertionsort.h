#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

constexpr bool DEBUG = false;

template<typename T, size_t N>
void print(array<T,N>& a)
{
	for (auto element : a) {
		cout << element << " ";
	}

	cout << endl;
}


template<typename T, size_t N>
void print(array<T,N>& a, T key, int j, int i)
{
	cout << "j: " << j << ", i: " << i << ", key: " << key << '\n';

	for (auto element : a) {
		cout << element << " ";
	}

	cout << endl;
}

template<typename T, size_t N>
void insertion_sort(array<T,N>& a)
{
	for (auto j = 1; j < N; ++j) {
		auto key = a[j];
		auto i = j - 1;

		while (i >= 0 && a[i] > key) {
			if (DEBUG) print(a, key, j, i);

			a[i+1] = a[i];
			i = i - 1;
		}

		a[i+1] = key;
	}

	if (DEBUG) print(a);
}
