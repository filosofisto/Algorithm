#include <iostream>
#include <thread>
#include <format>
#include <mutex>

using namespace std;

mutex mtx;
uint32_t counter{};

void function_throws()
{
	throw runtime_error{"Error"};
}

int main()
{
	auto worker = [] {
		for (int i{0}; i < 1000000; ++i) {
			mtx.lock();
			counter++;
			mtx.unlock();
		}
	};

	auto worker_exceptions = [] {
		for (int i{0}; i < 1000000; ++i) {
			try {
				lock_guard<mutex> lock{mtx};
				counter++;
				function_throws();
			} catch (system_error& e) {
				cout << e.what() << endl;
				return;
			} catch (...) {
				return;
			}
		}
	};

	thread t1{worker_exceptions};
	thread t2{worker};

	t1.join();
	t2.join();

	cout << "Final counter value: " << counter << endl;

	return EXIT_SUCCESS;
}
