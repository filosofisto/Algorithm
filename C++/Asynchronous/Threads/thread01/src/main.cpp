#include <iostream>
#include <thread>

using namespace std;

void func()
{
	cout << "Using function pointer\n";	
}

class FuncObjectClass
{
	public:
		void operator()()
		{
			cout << "Using function object class\n";
		}
};

class Obj
{
	public:
		void func()
		{
			cout << "Using non-static member function\n";
		}
};

class StaticObj
{
	public:
		static void static_func()
		{
			cout << "Using a static member function\n";
		}
};

int main()
{
	thread t1{func};

	auto lambda_func = []() {
		cout << "Using lambda function\n";
	};
	thread t2{lambda_func};

	thread t3{[]() {
		cout << "Using embedded lambda function\n";
	}};

	thread t4{FuncObjectClass()};

	Obj obj;
	thread t5{&Obj::func, &obj}; 	

	thread t6{&StaticObj::static_func};

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	const auto processorCount = thread::hardware_concurrency();
	cout << "Processor Count: " << processorCount << '\n';

	return EXIT_SUCCESS;
}
