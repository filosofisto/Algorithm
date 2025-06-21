#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <mutex>
#include <vector>

using namespace std;
using namespace std::chrono_literals;

constexpr int NUM_THREADS{8};
int counter{0};
int failed{0};

int main()
{
	timed_mutex tm;
	mutex m;

	auto worker = [&] {
		for (int i{0}; i < 10; ++i) {
			if (tm.try_lock_for(10ms)) {
				++counter;
				cout << "Counter: " << counter << endl;
				this_thread::sleep_for(10ms);
				tm.unlock();
			} else {
				m.lock();
				++failed;
				cout << "Thread " << this_thread::get_id() << " failed to lock" << endl;
				m.unlock();
			}

			this_thread::sleep_for(12ms);
		}
	};

	vector<thread> threads;

	for (int i{0}; i < NUM_THREADS; ++i) {
		threads.emplace_back(worker);
	}

	for (auto& t : threads) {
		t.join();
	}
	
	cout << "Counter: " << counter << endl;
	cout << "Failed:  " << failed << endl;
	
	return EXIT_SUCCESS;
}
