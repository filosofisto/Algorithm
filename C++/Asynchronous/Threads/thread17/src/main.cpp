#include <iostream>
#include <thread>
#include <exception>
#include <mutex>

int main()
{
	std::once_flag run_once_flag;
	std::once_flag run_once_exceptions_flag;

	auto thread_function = [&] {
		std::call_once(run_once_flag, [] {
			std::cout << "This must run just once\n";
		});
	};

	std::jthread t1{thread_function};
	std::jthread t2{thread_function};
	std::jthread t3{thread_function};
	
	return EXIT_SUCCESS;
}
