#include <iostream>
#include "ChainedHashTable.h"

using std::string;

int main()
{
	auto map = ChainedHashTable<int, string, 10>{};
	map.insert(1, "A");
	map.insert(11, "B");

  return EXIT_SUCCESS;
}
