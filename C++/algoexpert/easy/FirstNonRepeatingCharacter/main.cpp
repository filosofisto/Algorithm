#include <iostream>
#include <map>

using namespace std;

int firstNonRepeatingCharacter(string str) {
	map<char, size_t> m{};

	for (char c : str) {
		m[c]++;
	}

	size_t pos = -1;

	for (char ch : str) {
		++pos;
		if (m[ch] == 1) {
			return pos;
		}
	}

	return -1;
}

int main()
{
	//string s{"abcdcaf"};
	//string s{"abbccaf"};
	//string s{"abcdcaf"};
	string s{"ggyllaylacrhdzedddjsc"};
	
	cout << firstNonRepeatingCharacter(s) << '\n';

	return EXIT_SUCCESS;
}
