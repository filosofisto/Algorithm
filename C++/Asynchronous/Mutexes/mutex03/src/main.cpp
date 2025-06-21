#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <shared_mutex>

using namespace std;
using namespace std::chrono_literals;

int counter{0};

int main()
{
	shared_mutex mutex;

	auto reader = [&] {
		for (int i{0}; i < 10; ++i) {
			mutex.lock_shared();
			// read the counter and do something
			mutex.unlock_shared();
		}
	};

	auto writer = [&] {
		for (int i{0}; i < 10; ++i) {
			mutex.lock();
			++counter;
			cout << "Counter: " << counter << endl;
			mutex.unlock();
		
			this_thread::sleep_for(10ms);
		}
	};
	
	thread t1{reader};
	thread t2{reader};
	thread t3{writer};
	thread t4{reader};
	thread t5{reader};
	thread t6{writer};

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	
	return EXIT_SUCCESS;
}
