#include <iostream>

using namespace std;

bool isPalindrome(string str) 
{
	const size_t length = str.size();

	for (size_t i{0}, j{length-1}; i < length && j > -1; ++i, --j) {
		if (str[i] != str[j]) {
			return false;
		}
	}

  return true;
}

int main()
{
	cout << boolalpha << isPalindrome("abcdcba") << endl;

	return EXIT_SUCCESS;
}
