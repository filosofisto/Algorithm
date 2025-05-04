#include <iostream>
#include <sstream>

using namespace std;

string runLengthEncoding(string str) 
{
	size_t length = str.size();
	int count = 1;
	ostringstream oss;

	// special case string length equal to one
	if (length == 1) {
		oss << 1 << str[0];
		return oss.str();	
	}

	for (size_t i{1}; i < length; ++i) {
		if (str[i-1] == str[i]) {
			// same character
			++count;

			if (count == 9) {
				// limit achieved
				oss << count << str[i];
				count = 0;
			} else if (i == (length - 1)) {
				// special case when achieve last character
				oss << count << str[i];
			}
		} else {
			// different character
			if (count > 0) {
				oss << count << str[i-1];
			}
			count = 1;

			if (i == (length - 1)) {
				// special case when achieved last character
				oss << count << str[i];
			}
		}
	}
 
  return oss.str();
}

int main()
{
	//string test{"AAAAAAAAAAAAABBCCCCDD"};
	//string test{"aA"};
	string test{" "};
	//string test{"........______=========AAAA   AAABBBB   BBB"};
	//string test{" "};
	cout << runLengthEncoding(test) << '\n';

	return EXIT_SUCCESS;
}
