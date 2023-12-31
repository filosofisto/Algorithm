#include <iostream>
#include <vector>
#include <limits>
#include <string>

void show_vector(const std::vector<int>& v)
{
	for (auto value: v) {
		std::cout << value << " ";
	}
	
	std::cout << std::endl;
}

int cut_rod(const std::vector<int>& prices, int rod_length, std::vector<int>& memory)
{
	std::cout << "Memory: " << "\n";
	show_vector(memory);
	
	if (memory[rod_length-1] >= 0) {
		return memory[rod_length-1];
	} 
    if (rod_length == 0) return 0;
 
    int max_revenue{std::numeric_limits<int>::min()};

    // Try all possible cuts and choose the one that maximizes revenue
    for (int i = 1; i < rod_length; ++i) {
		std::cout 
			<< "i: " << i 
			<< ", prices[i]: " << prices[i] 
			<< ", rod_length: " << rod_length 
			<< ", max_revenue: " << max_revenue << "\n";
        max_revenue = std::max(max_revenue, prices[i] + cut_rod(prices, rod_length-i-1, memory));
    }
    
    memory[rod_length-1] = max_revenue;
    std::cout << "Filled memory on position " << (rod_length-1) << " with value " << max_revenue << "\n";

    return max_revenue;
}

int memoized_cut_rod(const std::vector<int>& prices, int rod_length)
{
	int infinity_negative{std::numeric_limits<int>::min()};
	
	std::vector<int> memory;
	for (auto i = 0; i < rod_length; ++i) {
		memory.push_back(infinity_negative);
	}
	
	return cut_rod(prices, rod_length, memory);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Wrong quantity of parameter\n";
        std::cout << "Pass the rod lenght as argument" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> prices = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    std::cout << "Prices: \n";
    show_vector(prices);
    
    int rod_length = std::stoi(argv[1]);
    std::cout << "Rod Length: " << rod_length << "\n";
    
    int max_revenue = memoized_cut_rod(prices, rod_length);

    std::cout << "Maximum revenue for a rod of length " << rod_length << ": " << max_revenue << std::endl;

    return EXIT_SUCCESS;
}
