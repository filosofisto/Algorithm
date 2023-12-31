#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <vector>
#include <chrono> 
#include <string>

void show_vector(const std::vector<int>& v);
void show_time(
			const std::chrono::time_point<std::chrono::high_resolution_clock>& start, 
			const std::chrono::time_point<std::chrono::high_resolution_clock>& end
		);
void report(
	const std::string& algorithm,
	int rod_length,
	int max_revenue,
	const std::chrono::time_point<std::chrono::high_resolution_clock>& start, 
	const std::chrono::time_point<std::chrono::high_resolution_clock>& end
);

#endif
