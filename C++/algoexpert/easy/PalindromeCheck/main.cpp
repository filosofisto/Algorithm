#include <iostream>

using namespace std;

bool isPalindrome(string str) 
{
	const size_t length = str.size();

	for (size_t i{0}, j{length-1}; i < length; ++i, --j) {
		if (str[i] != str[j]) {
			return false;
		}
	}

  return true;
}

int main()
{

	//cout << boolalpha << isPalindrome("abcdcba") << endl;
	cout << boolalpha << isPalindrome("ab") << endl;
	
	return EXIT_SUCCESS;
}
