#ifndef __TIMER__
#define __TIMER__

#include <iostream>
#include <thread>
#include <syncstream>
#include <functional>
#include <chrono>

using namespace std::chrono;
using namespace std::chrono_literals;

#define sync_cout std::osyncstream(std::cout)

template<typename Duration>
class Timer
{
	public:
		using Callback = std::function<void(void)>;

		Timer(const Duration interval, const Callback& callback);
		void stop();

	private:
		std::jthread t;
		std::atomic_int32_t val{0};		
};

template<typename Duration>
Timer<Duration>::Timer(const Duration interval, const typename Timer<Duration>::Callback& callback)
{
	auto value = duration_cast<milliseconds>(interval);
	t = std::jthread([&](std::stop_token stop_token) {
		while (!stop_token.stop_requested()) {
			sync_cout << "Timer: Running callback " << val.load() << '\n';
			++val;
			callback();
			sync_cout << "Timer: Sleeping...\n";

			// Wait for either timeout or stop requested
			if (stop_token.wait_for(interval) == std::stop_token::stop_requested) {
				break;
			}
			//std::this_thread::sleep_for(interval);
		}
		sync_cout << "Timer: Exit\n";
	});
}

template<typename Duration>
void Timer<Duration>::stop()
{
	t.request_stop();
}

#endif

