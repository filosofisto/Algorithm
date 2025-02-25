#include <array>

using std::cout;
using std::endl;
using std::size_t;
using std::array;

template<typename T, size_t N>
void print(array<T,N>& a)
{
	for (auto element : a) {
		cout << element << " ";
	}

	cout << endl;
}

