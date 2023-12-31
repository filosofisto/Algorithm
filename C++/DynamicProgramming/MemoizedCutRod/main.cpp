#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "util.h"
#include "memoized.h"
#include "default.h"

int main(int argc, char** argv) 
{
    if (argc != 2) {
        std::cerr << "Wrong quantity of parameter\n";
        std::cout << "Pass the rod lenght as argument" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> prices = { 
		1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 
		1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 
		1, 5, 8, 9, 10, 17, 17, 20, 24, 30 
	};
    int rod_length = std::stoi(argv[1]);
    
    if (rod_length > prices.size()) {
		std::cerr << "Max rod_length is " << prices.size() << std::endl;
		return EXIT_FAILURE;
	}
    
    std::cout << "Prices: \n";
    show_vector(prices);
    
    std::cout << "Rod Length: " << rod_length << "\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    int max_revenue = cut_rod(prices, rod_length);
    auto end = std::chrono::high_resolution_clock::now();
    report("Default", rod_length, max_revenue, start, end);
    
    start = std::chrono::high_resolution_clock::now();
    max_revenue = memoized_cut_rod(prices, rod_length);
    end = std::chrono::high_resolution_clock::now();
	report("Memoized", rod_length, max_revenue, start, end);

    return EXIT_SUCCESS;
}
