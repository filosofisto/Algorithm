#include <format>
#include <stdexcept>

#include "SalariedEmployee.h"

using std::string;
using std::string_view;
using std::invalid_argument;
using std::format;

SalariedEmployee::SalariedEmployee(string_view name, double salary) : Employee{name}
{
	setSalary(salary);
}

void SalariedEmployee::setSalary(double salary)
{
	if (salary < 0.0) {
		throw invalid_argument{"Salary must be >= 0"}; 
	}

	this->salary = salary;
}

double SalariedEmployee::getSalary() const
{
	return salary;
}

double SalariedEmployee::earnings() const
{
	return getSalary();
}

string SalariedEmployee::toString() const
{
	return format("{}\n{}: ${:.2f}\n", Employee::toString(), "salary", getSalary());
}

