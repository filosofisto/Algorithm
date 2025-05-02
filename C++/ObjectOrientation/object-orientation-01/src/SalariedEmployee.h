#ifndef __SALARIED_EMPLOYEE__
#define __SALARIED_EMPLOYEE__

#include <string>
#include <string_view>
#include "Employee.h"

class SalariedEmployee : public Employee
{
	public:
		SalariedEmployee(std::string_view name, double salary);
		virtual ~SalariedEmployee() = default;

		void setSalary(double salary);
		double getSalary() const;

		double earnings() const override;
		std::string toString() const override;

	private:
		double salary;
};

#endif
