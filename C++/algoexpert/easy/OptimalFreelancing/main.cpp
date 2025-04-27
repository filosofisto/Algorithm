#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>

using namespace std;

constexpr int DAYS_OF_WEEK = 7;

int optimalFreelancing(vector<unordered_map<string, int>> jobs)
{
	int profit = 0;
	array<bool, DAYS_OF_WEEK>	daysWorked{false, false, false, false, false, false, false};
	
	// descendent sort by payment
	sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
		return a.at("payment") > b.at("payment");
	});
	
	for (const auto& job : jobs) {
		// find the farest not filled
		auto deadline = job.at("deadline");
		if (deadline > 7) break;

		for (int i = job.at("deadline")-1; i > -1; --i) {
			if (!daysWorked[i]) {
				daysWorked[i] = true;
				profit += job.at("payment");
				break;
			}
		}
	}

	return profit;
}

int main()
{
	vector<unordered_map<string, int>> jobs = 
// case 1
//	{	
//		{ {"deadline", 1}, {"payment", 1} },
//		{ {"deadline", 2}, {"payment", 1} },
//		{ {"deadline", 2}, {"payment", 2} }
//	};

// case 2
//    {
//    	{ {"deadline", 2}, {"payment", 1} },
//    	{ {"deadline", 2}, {"payment", 2} },
//    	{ {"deadline", 2}, {"payment", 3} },
//    	{ {"deadline", 2}, {"payment", 4} },
//    	{ {"deadline", 2}, {"payment", 5} },
//    	{ {"deadline", 2}, {"payment", 6} },
//    	{ {"deadline", 2}, {"payment", 7} }
//    };

// case 3
//    {
//    	{ {"deadline", 2}, {"payment", 2} },
//    	{ {"deadline", 4}, {"payment", 3} },
//    	{ {"deadline", 5}, {"payment", 1} },
//    	{ {"deadline", 7}, {"payment", 2} },
//    	{ {"deadline", 3}, {"payment", 1} },
//    	{ {"deadline", 3}, {"payment", 2} },
//    	{ {"deadline", 1}, {"payment", 3} }
//    };

// case 4
  {
    { {"deadline", 1}, {"payment", 1} },
    { {"deadline", 2}, {"payment", 1} },
    { {"deadline", 3}, {"payment", 1} },
    { {"deadline", 4}, {"payment", 1} },
    { {"deadline", 5}, {"payment", 1} },
    { {"deadline", 6}, {"payment", 1} },
    { {"deadline", 7}, {"payment", 1} },
    { {"deadline", 8}, {"payment", 1} },
    { {"deadline", 9}, {"payment", 1} },
    { {"deadline", 10}, {"payment", 1} }
  };

	cout << optimalFreelancing(jobs) << '\n';

	return EXIT_SUCCESS;
}
