#include <iostream>

using namespace std;


int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n-1) + fib(n-2);
}

int getNthFib(int n)
{
	if (n == 0) return 0;
	return fib(n-1);
}

int main()
{

	cout << "Fib(0) = " << getNthFib(0) << '\n';
	cout << "Fib(1) = " << getNthFib(1) << '\n';
	cout << "Fib(2) = " << getNthFib(2) << '\n';
	cout << "Fib(3) = " << getNthFib(3) << '\n';
	cout << "Fib(4) = " << getNthFib(4) << '\n';
	cout << "Fib(5) = " << getNthFib(5) << '\n';
	cout << "Fib(6) = " << getNthFib(6) << '\n';
	cout << "Fib(7) = " << getNthFib(7) << '\n';
	cout << "Fib(8) = " << getNthFib(8) << '\n';
	cout << "Fib(9) = " << getNthFib(9) << '\n';
	cout << "Fib(10) = " << getNthFib(10) << '\n';
	
	return EXIT_SUCCESS;
}
