#include <iostream>
#include <chrono>
#include "ChainedHashTable.h"
#include "ChainedHashTableBT.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
	auto map = ChainedHashTable<int, string, 10>{};

	for (int i = 0; i < 10000; ++i) {
		map.insert(i+1, "A");
	}

	auto info = map.getInternalInfo();

	cout << "[Map] Collisions:   " << info.collisions << '\n';
	cout << "[Map] Replacements: " << info.replacements << endl;	

	auto mapBT = ChainedHashTableBT<int, string, 10>{};
	for (int i = 0; i < 10000; ++i) {
		mapBT.insert(i+1, "A");
	}

	auto infoBT = mapBT.getInternalInfo();

 	cout << "[MapBT] Collisions:   " << infoBT.collisions << '\n';
	cout << "[MapBT] Replacements: " << infoBT.replacements << endl;	

	auto start = std::chrono::steady_clock::now();
	map.search(501);
	auto end = std::chrono::steady_clock::now();
	
	auto startBT = std::chrono::steady_clock::now();
	mapBT.search(501);
	auto endBT = std::chrono::steady_clock::now();

	std::chrono::duration<double, std::milli> ellapsed = end - start;
	cout << "[Map] Search time: " << ellapsed.count() << '\n';

	std::chrono::duration<double, std::milli> ellapsedBT = endBT - startBT;
	cout << "[MapBT] Search time: " << ellapsedBT.count() << '\n'; 

 	return EXIT_SUCCESS;
}
