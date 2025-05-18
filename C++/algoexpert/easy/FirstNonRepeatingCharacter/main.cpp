#include <iostream>
#include <map>

using namespace std;

int firstNonRepeatingCharacter(string str) {
	map<char, size_t> m{};

	for (char c : str) {
		m[c]++;
	}

	char ch{'\0'};

	for (const auto& pair : m) {
		if (pair.second == 1) {
			ch = pair.first;
			break;
		}
	}
	
	if (ch == '\0') {
		return -1;
	}

	return str.find(ch);
}

int main()
{
	//string s{"abcdcaf"};
	//string s{"abbccaf"};
	string s{"abcdcaf"};
	
	cout << firstNonRepeatingCharacter(s) << '\n';

	return EXIT_SUCCESS;
}
