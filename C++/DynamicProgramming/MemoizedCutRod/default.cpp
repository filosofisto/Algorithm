#include "default.h"

int cut_rod(const std::vector<int>& prices, int rod_length)
{
    if (rod_length == 0) return 0;

    int max_revenue{std::numeric_limits<int>::min()};

    for (int i = 0; i < rod_length; ++i) {
        max_revenue = std::max(max_revenue, prices[i] + cut_rod(prices, rod_length-i-1));
    }

    return max_revenue;
}
