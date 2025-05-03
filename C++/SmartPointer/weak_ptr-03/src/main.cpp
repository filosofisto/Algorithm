#include <iostream>
#include <memory>

using namespace std;

// Problem: who will be destructed first? Destructor will never be called 
/*
struct Y;

struct X
{
	shared_ptr<Y> p;
	~X() { cout << "~X()\n"; }		
};

struct Y
{
	shared_ptr<X> p;
	~Y() { cout << "~Y()\n"; }		
};

void oops()
{
	auto x = make_shared<X>();
	auto y = make_shared<Y>();

	x->p = y;
	y->p = x;
}
*/

// Solution:
struct Y;

struct X
{
	weak_ptr<Y> p;
	~X() { cout << "~X()\n"; }		
};

struct Y
{
	shared_ptr<X> p;
	~Y() { cout << "~Y()\n"; }		
};

void oops()
{
	auto x = make_shared<X>();
	auto y = make_shared<Y>();

	x->p = y;
	y->p = x;
}

int main()
{
	oops();
	cout << "Done\n";

	return EXIT_SUCCESS;
}
