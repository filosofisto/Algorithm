#include <iostream>
#include <condition_variable>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

int counter{0};

int main()
{
	mutex mtx;
	mutex cout_mtx;
	condition_variable cv;

	auto increment_counter = [&] {
		for (int i{0}; i < 20; ++i) {
			this_thread::sleep_for(100ms);
			mtx.lock();
			++counter;
			mtx.unlock();
			cv.notify_one();
		}
	};

	auto wait_for_counter_non_zero_mtx = [&] {
		mtx.lock();

		while (counter == 0) {
			mtx.unlock();
			this_thread::sleep_for(10ms);
			mtx.lock();
		}

		mtx.unlock();
		lock_guard<mutex> cout_lck{cout_mtx};
		cout << "Counter is non-zero" << endl;
	};

	auto wait_for_counter_10_cv = [&] {
		unique_lock<mutex> lck{mtx};
		cv.wait(lck, [] { return counter == 10; });

		lock_guard<mutex> cout_lck{cout_mtx};
		cout << "Counter is " << counter << endl;
	};

	thread t1{wait_for_counter_non_zero_mtx};
	thread t2{wait_for_counter_10_cv};
	thread t3{increment_counter};

	t1.join();
	t2.join();
	t3.join();
	
	return EXIT_SUCCESS;
}
