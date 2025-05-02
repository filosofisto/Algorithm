#include <iostream>
#include "TrieTree.h"

int main()
{
  TrieTree tree{};

	for (int i{0}; i < 2; ++i) {
		tree.insert("tree");
	}
	for (int i{0}; i < 3; ++i) {
		tree.insert("true");
	}
	for (int i{0}; i < 4; ++i) {
		tree.insert("try");
	}

	auto result = tree.typeahead("tr", 3);

	return EXIT_SUCCESS;
}
