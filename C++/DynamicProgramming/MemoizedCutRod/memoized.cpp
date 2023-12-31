#include "memoized.h"

int memoized_cut_rod_aux(
		const std::vector<int>& prices, 
		int rod_length, 
		std::unordered_map<int, int>& memory
)
{	
	// Is it on cache? Return if so
	if (memory[rod_length] >= 0) return memory[rod_length];
	
	// Recursivity stop condition
    if (rod_length == 0) return 0;
 
    int max_revenue{std::numeric_limits<int>::min()};

    // Try all possible cuts and choose the one that maximizes revenue
    for (int i = 0; i < rod_length; ++i) {
		//std::cout 
		//	<< "i: " << i 
		//	<< ", prices[i]: " << prices[i] 
		//	<< ", rod_length: " << rod_length 
		//	<< ", max_revenue: " << max_revenue << "\n";
		
        max_revenue = std::max(max_revenue, prices[i] + memoized_cut_rod_aux(prices, rod_length-i-1, memory));
    }
    
    memory[rod_length] = max_revenue;
	//std::cout << rod_length << " calculated to " << max_revenue << "\n";
	
    return max_revenue;
}

int memoized_cut_rod(const std::vector<int>& prices, int rod_length)
{
	int infinity_negative{std::numeric_limits<int>::min()};
	std::unordered_map<int, int> memory;
	
	for (auto i = 1; i <= rod_length; ++i) {
		memory[i] = infinity_negative;
	}
	
	return memoized_cut_rod_aux(prices, rod_length, memory);
}
