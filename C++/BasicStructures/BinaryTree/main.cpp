#include <iostream>
#include "RecursiveBinaryTree.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
  RecursiveBinaryTree<int> tree{};
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);


	tree.inorderTreeWalker();
	tree.remove(10);
	tree.inorderTreeWalker();
  
	return EXIT_SUCCESS;
}
