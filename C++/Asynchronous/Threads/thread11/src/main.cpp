#include <iostream>
#include <random>
#include <string>
#include <syncstream>
#include <thread>
#include <chrono>

#define sync_cout std::osyncstream(std::cout)

using std::mutex;
using std::lock_guard;
using std::jthread;
using std::chrono::steady_clock;

using namespace std::chrono_literals;

namespace
{
	int val = 0;
	mutex mtx;
}
	
int main()
{
	auto work = [&](const std::string& name) {
		while (true) {
			bool workToDo = rand() % 2;
			if (workToDo) {
				sync_cout << name << ": working\n";
				lock_guard<mutex> lock{mtx};

				for (auto start = steady_clock::now(), now = start; now < start + 3s; now = steady_clock::now()) {

				}				
			} else {
				sync_cout << name << ": yielding\n";
				std::this_thread::yield();
			}
		}
	};

	jthread t1(work, "t1");
	jthread t2(work, "t2");

	return EXIT_SUCCESS;
}
