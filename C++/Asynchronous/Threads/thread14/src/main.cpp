#include <iostream>
#include <atomic>
#include <chrono>
#include <exception>
#include <mutex>
#include <thread>
#include <syncstream>

#define sync_cout std::osyncstream(std::cout)
#define sync_cerr std::osyncstream(std::cerr)

using namespace std::chrono_literals;

using std::exception_ptr;
using std::mutex;
using std::lock_guard;
using std::runtime_error;
using std::current_exception;
using std::rethrow_exception;
using std::exception;
using std::jthread;
using std::cerr;
using std::endl;

exception_ptr capturedException;
mutex mtx;

void func()
{
	try {
		std::this_thread::sleep_for(1s);
		throw runtime_error("Error in func used within thread"); 
	} catch (...) {
		lock_guard<mutex> lock{mtx};
		capturedException = current_exception();
	}
}

int main()
{
	jthread t{func};

	while (true) {
		{
			lock_guard<mutex> lock{mtx};
			if (capturedException) {
				break;
			}
		}
		
		std::this_thread::sleep_for(250ms);
		sync_cout << "In main thread\n";		
	}

	try {
		{
			lock_guard<mutex> lock{mtx};
			rethrow_exception(capturedException);
		}
	} catch (const exception& e) {
		cerr << "Exception caught in main thread: " << e.what() << endl;		
	}

	return EXIT_SUCCESS;
}
