#include <compare>
#include <format>
#include <iostream>
#include <string>

class Time
{
	public:
		Time(int hr, int min, int sec) noexcept;
		
		std::string toString() const; 

		auto operator<=>(const Time& time) const noexcept = default;

	private:
		int hr{0};
		int min{0};
		int sec{0};
};
