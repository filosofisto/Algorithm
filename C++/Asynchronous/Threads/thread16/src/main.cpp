#include <iostream>
#include <thread>
#include "Timer.h"

using namespace std::chrono;
using namespace std::chrono_literals;

int main()
{
	sync_cout << "Main: Create Timer\n";
	Timer timer(1s, [&]() {
		sync_cout << "Callback running...\n";
	});

	std::this_thread::sleep_for(3s);
	sync_cout << "Main thread: Stop timer\n";
	timer.stop();

	std::this_thread::sleep_for(500ms);
	sync_cout << "Main thread: Exit\n";

	return EXIT_SUCCESS;
}
