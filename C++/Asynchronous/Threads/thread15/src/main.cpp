#include <iostream>
#include <thread>
#include <syncstream>

#define sync_cout std::osyncstream(std::cout)

using namespace std;

thread_local int val = 0;

void setValue(int value)
{
	val = value;
}

void print()
{
	sync_cout << val << ' ';
}

void multiplyByTwo(int arg)
{
	setValue(arg);
	val *= 2;
	print();
}

int main()
{
	val = 1; // main thread
	thread t1{multiplyByTwo, 1};
	thread t2{multiplyByTwo, 2};
	thread t3{multiplyByTwo, 3};
	
	t1.join();
	t2.join();
	t3.join();

	cout << val << endl;

	return EXIT_SUCCESS;
}
