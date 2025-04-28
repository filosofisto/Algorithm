#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void func()
{
	std::this_thread::sleep_for(1s);
}

int main()
{
	std::thread t(func);
	std::cout << "Thread ID: " << t.get_id() << std::endl;
	t.join();

	return EXIT_SUCCESS;
}

