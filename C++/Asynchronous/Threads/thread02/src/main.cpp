#include <iostream>
#include <thread>
#include <cstring>
#include <syncstream>

using namespace std;

#define sync_cout osyncstream(cout)

void problem()
{
	thread t1([]() {
		for (int i = 0; i < 100; ++i) {
			cout << "1 " << "2 " << "3 " << "4 " << endl;
		}
	});	

	thread t2([]() {
		for (int i = 0; i < 100; ++i) {
			cout << "5 " << "6 " << "7 " << "8 " << endl;
		}
	});

	t1.join();
	t2.join();
}

void solution() 
{
	thread t1([]() {
		for (int i = 0; i < 100; ++i) {
			sync_cout << "1 " << "2 " << "3 " << "4 " << endl;
		}
	});	

	thread t2([]() {
		for (int i = 0; i < 100; ++i) {
			sync_cout << "5 " << "6 " << "7 " << "8 " << endl;
		}
	});

	t1.join();
	t2.join();
}

void usage(char **argv)
{
	cout << argv[0] << " problem|solution\n"; 
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		usage(argv);
		return EXIT_FAILURE;
	}
	if (strcmp(argv[1], "problem") != 0 && strcmp(argv[1], "solution") != 0) {
		usage(argv);
		return EXIT_FAILURE;
	}
	if (strcmp(argv[1], "problem") == 0) {
		problem();
	}
	if (strcmp(argv[1], "solution") == 0) {
		solution();
	}

	return EXIT_SUCCESS;
}

