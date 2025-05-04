#include <iostream>
#include <sstream>

using namespace std;

string runLengthEncoding(string str) 
{
	/*
	char curr = str[0];
	size_t length = str.size();
	int count = 1;
	ostringstream oss;

	for (size_t i{1}; i < length; ++i) {
		if (str[i] == curr) {
			if (++count == 9) { // 9 is the max length
				oss << count << curr;
				count = 1;
			}

			if (i == (length - 1)) {
				oss << count << curr;		
			}
		} else {
			oss << count << curr;
			count = 1;
			curr = str[i];

			if (i == (length - 1)) {
				oss << count << curr;
			}
		}
	}*/

	size_t length = str.size();
	int count = 1;
	ostringstream oss;

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
	string test{"aA"};
	
	//string test{"........______=========AAAA   AAABBBB   BBB"};
	//string test{" "};
	cout << runLengthEncoding(test) << '\n';

	return EXIT_SUCCESS;
}
