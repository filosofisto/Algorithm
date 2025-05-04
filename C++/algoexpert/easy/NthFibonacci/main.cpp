#include <iostream>

using namespace std;

int getNthFib(int n) 
{
  if (n < 0) return -1; // error condition
	if (n == 0) return 0;
	if (n == 1) return 1;

  return getNthFib(n-1) + getNthFib(n-2);
}

int main()
{

	cout << "Fib(0) = " << getNthFib(0) << '\n';
	cout << "Fib(1) = " << getNthFib(1) << '\n';
	cout << "Fib(2) = " << getNthFib(2) << '\n';
	cout << "Fib(3) = " << getNthFib(3) << '\n';
	cout << "Fib(4) = " << getNthFib(4) << '\n';
	cout << "Fib(5) = " << getNthFib(5) << '\n';

	return EXIT_SUCCESS;
}
