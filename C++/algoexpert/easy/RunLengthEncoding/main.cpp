#include <iostream>

using namespace std;

string runLengthEncoding(string str) 
{
	char curr = str[0];
	size_t length = str.size();
	string result;
	int count = 0;

	for (size_t i{1}; i < length; ++i) {
		if (str[i] == curr) {
			if (++count == 9) { // 9 is the max length
				result += format("{}{}", count, curr);
				count = 1;
			}

			if (i == (length - 1)) {
				result += format("{}{}", count, curr);		
			}
		} else {
			result += format("{}{}", count, curr);
			count = 1;
			curr = str[i];
		}
	}
 
  return result;
}

int main()
{
	string test{"AAAAAAAAAAAAABBCCCCDD"};
	cout << runLengthEncoding(test) << '\n';

	return EXIT_SUCCESS;
}
