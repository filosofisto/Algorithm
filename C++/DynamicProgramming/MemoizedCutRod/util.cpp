#include "util.h"

void show_vector(const std::vector<int>& v)
{
	for (auto value: v) {
		std::cout << value << " ";
	}
	
	std::cout << std::endl;
}

void show_time(
			const std::chrono::time_point<std::chrono::high_resolution_clock>& start, 
			const std::chrono::time_point<std::chrono::high_resolution_clock>& end
		)
{
	auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	
	std::cout << "\tProcessing time: " << elapsed_time.count() << " ms\n";
}

void report(
	const std::string& algorithm,
	int rod_length,
	int max_revenue,
	const std::chrono::time_point<std::chrono::high_resolution_clock>& start, 
	const std::chrono::time_point<std::chrono::high_resolution_clock>& end
)
{
	std::cout << "Algorithm: " << algorithm << "\n";
    std::cout 
			<< "\tMaximum revenue for a rod of length " 
			<< rod_length 
			<< ": " 
			<< max_revenue << std::endl;
			
    show_time(start, end);
}
