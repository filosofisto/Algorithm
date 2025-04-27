#include <iostream>
#include "constants.h"

void g()
{
	std::cout << "file b.cpp " << THE_STRING << '\n';
	std::cout << "Address: " << &THE_STRING << '\n';
}
