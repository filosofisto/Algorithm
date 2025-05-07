#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>

using namespace std::chrono_literals;
using std::thread;
using std::cout;
using std::endl;

#define sync_cout std::osyncstream(std::cout)

namespace
{
	int timeout = 3;
}

void daemonThread()
{
	sync_cout << "Daemon thread starting...\n";
	while (timeout-- > 0) {
		sync_cout << "Daemon thread is running...\n";
		std::this_thread::sleep_for(1s);
	}

	sync_cout << "Daemon thread exiting...\n";
}

int main()
{
	thread t(daemonThread);
	t.detach();

	std::this_thread::sleep_for(std::chrono::seconds(timeout + 1));
	sync_cout << "Main thread exiting...\n";

	return EXIT_SUCCESS;
}
