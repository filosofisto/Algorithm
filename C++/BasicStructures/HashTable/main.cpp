#include <iostream>
#include "ChainedHashTable.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
	auto map = ChainedHashTable<int, string, 10>{};

	for (int i = 0; i < 1000; ++i) {
		map.insert(i+1, "A");
	}

	auto info = map.getInternalInfo();

	cout << "Collisions:   " << info.collisions << '\n';
	cout << "Replacements: " << info.replacements << endl;	

  return EXIT_SUCCESS;
}
