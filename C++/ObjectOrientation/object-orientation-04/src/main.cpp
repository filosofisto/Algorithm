#include <iostream>
#include <print>
#include "Time.h"

using std::println;

int main()
{
	const Time t1(12, 15, 30);
	const Time t2(12, 15, 30);
	const Time t3(6, 30, 30);

	println("t1: {}, t2: {}, t2: {}\n", t1.toString(), t2.toString(), t3.toString());
	
	println("t1 == t2: {}", t1 == t2);
	println("t1 != t2: {}", t1 != t2);
	println("t1 < t2: {}", t1 < t2);
	println("t1 > t2: {}", t1 > t2);
	println("t1 <= t2: {}", t1 <= t2);
	println("t1 >= t2: {}", t1 >= t2);
	println("t1 == t3: {}", t1 == t3);
	println("t1 != t3: {}", t1 != t3);
	println("t1 < t3: {}", t1 < t3);
	println("t1 > t3: {}", t1 > t3);
	println("t1 <= t3: {}", t1 <= t3);
	println("t1 >= t3: {}", t1 >= t3);
	
	return EXIT_SUCCESS;
}

