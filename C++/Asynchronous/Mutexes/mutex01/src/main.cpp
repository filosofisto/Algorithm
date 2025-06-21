#include <iostream>
#include <thread>

using namespace std;

int counter{0};

int main()
{
	auto func = [] {
		for (int i{0}; i < 1'000'000; ++i) {
			++counter;
		}
	};

	thread t1{func};
	thread t2{func};

	t1.join();
	t2.join();

	cout << counter << endl;

	return EXIT_SUCCESS;
}
