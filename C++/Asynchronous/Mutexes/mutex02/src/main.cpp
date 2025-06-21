#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int counter{0};

int main()
{
	auto funcWithoutLocks = [] {
		for (int i{0}; i < 1'000'000; ++i) {
			++counter;
		}
	};

	auto funcWithLocks = [] {
		for (int i{0}; i < 1'000'000; ++i) {
			mtx.lock();
			++counter;
			mtx.unlock();
		}
	};

	{
		counter = 0;
		thread t1{funcWithoutLocks};
		thread t2{funcWithoutLocks};

		t1.join();
		t2.join();

		cout << "Counter without using locks: " << counter << endl;
	}

	{
		counter = 0;

		thread t1{funcWithLocks};
		thread t2{funcWithLocks};

		t1.join();
		t2.join();

		cout << "Counter using locks: " << counter << endl;
	}

	return EXIT_SUCCESS;
}
