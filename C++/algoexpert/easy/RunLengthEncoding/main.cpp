#include <iostream>
#include <sstream>

using namespace std;

string runLengthEncoding(string str) 
{
	char curr = str[0];
	size_t length = str.size();
	int count = 0;
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
		}
	}
 
  return oss.str();
}

int main()
{
	string test{"AAAAAAAAAAAAABBCCCCDD"};
	cout << runLengthEncoding(test) << '\n';

	return EXIT_SUCCESS;
}
