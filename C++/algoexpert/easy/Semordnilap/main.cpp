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

	int limitOut{static_cast<int>(words.size()-1)};
	int limitInner{static_cast<int>(words.size())};

	for (int i{0}; i < limitOut; ++i) {
		bool stop = false;

		for (int j{i+1}; j < limitInner && !stop; ++j) {
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
	//vector<string> words{"diaper", "abc", "test", "cba", "repaid"};
	//vector<string> words{};
	//vector<string> words{"aaa", "bbbb"};
	//vector<string> words{"dog", "god"};
	//vector<string> words{"aaa", "bbbb"};
	//vector<string> words{"dog", "hello", "god"};
	//vector<string> words{"aaa", "bbbb"};
	//vector<string> words{"dog", "desserts", "god", "stressed"};
	//vector<string> words{"dog", "hello", "desserts", "test", "god", "stressed"};
	//vector<string> words{"aaa", "bbbb"};
	//vector<string> words{"abcde", "edcba", "edbc", "edb", "cbde", "abc"};
	//vector<string> words{"abcde", "bcd", "dcb", "edcba", "aaa"};
	vector<string> words{"abcdefghijk", "aaa", "hello", "racecar", "kjihgfedcba"};


	print(semordnilap(words));

	return EXIT_SUCCESS;
}
