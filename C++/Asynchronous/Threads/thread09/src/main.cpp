#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

using std::jthread;
using std::cout;
using std::endl;

void func()
{
	std::this_thread::sleep_for(1s);
}

int main()
{
	jthread t(func);
	sync_cout << "Thread ID: " << t.get_id() << endl;

	return EXIT_SUCCESS;
}
