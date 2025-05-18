#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

using namespace std;

vector<string> commonCharacters(vector<string> strings) {
  vector<string> ret{};
	map<char, size_t> mapChars{};
	
	for (const auto& s : strings) {
		for (char c : s) {
			mapChars.emplace(c, 0);
		}			
	}

	for (const auto& s : strings) {
		set<char> setOfChars{s.begin(), s.end()};
		
		for (char c : setOfChars) {
				mapChars[c]++;
		}
	}

	for (const auto& pair : mapChars) {
		if (pair.second == strings.size()) {
			ret.push_back(string{pair.first});
		}
	}

	return ret;
}

int main()
{
	vector<string> strings{"abc", "bcd", "cbaccd"};
	vector<string> result = commonCharacters(strings);

	copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
	
	return EXIT_SUCCESS;
}
