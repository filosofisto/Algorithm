#include <iostream>
#include "SalariedCommissionEmployee.h"

using std::cout;
using std::endl;

int main()
{
	SalariedEmployee employee{"Sue Jones", 30000.0};
	cout << employee.toString() << endl;
	
	SalariedCommissionEmployee commissionEmployee{"Bob Lewis", 300.0, 5000.0, .04};
	cout << commissionEmployee.toString() << endl;

	return EXIT_SUCCESS;
}

