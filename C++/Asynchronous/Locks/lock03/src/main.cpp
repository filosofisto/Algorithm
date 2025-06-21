#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>
#include "queue.h"

using namespace std;
using namespace std::chrono_literals;

#define sync_cout std::osyncstream(std::cout)

int main()
{
	Queue<int> q{10};

	auto producer_work = [&] () {
		for (int i{0}; i < 100; ++i) {
			sync_cout << "Gonna to produce " << i << endl;
			q.push(i);
			sync_cout << "Produced " << i << endl;

			this_thread::sleep_for(20ms);
		}
	};

	auto consumer_work = [&] () {
		int x;

		for (int i{0}; i < 100; ++i) {
			sync_cout << "Gonna to consume " << i << endl;
			q.pop(x);
			sync_cout << "Consumed " << x << endl;

			this_thread::sleep_for(10ms);
		}
	};

	thread consumer{consumer_work};
	thread producer{producer_work};

	consumer.join();
	producer.join();

	return EXIT_SUCCESS;
}
