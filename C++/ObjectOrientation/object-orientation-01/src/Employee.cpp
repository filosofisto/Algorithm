#include <format>
#include "Employee.h"

using std::string;
using std::string_view;
using std::format;

Employee::Employee(string_view name) : name{name}
{

}

void Employee::setName(string_view name)
{
	this->name = name;
}

string Employee::getName() const
{
	return name;
}

string Employee::toString() const
{
	return format("name: {}", getName());
}

