#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>
#include <functional>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;
using std::endl;
using std::string;
using std::function;
using std::jthread;

class JThreadWrapper
{
	public:
		JThreadWrapper(
			const function<void(const std::string&)>& func,
			const string& str
		) : t(func, str), name(str) 
		{
			sync_cout << "Thread " << name << " being created" << endl;
		}

		~JThreadWrapper()
		{
			sync_cout << "Thread " << name << " being destroyed" << endl;
		}

	private:
		jthread t;
		string name;
};

void func(const string& name)
{
	sync_cout << "Thread " << name << " starting...\n";
	std::this_thread::sleep_for(1s);
	sync_cout << "Thread " << name << " finishing...\n";
}

int main()
{
	JThreadWrapper t1(func, "t1");
	JThreadWrapper t2(func, "t2");
	JThreadWrapper t3(func, "t3");

	std::this_thread::sleep_for(2s);

	sync_cout << "Main thread exiting..." << endl;
		
	return EXIT_SUCCESS;
}
