#include <iostream>
#include "constants.h"

void f()
{
	std::cout << "file a.cpp " << THE_STRING << '\n';
	std::cout << "Address: " << &THE_STRING << '\n';
}
