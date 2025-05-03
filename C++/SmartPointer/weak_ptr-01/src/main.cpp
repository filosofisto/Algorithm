#include <iostream>
#include <memory>
#include <print>

using namespace std;

void observe(weak_ptr<int> w)
{
	if (shared_ptr<int> sh = w.lock()) {
		println("*sh = {}", *sh);
	} else {
		cout << "w is expired\n";
	}
}

int main()
{
	weak_ptr<int> w;

	{
		auto sh = make_shared<int>(3);
		w = sh; // weak_ptr made from shared_ptr
		// w points to a live shared_ptr<int> here
		observe(w);
	}

	// w points to an expired shared_ptr<int> here
	observe(w);

	return EXIT_SUCCESS;
}

