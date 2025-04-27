#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

map<int, unordered_map<string, int>> bestPaymentByDeadline(vector<unordered_map<string, int>> jobs)
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
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs)
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
}

int main()
{
	vector<unordered_map<string, int>> jobs = {	
		{ {"deadline", 1}, {"payment", 1} },
		{ {"deadline", 2}, {"payment", 1} },
		{ {"deadline", 2}, {"payment", 2} }
	};

	cout << optimalFreelancing(jobs) << '\n';

	return EXIT_SUCCESS;
}
