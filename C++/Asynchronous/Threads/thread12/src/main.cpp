#include <iostream>
#include <chrono>
#include <functional>
#include <syncstream>
#include <thread>

#define sync_cout std::osyncstream(std::cout)

using std::jthread;
using std::atomic_bool;

using namespace std::chrono_literals;

class Counter
{
	using Callback = std::function<void(void)>;

	public:
		Counter(const Callback& callback)
		{
			t = jthread([&]() {
				while (running.load()) {
					callback();
					std::this_thread::sleep_for(1s);
				}
			});
		}

		void stop()
		{
			running.store(false);
		}

	private:
		jthread t;
		atomic_bool running{true};		
};

int main()
{
	Counter counter1{[&]() {
		sync_cout << "Callback 1 running...\n";
	}};
	Counter counter2{[&]() {
		sync_cout << "Callback 2 running...\n";
	}};
	Counter counter3{[&]() {
		sync_cout << "Callback 3 running...\n";
	}};

	std::this_thread::sleep_for(3s);

	counter1.stop();
	counter2.stop();
	counter3.stop();
	
	return EXIT_SUCCESS;
}
