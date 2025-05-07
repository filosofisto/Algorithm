#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
 
void func()
{
	for (auto i{0}; i < 10; ++i) {
		std::this_thread::sleep_for(500ms);	
	}
}

int main()
{
	std::thread t1(func);
	std::thread t2(std::move(t1));
	
	t2.join();

	return EXIT_SUCCESS;
}
