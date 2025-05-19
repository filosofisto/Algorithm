#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool test(const string& a, const string& b)
{
	string bcopy{b};
	reverse(bcopy.begin(), bcopy.end());

	return a.size() == b.size() && a == bcopy;
}

vector<vector<string>> semordnilap(vector<string> words)
{
	vector<vector<string>> result{};
	set<string> processed;

	for (size_t i{0}; i < words.size()-1; ++i) {
		bool stop = false;

		for (size_t j{i+1}; j < words.size() && !stop; ++j) {
			if (processed.find(words[j]) != processed.end()) {
				continue;
			}

			if (test(words[i], words[j])) {
				result.push_back({words[i], words[j]});
				stop = true;
				processed.insert(words[j]);
			}
		}

		processed.insert(words[i]);
	}

	return result;
}

void print(const vector<vector<string>>& vec)
{
	cout << "[";

	for (const auto& v : vec) {
		cout << "[";
		
		for (const auto& s : v) {
			cout << s << ", ";
		}
		
		cout << "\b\b";
		cout << "], ";
	}

	cout << "\b\b";
	cout << "]\n";
}

int main()
{
	vector<string> words{"diaper", "abc", "test", "cba", "repaid"};
	print(semordnilap(words));

	return EXIT_SUCCESS;
}
