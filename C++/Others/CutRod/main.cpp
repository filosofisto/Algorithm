#include <iostream>
#include <vector>
#include <limits>
#include <string>

/**
 * Return the maximum revenue possible for a rod of length n.
 * 
 * p[1..n]: array of prices
 * n      : length of rod 
 */ 
int cut_rod(const std::vector<int>& prices, int rod_length)
{
    if (rod_length == 0) return 0;

    int max_revenue{std::numeric_limits<int>::min()};

    // Try all possible cuts and choose the one that maximizes revenue
    for (int i = 0; i < rod_length; ++i) {
        max_revenue = std::max(max_revenue, prices[i] + cut_rod(prices, rod_length-i-1));
    }

    return max_revenue;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Wrong quantity of parameter\n";
        std::cout << "Pass the rod lenght as argument" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> prices = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    int rod_length = std::stoi(argv[1]);
    int max_revenue = cut_rod(prices, rod_length);

    std::cout << "Maximum revenue for a rod of length " << rod_length << ": " << max_revenue << std::endl;

    return EXIT_SUCCESS;
}
