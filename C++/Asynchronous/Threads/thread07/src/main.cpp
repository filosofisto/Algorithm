#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
using std::thread;
using std::cout;
using std::endl;
using std::boolalpha;

void func()
{
	std::this_thread::sleep_for(100ms);
}

int main()
{
	cout << boolalpha;

	thread t1;
	cout << "Is t1 joinable? " << t1.joinable() << endl;

	thread t2(func);
	cout << "Is t2 joinable? " << t2.joinable() << endl;
	
	t1.swap(t2);
	cout << "Is t1 joinable after swap? " << t1.joinable() << endl;	
	cout << "Is t2 joinable after swap? " << t2.joinable() << endl;

	t1.join();	
	cout << "Is t1 joinable after join? " << t1.joinable() << endl;

	return EXIT_SUCCESS;
}
