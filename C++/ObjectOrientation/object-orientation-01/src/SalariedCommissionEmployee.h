#ifndef __SALARIED_COMMISSION_EMPLOYEE__
#define __SALARIED_COMMISSION_EMPLOYEE__

#include <string>
#include <string_view>
#include "SalariedEmployee.h"

class SalariedCommissionEmployee : public SalariedEmployee
{
	public:
		SalariedCommissionEmployee(std::string_view name, double salary, double grossSales, double commissionRate);
		virtual ~SalariedCommissionEmployee() = default;
		void setGrossSales(double grossSales);
		double getGrossSales() const;

		void setCommissionRate(double commissionRate);
		double getCommissionRate() const;

		double earnings() const;
		std::string toString() const;
	private:
		double grossSales{0.0};
		double commissionRate{0.0};
};

#endif
