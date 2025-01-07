#include <iostream>
#include <vector>
#include <set>

using namespace std;

int nonConstructibleChange(vector<int> coins) 
{
  if (coins.empty()) return 1;
 
	auto n = coins.size();
	auto total_combinations = 1 << n;
	set<int> sum_set;
	
	for (int mask = 1; mask < total_combinations; ++mask) { // Start from 1 to exclude the empty set
  	auto sum = 0;
        
		for (int i = 0; i < n; ++i) {
    	if (mask & (1 << i)) { // Check if the ith element is in the subset
      	sum += coins[i];
      }
    }

		sum_set.insert(sum);
  }

	auto min_change = 1;
	while (sum_set.find(min_change) != sum_set.end()) {
		min_change++;
	}

	return min_change;
}

int main()
{
	vector<int> coins{};
	//vector<int> coins{1, 2, 5};
	//vector<int> coins{5, 7, 1, 1, 2, 3, 22};
	auto result = nonConstructibleChange(coins);
	cout << result << '\n';

	return EXIT_SUCCESS;	
}
