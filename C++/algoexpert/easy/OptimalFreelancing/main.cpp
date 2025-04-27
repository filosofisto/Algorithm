#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>

using namespace std;

/*map<int, unordered_map<string, int>> bestPaymentByDeadline(vector<unordered_map<string, int>> jobs)
{
	map<int, unordered_map<string, int>> bestRecords;
 
	for (const auto& record: jobs) {
		int deadline = record.at("deadline");
		int payment = record.at("payment");

		auto it = bestRecords.find(deadline);
		if (it == bestRecords.end() || payment > it->second.at("payment")) {
			bestRecords[deadline] = record;
		}
	}

	return bestRecords;
}*/

/*int optimalFreelancing(vector<unordered_map<string, int>> jobs)
{
	auto payments = bestPaymentByDeadline(jobs);

	int day = 1;
	int totalPayment = 0;
	
	for (const auto& pair : payments) {
		int deadline = pair.first;

		if (day <= deadline) {
			const auto& record = pair.second;	
			totalPayment += record.at("payment");
			day++;
		}

		if (day > 7) {
			break;
		}
	}

	return totalPayment;
}*/

constexpr int DAYS_OF_WEEK = 7;

int optimalFreelancing(vector<unordered_map<string, int>> jobs)
{
	int profit = 0;
	array<bool, DAYS_OF_WEEK>	daysWorked;
	
	// descendent sort by payment
	sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
		return a.at("payment") > b.at("payment");
	});
	
	for (const auto& job : jobs) {
		// find the farest not filled
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
//	{	
//		{ {"deadline", 1}, {"payment", 1} },
//		{ {"deadline", 2}, {"payment", 1} },
//		{ {"deadline", 2}, {"payment", 2} }
    {
    	{ {"deadline", 2}, {"payment", 1} },
    	{ {"deadline", 2}, {"payment", 2} },
    	{ {"deadline", 2}, {"payment", 3} },
    	{ {"deadline", 2}, {"payment", 4} },
    	{ {"deadline", 2}, {"payment", 5} },
    	{ {"deadline", 2}, {"payment", 6} },
    	{ {"deadline", 2}, {"payment", 7} }
    };

	cout << optimalFreelancing(jobs) << '\n';

	return EXIT_SUCCESS;
}
