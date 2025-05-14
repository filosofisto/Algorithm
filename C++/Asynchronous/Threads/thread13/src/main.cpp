#include <iostream>
#include <chrono>
#include <string_view>
#include <syncstream>
#include <thread>
#include <ios>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

using std::string_view;
using std::boolalpha;
using std::jthread;
using std::thread;
using std::stop_token;
using std::stop_source;
using std::stop_callback;

template <typename T>
void show_stop_props(string_view name, const T& stopItem)
{
	sync_cout << boolalpha
						<< name
						<< ": stop_possible = " << stopItem.stop_possible()
						<< ", stop_requested = " << stopItem.stop_requested()
						<< '\n';
}

void func_with_stop_token(stop_token stopToken)
{
	for (int i{0}; i < 10; ++i) {
		std::this_thread::sleep_for(300ms);

		if (stopToken.stop_requested()) {
			sync_cout << "stop_worker stopping as requested\n";
			return; 
		}

		sync_cout << "stop_worker going back to sleep\n";
	}
}

int main()
{
	// stop_token
	auto worker1 = jthread(func_with_stop_token);
	stop_token stopToken{worker1.get_stop_token()};
	show_stop_props("stop_token", stopToken);

	worker1.request_stop();
	worker1.join();
	show_stop_props("stop_token after stop_request", stopToken);

	// stop_source
	auto worker2 = jthread(func_with_stop_token);
	stop_source stopSource{worker2.get_stop_source()};	
	show_stop_props("stop_source", stopSource);

	auto stopper = thread([](stop_source source) {
		std::this_thread::sleep_for(500ms);
		sync_cout << "Request stop for worker2 via source\n";
		source.request_stop();
	}, stopSource);

	stopper.join();

	std::this_thread::sleep_for(200ms);
	show_stop_props("stop_source after request_stop()", stopSource);

	// stop_callback
	stop_callback stopCallback{worker1.get_stop_token(), []{
		sync_cout << "stop_callback for worker1 executed by thread " << std::this_thread::get_id() << '\n';
	}};

	sync_cout << "main thread: " << std::this_thread::get_id() << '\n';
	
	stop_callback stopCallbackAfterStop{worker2.get_stop_token(), []{
		sync_cout << "stop_callback for worker2 executed by thread " << std::this_thread::get_id() << '\n';
	}};

	return EXIT_SUCCESS;
}
