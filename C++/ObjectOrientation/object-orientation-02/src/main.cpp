#include <iostream>

class Base
{
	public:
		virtual void print() const = 0;
};

// add virtual public Base
class DerivedOne : virtual public Base
{
	public:
		void print() const override
		{
			std::cout << "DerivedOne\n";
		}
};

// add virtual public Base
class DerivedTwo : virtual public Base
{
	public:
		void print() const override
		{
			std::cout << "DerivedTwo\n";
		}
};

class Multiple : public DerivedOne, public DerivedTwo
{
	public:
		void print() const override 
		{
			DerivedTwo::print();
		}
};

int main()
{
	Multiple both{};
	DerivedOne one{};
	DerivedTwo two{};

	Base* array[3]{};

	array[0] = &both; // error: ‘Base’ is an ambiguous base of ‘Multiple’ -> add virtual public Base on inherited
	array[1] = &one;
	array[2] = &two;

	for (int i{0}; i < 3; ++i) {
		array[i]->print();
	}

	return EXIT_SUCCESS;
}

