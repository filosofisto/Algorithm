#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>
#include <random>
#include <mutex>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

namespace {
	int result = 0;
	std::mutex mtx;
};

void func(int& result) 
{
	std::this_thread::sleep_for(1s);
	result = 1 + (rand() % 10);
}

void funcWithMutex()
{
	std::this_thread::sleep_for(1s);
	int localVar = 1 + (rand() % 10);
	std::lock_guard<std::mutex> lock{mtx};
	result = localVar;
}

int main()
{
	std::thread t1{func, std::ref(result)};
	t1.join();
	sync_cout << "Result: " << result << std::endl;

	std::thread t2{funcWithMutex};
	t2.join();
	sync_cout << "Result (Mutex): " << result << std::endl;

	return EXIT_SUCCESS;
}
