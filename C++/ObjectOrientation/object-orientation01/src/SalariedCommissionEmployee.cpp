#include <string>
#include <string_view>
#include <format>
#include <stdexcept>
#include "SalariedCommissionEmployee.h"

using std::string;
using std::string_view;
using std::format;
using std::invalid_argument;

SalariedCommissionEmployee::SalariedCommissionEmployee(string_view name, double salary, double grossSales, double commissionRate) : SalariedEmployee{name, salary}
{
	setGrossSales(grossSales);
	setCommissionRate(commissionRate);
}

void SalariedCommissionEmployee::setGrossSales(double grossSales)
{
	if (grossSales < 0.0) {
		throw invalid_argument{"Gross sales must be >= 0"};
	}

	this->grossSales = grossSales;
}

double SalariedCommissionEmployee::getGrossSales() const
{
	return grossSales;
}

void SalariedCommissionEmployee::setCommissionRate(double commissionRate)
{
	if (commissionRate <= 0.0 || commissionRate >= 1.0) {
		throw invalid_argument{"Commission rate must be > 0.0 and < 1.0"};
	}

	this->commissionRate = commissionRate;
}

double SalariedCommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

double SalariedCommissionEmployee::earnings() const
{
	return SalariedEmployee::earnings() + getGrossSales() * getCommissionRate();
}

string SalariedCommissionEmployee::toString() const
{
	return format("{}gross sales: ${:.2f}\ncommission rate: ${:.2f}\n", SalariedEmployee::toString(), getGrossSales(), getCommissionRate());
}

