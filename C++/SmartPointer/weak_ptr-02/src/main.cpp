#include <iostream>
#include "Cache.h"

using std::cout;
using std::endl;

int main()
{
	Cache<5> cache;
	
	for (int i{0}; i < 5; ++i) {
		cache.add(new Resource{i+1});		
	}

	auto p = cache.obtain(3);
	if (auto q = p.lock(); q) {
		cout << "Using resource " << q->id << endl;		
	}

	for (int i{6}; i < 15; ++i) {
		cache.add(new Resource{i+1});		
	}

	if (auto q = p.lock(); q) {
		cout << "Using resource " << q->id << endl;
	} else {
		cout << "Resource not available ..." << endl;
	}
	return EXIT_SUCCESS;
}
