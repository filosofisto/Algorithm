#include <string>
#include <format>
#include "Time.h"

using std::string;
using std::format;

Time::Time(int hr, int min, int sec) noexcept : 
	hr{hr}, 
	min{min}, 
	sec{sec} 
{ 

}
		
string Time::toString() const 
{
	return format("{}:{}:{}", hr, min, sec);	
}
